#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "k0gram.tab.h" 
#include "tree.h"
#include "symtab.h"


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
struct token yytoken;
char *filename;
extern struct tree *root;
int serial = 0;
extern const char *yyname(int sym);
SymbolTable current = NULL;
SymbolTable globals = NULL;
SymbolTable last_scope = NULL;
int SCOPE = 0; 
#define pushscope(stp) do { stp->parent = current; current = stp; SCOPE++; } while (0)
#define popscope() do { current = current->parent; SCOPE--; } while(0)
void printsymbols(SymbolTable st, int level);


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
    exit(1);
    
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
    struct tree *ptr = malloc(sizeof(struct tree) + (nkids-1)*sizeof(struct tree *));

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
   while (c = *s++) {
      h += c & 0377;
      h *= 37;
      }
   if (h < 0) h = -h;
   return h % st->nBuckets;
}

/*
 * Insert a symbol into a symbol table.
 */
int insert_sym(SymbolTable st, char *s) { 
    struct sym_entry *se;
    int h;
    h = hash(st, s);
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
    //se->type = t;
    st->nEntries++;
    return 1;
}


void enter_newscope(char *s) {
    // Allocate a new symbol table
    SymbolTable newTable = mksymtab(101, s);
    
    // Insert s into the current symbol table
    insert_sym(current, s);

    //attach new symbol to s's entry 
    int h = hash(current, s);
    struct sym_entry *se;
    for (se = current->tbl[h]; se != NULL; se = se->next) {
        if (!strcmp(se->s, s)) {
            // Attach new symbol table to this entry
            se->table = newTable;
            break;
        }
    }

    // Push new symbol table onto the stack
    //newTable->parent = current;
    //current = newTable;
    pushscope(newTable);
    //newTable->tbl = current->tbl;
    //current->tbl = newTable;
    //current = newTable;
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
                if (n->kids[i] != NULL && n->kids[i]->leaf != NULL && n->kids[i]->leaf->category == 406) {
                   //printf("Function new name: %s\n", n->kids[i]->leaf->text);
                   enter_newscope(n->kids[i]->leaf->text);
                   break;
                }
            } 
            break;
        }

        // Handle entering a new class/struct scope
        //case 1033: /* Production rule for class/struct declaration */ {
            //printf("Entering new CLASS scope\n");
            //enter_newscope("Class"); // Replace "Class" with actual class name if retrievable
            //break;
        //}

        case 1022: /* whatever production rule(s) designate a variable declaration */
            // enter_newscope("variable_declaration");
            // printf("Global variable next->s: %s /n",globals->next->s);
            //for (i = 0; i < n->nkids; i++) {
               // if (n->kids[i] != NULL){
               //     printf("category %d\n",n->kids[i]->prodrule);
               // }
            //}
            
            for (i = 0; i < n->nkids; i++) {
                 if (n->kids[i] != NULL && n->kids[i]->leaf != NULL && n->kids[i]->leaf->category == 406) {
                    if ((lookup_st(current, n->kids[i]->leaf->text)) != NULL){
                        fprintf(stderr, "Error: Redeclaration of variable '%s' at line %d\n", n->kids[i]->leaf->text, n->kids[i]->leaf->lineno);
                    }else{
                        insert_sym(current, n->kids[i]->leaf->text);

                    }
                 }
             }
            
            break;
        
        case 406: /* whatever leaf denotes a variable name */
            //printf("Variable name: %s\n", n->leaf->text); 
            if ((lookup_st(current, n->leaf->text)) == NULL && (lookup_st(globals, n->leaf->text)) == NULL){ //
            //    insert_sym(current, n->leaf->text);
                fprintf(stderr, "Error: Undeclared variable '%s' at line %d\n", n->leaf->text, n->leaf->lineno);
            }
            break;
        }
    /* Visit children (Recursive traversal of child nodes) */
    for (i = 0; i < n->nkids; i++) {
        populate_symboltables(n->kids[i]);
    }

    /* Post-order activity */
    switch (n->prodrule) {
    
        case 1004: /* End of class scope */ {
            printsymbols(current, SCOPE);
            printf("---\n");
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


 void printsyms(struct tree *t) {
    if (t == NULL) { 
        return;
    }
 
    if (t->leaf != NULL && t->leaf->category == 406) {
        printsymbol(t->leaf->text);
    }
    for (int i = 0; i < t->nkids; i++) {
        printsyms(t->kids[i]);
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

 
int main(int argc, char **argv) {
    int generate_dot = 0;      // Flag for -dot option
    int generate_tree = 0;     // Flag for -tree option
    int generate_symtab = 0;   // Flag for -symtab option

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-dot] [-tree] [-symtab] <filename>\n", argv[0]);
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
        } else if (argv[i][0] != '-') {  // Assume it's the filename
            filename = kt_extension(argv[i]);
        }
    }

    if (filename == NULL) {
        fprintf(stderr, "Error: No input file specified.\n");
        return 1;
    }

    yyin = fopen(filename, "r");
    if (!yyin) {
        perror(filename);
        free(filename);
        return 1;
    }

    // Call the parser
    printf("Parsing file: %s\n", filename);
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
            populate_symboltables(root);
            //printf("Symbol tables generated.\n");
            printsymbols(globals, 0);  // Print symbol tables
        } else {
            printf("Errors encountered during parsing. Symbol tables not generated.\n");
        }
    }

    // Handle the -dot option
    if (generate_dot) {
        print_graph(root, "tree.dot");  // Generate a .dot file
        printf("Dot file generated: tree.dot\n");
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
    return 0;
}