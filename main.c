#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "k0gram.tab.h" 
#include "tree.h"
#include "symtab.h"
#include "type.h" 
#include <math.h>

extern FILE *yyin;
extern int yyparse(void);
extern char *yytext;
extern int yylineno;
extern YYSTYPE yylval;
extern int yyival;
extern double yydval;
extern char *yysval;
extern int yylex_destroy();
extern int yydebug;
extern const char *yyname(int sym);
extern void yyrestart(FILE *input_file);
extern struct tree *root;
struct token yytoken; 
char *filename;
int serial = 0;
SymbolTable current = NULL;
SymbolTable globals = NULL;
SymbolTable predefined = NULL;
SymbolTable last_scope = NULL;
int SCOPE = 0; 
int variable_declaration = 0;
#define pushscope(stp) do { stp->parent = current; current = stp; SCOPE++; } while (0)
#define popscope() do { current = current->parent; SCOPE--; } while(0)
void printsymbols(SymbolTable st, int level);
SymbolTable find_table(char *table_name);
bool nullable = false;
bool mutability = false; 
void insert_type(SymbolTable st, char *s, typeptr t);

struct token {
   int category;   /* the integer code returned by yylex */
   char *text;     /* the actual string (lexeme) matched */
   int lineno;     /* the line number on which the token occurs */
   char *filename; /* the source file in which the token occurs */
   int ival;       /* for integer constants, store binary value here */
   double dval;	   /* for real constants, store binary value here */
   char *sval;     /* for string constants, malloc space, de-escape, store */
                   /*    the string (less quotes and after escapes) here */
}token;

int yyerror(char *s) {
    fprintf(stderr, "Syntax error: %s at line %d, near token '%s'\n", s, yylineno, yytext);
    exit(2);
    
}

char *appendstring(char *s, char c) {
    int i = strlen(s);
    s = realloc(s, i + 2);
    s[i] = c;
    s[i + 1] = '\0';
    return s;
}
char *descape(const char* yytext) {
    char *sval;

    if (yytext[0] == '"') {
        sval = strdup("");
        for (int i = 1; yytext[i] != '\0'; i++) {
            if (yytext[i] == '\\') {
                switch (yytext[++i]) {
                    case 'n':
                        sval = appendstring(sval, '\n');
                        break;
                    case 't':
                        sval = appendstring(sval, '\t');
                        break;
                    case 'r':
                        sval = appendstring(sval, '\r');
                        break;
                    case '\\':
                        sval = appendstring(sval, '\\');
                        break;
                    case '"':
                        sval = appendstring(sval, '"');
                        break;
                    default:
                        sval = appendstring(sval, yytext[i]);
                        break;
                }
            } else if (yytext[i] == '"') {
                continue;  // Skip the ending double-quote
            } else {
                sval = appendstring(sval, yytext[i]);
            }
        }
    } else {
        sval = NULL;
    }

    return sval;
}

void printnode(struct tree *t) {
    if (t == NULL) {
        printf("Tree node is NULL\n");
        return;
    }

    if (t->leaf != NULL) {
        printf("Leaf node:\n");
        printf("\tprodrule = %d\n", t->prodrule);
        printf("\tsymbolname = %s\n", t->symbolname ? t->symbolname : "NULL");
        printf("\tnkids = %d\n", t->nkids);
        printf("\tToken information:\n");
        printf("\t\tcategory = %d\n", t->leaf->category);
        printf("\t\ttext = %s\n", t->leaf->text);
        printf("\t\tlineno = %d\n", t->leaf->lineno);
        printf("\t\tfilename = %s\n", t->leaf->filename);
        if (t->leaf->sval != NULL) {
            printf("\t\tsval = %s\n", t->leaf->sval);
        } else if (t->leaf->ival != 0) {
            printf("\t\tival = %d\n", t->leaf->ival);
        } else if (t->leaf->dval != 0.0) {
            printf("\t\tdval = %f\n", t->leaf->dval);
        }
    } else {
        printf("Internal node:\n");
        printf("\tprodrule = %d\n", t->prodrule);
        printf("\tsymbolname = %s\n", t->symbolname ? t->symbolname : "NULL");
        printf("\tnkids = %d\n", t->nkids);
        printf("\tChildren:\n");
        for (int i = 0; i < t->nkids; i++) {
            printf("\t\tChild %d: %p\n", i + 1, (void *)t->kids[i]);
        }
    }
}

