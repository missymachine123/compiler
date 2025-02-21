#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

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

extern FILE *yyin;
extern int yylex();
extern char *yytext;
extern int yylineno;
extern int yyival;
extern double yydval;
extern char *yysval;
extern int yylex_destroy();
struct tokenlist {
      struct token *t;
      struct tokenlist *next;
};

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

struct tokenlist *create_tokenlist(struct token *t) {
    struct tokenlist *new_node = (struct tokenlist *)malloc(sizeof(struct tokenlist));
    new_node->t = t;
    new_node->next = NULL;
    return new_node;
}


char* kt_extension(const char* filename) {
    char *new_filename = (char*)malloc(strlen(filename) + 4);
    strcpy(new_filename, filename);
    if (strstr(filename, ".kt") == NULL) {
        strcat(new_filename, ".kt");
    }
    return new_filename;
}

void free_tokens(struct tokenlist *head) {
    struct tokenlist *current = head;
    while (current != NULL) {
        struct tokenlist *temp = current;
        current = current->next;
        free(temp->t->text);
        free(temp->t->filename);
        if (temp->t->sval){ 
            free(temp->t->sval);}
        free(temp->t);
        free(temp);
    }
}

void print_tokens(struct tokenlist *head) {
    struct tokenlist *current = head;
    printf("Category\tText\t\tLineno\tFilename\t\tValues\n");
    printf("--------------------------------------------------------------------------\n");
    while (current != NULL) {
        printf("%d\t\t%s\t\t%d\t%s\t", 
               current->t->category, current->t->text, current->t->lineno, current->t->filename);
        
        if (current->t->ival != 0) {
            printf("%d ", current->t->ival);
        }else if (current->t->dval != 0.0) {
            printf("%f ", current->t->dval);
        } else if (current->t->sval != NULL) {
            printf("%s ", current->t->sval);
        }

        printf("\n");
        current = current->next;
    }
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
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = kt_extension(argv[1]);
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        free(filename);
        return 1;
    }
    struct tokenlist *head = NULL, *current = NULL;
    yyin = file;
    int category;
    
    while ((category = yylex()) != 0) {
        
        if (yytext[0] == '"') {
            yysval = strdup("");
            for (int i = 1; yytext[i] != '\0'; i++) {
                if (yytext[i] == '\\') {
                    switch (yytext[++i]) {
                        case 'n':
                            yysval = appendstring(yysval, '\n');
                            break;
                        case 't':
                            yysval = appendstring(yysval, '\t');
                            break;
                        case 'r':
                            yysval = appendstring(yysval, '\r');
                            break;
                        case '\\':
                            yysval = appendstring(yysval, '\\');
                            break;
                        case '"':
                            yysval = appendstring(yysval, '"');
                            break;
                        default:
                            yysval = appendstring(yysval, yytext[i]);
                            break;
                    }
                } else if (yytext[i] == '"') {
                    continue;  // Skip the ending double-quote
                } else {
                    yysval = appendstring(yysval, yytext[i]);
                }
            }
        } else {
            yysval = NULL;
            }
        struct token *new_token = create_token(category, yytext, yylineno, filename, yyival, yydval, yysval);    
        struct tokenlist *new_node = create_tokenlist(new_token);
        if (head == NULL) {
            head = new_node;
            current = head;
        } else {
            current->next = new_node;
            current = current->next;
        }    
        print_token(new_token); // Print each token as it's processed
        free(yysval);
        yyival = 0;
        yydval = 0.0; 
        
    }
    

    fclose(file); 
    print_tokens(head);
    yylex_destroy();
    free_tokens(head); 
    free(filename);
    return 0;
}
