%{
    extern int yylex(void);
    extern int yyerror(char *s);
    #define YYDEBUG 1
    #include "tree.h"
%}

%union {
   struct tree *treeptr;
}

%token RESERVED DOT COMMA LPAREN RPAREN LSQUARE RSQUARE LCURL RCURL MULT MOD DIV ADD SUB INCR DECR CONJ DISJ EXCL_WS EXCL_NO_WS
%token COLON SEMICOLON ASSIGNMENT ADD_ASSIGNMENT SUB_ASSIGNMENT MULT_ASSIGNMENT DIV_ASSIGNMENT MOD_ASSIGNMENT ARROW DOUBLE_ARROW
%token RANGE COLONCOLON DOUBLE_SEMICOLON HASH AT_NO_WS AT_POST_WS AT_PRE_WS AT_BOTH_WS QUEST_WS QUEST_NO_WS LANGLE RANGLE LE GE QUEST_DOT
%token EXCL_EQ EXCL_EQEQ AS_SAFE EQEQ EQEQEQ SINGLE_QUOTE RETURN_AT CONTINUE_AT BREAK_AT THIS_AT SUPER_AT FILES FIELD PROPERTY GET QUEST_COLON
%token SET RECEIVER PARAM SETPARAM DELEGATE PACKAGE IMPORT CLASS INTERFACE FUN OBJECT VAL VAR TYPEALIAS CONSTRUCTOR BY COMPANION
%token INIT THIS SUPER TYPEOF WHERE IF ELSE WHEN TRY CATCH FINALLY FOR DO WHILE THROW RETURN CONTINUE BREAK AS IS IN OUT DYNAMIC PUBLIC
%token PRIVATE PROTECTED INTERNAL ENUM SEALED ANNOTATION DATA INNER TAILREC OPERATOR INLINE INFIX EXTERNAL SUSPEND OVERRIDE ABSTRACT NULL_LITERAL
%token FINAL OPEN CONST LATEINIT VARARG NOINLINE CROSSINLINE REIFIED EXPECT ACTUAL REAL_LITERAL FLOAT_LITERAL DOUBLE_LITERAL INTEGER_LITERAL CHARACTER_LITERAL
%token HEX_LITERAL BIN_LITERAL UNSIGNED_LITERAL LONG_LITERAL BOOLEAN_LITERAL IDENTIFIER STRING_LITERAL INT FLOAT BOOLEAN CHAR STRING BYTE T_EOF
%debug 

%left ADD SUB
%left MULT DIV MOD
%left AND OR

%nonassoc ELSE
%nonassoc LOWER_THAN_ELSE

%start program
%%

/* Program Structure */
program:
    topLevelObjects
;

topLevelObjects:
    topLevelObject
  | topLevelObjects topLevelObject
;

topLevelObject:
    functionDeclaration
  | classDeclaration
  | objectDeclaration
;

/* Function Declaration */
functionDeclaration:
    FUN IDENTIFIER LPAREN functionParameters RPAREN functionBody
  | FUN IDENTIFIER LPAREN functionParameters RPAREN COLON type functionBody
;

/* Function Parameters */
functionParameters:
    /* empty */
  | functionParameter
  | functionParameters COMMA functionParameter
;

functionParameter:
    IDENTIFIER COLON type
;

/* Type */
type:
    IDENTIFIER
  | INTEGER_LITERAL
  | DOUBLE_LITERAL
  | BOOLEAN_LITERAL
  | STRING_LITERAL
  | NULL_LITERAL
;

/* Function Body */
functionBody:
    block
  | ASSIGNMENT expression SEMICOLON
;

/* Block of Code */
block:
    LCURL statements RCURL
;

/* Statements */
statements:
    /* empty */
  | statements statement SEMICOLON
  | statements statement
;

statement:
    variableDeclaration SEMICOLON
  | assignment SEMICOLON
  | assignment
  | expression
  | expression SEMICOLON
  | loopStatement
  | controlStructure
  | returnStatement
;

/* Variable Declaration */
variableDeclaration:
    IDENTIFIER COLON type
;

/* Assignment */
assignment:
    IDENTIFIER ASSIGNMENT expression SEMICOLON
;

/* Function Call */
functionCall:
    IDENTIFIER LPAREN functionArguments RPAREN
;

/* Function Arguments */
functionArguments:
    /* empty */
  | expression
  | functionArguments COMMA expression
;

/* Loops */
loopStatement:
    WHILE LPAREN expression RPAREN block
  | FOR LPAREN IDENTIFIER IN expression RPAREN block
;

/* Control Structures */
controlStructure:
    IF LPAREN expression RPAREN block %prec LOWER_THAN_ELSE
  | IF LPAREN expression RPAREN block ELSE block
;

/* Return Statement */
returnStatement:
    RETURN expression SEMICOLON
;

/* Class Declaration */
classDeclaration:
    CLASS IDENTIFIER classBody
;

classBody:
    LCURL classMembers RCURL
;

classMembers:
    /* empty */
  | classMembers classMember
;

classMember:
    functionDeclaration
  | variableDeclaration
;

/* Object Declaration */
objectDeclaration:
    OBJECT IDENTIFIER objectBody
;

objectBody:
    LCURL classMembers RCURL
;

/* Expressions */
expression:
    functionCall
  | IDENTIFIER
  | STRING_LITERAL
  | INTEGER_LITERAL
;
%%
