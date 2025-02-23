#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int alctoken(int category) {
    // Allocate memory for the tree node
    yylval.treeptr = malloc(sizeof(struct tree));
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
    if (yysval) {
        yylval.treeptr->leaf->sval = strdup(yysval);
        free(yysval);  // Free yysval here after copying it
        yysval = NULL;
    } else {
        yylval.treeptr->leaf->sval = NULL;
    }

    // Print debugging information
    printf("Token created:\t"
           "category = %d\t"
           "text = %s\t"
           "lineno = %d\t"
           "filename = %s\t"
           "ival = %d\t"
           "dval = %f\t"
           "sval = %s\n",
           yylval.treeptr->leaf->category,
           yylval.treeptr->leaf->text,
           yylval.treeptr->leaf->lineno,
           yylval.treeptr->leaf->filename,
           yylval.treeptr->leaf->ival,
           yylval.treeptr->leaf->dval,
           yylval.treeptr->leaf->sval ? yylval.treeptr->leaf->sval : "NULL");

    yydval = 0.0;
    yyival = 0;
    return category;
}


// int alctoken(int category){
//     yylval.treeptr = malloc(sizeof (struct tree));
//     // Initialize the tree node fields
//     yylval.treeptr->prodrule = category;
//     yylval.treeptr->nkids = 0;
//     yylval.treeptr->leaf = malloc(sizeof(struct token));

//     // Allocate and initialize the token
//     yylval.treeptr->leaf->category = category;
//     yylval.treeptr->leaf->text = strdup(yytext);
//     yylval.treeptr->leaf->lineno = yylineno;
//     yylval.treeptr->leaf->filename = strdup(filename);
//     yylval.treeptr->leaf->ival = yyival;
//     yylval.treeptr->leaf->dval = yydval;
//     yylval.treeptr->leaf->sval = strdup(yysval);

//     return category;

// }

// struct token *create_token(int category, const char *text, int lineno, const char *filename, int ival, double dval, const char *sval) {
//         struct token *new_token = (struct token *)malloc(sizeof(struct token));
//         new_token -> category = category;
//         new_token -> text = strdup(text);
//         new_token -> lineno =  lineno;
//         new_token -> filename = strdup(filename);
//         new_token -> ival = ival;
//         new_token -> dval = dval;
//         if (sval) {
//             new_token->sval = strdup(sval);
//         } else {
//             new_token->sval = NULL;
//         }
//         return new_token;
// };



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
    int result = yyparse();
    printf("yyparse returns %d\n", result);

    // Close the input file
    fclose(yyin);

    return 0;
    
}
