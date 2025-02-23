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

%start function_declaration

%%


function_declaration:
    FUN IDENTIFIER LPAREN parameter_list RPAREN function_body
  | FUN IDENTIFIER LPAREN parameter_list RPAREN type_hint function_body
    ;

function_body:
    block
    ;

block:
    LCURL statements RCURL
  | LCURL RCURL
    ;

statements:
    statement
  | statements statement
    ;

assignment_statement:
    IDENTIFIER ASSIGNMENT expression
    ;

statement:
    variable_declaration
  | expression
  | control_structure
  | assignment_statement
  | loop_statement         // Add loop_statement here
    ;

expression:
    IDENTIFIER LPAREN parameter_list RPAREN
  | IDENTIFIER DOT IDENTIFIER
  | literal_constant
  | expression ADD expression
  | expression SUB expression
  | expression MULT expression
  | expression DIV expression
    ;

variable_declaration:
    VAR IDENTIFIER optional_type_hint ASSIGNMENT expression
  | VAL IDENTIFIER optional_type_hint ASSIGNMENT expression
    ;

optional_type_hint:
    /* empty */
  | type_hint
    ;

literal_constant:
    INTEGER_LITERAL
  | BOOLEAN_LITERAL
  | STRING_LITERAL
  | FLOAT_LITERAL
    ;

type:
  INTEGER_LITERAL
  |IDENTIFIER
  |IDENTIFIER LANGLE IDENTIFIER RANGLE
  ;
type_hint:
    COLON type
    ;

parameter:
    IDENTIFIER
  | IDENTIFIER type_hint
  | literal_constant
    ;

parameter_list:
    /* empty */
  | parameter
  | parameter_list COMMA parameter
    ;

control_structure:
    IF LPAREN expression RPAREN control_structure_body
  | IF LPAREN expression RPAREN statement ELSE control_structure_body
    ;

loop_statement:
    FOR LPAREN expression RPAREN control_structure_body
  | WHILE LPAREN expression RPAREN control_structure_body
  | DO control_structure_body WHILE LPAREN expression RPAREN
    ;

control_structure_body:
    block
    ;

%% 

