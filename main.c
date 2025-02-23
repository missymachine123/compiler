#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "k0gram.tab.h" 


extern FILE *yyin;
extern int yyparse(void);
extern char *yytext;
extern int yylineno;
extern int ival;
extern double dval;
extern char *sval;
extern int yylex_destroy();
extern int yydebug;

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

char *appendstring(char *s, char c)
{
    int i = strlen(s);
    s = realloc(s, i+2);
    s[i] = c;
    s[i+1] = '\0';
    return s;
}

struct token *create_token(int category, const char *text, int lineno, const char *filename, int ival, double dval, const char *sval) {
        struct token *new_token = (struct token *)malloc(sizeof(struct token));
        new_token -> category = category;
        new_token -> text = strdup(text);
        new_token -> lineno =  lineno;
        new_token -> filename = strdup(filename);
        new_token -> ival = ival;
        new_token -> dval = dval;
        if (sval) {
            new_token->sval = strdup(sval);
        } else {
            new_token->sval = NULL;
        }
        return new_token;
};



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

void print_token(struct token *t) {
    printf("%d\t\t%s\t\t%d\t%s\t", 
           t->category, t->text, t->lineno, t->filename);
    
    if (t->ival != 0) {
        printf("%d ", t->ival);
    } else if (t->dval != 0.0) {
        printf("%f ", t->dval);
    } else if (t->sval != NULL) {
        printf("%s ", t->sval);
    }

    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = kt_extension(argv[1]);
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