int alctoken(int category) {
    // Allocate memory for the tree node
    yylval.treeptr = calloc(1, sizeof(struct tree));
    if (yylval.treeptr == NULL) {
        fprintf(stderr, "Error: Out of memory while allocating tree node\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the tree node fields
    yylval.treeptr->prodrule = category;
    yylval.treeptr->nkids = 0;
    yylval.treeptr->id  = serial++;

    yylval.treeptr->leaf = malloc(sizeof(struct token));
    if (yylval.treeptr->leaf == NULL) {
        fprintf(stderr, "Error: Out of memory while allocating token\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the token fields
    yylval.treeptr->leaf->category = category;
    yylval.treeptr->leaf->text = strdup(yytext);    
    yylval.treeptr->leaf->lineno = yylineno;
    yylval.treeptr->leaf->filename = strdup(filename); // Replace with actual file name if needed
    yylval.treeptr->leaf->ival = yyival;
    yylval.treeptr->leaf->dval = yydval;
    yylval.treeptr->leaf->sval = NULL; // Initialize sval to NULL
    
    if (yysval) {
        yylval.treeptr->leaf->sval = strdup(yysval);
        free(yysval); // Free yysval here after copying it
        yysval = NULL;
    }
    
    yydval = 0.0;
    yyival = 0;
    
    return category;
}

struct tree *alctree(int prodrule, const char *symbolname, int nkids, ...) {
    int i;
    va_list ap;
    struct tree *ptr = calloc(1, sizeof(struct tree) + (nkids-1)*sizeof(struct tree *));

    if (ptr == NULL) {
        fprintf(stderr, "alctree out of memory\n");
        exit(1);
    }
    ptr->prodrule = prodrule;
    ptr->symbolname = strdup(symbolname);
    ptr->nkids = nkids;
    ptr->id  = serial++;

    va_start(ap, nkids);
    for(i=0; i < nkids; i++)
        ptr->kids[i] = va_arg(ap, struct tree *);
    va_end(ap);
    return ptr;
} 
 
char *pretty_print_name(struct tree *t) {
    char *s2 = malloc(40);
    if (t->leaf == NULL) {
       sprintf(s2, "%s#%d", t->symbolname, t->prodrule%10);
       return s2;
       }
    else {
       sprintf(s2,"%s:%d", descape(t->leaf->text), t->leaf->category);
       return s2;
       }
 }
 
 void print_branch(struct tree *t, FILE *f) {
    fprintf(f, "N%d [shape=box label=\"%s\"];\n", t->id, pretty_print_name(t));
 }
 
 
 void print_leaf(struct tree *t, FILE *f) {
    const char * s = yyname(t->leaf->category);
    print_branch(t, f);
    fprintf(f, "N%d [shape=box style=dotted label=\" %s \\n ", t->id, s);
    fprintf(f, "text = %s \\l lineno = %d \\l\"];\n", descape(t->leaf->text),
    t->leaf->lineno);
 }
 
 void print_graph2(struct tree *t, FILE *f) {
    int i;
    if (t->symbolname == NULL) {
       print_leaf(t, f);
       return;
       }
    /* not a leaf ==> internal node */
    print_branch(t, f);
    for(i=0; i < t->nkids; i++) {
       if (t->kids[i] != NULL) {
          fprintf(f, "N%d -> N%d;\n", t->id, t->kids[i]->id);
      print_graph2(t->kids[i], f);
      }
       else { /* NULL kid, epsilon production or something */
          fprintf(f, "N%d -> N%d%d;\n", t->id, t->id, serial);
      fprintf(f, "N%d%d [label=\"%s\"];\n", t->id, serial, "Empty rule");
      serial++;
      }
       }
 }

 void printsymbol(char *s)
 {
    printf("%s\n", s); fflush(stdout);
 }
 
 
char * alloc(int n)
{
   char *a = calloc(n, sizeof(char));
   if (a == NULL) {
      fprintf(stderr, "alloc(%d): out of memory\n", (int)n);
      exit(-1);
      }
   return a;
}
/*
 * create a symbol table and return a pointer to it.
 */
SymbolTable mksymtab(int nbuckets, char *name) {
    SymbolTable table = (SymbolTable)malloc(sizeof(struct sym_table));
     if (table) {
        table->nBuckets = nbuckets;
        table->nEntries = 0;
        table->name = strdup(name);
        table->tbl = (struct sym_entry **)
        alloc((unsigned int)(nbuckets * sizeof(struct sym_entry *)));
     }
     return table;
}
/*
 * hash function
 */
int hash(SymbolTable st, char *s)
{
   register int h = 0;
   register char c;
   while ((c = *s++)) {
      h += c & 0377;
      h *= 37;
      }
   if (h < 0) h = -h;
   return h % st->nBuckets;
}

/*
 * Insert a symbol into a symbol table.
 */
int insert_sym(SymbolTable st, char *s, typeptr t, bool mutability, bool nullability) { 
    struct sym_entry *se;
    int h;

    h = hash(st, s);
    if (t != NULL) { 
        // printf("Inserting symbol: %d\n", t->basetype); 
        }
    
    for (se = st->tbl[h]; se != NULL; se = se->next) {
        if (!strcmp(s, se->s)) {
            /*
             * A copy of the string is already in the table.
             */
            return 0;
        }
    }
    /*
     * The string is not in the table. Add the copy from the
     * buffer to the table.
     */
    se = (SymbolTableEntry)alloc((unsigned int) sizeof(struct sym_entry)); 
    se->s = strdup(s);
    se->table = st;
    se->next= st->tbl[h];
    st->tbl[h] = se;
    se->type = t;
    se->mutability = mutability;
    se->nullable = nullability;
    st->nEntries++;
    return 1;
}


void enter_newscope(char *s) {
    // Step 1: Allocate a new symbol table
    SymbolTable newTable = mksymtab(101, s);

    // Step 2: Allocate the corresponding type for the new scope
    typeptr t;
    t = alctype(FUNC_TYPE); // Assuming FUNC_TYPE for function scope
    // Allocate a function type and associate it with the symbol table 
    

    // Step 3: Insert the symbol into the current symbol table with the type
    if (insert_sym(current, s, t,false, false)) {        // Successfully inserted, now attach the symbol table to its entry
        int h = hash(current, s);
        struct sym_entry *se;
        for (se = current->tbl[h]; se != NULL; se = se->next) {
            if (!strcmp(se->s, s)) {
                // Attach the new symbol table (scope) to this symbol's entry
                se->table = newTable;
                break;
            }
        }
    } else {
        // If insertion failed (symbol already exists), handle the error
        fprintf(stderr, "Symbol '%s' already exists in the current scope.\n", s);
        return;
    }

    // Step 4: Push the new symbol table onto the stack to set it as the current scope
    pushscope(newTable);
}

/*
 * lookup_st - search the symbol table for a given symbol, return its entry.
 */
SymbolTableEntry lookup_st(SymbolTable st, char *s){
//  register int i; 
    int h;
    SymbolTableEntry se;

    h = hash(st, s);
    for (se = st->tbl[h]; se != NULL; se = se->next)
        if (!strcmp(s, se->s)) {
        /*
            *  Return a pointer to the symbol table entry.
            */
        return se;
        }
    return NULL;
}


void predefined_symbols() {
    // Step 1: Create the predefined symbol table
    predefined = mksymtab(101, "predefined");
    
    // Step 2: Insert symbols with type information
    insert_sym(predefined, "print", alctype(FUNC_TYPE), false, false);       // Function
    insert_sym(predefined, "println", alctype(FUNC_TYPE), false, false);     // Function
    insert_sym(predefined, "get", alctype(FUNC_TYPE), false, false);         // Function
    insert_sym(predefined, "equals", alctype(FUNC_TYPE), false, false);      // Function
    insert_sym(predefined, "length", alctype(FUNC_TYPE), false, false);      // Function
    insert_sym(predefined, "toString", alctype(FUNC_TYPE), false, false);    // Function
    insert_sym(predefined, "valueOf", alctype(FUNC_TYPE), false, false);     // Function
    insert_sym(predefined, "readln", alctype(FUNC_TYPE), false, false);      // Function
    insert_sym(predefined, "String", alctype(CLASS_TYPE), false, false);     // Class
    insert_sym(predefined, "java", alctype(PACKAGE_TYPE), false, false);     // Package
    insert_sym(predefined, "lang", alctype(PACKAGE_TYPE), false, false);     // Package
    insert_sym(predefined, "util", alctype(PACKAGE_TYPE), false, false);     // Package
    insert_sym(predefined, "Math", alctype(CLASS_TYPE), false, false);       // Class
    insert_sym(predefined, "abs", alctype(FUNC_TYPE), false, false);         // Function
    insert_sym(predefined, "max", alctype(FUNC_TYPE), false, false);         // Function
    insert_sym(predefined, "min", alctype(FUNC_TYPE), false, false);         // Function
    insert_sym(predefined, "pow", alctype(FUNC_TYPE), false, false);         // Function
    insert_sym(predefined, "cos", alctype(FUNC_TYPE), false, false);         // Function
    insert_sym(predefined, "sin", alctype(FUNC_TYPE), false, false);         // Function
    insert_sym(predefined, "tan", alctype(FUNC_TYPE), false, false);         // Function
    insert_sym(predefined, "random", alctype(FUNC_TYPE), false, false);      // Function
    insert_sym(predefined, "nextInt", alctype(FUNC_TYPE), false, false);     // Function
}

void populate_symboltables(struct tree *n)
{
    int i;
    if (n == NULL) return;
    /* pre-order activity */
    switch (n->prodrule) {

        // Handle entering a new function scope
        case 1004: /* Production rule for function declaration */ {
            //finding the function name in tree
            for (i = 0; i < n->nkids; i++) {
                if (n->kids[i] != NULL && n->kids[i]->leaf != NULL && n->kids[i]->leaf->category == 407) {
                   //printf("Function new name: %s\n", n->kids[i]->leaf->text);
                   //(n->kids[i]->leaf->text);
                   enter_newscope(n->kids[i]->leaf->text);
                   break;
                }
            } 
            break;
        } 
        case 1007: /* rule for function paramteres */ 
        for (i = 0; i < n->nkids; i++) {
             if (n->kids[i] != NULL && n->kids[i]->leaf != NULL && n->kids[i]->leaf->category == 407) {
                if ((lookup_st(current, n->kids[i]->leaf->text)) != NULL){
                    fprintf(stderr, "Error: Redeclaration of variable '%s' at line %d\n", n->kids[i]->leaf->text, n->kids[i]->leaf->lineno);
                    exit(3);
                }else{
                    insert_sym(current, n->kids[i]->leaf->text,alctype(NULL_TYPE),false, nullable);
                }
             }
         }
        
        break;  

        case 1028: /* check if it has passed through rule: property declaration*/
            variable_declaration = 1;

            if (n->kids[1]->leaf != NULL){ /* check if this is val or var */
                char *val_var = n->kids[1]->leaf->text;
                /* set the muatbility attribute based on val/var */
                if ((strcmp(val_var, "val") == 0)){
                    mutability = false;
                    
                } else {
                    mutability = true;
                    
                }
            }
            break;

        case 1022: /* whatever production rule(s) designate a variable declaration */
            /* if variable flag = 1, insert variable, if 0 then it is part of a control structure*/
            if(variable_declaration == 1){
                
                for (i = 0; i < n->nkids; i++) {
                    if (n->kids[i] != NULL && n->kids[i]->leaf != NULL && n->kids[i]->leaf->category == 407) {
                        
                        if ((lookup_st(current, n->kids[i]->leaf->text)) != NULL){
                            fprintf(stderr, "Error: Redeclaration of variable '%s' at line %d\n", n->kids[i]->leaf->text, n->kids[i]->leaf->lineno);
                            exit(3);
                        }else{ 
                            // printf("current type is : %d\n", n->kids[1]->leaf->text);
                            insert_sym(current, n->kids[i]->leaf->text,NULL,mutability, nullable);
                        }
                    }
                }
            } 
            variable_declaration = 0;
            break;
        
        case 1034:
        nullable = false;
        struct tree *z;
        if (n->kids[2] != NULL){
            z = n->kids[2];
        for (i = 0; i < z->nkids; i++) {
            if (z->kids[i] != NULL && z->kids[i]->prodrule == 1024) {
                if(z->kids[i]->kids[1] != NULL){
                    nullable = true;
                }
            }
        }
        }
        if (n->kids[1] == NULL){
            struct tree *child = n->kids[0];
            while (child != NULL && (child->leaf == NULL || child->leaf->category != 407)) {
                child = child->kids[0];
            }
            if (child != NULL && child->leaf != NULL && child->leaf->category == 407) {
                printf("Found leaf with category 407: %s\n", child->leaf->text);
            }
            // insert_sym(current,child->leaf->text,alctype(ARRAY_TYPE),false);
            break;
        }
        
        
             
        
            case 1043: /* assignment */
            //printnode(n->kids[0]->kids[]);
            struct tree *b = n->kids[0]->kids[0];
            SymbolTableEntry se;
            //printnode(b);
            for (i = 0; i < b->nkids; i++) {
                if (b->kids[i] != NULL && b->kids[i]->leaf != NULL && b->kids[i]->leaf->category == 407) {
                    se = lookup_st(current, b->kids[i]->leaf->text);
                    if (se != NULL && se->mutability == 0){
                        fprintf(stderr, "line %d: Error: symbol '%s' declared with val cannot be reassigned\n", b->kids[i]->leaf->lineno, b->kids[i]->leaf->text);
                            exit(3);
                    }   
                }
            } 
            if(n->kids[1] != NULL){ /* at assignment */
                b = n->kids[1];
                while(b->kids[0] != NULL){ /* traverse down to the actual value*/
                    b = b->kids[0];
                    if (b->leaf != NULL && b->leaf->category == 371) { /* check if being assigned to null literal*/
                        //printf("entry %s", )
                        if (se != NULL && se->nullable == 0){
                            fprintf(stderr, "Error: line %d: symbol '%s' cannot be assigned to null type \n", b->leaf->lineno, se->s);
                            exit(3);
                        }   
                    }
                }

            }

        break;
             
        case 407: /* whatever leaf denotes a variable name */
        /*for any variable it encounters, check if it is in global and current table if 
         * not mark it as undeclared 
         */
            //printf("Variable name: %s\n", n->leaf->text); 
            if ((lookup_st(current, n->leaf->text)) == NULL && (lookup_st(globals, n->leaf->text)) == NULL && (lookup_st(predefined, n->leaf->text)) == NULL){ 
                fprintf(stderr, "Error: Undeclared variable '%s' at line %d\n", n->leaf->text, n->leaf->lineno);
                exit(3);
            }
            break;
    }
    /* Visit children (Recursive traversal of child nodes) */
    for (i = 0; i < n->nkids; i++) {
        populate_symboltables(n->kids[i]);
    }

    /* Post-order activity */
    switch (n->prodrule) {
    
        case 1004: /* End of function scope */ {
            //printsymbols(current, SCOPE);
            //printf("---\n");
            if (current != NULL) {
                popscope(); // Pop the current scope to return to the parent scope
            }
            break;
        }
    }
}
void printsyms(struct tree *t) {
    if (t == NULL) { 
        return;
    }
 
    if (t->leaf != NULL && t->leaf->category == 407) {
        printsymbol(t->leaf->text);
    }
    for (int i = 0; i < t->nkids; i++) {
        printsyms(t->kids[i]);
    }
}

void build_function_parameter(struct tree *t) {
    int i;
    if (t == NULL) return; 
    
    struct tree *p = NULL;
    char *returntype = NULL;
    char *function_name = NULL;
    /* pre-order activity */
    switch (t->prodrule) {
        case 1004: /* rule for functions */ 

            if (t->kids[4] != NULL && t->kids[4]->prodrule == 1100) { 
                // printnode(t->kids[4]->kids[1]); // Assuming the return type is the first child of the 4th kid
                returntype = t->kids[4]->kids[0]->leaf->text; // Assuming the return type is the first child of the 4th kid
                printf("Return type: %s\n", returntype);
            }
        
            for (i = 0; i < t->nkids; i++) {
                // printf("Child: %d: \n ---------------------------------\n", i);
                // printnode(t->kids[i]);
            
                if (t->kids[i] != NULL && t->kids[i]->prodrule == 1005) {
                    p = t->kids[i];                 
                }
            } 
            for (i = 0; i < t->nkids; i++) {
                if (t->kids[i] != NULL && t->kids[i]->leaf != NULL && t->kids[i]->leaf->category == 407) {
                function_name = t->kids[i]->leaf->text;
            //    printf("Function new name: %s\n", function_name);
               SymbolTable name = find_table(function_name);
               pushscope(name); 
               break;
                }
            }
            insert_type(current,function_name,alcfunctype(returntype,p,current)); // Assuming FUNC_TYPE for function scope
            
            

            break;  

    }
    for (i = 0; i < t->nkids; i++) {
        build_function_parameter(t->kids[i]);
    }
    
    /* Post-order activity */
    switch (t->prodrule) {
        case 1004: /* End of class scope */ {
            popscope(); // Pop the current scope to return to the parent scope
            break;
        }
    }
}


void insert_type(SymbolTable st, char *s, typeptr t){
    //  register int i;
     int h;
     SymbolTableEntry se;
    
     h = hash(st, s);
     for (se = st->tbl[h]; se != NULL; se = se->next)
        if (!strcmp(s, se->s)) { 
            se->type = t; // Update the type of the existing symbol
           /*
            *  Return a pointer to the symbol table entry.
            
            */
           return ;
           }
     return;
}

/* given table name, find table */
SymbolTable find_table(char *table_name){
    struct sym_entry *se;
    int h = hash(current, table_name);
    for (se = current->tbl[h]; se != NULL; se = se->next) {
        return se->table;
    }
    return NULL;

}
typeptr alcarraytype(struct tree * s, struct tree * e)
{
   typeptr rv = alctype(ARRAY_TYPE);
   printf("in alcarraytype\n------------------\n");
   if (rv == NULL) return NULL; 
   if (s == NULL) {
       rv->u.a.size = -1; // default size is -1 (unspecified/unknown size)
   }else {
    rv->u.a.size = atoi(s->leaf->text); // default size is -1 (unspecified/unknown size)

   }
   rv->u.a.elemtype = NULL; // default element type is NULL
 
    struct tree *child = NULL; // Assuming this is the child node for element type
   if (e->kids[1]->kids[1]!= NULL) { /* check if it is a array of arrays*/ 
    printf("in child\n------------------\n");
        child = e->kids[1]->kids[1];
        while (child != NULL && (child->leaf == NULL || child->leaf->category != 400)) {
            child = child->kids[0];
        } 
        if (child != NULL && child->leaf != NULL && child->leaf->category == 400) {
            printf("Found leaf with category 400: %s\n", child->leaf->text);
            rv->u.a.elemtype = assignType(child->leaf->text ); // Assuming STRING_TYPE for the element type
        } 
   } else {
       rv->u.a.elemtype = alctype(NULL_TYPE); // Assuming STRING_TYPE for the element type
   }
   if (rv != NULL) {
       printf("Array type: %d\n", rv->u.a.elemtype ? rv->u.a.elemtype->basetype : -1);
       printf("Array size: %d\n", rv->u.a.size);
   } else {
       fprintf(stderr, "Error: rv is NULL. Cannot print array type or size.\n");
   }
 
   return rv;
}


void symboltable_type_init(struct tree *t) {
    int i;
    if (t == NULL) return; 
    /* pre-order activity */
    switch (t->prodrule) {
    case 1004: /* rule for functions */
        for (i = 0; i < t->nkids; i++) {
            if (t->kids[i] != NULL && t->kids[i]->leaf != NULL && t->kids[i]->leaf->category == 407) {
           char *function_name = t->kids[i]->leaf->text;
        //    printf("Function new name: %s\n", function_name);
           SymbolTable name = find_table(function_name);
           pushscope(name); 
           break;
            }
        }
        break;
    case 1034:
        struct tree *s = t->kids[0];
        while (s != NULL && s->prodrule != 407) {
            s = s->kids[0];
        }
        if (s != NULL && s->prodrule == 407) {
            // printnode(s);
        }
                 
        if(t->kids[2]){  
            if (t->kids[2]->kids[0]->kids[0]->prodrule == 400){  
                insert_type(current,s->leaf->text,assignType(t->kids[2]->kids[0]->kids[0]->leaf->text)); // Assuming the type is in the second child
            }
        }
 
    break;
    /* make sure this only happens for implicit types not all */
    case 1028: /* rule for property declaration*/
        struct tree *b;
        struct tree *c; 
        int implicit_variable = 0;

        /* first check if we are a implicit variable declaration */
        if (t->kids[3] != NULL) { /* multivariable_variableDeclaration */
            c = t->kids[3];
            if (c->kids[0] != NULL){
                c = c->kids[0];
                if(c->kids[0] != NULL && c->nkids < 2){
                    implicit_variable = 1;
                    c = c->kids[0];
                    while (c != NULL && c->prodrule != 407) {
                        c = c->kids[0]; /* get and store the symbols name*/
                    }
                }
                }
            }

        if(implicit_variable == 1){
        /* then traverse tree down to grammar rule for expression*/
            if (t->kids[4] != NULL) { 
                b = t->kids[4];
                if(b->kids[1] != NULL) { /* at the rule for expression*/
                    b = b->kids[1];
                    while(b->kids[0] != NULL){ /* traverse down to the actual value*/
                        b = b->kids[0];
                        if (b->leaf != NULL) { /* found value*/
                            //printf("Value:%s\n", b->leaf->text);
                            insert_type(current,c->leaf->text,get_type(b->leaf->category));

                        }

                    }
                    }      
            }

         
            struct tree *child = NULL;
            struct tree *child2 = NULL;
            char *arrayname = NULL;

            for (i = 0; i < t->nkids; i++) {
                if (t->kids[i] != NULL && t->kids[i]->prodrule == 1027) { 
                    if (t->kids[i]->kids[1] == NULL){
                        child = t->kids[i]->kids[0];
                                
                        while (child != NULL && (child->leaf == NULL || child->leaf->category != 407)) {
                            child = child->kids[0];
                        }
                        if (child != NULL && child->leaf != NULL && child->leaf->category == 407) {
                            printf("Found leaf with category 407: %s\n", child->leaf->text);
                            arrayname = child->leaf->text;
                        } 
                    }
                }
            }

            for (i = 0; i < t->nkids; i++) {
                if (t->kids[i] != NULL && t->kids[i]->prodrule == 1026) { 
                    printf("Found opt_eq_exp\n-----------\n");
                    child2 = t->kids[i]->kids[1]; //expression 
                    while (child2 != NULL &&  child2->prodrule != 2000) {
                        child2 = child2->kids[0];
                    }
                    if (child2 != NULL && child2->prodrule== 2000) {
                        // printf("find 2000\n------------------\n");   
                        insert_type(current,arrayname,alcarraytype(child2->kids[2],child2->kids[0])); // Assuming the type is in the second child
                        
                        // printnode(child2->kids[0]);

                        



                    }

                }
            }


 
             
    }  
        break;
    }
    for (i = 0; i < t->nkids; i++) {
        symboltable_type_init(t->kids[i]);
    }

    /* Post-order activity */
    switch (t->prodrule) {

        case 1004: /* End of class scope */ {
            popscope(); // Pop the current scope to return to the parent scope
            break;
        }
    }

}

/* print all symbol tables, pushes and pops scopes when it encounters a function*/
void print_all(struct tree *t){
    int i;
    if (t == NULL) return; 
    /* pre-order activity */
    switch (t->prodrule) {
    case 1004: /* rule for functions */
        for (i = 0; i < t->nkids; i++) {
            if (t->kids[i] != NULL && t->kids[i]->leaf != NULL && t->kids[i]->leaf->category == 407) {
           char *function_name = t->kids[i]->leaf->text;
           SymbolTable name = find_table(function_name);
           pushscope(name); 
           break;
            }
        }
        break;
    }
    for (i = 0; i < t->nkids; i++) {
       print_all(t->kids[i]);
    }
    /* Post-order activity */
    switch (t->prodrule) {
        case 1004: /* End of class scope */ {
            printsymbols(current, SCOPE);
            popscope(); // Pop the current scope to return to the parent scope
            break;
        }
    }

}


void printsymbols(SymbolTable st, int level) {
    int i;
    SymbolTableEntry ste;
    if (st == NULL) return;
    printf("---");
    printf("SCOPE %d - Symbol table for: %s\n", level, st->name);


    // Iterate over each bucket
    for (i = 0; i < st->nBuckets; i++) {
        for (ste = st->tbl[i]; ste != NULL; ste = ste->next) {
            printf("%s\n", ste->s);

            if (ste->type != NULL) {
                // Print the type information if available
                printf("Type: %d\n", ste->type->basetype);
            } else {
                // printf("Type: NULL\n");
            }
            printf("Mutability: %x\n", ste->mutability);
            printf("Nullability: %x\n", ste->nullable);

            // If the symbol has a sub-scope, print it recursively
            //if (ste->table != NULL && ste->table != st) {
              // printsymbols(ste->table, level + 1);
            //}
        }
    }
}





void print_symbol_table(SymbolTable st) {
    printf("Symbol Table:\n");

    // Traverse the hash table 
    for (int i = 0; i < st->nBuckets; i++) {
        struct sym_entry *se = st->tbl[i];
        while (se != NULL) {
            printf("Symbol: %s\n", se->s); // Print symbol name
            // Print other properties 
            // printf("Type: %d\n", se->type);
            se = se->next;
        }
    }
    printf("\n");
}

/*Traverse all symbol tables starting from current*/
void print_all_symbol_tables() {
    SymbolTable current_table = current;

    while (current_table != NULL) {
        print_symbol_table(current_table);
        current_table = current_table->parent;
    }
}

 
void print_graph(struct tree *t, char *filename){
       FILE *f = fopen(filename, "w"); /* should check for NULL */
       fprintf(f, "digraph {\n");
       print_graph2(t, f);
       fprintf(f,"}\n");
       fclose(f);
 }

void humanreadable(struct tree *t) {
    if (t->symbolname == NULL) {
        printf("%d: %s", t->leaf->category, t->leaf->text);
    } else {
        printf("%s: %d", t->symbolname, t->nkids);
    }
}

void treeprint(struct tree *t, int depth) {
    if (t == NULL) {
        return;
    }
    printf("%*s", depth * 2, " ");
    humanreadable(t);
    printf("\n");
    
    for (int i = 0; i < t->nkids; i++) {
        treeprint(t->kids[i], depth + 1);
    }
}


char* kt_extension(const char* filename) {
    char *new_filename = (char*)malloc(strlen(filename) + 4);
    strcpy(new_filename, filename);
    if (strstr(filename, ".kt") == NULL) {
        strcat(new_filename, ".kt");
    }
    return new_filename;
}

char* removeSeparators(char* yytext) {
    static char cleanText[256];
    int j = 0;
    for (int i = 0; yytext[i] != '\0'; i++) {
        if (yytext[i] != '_') {
            cleanText[j++] = yytext[i];
        }
    }
    cleanText[j] = '\0';
    return cleanText;
} 
 
struct param * mk_nparams(struct tree *n)
{ 
   if (n->prodrule == 1007) { /* base case: Parameter*/
      struct param *parameter = malloc(sizeof(struct param));
      if (!parameter) {
         fprintf(stderr, "Memory allocation failed for parameter.\n");
         return NULL;
      }
      parameter->name = n->kids[0]->leaf->text; // Assuming the name is in the first child 
       
      if(n->kids[2]){ 
        if (n->kids[2]->kids[0]->kids[0]->prodrule == 2001)
            parameter->type = alcarraytype(NULL, n->kids[2]->kids[0]->kids[0]);
        else if (n->kids[2]->kids[0]->prodrule == 1024) //nullabletype
            parameter->type = assignType(n->kids[2]->kids[0]->kids[0]->leaf->text); // Assuming the type is in the second child
        else {
            parameter->type = assignType(n->kids[2]->kids[0]->leaf->text); // Assuming the type is in the second child
        }
    }
    printf("Parameter Info:\n");
    printf("Name: %s\n", parameter->name);
    if (parameter->type != NULL) {
        printf("Type: %d\n", parameter->type->basetype);
    } else {
        printf("Type: NULL\n");
    }
      parameter->next = NULL;
      return parameter;

   } else if (n->prodrule == 1009) { /* recursive case */
      struct param *firstParameter = mk_nparams(n->kids[0]->kids[0]);
      struct param *remainingParameters = NULL;
      if (n->kids[1] != NULL){
           remainingParameters = mk_nparams(n->kids[1]->kids[2]->kids[0]);
      }
      if (!firstParameter) return remainingParameters;
      struct param *currentParameter = firstParameter;
      while (currentParameter->next != NULL) currentParameter = currentParameter->next;
      currentParameter->next = remainingParameters;
      return firstParameter;
   }
   
   return NULL;
} 
int main(int argc, char **argv) {
    int generate_dot = 0;      // Flag for -dot option
    int generate_tree = 0;     // Flag for -tree option
    int generate_symtab = 0;   // Flag for -symtab option
    int file_count = 0;        // Count of input files
    char **files = NULL;       // Array of input files

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-dot] [-tree] [-symtab] <filename1> [<filename2> ...]\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-dot") == 0) {
            generate_dot = 1;
        } else if (strcmp(argv[i], "-tree") == 0) {
            generate_tree = 1;
        } else if (strcmp(argv[i], "-symtab") == 0) {
            generate_symtab = 1;
        } else if (argv[i][0] != '-') {  // Assume it's a filename
            files = realloc(files, sizeof(char*) * (file_count + 1));
            files[file_count++] = kt_extension(argv[i]);
        }
    }

    if (file_count == 0) {
        fprintf(stderr, "Error: No input files specified.\n");
        return 1;
    }

    for (int i = 0; i < file_count; i++) {
        filename = files[i];
        printf("\nthis filename: %s\n", filename);
        yyin = fopen(filename, "r");
        if (!yyin) {
            perror(filename);
            free(filename);
            continue;
        }
        

        // Call the parser
        printf("Parsing file: %s\n", filename);
        yyrestart(yyin);  // Restart the lexer with the new file
        yylineno = 1;
        // yydebug = 1;
        int result = yyparse();
        printf("yyparse returns %d\n", result);

        // Handle the -tree option
        if (generate_tree) {
            treeprint(root, 1);  // Print the syntax tree
            printf("Syntax tree printed.\n");
        }

        // Handle the -symtab option
        if (generate_symtab) {
            if (result == 0) {  // Only generate symbol tables if parsing succeeds
                globals = mksymtab(101, "Global");
                current = globals;
                predefined_symbols();
                populate_symboltables(root);
                symboltable_type_init(root);
                build_function_parameter(root);



                // printf("Symbol tables generated.\n");
                printsymbols(current, 0);  // Print global symbol table
                print_all(root);
            } else {
                printf("Errors encountered during parsing. Symbol tables not generated.\n");
            }
        }

// Handle the -dot option
    if (generate_dot) {
        char dot_filename[256];
        snprintf(dot_filename, sizeof(dot_filename), "%s.dot", filename);
        print_graph(root, dot_filename);  // Generate a .dot file
        printf("Dot file generated: %s\n", dot_filename);
    }

    // Default behavior when no flags are provided
    if (!generate_tree && !generate_symtab && !generate_dot) {
        if (result == 0) {
            printf("No errors.\n");
        } else {
            printf("Errors encountered.\n");
        }
    }

    // Cleanup
    fclose(yyin);
    free(filename); 
    yylex_destroy();  // Free lexer resources

}

free(files);
return 0;
}
