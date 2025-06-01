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
#include <stdbool.h>
#include "tac.h"

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
extern int local_offset;
extern int global_offset;
extern int temp_offset;
struct token yytoken; 
extern int str_offset;

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
bool can_assign_to(int target_type, int value_type);
void printsymbols(SymbolTable st, int level);
SymbolTable find_table(char *table_name);
bool nullable = false;
bool mutability = false; 
void insert_type(SymbolTable st, char *s, typeptr t);
int literal[] = {385, 392, 383, 386, 391};
struct tree *find_leaf(struct tree *t, int category) ;
void codegen(struct tree *t);
void printcode(struct instr *L);

int addString(struct string_table *table, const char *s);
void initStringTable(struct string_table *table);

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
//fprintf(f, "N%d -> N%d%d;\n", t->id, t->id, serial);
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

/**
 * @brief Inserts a symbol into the symbol table.
 *
 * This function is responsible for adding a new symbol to the symbol table.
 * It ensures that the symbol is properly stored and can be retrieved or
 * referenced later during compilation or interpretation.
 *
 * @param symbol The symbol to be inserted into the table.
 * @param table The symbol table where the symbol will be stored.
 * @return int Returns 0 on success, or an error code if the insertion fails.
 */
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
    typeptr t = alctype(FUNC_TYPE);
    if (t == NULL) {
        fprintf(stderr, "Error: Failed to allocate type for new scope '%s'.\n", s);
        return;
    }
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
                // printf("Found leaf with category 407: %s\n", child->leaf->text);
            }
            //insert_sym(current,child->leaf->text,alctype(ARRAY_TYPE),false, false);
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

        case 1052:
        SymbolTableEntry ste;
        if(n->kids[0]->kids[0] != NULL && n->kids[1] != NULL){
            ste = lookup_st(current, n->kids[0]->kids[0]->leaf->text);
            //printnode(n->kids[0]->kids[0]);
            if (ste != NULL && ste->mutability == 0){
                fprintf(stderr, "line %d: Error: symbol '%s' declared with val cannot be reassigned\n", n->kids[0]->kids[0]->leaf->lineno, n->kids[0]->kids[0]->leaf->text);
                    exit(3);
            }   
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
struct tree *find_node_by_prodrule(struct tree *t, int prodrule) ;

void build_function_parameter(struct tree *t) {
    int i;
    if (t == NULL) return; 
    
    struct tree *p = NULL;
    char *returntype = NULL;
    char *function_name = NULL;
    SymbolTable name = NULL;
    /* pre-order activity */
    switch (t->prodrule) {
        case 1004: /* rule for functions */  

            if (find_node_by_prodrule(t,1100)) {   
            struct tree *node = find_node_by_prodrule(t,1100);  
            struct tree *leaf = find_leaf(node,400);
            // printnode(leaf);
               returntype = leaf->leaf->text; // Assuming the return type is the first child of the 4th kid
                // printf("Return type: %s\n", returntype);
            }
        
            for (i = 0; i < t->nkids; i++) { 
            
                if (t->kids[i] != NULL && t->kids[i]->prodrule == 1005) {
                    p = t->kids[i];  //functionvalueparamters        
                    break;        
                }
            } 
            for (i = 0; i < t->nkids; i++) {
                if (t->kids[i] != NULL && t->kids[i]->leaf != NULL && t->kids[i]->leaf->category == 407) {
                function_name = t->kids[i]->leaf->text;
            //    printf("Function new name: %s\n", function_name);
               name = find_table(function_name);
               pushscope(name); 
               break;
                }
            }
            struct typeinfo *functype = alcfunctype(returntype,p,current);
            insert_type(current->parent,function_name,functype); // Assuming FUNC_TYPE for function scope
            break;      

    }
    /* Post-order activity */
    switch (t->prodrule) {
        case 1004: /* End of class scope */ {
            popscope(); // Pop the current scope to return to the parent scope
            break;
        }
    }
    
    for (i = 0; i < t->nkids; i++) {
        build_function_parameter(t->kids[i]);
    }
    
}


void insert_type(SymbolTable st, char *s, typeptr t) {
    if (st == NULL || s == NULL || t == NULL) {
        fprintf(stderr, "Error: Null parameter in insert_type\n");
        return;
    }
    int h;
    SymbolTableEntry se = NULL;

    h = hash(st, s);
    for (se = st->tbl[h]; se != NULL; se = se->next) {
        if (!strcmp(s, se->s)) {
            se->type = t; // Update the type of the existing symbol
            return;
        }
    }

    // If the symbol is not found, insert a new entry
    se = (SymbolTableEntry)alloc(sizeof(struct sym_entry));
    if (se == NULL) {
        fprintf(stderr, "Error: Out of memory while inserting type.\n");
        exit(EXIT_FAILURE);
    }
    se->s = strdup(s);
    if (se->s == NULL) {
        fprintf(stderr, "Error: Out of memory while duplicating string.\n");
        free(se);
        exit(EXIT_FAILURE);
    }
    se->type = t;
    se->mutability = false; // Default values for new entry
    se->nullable = false;
    se->table = NULL;
    se->next = st->tbl[h];
    st->tbl[h] = se;
    st->nEntries++;
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
//    printf("in alcarraytype\n------------------\n");
   if (rv == NULL) return NULL; 
   if (s == NULL) {
       rv->u.a.size = -1; // default size is -1 (unspecified/unknown size)
   }else {
    rv->u.a.size = atoi(s->leaf->text); // default size is -1 (unspecified/unknown size)

   }
   rv->u.a.elemtype = NULL; // default element type is NULL
 
    struct tree *child = NULL; // Assuming this is the child node for element type
   if (e->kids[1]->kids[1]!= NULL) { /* check if it is a array of arrays*/ 
        child = e->kids[1]->kids[1];
        while (child != NULL && (child->leaf == NULL || child->leaf->category != 400)) {
            child = child->kids[0];
        } 
        if (child != NULL && child->leaf != NULL && child->leaf->category == 400) {
            // printf("Found leaf with category 400: %s\n", child->leaf->text);
            rv->u.a.elemtype = assignType(child->leaf->text ); // Assuming STRING_TYPE for the element type
        } 
   } else {
       rv->u.a.elemtype = alctype(NULL_TYPE); // Assuming STRING_TYPE for the element type
   }
//    if (rv != NULL) {
//        printf("Array type: %d\n", rv->u.a.elemtype ? rv->u.a.elemtype->basetype : -1);
//        printf("Array size: %d\n", rv->u.a.size);
//    } else {
//        fprintf(stderr, "Error: rv is NULL. Cannot print array type or size.\n");
//    }
 
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
                            // printf("from get type Value:%s\n", b->leaf->text);
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
                            // printf("Found leaf with category 407: %s\n", child->leaf->text);
                            arrayname = child->leaf->text;
                        } 
                    }
                }
            }

            for (i = 0; i < t->nkids; i++) {
                if (t->kids[i] != NULL && t->kids[i]->prodrule == 1026) { 
                    // printf("Found opt_eq_exp\n-----------\n");
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
                printf("Type: %s\n", get_typename(ste->type->basetype));
            } else {
                // printf("Type: NULL\n");
            }
            printf("Mutability: %x\n", ste->mutability);
            printf("Nullability: %x\n", ste->nullable);
            printf("\n");
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
 
struct param *mk_nparams(struct tree *n) {
    // Case: multi_comma_functionParameter (recursive case)
    if (!n) return NULL;

    if (n->prodrule == 1008) {
        struct param *p1 = mk_nparams(n->kids[0]);  // Process first parameter
        struct param *p2 = mk_nparams(n->kids[2]);  // Process next parameter

        if (!p1) return p2;  // If first parameter is NULL, return second

        struct param *temp = p1;
        while (temp->next != NULL) temp = temp->next;  // Traverse to last element
        temp->next = p2;  // Link parameter lists together

        return p1;
    }

    // Case: functionValueParameter (base case)
    if (n->prodrule == 1006) {
        return mk_nparams(n->kids[0]);  // Process single parameter
    }

    // Case: parameter (base case)
    if (n->prodrule == 1007) {
        struct param *parameter = malloc(sizeof(struct param));
        if (!parameter) {
            fprintf(stderr, "Memory allocation failed for parameter.\n");
            return NULL;
        }
        parameter->name = n->kids[0]->leaf->text;

        // Process type information
        if (n->kids[2]) {
            struct tree *typeNode = n->kids[2]->kids[0];
            // printnode(typeNode);
            if (typeNode->kids[0]->prodrule == 2001) {
                parameter->type = alcarraytype(NULL, typeNode->kids[0]);
            } else if (typeNode->prodrule == 1024) {
                parameter->type = assignType(typeNode->kids[0]->leaf->text);
            } else {
                parameter->type = assignType(typeNode->leaf->text);
            }
        }

        // Print parameter information for debugging
        // printf("Parameter Info:\nName: %s\n", parameter->name);
        // if (parameter->type) {
        //     printf("Type: %d\n", parameter->type->basetype);
        // } else {
        //     printf("Type: NULL\n");
        // }

        parameter->next = NULL;
        return parameter;
    }

    // Case: opt_functionValueParameter (recursive case)
    if (n->prodrule == 1009) {
        struct param *p1 = mk_nparams(n->kids[0]);  // Process first parameter
        struct param *p2 = mk_nparams(n->kids[1]);  // Process remaining parameters

        if (!p1) return p2;

        struct param *temp = p1;
        while (temp->next) temp = temp->next;  // Traverse to last parameter
        temp->next = p2;  // Link the parameters together

        return p1;
    }

    return NULL;
}

struct typeinfo *check_types(int operator, struct typeinfo *e1, struct typeinfo *e2, int linenum) 
{
    if (operator == 0 && e1 == NULL) // no operator
        return alctype(e2->basetype);
    else if (operator == 0 && e2 == NULL)
        return alctype(e1->basetype);
    
    if (e1 == NULL || e2 == NULL) {
        fprintf(stderr, "Error: Null type information provided.\n");
        exit(3);
    }

    struct typeinfo *result = malloc(sizeof(struct typeinfo));
    if (!result) {
        fprintf(stderr, "Error: Memory allocation failed for typeinfo.\n");
        exit(3);
    }

    switch (operator) {
        case ADD: 
            if (e1->basetype == INT_TYPE && e2->basetype == INT_TYPE) {
                result->basetype = INT_TYPE;
            } else if ((e1->basetype == FLOAT_TYPE && e2->basetype == INT_TYPE) ||
                       (e1->basetype == INT_TYPE && e2->basetype == FLOAT_TYPE) ||
                       (e1->basetype == FLOAT_TYPE && e2->basetype == FLOAT_TYPE)) {
                result->basetype = FLOAT_TYPE;
            } else if ((e1->basetype == DOUBLE_TYPE && e2->basetype == INT_TYPE) ||
                       (e1->basetype == INT_TYPE && e2->basetype == DOUBLE_TYPE) ||
                       (e1->basetype == DOUBLE_TYPE && e2->basetype == FLOAT_TYPE) ||
                       (e1->basetype == FLOAT_TYPE && e2->basetype == DOUBLE_TYPE) ||
                       (e1->basetype == DOUBLE_TYPE && e2->basetype == DOUBLE_TYPE)) {
                result->basetype = DOUBLE_TYPE;
            } else if (e1->basetype == STRING_TYPE && e2->basetype == STRING_TYPE) {
                result->basetype = STRING_TYPE; 
            } else if (e1->basetype == ARRAY_TYPE && e2->basetype == ARRAY_TYPE) {
                result->basetype = ARRAY_TYPE;     
            } else {
                fprintf(stderr, "Type error: Unsupported types for '+' operator on line %d.\n", linenum);
                exit(3);
            }
            break;
        
        case SUB: 
            if (e1->basetype == INT_TYPE && e2->basetype == INT_TYPE) {
                result->basetype = INT_TYPE;
            } else if ((e1->basetype == FLOAT_TYPE && e2->basetype == INT_TYPE) ||
                    (e1->basetype == INT_TYPE && e2->basetype == FLOAT_TYPE) ||
                    (e1->basetype == FLOAT_TYPE && e2->basetype == FLOAT_TYPE)) {
                result->basetype = FLOAT_TYPE;  
            } else if ((e1->basetype == DOUBLE_TYPE && e2->basetype == INT_TYPE) ||
                    (e1->basetype == INT_TYPE && e2->basetype == DOUBLE_TYPE) ||
                    (e1->basetype == DOUBLE_TYPE && e2->basetype == FLOAT_TYPE) ||
                    (e1->basetype == FLOAT_TYPE && e2->basetype == DOUBLE_TYPE) ||
                    (e1->basetype == DOUBLE_TYPE && e2->basetype == DOUBLE_TYPE)) {
                result->basetype = DOUBLE_TYPE;
            } else {
                fprintf(stderr, "Type error: Unsupported types for '-' operator on line %d.\n", linenum);
                exit(3);
            }
            break;
        
        case MULT:
            if (e1->basetype == INT_TYPE && e2->basetype == INT_TYPE) {
                result->basetype = INT_TYPE;
            } else if ((e1->basetype == FLOAT_TYPE && e2->basetype == INT_TYPE) ||
                    (e1->basetype == INT_TYPE && e2->basetype == FLOAT_TYPE) ||
                    (e1->basetype == FLOAT_TYPE && e2->basetype == FLOAT_TYPE)) {
                result->basetype = FLOAT_TYPE;  
            } else if ((e1->basetype == DOUBLE_TYPE && e2->basetype == INT_TYPE) ||
                    (e1->basetype == INT_TYPE && e2->basetype == DOUBLE_TYPE) ||
                    (e1->basetype == DOUBLE_TYPE && e2->basetype == FLOAT_TYPE) ||
                    (e1->basetype == FLOAT_TYPE && e2->basetype == DOUBLE_TYPE) ||
                    (e1->basetype == DOUBLE_TYPE && e2->basetype == DOUBLE_TYPE)) {
                result->basetype = DOUBLE_TYPE;
            } else {
                fprintf(stderr, "Type error: Unsupported types for '-' operator on line %d.\n", linenum);
                exit(3);
            }
            break;
            
        case DIV: 
            if (e1->basetype == INT_TYPE && e2->basetype == INT_TYPE) {
            result->basetype = INT_TYPE;
            } else if ((e1->basetype == FLOAT_TYPE && e2->basetype == INT_TYPE) ||
                (e1->basetype == INT_TYPE && e2->basetype == FLOAT_TYPE) ||
                (e1->basetype == FLOAT_TYPE && e2->basetype == FLOAT_TYPE)) {
            result->basetype = FLOAT_TYPE;  
            } else if ((e1->basetype == DOUBLE_TYPE && e2->basetype == INT_TYPE) ||
                (e1->basetype == INT_TYPE && e2->basetype == DOUBLE_TYPE) ||
                (e1->basetype == DOUBLE_TYPE && e2->basetype == FLOAT_TYPE) ||
                (e1->basetype == FLOAT_TYPE && e2->basetype == DOUBLE_TYPE) ||
                (e1->basetype == DOUBLE_TYPE && e2->basetype == DOUBLE_TYPE)) {
            result->basetype = DOUBLE_TYPE;
            } else {
            fprintf(stderr, "Type error: Unsupported types for '/' operator on line %d.\n", linenum);
            exit(3);
            }
            break;
        case MOD:
            if (e1->basetype == INT_TYPE && e2->basetype == INT_TYPE) {
            result->basetype = INT_TYPE;
            } else if ((e1->basetype == FLOAT_TYPE && e2->basetype == INT_TYPE) ||
                (e1->basetype == INT_TYPE && e2->basetype == FLOAT_TYPE) ||
                (e1->basetype == FLOAT_TYPE && e2->basetype == FLOAT_TYPE)) {
            result->basetype = FLOAT_TYPE;  
            } else if ((e1->basetype == DOUBLE_TYPE && e2->basetype == INT_TYPE) ||
                (e1->basetype == INT_TYPE && e2->basetype == DOUBLE_TYPE) ||
                (e1->basetype == DOUBLE_TYPE && e2->basetype == FLOAT_TYPE) ||
                (e1->basetype == FLOAT_TYPE && e2->basetype == DOUBLE_TYPE) ||
                (e1->basetype == DOUBLE_TYPE && e2->basetype == DOUBLE_TYPE)) {
            result->basetype = DOUBLE_TYPE;
            } else {
            fprintf(stderr, "Type error: Unsupported types for '%%' operator on line %d.\n", linenum);
            exit(3);
            }
            break;
            
        case ASSIGNMENT:
        if (e1->basetype == e2->basetype ) {
            result->basetype = e1->basetype;
            } else {
            fprintf(stderr, "Assignment type mismatch: actual type is '%s', but '%s' was expected on line %d.\n", get_typename(e2->basetype), get_typename(e1->basetype),linenum);
            exit(1);
            }
            break;  
            case ADD_ASSIGNMENT: case SUB_ASSIGNMENT: case MULT_ASSIGNMENT: case DIV_ASSIGNMENT: case MOD_ASSIGNMENT:
            {
                // determine the result type of the operation part 
                int operation_result_type;
                
                if (e1->basetype == DOUBLE_TYPE || e2->basetype == DOUBLE_TYPE) {
                    operation_result_type = DOUBLE_TYPE;
                } else if (e1->basetype == FLOAT_TYPE || e2->basetype == FLOAT_TYPE) {
                    operation_result_type = FLOAT_TYPE;
                } else if (e1->basetype == LONG_TYPE || e2->basetype == LONG_TYPE) {
                    operation_result_type = LONG_TYPE;
                } else if (e1->basetype == INT_TYPE || e2->basetype == INT_TYPE) {
                    operation_result_type = INT_TYPE;
                } else {
                    operation_result_type = e1->basetype;
                }
                
                // ADD_ASSIGNMENT with strings
                if (operator == ADD_ASSIGNMENT && e1->basetype == STRING_TYPE) {
                    result->basetype = STRING_TYPE;
                    break;
                }
                
                // Check if operation result can be assigned back to lhs
                if (can_assign_to(e1->basetype, operation_result_type)) {
                    result->basetype = e1->basetype;
                } else {
                    fprintf(stderr, "Type mismatch in compound assignment: cannot assign '%s' to '%s' on line %d.\n", 
                    get_typename(operation_result_type), get_typename(e1->basetype), linenum);
                    exit(3);
                }
                break;
            }

            case LE: 
            case GE:
            case CONJ:
            case DISJ:
            case LANGLE:
            case RANGLE:
            case EQEQ:
            case EXCL_EQ:
            case EXCL_EQEQ:
                if (e1->basetype == e2->basetype) {
                    result->basetype = BOOL_TYPE;
                } else if ((e1->basetype == INT_TYPE || e1->basetype == FLOAT_TYPE || e1->basetype == DOUBLE_TYPE) &&
                           (e2->basetype == INT_TYPE || e2->basetype == FLOAT_TYPE || e2->basetype == DOUBLE_TYPE)) {
                    result->basetype = BOOL_TYPE; // Allow numeric comparisons
    
                } else {
                    fprintf(stderr, "Comparison type mismatch: '%s' and '%s' on line %d.\n", get_typename(e1->basetype), get_typename(e2->basetype), linenum);
                    exit(1);
                }
                
                break;
    
            default:
                fprintf(stderr, "Error: Unknown operator on line %d.\n", linenum);
                exit(1);
        }
    
        return result;
    }
void print_symbol_table_entry(SymbolTableEntry entry) {
    if (entry == NULL) {
        printf("SymbolTableEntry is NULL.\n");
        return;
    }

    printf("Symbol: %s\n", entry->s);
    if (entry->type != NULL) {
        printf("Type: %d\n", entry->type->basetype);
    } else {
        printf("Type: NULL\n");
    }
    printf("Mutability: %s\n", entry->mutability ? "mutable" : "immutable");
    printf("Nullability: %s\n", entry->nullable ? "nullable" : "non-nullable");

    if (entry->table != NULL) {
        printf("Sub-scope: %s\n", entry->table->name);
    } else {
        printf("Sub-scope: None\n");
    }
}

struct tree *find_node_by_prodrule(struct tree *t, int prodrule) {
    if (t == NULL) {
        return NULL;
    }

    if (t->prodrule == prodrule) {
        return t;
    }

    for (int i = 0; i < t->nkids; i++) {
        struct tree *result = find_node_by_prodrule(t->kids[i], prodrule);
        if (result != NULL) {
            return result;
        }
    }

    return NULL;
}

struct tree *find_leaf(struct tree *t, int category) {
    if (t == NULL) {
        return NULL;
    }

    if (t->leaf != NULL && t->leaf->category == category) {
        return t;
    }

    for (int i = 0; i < t->nkids; i++) {
        struct tree *result = find_leaf(t->kids[i], category);
        if (result != NULL) {
            return result;
        }
    }

    return NULL;
}

struct typeinfo *find_typeinfo(struct tree *n,bool null){
    struct tree *op = find_leaf(n, 407);
    int array[6] = {385, 392, 383, 384, 386, 391};
    SymbolTableEntry se = NULL;
    struct typeinfo *e = NULL;
    
    if (op != NULL) {
        se = lookup_st(current, op->leaf->text);
        SymbolTable temp = current; // Use a temporary variable
        while (se == NULL && temp != NULL) {
            temp = temp->parent; // Move to the parent scope
            if (temp != NULL) {
            se = lookup_st(temp, op->leaf->text); // Check in the parent scope
            }
        }
        if (se == NULL) {
            fprintf(stderr, "Error: Undefined variable '%s' at line %d\n", op->leaf->text, op->leaf->lineno);
            exit(3);
        }
        if (se->nullable == true && null == false) {
            fprintf(stderr, "Error: Variable '%s' is nullable and cannot be used in this context at line %d\n", op->leaf->text, op->leaf->lineno);
            exit(3);
        }
        e = se->type;
        return e;
    
    } else{
        struct tree *op1 = NULL;
        for (int i = 0; i < 6; i++) {
            op1 = find_leaf(n, array[i]);
            if (op1 != NULL) {
                break; 
            }
        }
        if (op1 != NULL){
            e = get_type(op1->leaf->category);
        }
        return e;
    }
    return NULL;
    
    

}
struct typeinfo* handle_three_children(struct tree *n,bool lhs_null) {
    if( n->nkids == 1 && n->kids[0]->nkids == 3){
        struct typeinfo *result = handle_three_children(n->kids[0],lhs_null); // Recursively handle the first child
        return result; 
    }
    if (n->nkids == 3) {
        struct typeinfo *left_type = NULL;
        struct typeinfo *right_type = NULL; 
        struct typeinfo *result = NULL;

        // Handle left-hand side
        if (n->kids[0]->nkids == 3 && n->kids[0]->kids[1]->leaf != NULL) {
            left_type = handle_three_children(n->kids[0],lhs_null); // Recursively handle left-hand side
        } else {
            left_type = find_typeinfo(n->kids[0],lhs_null); // Handle literals or other types
            // printf("Left type: %d\n", left_type->basetype);
        }
 
        // Handle right-hand side
        if (n->kids[2]->nkids == 3 && n->kids[2]->kids[1]->leaf != NULL) {
            right_type = handle_three_children(n->kids[2],lhs_null); // Recursively handle right-hand side
        } else if (n->kids[2]->kids[0] != NULL && find_node_by_prodrule(n->kids[2],1068) != NULL) {
            // printf("inside handle right hand\n");
            // Handle function call case
            struct tree *function_node = find_node_by_prodrule(n->kids[2],1068);
            char *function_name = function_node->kids[0]->leaf->text;
            SymbolTableEntry function_entry = lookup_st(current, function_name);
            SymbolTable temp = current;

            while (function_entry == NULL && temp != NULL) {
                temp = temp->parent;
                if (temp != NULL) {
                    function_entry = lookup_st(temp, function_name);
                }
            }
            if (lookup_st(predefined, function_name)) {
                printf("found predefined function\n");
            }else if (function_entry == NULL) {
            fprintf(stderr, "Error: Undefined function '%s' at line %d\n", function_name, function_node->kids[0]->leaf->lineno);
            exit(3);
            }

            if (function_entry->type == NULL || function_entry->type->basetype != FUNC_TYPE) {
            fprintf(stderr, "Error: '%s' is not a function at line %d\n", function_name, function_node->kids[0]->leaf->lineno);
            exit(3);
            }

            right_type = function_entry->type->u.f.returntype;
        } else {
            right_type = find_typeinfo(n->kids[2],lhs_null); // Handle literals or other types  
        }

        // Check types and determine the result type
        if (left_type && right_type) {
            // printf("Both left_type and right_type are present.\n");
            result = check_types(n->kids[1]->leaf->category, left_type, right_type,n->kids[1]->leaf->lineno);
        } else if (left_type) {
            // printf("Only left_type is present.\n");
            result = check_types(n->kids[1]->leaf->category, left_type, NULL,n->kids[1]->leaf->lineno);
        } else if (right_type) {
            // printf("Only right_type is present.\n");
            result = check_types(n->kids[1]->leaf->category, NULL, right_type,n->kids[1]->leaf->lineno);
        } 
        // printf("Result type: %d\n", result->basetype);
        return result;
        
    }
    return NULL;

}

// Helper function to create a param from an expression node
struct param *mk_param(struct tree *expr_node) {
    if (!expr_node) return NULL;
    
    // The expression node should have prodrule 1086 and 1 kid (disjunction)
    if (expr_node->prodrule == 1086 && expr_node->nkids == 1) {
        struct tree *node = find_node_by_prodrule(expr_node->kids[0], 1052);
        // Continue walking down the expression tree if needed
        // For simplicity, we'll assume we can get the type directly from the expression
        
        struct param *argument = malloc(sizeof(struct param));
        if (!argument) {
            fprintf(stderr, "Memory allocation failed for argument.\n");
            return NULL;
        }

        argument->name = NULL;  // Arguments don't have names
        argument->type = find_typeinfo(node->kids[0],NULL);  // You might need to adjust this
        argument->next = NULL;

        return argument;
    }
    
    return NULL;
}
struct param *mk_functionArguments(struct tree *n) {
    if (!n) return NULL;

    // Case: functionArguments COMMA expression (recursive case)
    if (n->prodrule == 1070 && n->nkids == 3) {
        struct param *p1 = mk_functionArguments(n->kids[0]);  // Process previous arguments
        struct param *p2 = mk_param(n->kids[2]);             // Process new argument

        if (!p1) return p2;  // If no previous arguments, return the new one
        if (!p2) return p1;   // If no new argument, return previous ones

        // Link the new argument to the end of the list
        struct param *temp = p1;
        while (temp->next != NULL) temp = temp->next;
        temp->next = p2;

        return p1;
    }

    // Case: single expression (base case)
    if (n->prodrule == 1069 && n->nkids == 1) {
        return mk_param(n->kids[0]);  // Process the single expression
    }

    return NULL;
}

 
void typecheck(struct tree *n) {
    if (n == NULL) return;
    struct tree *lhs = NULL;
    struct tree *rhs = NULL; // Assuming the right-hand side is the second child
    struct typeinfo *lhs_type = NULL;
    struct typeinfo *rhs_type = NULL;
    struct typeinfo *comparison = NULL;
    
    struct typeinfo *equality = NULL;
    bool nullable_left = false; 
    

    // Perform type checking based on production rules
    switch (n->prodrule) { 
        int i;
        
        case 1090: 
            if (n->nkids == 3){ 
                printf("comparison \n");
                comparison = handle_three_children(n,nullable_left);
                if (comparison != NULL){
                printf("comparison print: %d\n",comparison->basetype);
                }
            }
            break;

        case 1089:
            if (n->nkids == 3 ){ 
                    printf("equality \n");
                    equality = handle_three_children(n,nullable_left);
                    if (equality != NULL){
                    printf("equality print: %d\n",equality->basetype);
                    }
                }
                break;
        case 1004: /* rule for functions for pushing the scope*/
            for (i = 0; i < n->nkids; i++) {
                if (n->kids[i] != NULL && n->kids[i]->leaf != NULL && n->kids[i]->leaf->category == 407) {
            char *function_name = n->kids[i]->leaf->text; 
            SymbolTable name = find_table(function_name); 
            pushscope(name); 
            break;
                }
            }
            break;

            case 1043:  // Assignment: directly_assign expression 
            if (n->kids[0] != NULL && n->kids[1] != NULL) {
                // printf("From typecheck lhs:\n------------------\n");

                lhs = find_leaf(n->kids[0], 407); // Find the leaf node with category variable
                SymbolTableEntry se = lookup_st(current, lhs->leaf->text);

                SymbolTable temp = current; // Use a temporary variable
                while (se == NULL && temp != NULL) {
                    temp = temp->parent; // Move to the parent scope
                    if (temp != NULL) {
                        se = lookup_st(temp, lhs->leaf->text); // Check in the parent scope
                         
                    }
                } 
                if (se == NULL) {
                    fprintf(stderr, "Error: Undeclared variable '%s' at line %d\n", lhs->leaf->text, lhs->leaf->lineno);
                    exit(3);
                }
                
                rhs = n->kids[1]; // Assuming the right-hand side is the second child
                struct tree *value = NULL;


                lhs_type = se->type; 
                if (se->nullable == true) {
                    nullable_left = true;
                }               

                // Walk through the rhs child to find cases with three children
                struct tree *current_node = rhs;
                struct typeinfo *expressions =NULL;
                while (current_node != NULL) {
                    if (current_node->nkids == 3) {
                        // printf("Found a node with three children.\n");
                        expressions = handle_three_children(current_node,nullable_left);
                        if (expressions != NULL) {
                            // printf("Result type from three children: %d\n", expressions->basetype);
                        }
                        break;
                    }
                    current_node = current_node->kids[0]; // Traverse to the next child
                } 
                if (expressions){
                    rhs_type= expressions;
                    // printf("lhs_type:%d\n---------------------\n", lhs_type->basetype);
                    // printf("rhs_type:%d\n---------------------\n", rhs_type->basetype);
                    if (lhs_type->basetype != rhs_type->basetype ){
                    fprintf(stderr, "Error: Type miss match '%s' at line %d\n", lhs->leaf->text, lhs->leaf->lineno);
                    exit(3);
                    }
                    
                }else {
                    struct token *operator = n->kids[0]->kids[1]->leaf;
                    SymbolTableEntry se2 = NULL;
                    // printf("From typecheck rhs:\n------------------\n");
                    int array[7] = {385, 392, 383, 384, 386, 391, 407};
                    for (int i = 0; i < 7; i++) {
                        value = find_leaf(n, array[i]);
                        if (value != NULL) {
                            if (array[i] == 407){
                                se2 = lookup_st(current, value->leaf->text);
                                rhs_type = se2->type;
                            }else {
                                printf("value->leaf->category: %d\n", value->leaf->category);
                                rhs_type = get_type(value->leaf->category);
                            }
                            break; 
                        }
                } 
                if (lhs_type == NULL && rhs_type != NULL) {
                    if(find_node_by_prodrule(n->kids[0], 1059) != NULL){
                        lhs = find_leaf(n->kids[0], 407); 
                        printnode(lhs);
                        insert_type(current, lhs->leaf->text, assignType("Int"));
                        //printf("array is here\n");
                    }
                }else{
                    check_types(operator->category, lhs_type, rhs_type,operator->lineno); // Check types for assignment
                }
                }}
            break;


        //case 1029:

        
        case 1028: /* rule for property declaration*/
        struct tree *c; 
        struct tree *b; 
        struct tree *type_lit = NULL;
        struct typeinfo *type_specifier = NULL;
        struct typeinfo *symbol_type = NULL;

        /* get type specifier */
        if (n->kids[3] != NULL) { /* multivariable_variableDeclaration */
            c = n->kids[3];
            if (c->kids[0] != NULL){
                c = c->kids[0];
                
                if(c->nkids == 3 && c->kids[2] != NULL){ 
                    type_lit = find_leaf(c->kids[2], 400);
                    type_specifier = assignType(type_lit->leaf->text);
                    // printf("Type specifier: %s\n", type_lit->leaf->text);
                    // printnode(type_lit);
                }
            }

            if (n->kids[4] != NULL && c->nkids == 3) { 
                b = n->kids[4]; //opt_eq_exp 
                if (b->kids[1] != NULL) { /* at the rule for expression */
                    b = b->kids[1];
                    while (b->kids[0] != NULL) { /* traverse down to the actual value */
                        b = b->kids[0];
                        if (b->nkids == 3){
                            symbol_type = handle_three_children(b,nullable_left);
                            // printf("symbol type: %s \n",get_typename(symbol_type->basetype));
                            break;
                        }
                        if (b->leaf != NULL) { /* found value */
                            if (b->leaf->category == 407) {
                                SymbolTableEntry se_var = lookup_st(current, b->leaf->text);
                                symbol_type = se_var->type;
                            } else {
                                symbol_type = get_type(b->leaf->category);
                            }
                        }
                    }
                }
            }

            // Ensure the rhs type matches the lhs type
            if (type_specifier != NULL && symbol_type != NULL) {
                if (type_specifier->basetype != symbol_type->basetype) {
                    fprintf(stderr, "Initializer type mismatch: expected '%s', actual '%s'\n", 
                            get_typename(type_specifier->basetype), get_typename(symbol_type->basetype));
                    exit(3);
                }
            }
        } 


        break;

        case 1094:
        struct typeinfo *result = handle_three_children(n,nullable_left); // Handle the three children case
        if (result != NULL) {
            // printf("Final Result type: %d\n", result->basetype); 
        }

        break;

        case 1052:

        if (n->kids[0]->kids[0] != NULL && n->kids[0]->kids[0]->prodrule == 1068) {
            // printf("Now in funcall\n");
            struct tree *function_node = n->kids[0]->kids[0]; //where the functioncall node is at
            struct tree *function_name_node = n->kids[0]->kids[0]->kids[0]; //first child have function_name
            char *function_name = function_name_node->leaf->text;
            SymbolTableEntry function_entry = NULL;
            SymbolTable temp = current; // Use a temporary variable in case it doesn't exist in current scope

                while (function_entry == NULL && temp->parent != NULL) {
                    temp = temp->parent; // Move to the parent scope
                    if (temp != NULL) {
                        function_entry = lookup_st(temp, function_name); // Check in the parent scope
                    }
                }
                if (lookup_st(predefined, function_name)) {
                    function_entry = lookup_st(predefined, function_name);
                    break;// temp fix for function_name in predefined so it doesn't check
                }

                if (function_entry == NULL) {
                    fprintf(stderr, "Error: Undefined function '%s' at line %d\n", function_name, function_name_node->leaf->lineno);
                    exit(3);
                }

                if (function_entry->type == NULL || function_entry->type->basetype != FUNC_TYPE) {
                    fprintf(stderr, "Error: '%s' is not a function at line %d\n", function_name, function_name_node->leaf->lineno);
                    exit(3);
                }
            
                if (function_entry) {
                    // printf("Function entry exists with type: %d\n", function_entry->type->basetype);
                    struct param *param = function_entry->type->u.f.parameters;
                    while (param != NULL) {
                        // printf("Parameter name: %s, type: %d\n", param->name, param->type->basetype);
                        param = param->next;
                    }
                }

            // Check function parameters
            struct param *expected_params = function_entry->type->u.f.parameters;
            struct tree *actual_params_node = function_node->kids[2]; // Assuming the actual parameters are the third child
            struct param *actual_params = mk_functionArguments(actual_params_node);

            while (expected_params != NULL && actual_params != NULL) {
                if (expected_params->type->basetype != actual_params->type->basetype) {
                fprintf(stderr, "Error: Parameter type mismatch in function '%s' at line %d\n", function_name, function_name_node->leaf->lineno);
                exit(3);
                }
                expected_params = expected_params->next;
                actual_params = actual_params->next;
            } 



            if (expected_params != NULL || actual_params != NULL) {
                fprintf(stderr, "Error: Parameter count mismatch in function '%s' at line %d\n", function_name, function_name_node->leaf->lineno);
                exit(3);
            }
            
            }
        
        
        if(n->kids[0]->kids[0] != NULL && n->kids[1] != NULL){
            //ste = lookup_st(current, n->kids[0]->kids[0]->leaf->text);
            //printnode(n->kids[0]->kids[0]); 
            struct token *val = n->kids[0]->kids[0]->leaf; 
            SymbolTableEntry se3 = NULL;
            struct typeinfo *post_type = NULL;

            if (val != NULL && val->category == 407) {
                se3 = lookup_st(current, val->text);
                post_type = se3->type;
                
                if(post_type->basetype == BOOL_TYPE || post_type->basetype == STRING_TYPE || post_type->basetype == ARRAY_TYPE){
                    fprintf(stderr, "Type error: Unsupported types for '%s' operator.\n", n->kids[1]->kids[1]->kids[0]->leaf->text);
                    exit(3);
                }
            }
        }else if(n->kids[0] != NULL && n->kids[1] != NULL){
            //printnode(n->kids[0]); 
            fprintf(stderr, "Error: Variable expected at line %d\n", n->kids[0]->leaf->lineno);
            exit(3);

        }
        break;
        }
        
        // Recursively typecheck all children
        for (int i = 0; i < n->nkids; i++) typecheck(n->kids[i]);   

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
void assign_first(struct tree *t);
void assign_follow(struct tree *t);
void assign_onTrue_onFalse(struct tree *t);
void print_tree_flags(struct tree *t) {
    if (t == NULL) {
        return;
    }

    if (t->first || t->follow || t->onTrue || t->onFalse) {
        printf("Tree Node Flags:\n");
        printf("\tNode ID: %d\n", t->id);
        printf("\tProduction Rule: %d\n", t->prodrule);
        printf("\tNumber of Children: %d\n", t->nkids);

        if (t->symbolname != NULL) {
            printf("\tSymbol Name: %s\n", t->symbolname);
        } else {
            printf("\tSymbol Name: NULL\n");
        }

        if (t->leaf != NULL) {
            printf("\tLeaf Node Information:\n");
            printf("\t\tCategory: %d\n", t->leaf->category);
            printf("\t\tText: %s\n", t->leaf->text ? t->leaf->text : "NULL");
            printf("\t\tLine Number: %d\n", t->leaf->lineno);
            printf("\t\tFilename: %s\n", t->leaf->filename ? t->leaf->filename : "NULL");
        } else {
            printf("\tLeaf Node: NULL\n");
        }

        if (t->first) {
            printf("\tFirst: %p\n", (void *)t->first);
        }
        if (t->follow) {
            printf("\tFollow: %p\n", (void *)t->follow);
        }
        if (t->onTrue) {
            printf("\tOnTrue: %p\n", (void *)t->onTrue);
        }
        if (t->onFalse) {
            printf("\tOnFalse: %p\n", (void *)t->onFalse);
        }
    }

    for (int i = 0; i < t->nkids; i++) {
        print_tree_flags(t->kids[i]);
    }
}

//iterate through symbol table and assign each address 
void assign_addresses_in_scope(SymbolTable st){
    int i;
    SymbolTableEntry ste;
    if (st == NULL) return;
    printf("In Symbol table for: %s\n", st->name);
    // Iterate over each bucket
    for (i = 0; i < st->nBuckets; i++) {
        for (ste = st->tbl[i]; ste != NULL; ste = ste->next) {   
            
            if (ste->address == NULL) {
                ste->address = genvar(R_LOCAL);
        
            
        }
    }
    
}
}
struct string_table string_tbl;

//write some tree traveral similar to populate_symbol table 
//before entering any scope, set all regions for nodes to R_GLOBAL 
//When we see a function, reset local offset 
//set each address so set a.region = R_LOCAL and a.u.offset = to whatever 
// if constant value is encountered like 10 + 2, get the text, and set a.u.offset = t->??->leaf->text
void assign_address(struct tree *t)
{
    int i;
    SymbolTable temp;
    if (t == NULL) return;
    /* pre-order activity */
    switch (t->prodrule) {  
        case 1004: /* rule for functions */
        local_offset = 0;
        for (i = 0; i < t->nkids; i++) {
            if (t->kids[i] != NULL && t->kids[i]->leaf != NULL && t->kids[i]->leaf->category == 407) {
           char *function_name = t->kids[i]->leaf->text;
           SymbolTable name = find_table(function_name);
           pushscope(name); 
           assign_addresses_in_scope(current);
           struct addr *a = malloc(sizeof(struct addr));
           if (!a) {
               fprintf(stderr, "Memory allocation failed\n");
               exit(1);
           }
           a->region = R_NAME;
           a->u.name = function_name;
           t->address = a;
           //printf("We allocated: %s\n", t->address->u.name);
           //printnode(t);

           //printf("table:%s\n",current->name);
           break;
            }
        }
        break; 
        
        
            
        
        
        case 1086:
        if (t->kids[0]->address!= NULL) {
            t->address = t->kids[0]->address;  // Assign the address from the child
        }  
        break;
        case 1087:
        case 1088: 
        case 1089: //equality    
        case 1090: //multiplication
        case 1091: //division
        case 1092: //modulus
        case 1093: //exponentiation
        case 1094: //addition  
        case 1095: //subtraction
        if(t->nkids == 3){
            if (t->address == NULL) 
                t->address = genvar(R_LOCAL);  // Generate a local address for the current node
            SymbolTableEntry se1 = NULL;
            SymbolTableEntry se2 = NULL;
            struct tree *value = NULL;
            struct tree *value2 = NULL;

            // printnode(t->kids[0]);  // Print the node for debugging
            printnode(find_leaf(t->kids[0], 407));  // Find a leaf node with category 407 in the left child

            int array[7] = {385, 392, 383, 384, 386, 391, 407};  // Array of categories to check
            // First, handle the left child (value)
            for (int i = 0; i < 7; i++) {
                value = find_leaf(t->kids[0], array[i]);  // Find a matching leaf in the left child
                if (value != NULL) {
                    if (array[i] == 407) {  // If it's a variable
                        se1 = lookup_st(current, value->leaf->text);  // Lookup the symbol table entry
                        t->kids[0]->address = se1->address;  // Assign the address from the symbol table
                    } else if (array[i] == INTEGER_LITERAL || array[i] == BOOLEAN_LITERAL || 
                               array[i] == UNSIGNED_LITERAL || array[i] == LONG_LITERAL || 
                               array[i] == HEX_LITERAL || array[i] == BIN_LITERAL) {  // If it's a constant
                        t->kids[0]->address = genvar(R_CONST);  // Generate a constant address
                        t->kids[0]->address->u.offset = atoi(value->leaf->text);  // Set the offset to the constant value
                    } else if (array[i] == FLOAT_LITERAL || array[i] == DOUBLE_LITERAL || array[i] == REAL_LITERAL) {
                        t->kids[0]->address = genvar(R_FLOAT);
                        t->kids[0]->address->u.dval = value->leaf->dval; // Convert text to double
                    }
                    break; // Stop after the first match
                }
            }

            // Then, handle the right child (value2)
            for (int i = 0; i < 7; i++) {
                value2 = find_leaf(t->kids[2], array[i]);  // Find a matching leaf in the right child
                if (value2 != NULL) {
                    if (array[i] == 407) {  // If it's a variable
                        se2 = lookup_st(current, value2->leaf->text);  // Lookup the symbol table entry
                        t->kids[2]->address = se2->address;  // Assign the address from the symbol table
                    } else if (array[i] == INTEGER_LITERAL || array[i] == BOOLEAN_LITERAL || 
                               array[i] == UNSIGNED_LITERAL || array[i] == LONG_LITERAL || 
                               array[i] == HEX_LITERAL || array[i] == BIN_LITERAL) {  // If it's a constant
                        t->kids[2]->address = genvar(R_CONST);  // Generate a constant address
                        t->kids[2]->address->u.offset = atoi(value2->leaf->text);  // Set the offset to the constant value
                    } else if (array[i] == FLOAT_LITERAL || array[i] == DOUBLE_LITERAL || array[i] == REAL_LITERAL) {
                        t->kids[2]->address = genvar(R_FLOAT);
                        t->kids[2]->address->u.dval = value2->leaf->dval; // Convert text to double
                    } 
                    break; // Stop after the first match
                }
            }
            value = find_leaf(t->kids[0], 392);
            value2 = find_leaf(t->kids[2], 392);
            if(value && value2){
               // printf("STRING CONCATENATION DETECTED\n");
               t->kids[1]->address = genvar(R_STRING);
               t->kids[2]->address = genvar(R_STRING);
               t->kids[0]->address = genvar(R_STRING);
               char *function_name = "strcat";
               //function name
               struct addr *a = malloc(sizeof(struct addr));
               if (!a) {
                   fprintf(stderr, "Memory allocation failed\n");
                   exit(1);
               }
               a->region = R_NAME;
               a->u.name = function_name;
               t->kids[1]->address = a;
               //t->address = genvar(R_LOCAL); 
            }
        }

        break;
        case 392: /* String literal */
            printf("String literal: %s\n", t->leaf->text);
            addString(&string_tbl, descape(t->leaf->text)); // Add the string to the string table
            //t->address = genvar(R_CONST); // Generate a constant address for the string literal
        break; 
        
        }

        
    for (i = 0; i < t->nkids; i++) {
        assign_address(t->kids[i]);
    }
    /* Post-order activity */
    switch (t->prodrule) {
        case 1086: case 1087: case 1088: case 1089: /* Binary operations */
        case 1090: case 1091: case 1092: case 1093: 
        case 1094: case 1095: 
        if (t->nkids == 1) {
            // Synthesize the address from the child
            if (t->kids[0]->address && t->address == NULL) {
            t->address = t->kids[0]->address;

            }
        } else if (t->nkids == 3) {
            // Assign a new R_LOCAL address
            printf("%s have three children, and id of %d, local_offset = %d\n", t->symbolname, t->id, local_offset);
            if (!t->address) t->address = genvar(R_LOCAL);

            SymbolTableEntry se1 = NULL;
            SymbolTableEntry se2 = NULL;
            struct tree *value = NULL;
            struct tree *value2 = NULL;

            if (find_node_by_prodrule(t->kids[0],1066)){
                struct tree *parenthesis = find_node_by_prodrule(t->kids[0],1066);
                t->kids[0]->address = parenthesis->kids[1]->address; // Assign the address from the child
                assign_address(t->kids[0]);
            }
            if(t->kids[0]->address != NULL)
                break; // If the left child already has an address, skip further processing
            int array[7] = { 407,385, 392, 383, 384, 386, 391};  // Array of categories to check
            // First, handle the left child (value)
            for (int i = 0; i < 7; i++) {
                value = find_leaf(t->kids[0], array[i]);  // Find a matching leaf in the left child
                if (value != NULL) {
                    if (array[i] == 407) {  // If it's a variable
                        se1 = lookup_st(current, value->leaf->text);  // Lookup the symbol table entry
                        value->address = se1->address;  // Assign the address from the symbol table
                        if (!t->kids[0]->address) {  // Check if address already exists
                            t->kids[0]->address = se1->address;  // Assign the address from the symbol table
                        }
                    } else {  // If it's a constant
                        if (!t->kids[0]->address) {  // Check if address already exists
                            t->kids[0]->address = genvar(R_CONST);  // Generate a constant address
                            t->kids[0]->address->u.offset = atoi(value->leaf->text);  // Set the offset to the constant value
                        }
                    }
                    break; // Stop after the first match
                }
            }
            if (find_node_by_prodrule(t->kids[2],1066)){
                struct tree *parenthesis = find_node_by_prodrule(t->kids[2],1066);
                t->kids[2]->address = parenthesis->kids[1]->address; // Assign the address from the child
                assign_address(t->kids[2]);
            }
            if (t->kids[2]->address != NULL)
                break;            
            // Then, handle the right child (value2)
            for (int i = 0; i < 7; i++) {
                value2 = find_leaf(t->kids[2], array[i]);  // Find a matching leaf in the right child
                if (value2 != NULL) {
                    if (array[i] == 407) {  // If it's a variable
                        se2 = lookup_st(current, value2->leaf->text);  // Lookup the symbol table entry
                        value2->address = se2->address;  // Assign the address from the symbol table
                        if (!t->kids[2]->address) {  // Check if address already exists
                            t->kids[2]->address = se2->address;  // Assign the address from the symbol table
                        }
                    } else {  // If it's a constant
                        if (!t->kids[2]->address) {  // Check if address already exists
                            t->kids[2]->address = genvar(R_CONST);  // Generate a constant address
                            t->kids[2]->address->u.offset = atoi(value2->leaf->text);  // Set the offset to the constant value
                        }
                    } 
                    break; // Stop after the first match
                }
            }
        }
        break; 

        case 1043: /* Assignment */
            if (t->kids[0]->kids[0]->kids[0] != NULL && t->kids[0]->kids[0]->kids[0]->leaf != NULL) {
                struct token *var_token = t->kids[0]->kids[0]->kids[0]->leaf;
                if (var_token->category == 407) { // Check if it's a variable
                    SymbolTableEntry ste = lookup_st(current, var_token->text);
                    if (ste != NULL) {
                        
                        // t->kids[0]->kids[0]->address = ste->address; // Create a new address for the variable
                        t->kids[0]->kids[0]->kids[0]->address = ste->address; // Assign a local address
                        t->kids[0]->address = ste->address; // Assign the address from the symbol table entry
                    } else {
                        fprintf(stderr, "Error: Variable '%s' not found in symbol table.\n", var_token->text);
                        exit(3);
                    }
                }
                if (t->kids[1] != NULL && t->kids[1]->address == NULL) {
                    
                    struct tree *value = NULL;
                    int array[7] = {385, 392, 383, 384, 386, 391, 407};
                    for (int i = 0; i < 7; i++) {
                        value = find_leaf(t->kids[1], array[i]);
                        if (value != NULL) {
                            if (array[i] == 407) {
                                SymbolTableEntry ste = lookup_st(current, value->leaf->text);
                                t->kids[1]->address = ste->address;
                            } else if(value->leaf->category == 392) {
                                    t->kids[1]->address = genvar(R_STRING);
                            } else {
                                    t->kids[1]->address = genvar(R_CONST);
                                    t->kids[1]->address->u.offset = atoi(value->leaf->text);
                                }
                            
                            break;
                        }
                    }
                }
                if (find_node_by_prodrule(t->kids[0], 1059) != NULL) {
                    t->kids[0]->kids[0]->kids[0]->address->region = R_LOCAL; 
                    t->kids[0]->kids[0]->kids[0]->address->u.offset = 8;

                    t->kids[0]->kids[0]->address->region = R_CONST; 
                    t->kids[0]->kids[0]->address->u.offset = 8;

                    t->kids[0]->address->region = R_LOCAL; 
                    t->kids[0]->address->u.offset = 16;


                }

            }
            break; 
            case 2000: //array declaration
            if (t->address == NULL) {
                t->address = genvar(R_LOCAL);  // Generate a local address for the current node
                printf("Assigning address for node with addr %d\n", t->address->u.offset);
                t->kids[1]->address = genvar(R_CONST); 
                t->kids[1]->address->u.offset = t->kids[2]->leaf->ival * 8; // Assign the integer value to the offset
                struct addr *a = malloc(sizeof(struct addr));
                if (!a) {
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(1);
                }
                a->region = R_NAME;
                a->u.name = "malloc";
                t->kids[0]->address = a;
                t->kids[5]->address = genvar(R_CONST); 
                t->kids[5]->address->u.offset = t->kids[5]->leaf->ival;


            }
            break; 

            case 1028: { /* Property declaration (variables) */
                printf("here\n");
                //printnode(t->kids[3]);
                //check if its an array first 
                struct tree *var_decl = t->kids[3]; // multivariable_variableDeclaration
                if (var_decl->kids[0]->kids[2] != NULL){
                    //printnode(var_decl->kids[0]->kids[2]);
                    if (find_node_by_prodrule(t->kids[3],2001)){
                        struct tree *arraytype= find_node_by_prodrule(t->kids[3],2001);
                        printnode(arraytype);
                        //t->kids[3]->address = parenthesis->kids[1]->address; // Assign the address from the child
                        //assign_address(t->kids[2]);
                    }
                }
                if (var_decl->prodrule == 1035) { // multiVariableDeclaration
                    // Handle multiple variables
                    struct tree *var_list = var_decl;
                    while (var_list) {
                        if (var_list->kids[1]->leaf && var_list->kids[1]->leaf->category == 407) {
                            var_list->kids[1]->address = genvar(R_LOCAL);
                            printf("here: %s\n", var_list->kids[1]->leaf->text);
                            // Store in symbol table
                            SymbolTableEntry ste = lookup_st(current, var_list->kids[1]->leaf->text);
                            if (ste) {
                                ste->address = var_list->kids[1]->address;
                            }
                        }
                        var_list = var_list->kids[2]; // multi_comma_variableDeclaration
                    }
                }else{
                    if (t->kids[3] != NULL) { /* multivariable_variableDeclaration */
                        struct tree *c;
                        c = find_leaf(t->kids[3], 407);
    
                        //while (c != NULL && c->prodrule != 407) {
                        //    c = c->kids[0]; /* get and store the symbols name*/
                        //}
    
                        //printf("WHATTTT %s", c->leaf->text);
                        SymbolTableEntry ste = lookup_st(current, c->leaf->text);
                        t->kids[3]->address = ste->address;
                        //printnode(c);
                    }
                }
                //assign right hand side if it exists
                //printf("\nHERE:\n");
                //printnode(t);
                if (t->kids[4] != NULL && t->kids[4]->prodrule == 1026) {
                    if (t->kids[4]->kids[1]->address == NULL) { 
                    struct tree *value = NULL;
                    int array1[7] = {385, 392, 383, 384, 386, 391};
                    for (int i = 0; i < 7; i++) {
                        value = find_leaf(t->kids[4]->kids[1], array1[i]);
                        if (value != NULL) {
                            if(value->leaf->category == 392) {
                                t->kids[4]->kids[1]->address = genvar(R_STRING);
                            } else if (value->address != NULL) {
                                t->kids[4]->kids[1]->address = value->address; // Use existing address
                            // } else if (array1[i] == 407) {  // If it's a variable
                            //     SymbolTableEntry se1 = lookup_st(current, value->leaf->text);  // Lookup the symbol table entry
                            //     t->kids[4]->kids[1]->address = se1->address;  // Assign the address from the symbol table
                            } else if (array1[i] == INTEGER_LITERAL || array1[i] == BOOLEAN_LITERAL || 
                                       array1[i] == UNSIGNED_LITERAL || array1[i] == LONG_LITERAL || 
                                       array1[i] == HEX_LITERAL || array1[i] == BIN_LITERAL) {  // If it's a constant
                                t->kids[4]->kids[1]->address = genvar(R_CONST);  // Generate a constant address
                                t->kids[4]->kids[1]->address->u.offset = atoi(value->leaf->text);  // Set the offset to the constant value
                            } else if (array1[i] == FLOAT_LITERAL || array1[i] == DOUBLE_LITERAL || array1[i] == REAL_LITERAL) {
                                t->kids[4]->kids[1]->address = genvar(R_FLOAT);
                                t->kids[4]->kids[1]->address->u.dval = value->leaf->dval; // Convert text to double
                            }
                        }
                    }
                }}
                break;
            }
    
            break;

            case 1068: // Function call
            char *function_name = t->kids[0]->leaf->text;
            //function name
            struct addr *a = malloc(sizeof(struct addr));
            if (!a) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            a->region = R_NAME;
            a->u.name = function_name;
            t->kids[0]->address = a;
            t->address = genvar(R_LOCAL); 
            
            struct tree *val = NULL;
            int nparams = 0; 
            if(t->kids[2] != NULL) { // chech parameters
                nparams = 1; 
                int array[7] = { 407,385, 392, 383, 384, 386, 391};  // Array of categories to check
                for (int i = 0; i < 7; i++) {
                    val = find_leaf(t->kids[2], array[i]);
                    if (val != NULL) {
                    if(val->leaf->category == 392) {
                        t->kids[2]->address = genvar(R_STRING);

                    // } else if (val->leaf->category == 407) {
                    //     SymbolTableEntry se = lookup_st(current, val->leaf->text);  // Lookup the symbol table entry
                    //     t->kids[2]->address = se->address;  // Assign the address from the symbol table
                    } else if (t->kids[2]->kids[0]->address != NULL) {
                        t->kids[2]->address = t->kids[2]->kids[0]->address; // adress if expression
                        //t->kids[2]->address->u.offset = atoi(value->leaf->text);
                    }
                }
                        
                }
            }
            if(t->kids[2] != NULL) {
            struct addr *a = malloc(sizeof(struct addr));
            if (!a) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
            a->region = R_PARAM;
            a->u.offset = nparams;
            t->kids[1]->address = a;
            }
            break; 
        // case 1043: /* Assignment */
        //     if (t->kids[0]->address) {
        //         /* Propagate LHS address to RHS */
        //         t->address = t->kids[0]->address;
        //         if (!t->kids[1]->address) {
        //             t->kids[1]->address = t->address;
        //         }
        //     }
        //     break;
        case 407:
            SymbolTableEntry se = lookup_st(current, t->leaf->text);
            if (se != NULL) {
                t->address = se->address; // Assign the address from the symbol table entry
            } 

            break;
        // Handle all literal cases for assignment of address and offset
        case INTEGER_LITERAL:
        case BOOLEAN_LITERAL:
        case UNSIGNED_LITERAL:
        case LONG_LITERAL:
        case HEX_LITERAL:
        case BIN_LITERAL:
            if (t->leaf != NULL) {
            t->address = genvar(R_CONST);
            t->address->u.offset = t->leaf->ival; // Assign the integer value to the offset
            } else {
                fprintf(stderr, "Error: Leaf node is NULL for INTEGER_LITERAL\n");
                exit(3);
            }
            break;
        case FLOAT_LITERAL:
        case DOUBLE_LITERAL:
        case REAL_LITERAL:
            if (t->leaf != NULL) {
            t->address = genvar(R_FLOAT);
            t->address->u.dval = t->leaf->dval;
            }
            break;
        // case STRING_LITERAL:
        //     if (t->leaf != NULL) {
        //     t->address = genvar(R_STRING);
        //     // Optionally, add to string table here if needed
        //     }
        //     break;
            
        case 1004: /* End function scope */
            if (current) popscope();
            break;
        default:
            // Post-order: if this node doesn't have an address, but one of its children does, assign it
            for (int i = 0; i < t->nkids; i++) {
                if (t->address == NULL && t->kids[i] && t->kids[i]->address) {
                    t->address = t->kids[i]->address;
                    break;
                }
            }
            break;
    }
}
void print_tree_with_icode(struct tree *t, int depth) {
    if (t == NULL) return;

    // Indent based on depth
    printf("%*s", depth * 2, " ");

    // Print the current node's information
    if (t->symbolname) {
        printf("%s", t->symbolname);
    } else if (t->leaf) {
        printf("%s (%d)", t->leaf->text ? t->leaf->text : "NULL", t->leaf->category);
    } else {
        printf("Internal Node");
    }

    printf(" [ID: %d]", t->id);

    // Print the intermediate code (icode) if available
    if (t->icode) {
        printf(" [ICODE: ");
        print_icode(t->icode); // Use printcode to print the intermediate code
        printf("]");
    }
    printf("\n");

    // Recursively print child nodes
    for (int i = 0; i < t->nkids; i++) {
        print_tree_with_icode(t->kids[i], depth + 1);
    }
}
void print_tree_with_addresses(struct tree *t, int depth) {
    if (t == NULL) return;

    // Indent based on depth
    printf("%*s", depth * 2, " ");

    // Print the current node's information
    if (t->symbolname) {
        printf("%s", t->symbolname);
    } else if (t->leaf) {
        printf("%s (%d)", t->leaf->text ? t->leaf->text : "NULL", t->leaf->category);
    } else {
        printf("Internal Node");
    }
    
    printf(" [ID: %d]", t->id);

    // Print the address information if available
    if (t->address) {
        printf(" [Region: %s, ",
            t->address->region == R_LOCAL ? "Local" :
            t->address->region == R_GLOBAL ? "Global" :
            t->address->region == R_CONST ? "Constant" :
            t->address->region == R_FLOAT ? "Float" : "Unknown");

        if (t->address->region == R_FLOAT) {
            printf("Value: %f", t->address->u.dval);
        } else {
            printf("Offset: %d", t->address->u.offset);
        }

        printf("]");
        printf("[Name: %s]", t->address->region == R_NAME ? "name" : "unknown");
    }
    printf("\n");

    // Recursively print child nodes
    for (int i = 0; i < t->nkids; i++) {
        print_tree_with_addresses(t->kids[i], depth + 1);
    }
} 
void print_tree_with_onTrue_onFalse(struct tree *t, int depth) {
    if (t == NULL) return;

    // Indent based on depth
    printf("%*s", depth * 2, " ");

    // Print the current node's information
    if (t->symbolname) {
        printf("%s", t->symbolname);
    } else if (t->leaf) {
        printf("%s (%d)", t->leaf->text ? t->leaf->text : "NULL", t->leaf->category);
    } else {
        printf("Internal Node");
    }

    printf(" [ID: %d]", t->id);

    // Print the onTrue and onFalse pointers if available
    if (t->onTrue || t->onFalse) {
        printf(" [onTrue: %p, onFalse: %p]", (void *)t->onTrue, (void *)t->onFalse);
    }
    printf("\n");

    // Recursively print child nodes
    for (int i = 0; i < t->nkids; i++) {
        print_tree_with_onTrue_onFalse(t->kids[i], depth + 1);
    }
}

struct entry_list *global_entries = NULL;

void reset_stdout() {
    #ifdef _WIN32
        freopen("CON", "w", stdout);       // Windows
    #else
        freopen("/dev/tty", "w", stdout);  // Unix/Linux/macOS
    #endif
}
void add_global_or_function_to_list(const char *name) {
    struct entry_list *new_entry = malloc(sizeof(struct entry_list));
    if (!new_entry) {
        fprintf(stderr, "Error: Memory allocation failed for global entry.\n");
        exit(EXIT_FAILURE);
    }
    new_entry->name = strdup(name);
    new_entry->next = global_entries;
    global_entries = new_entry;
}

void collect_globals_and_functions() {
    SymbolTableEntry ste;
    for (int i = 0; i < globals->nBuckets; i++) {
        for (ste = globals->tbl[i]; ste != NULL; ste = ste->next) {
            add_global_or_function_to_list(ste->s);
        }
    }
}

 int main(int argc, char **argv) {
    int generate_dot = 0;      // Flag for -dot option
    int generate_tree = 0;     // Flag for -tree option
    int generate_symtab = 0;   // Flag for -symtab option
    int file_count = 0;        // Count of input files
    char **files = NULL;       // Array of input files
    initStringTable(&string_tbl);


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
        
        globals = mksymtab(101, "Global");
        current = globals;
        predefined_symbols();
        populate_symboltables(root);

        // Handle the -tree option
        if (generate_tree) {
            treeprint(root, 1);  // Print the syntax tree
            printf("Syntax tree printed.\n");
        }

        // Handle the -symtab option
        if (generate_symtab) {
            if (result == 0) {  // Only generate symbol tables if parsing succeeds
                symboltable_type_init(root);
                build_function_parameter(root);
                typecheck(root);



                // printf("Symbol tables generated.\n");
                printsymbols(current, 0);  // Print global symbol table
                print_all(root);
            } else {
                printf("Errors encountered during parsing. Symbol tables not generated.\n");
            }
        }

// Handle the -dot option
    if (generate_dot) {
        char dot_filename[512]; // Increase buffer size to handle longer filenames
        int written = snprintf(dot_filename, sizeof(dot_filename), "%s.dot", filename);
        if (written < 0 || written >= sizeof(dot_filename)) {
            fprintf(stderr, "Error: Filename too long for buffer.\n");
            exit(EXIT_FAILURE);
        }
        print_graph(root, dot_filename);  // Generate a .dot file
        printf("Dot file generated: %s\n", dot_filename);
    }

    // Default behavior when no flags are provided
    if (!generate_tree && !generate_symtab && !generate_dot) {
        if (result == 0) {
            symboltable_type_init(root);
            build_function_parameter(root);
            typecheck(root);
            current = globals;
            assign_first(root);
            assign_follow(root);
            assign_onTrue_onFalse(root);
            
            assign_addresses_in_scope(globals);
            assign_address(root);
            print_tree_with_addresses(root,0); // Print the tree with addresses

            codegen(root);
            collect_globals_and_functions();
            char filename_ic[512];
            strcpy(filename_ic, filename);
            char *dot = strrchr(filename_ic, '.'); // Find the last dot in the filename
            if (dot != NULL) {
                *dot = '\0'; // Truncate the string at the dot
            }
            const char *extension = ".ic";
            strcat(filename_ic, extension);
            FILE *ic_file = fopen(filename_ic, "w");
            if (!ic_file) {
                fprintf(stderr, "Error: Could not open %s for writing.\n", filename_ic);
                exit(EXIT_FAILURE);
            }
            fflush(stdout);
            dup2(fileno(ic_file), fileno(stdout));
            print_tcode(filename,global_entries, &string_tbl);
            fclose(stdout);
            reset_stdout();
            printf("Intermediate code generated and written to %s\n", filename_ic);
            
            // print_tree_flags(root);
            // print_tree_with_addresses(root,0); // Print the tree with addresses
            // print_tree_with_icode(root, 0); // Print the tree with intermediate code
            // print_tree_with_onTrue_onFalse(root, 0); // Print the tree with onTrue and onFalse pointers
            
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

}