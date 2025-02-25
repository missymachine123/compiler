#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "k0gram.tab.h" 
#include "tree.h"


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
    va_start(ap, nkids);
    for(i=0; i < nkids; i++)
        ptr->kids[i] = va_arg(ap, struct tree *);
    va_end(ap);
    return ptr;
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


void freetree(struct tree *t) {
    if (t == NULL) {
        return;
    }
    
    for (int i = 0; i < t->nkids; i++) {
        freetree(t->kids[i]);
    }
    
    if (t->leaf) {
        free(t->leaf->text);
        free(t->leaf->filename);
        if (t->leaf->sval) {
            free(t->leaf->sval);
        }
        free(t->leaf);
    }
    free(t);
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
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    filename = kt_extension(argv[1]);
    yyin = fopen(filename, "r");
    if (!yyin) {
        perror(filename);
        free(filename);
        return 1;
    }
    
    // Call the parser
    // yydebug = 1; // Enable debugging
    printf("Printing from inside yyparse():\n\n");
    int result = yyparse();
    printf("yyparse returns %d\n", result);
    treeprint(root,1);

    // Close the input file
    fclose(yyin);
    free(filename);

    return 0;
    
}
