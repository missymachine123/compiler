%{
    extern int yylex(void);
    extern int yyerror(char *s);
    #define YYDEBUG 1
    #include "tree.h"
    void printnode();
    struct tree *root;
    void treeprint(struct tree *t, int depth);
    struct tree *alctree(int prodrule, const char *symbolname, int nkids, ...);
%}

%union {
   struct tree *treeptr;
}

%token <treeptr> RESERVED DOT COMMA LPAREN RPAREN LSQUARE RSQUARE LCURL RCURL INCR DECR CONJ DISJ EXCL_WS EXCL_NO_WS
%token <treeptr> COLON SEMICOLON ASSIGNMENT ADD_ASSIGNMENT SUB_ASSIGNMENT MULT_ASSIGNMENT DIV_ASSIGNMENT MOD_ASSIGNMENT ARROW DOUBLE_ARROW
%token <treeptr> RANGE COLONCOLON DOUBLE_SEMICOLON HASH AT_NO_WS AT_POST_WS AT_PRE_WS AT_BOTH_WS QUEST_WS QUEST_NO_WS LANGLE RANGLE LE GE QUEST_DOT
%token <treeptr> EXCL_EQ EXCL_EQEQ AS_SAFE EQEQ EQEQEQ SINGLE_QUOTE RETURN_AT CONTINUE_AT BREAK_AT THIS_AT SUPER_AT FILES FIELD PROPERTY GET QUEST_COLON
%token <treeptr> SET RECEIVER PARAM SETPARAM DELEGATE PACKAGE IMPORT CLASS INTERFACE FUN OBJECT VAL VAR TYPEALIAS CONSTRUCTOR BY COMPANION
%token <treeptr> INIT THIS SUPER TYPEOF WHERE IF ELSE WHEN TRY CATCH FINALLY FOR DO WHILE THROW RETURN CONTINUE BREAK AS IS IN OUT DYNAMIC PUBLIC
%token <treeptr> PRIVATE PROTECTED INTERNAL ENUM SEALED ANNOTATION DATA INNER TAILREC OPERATOR INLINE INFIX EXTERNAL SUSPEND OVERRIDE ABSTRACT NULL_LITERAL
%token <treeptr> FINAL OPEN CONST LATEINIT VARARG NOINLINE CROSSINLINE REIFIED EXPECT ACTUAL REAL_LITERAL FLOAT_LITERAL DOUBLE_LITERAL INTEGER_LITERAL CHARACTER_LITERAL
%token <treeptr> HEX_LITERAL BIN_LITERAL UNSIGNED_LITERAL LONG_LITERAL BOOLEAN_LITERAL STRING_LITERAL INT FLOAT BOOLEAN CHAR STRING BYTE T_EOF
%token <treeptr> MULT MOD DIV ADD SUB
%token <treeptr> IDENTIFIER
%debug 

%type <treeptr> program topLevelObjects topLevelObject functionDeclaration functionParameters functionParameter type functionBody block statements statement variableDeclaration assignment functionCall functionArguments loopStatement controlStructure returnStatement classDeclaration classBody classMembers classMember objectDeclaration objectBody expression
%left ADD SUB
%left MULT DIV MOD
%left AND OR

%nonassoc ELSE
%nonassoc LOWER_THAN_ELSE

%start program
%%

/* Program Structure */
program:
    topLevelObjects {root = $1;}
;

topLevelObjects:
    topLevelObject {$$ = alctree(1001, "topLevelObjects", 1, $1);}
  | topLevelObjects topLevelObject {$$ = alctree(1001, "topLevelObjects", 2, $1, $2);}
;

topLevelObject:
    functionDeclaration {$$ = alctree(1002, "topLevelObject", 1, $1);}
  | classDeclaration {$$ = alctree(1002, "topLevelObject", 1, $1);}
  | objectDeclaration {$$ = alctree(1002, "topLevelObject", 1, $1);}
;

/* Function Declaration */
functionDeclaration:
    FUN IDENTIFIER LPAREN functionParameters RPAREN functionBody {$$ = alctree(1003, "functionDeclaration", 6, $1, $2, $3, $4, $5,$6);}
  | FUN IDENTIFIER LPAREN functionParameters RPAREN COLON type functionBody  {$$ = alctree(1003, "functionDeclaration", 7, $1, $2, $3, $4, $5, $6,$7);}
;

/* Function Parameters */
functionParameters:
    /* empty */{$$ = NULL;}
  | functionParameter {$$ = alctree(1004, "functionParameters", 1, $1);}  
  | functionParameters COMMA functionParameter  {$$ = alctree(1004, "functionParameters", 3, $1, $2, $3);}  
;

functionParameter:
  IDENTIFIER COLON type {$$ = alctree(1005, "functionParameter", 3, $1, $2, $3);} 
;

/* Type */
type:
    IDENTIFIER  {$$ = $1;}
  | INTEGER_LITERAL {$$ =  $1;}
  | DOUBLE_LITERAL  {$$ =  $1;}  
  | BOOLEAN_LITERAL {$$ = $1;}
  | STRING_LITERAL  {$$ =  $1;}  
  | NULL_LITERAL  {$$ =  $1;}
;

/* Function Body */
functionBody:
    block {$$ = alctree(1007, "functionBody", 1, $1);}
  | ASSIGNMENT expression SEMICOLON {$$ = alctree(1007, "functionBody", 3, $1, $2, $3);}
;

/* Block of Code */
block:
    LCURL statements RCURL  {$$ = alctree(1008, "block", 3, $1, $2, $3);  }
;

/* Statements */
statements:
    /* empty */ {$$ = NULL;}
  | statements statement SEMICOLON  {$$ = alctree(1009, "statements", 3, $1, $2,$3);}
  | statements statement  {$$ = alctree(1009, "statements", 2, $1,$2);}  
;

statement:
    variableDeclaration SEMICOLON {$$ = alctree(1010, "statement", 2, $1,$2);}
  | assignment SEMICOLON  {$$ = alctree(1010, "statement", 2, $1,$2);}
  | assignment  {$$ = alctree(1010, "statement", 1, $1);}
  | expression  {$$ = alctree(1010, "statement", 1, $1); }
  | expression SEMICOLON  {$$ = alctree(1010, "statement", 2, $1,$2);}
  | loopStatement {$$ = alctree(1010, "statement", 1, $1);}
  | controlStructure    {$$ = alctree(1010, "statement", 1, $1);}
  | returnStatement {$$ = alctree(1010, "statement", 1, $1);}
;

/* Variable Declaration */
variableDeclaration:
    IDENTIFIER COLON type {$$ = alctree(1011, "variableDeclaration", 3, $1, $2, $3);}
;

/* Assignment */
assignment:
    IDENTIFIER ASSIGNMENT expression SEMICOLON  {$$ = alctree(1012, "assignment", 4, $1, $2, $3,$4);}
;

/* Function Call */
functionCall:
    IDENTIFIER LPAREN functionArguments RPAREN  {$$ = alctree(1013, "functionCall", 4, $1, $2, $3,$4);}
;

/* Function Arguments */
functionArguments:
    /* empty */{$$ = NULL;}
  | expression  {$$ = alctree(1014, "functionArguments", 1, $1);}
  | functionArguments COMMA expression  {$$ = alctree(1014, "functionArguments", 3, $1, $2, $3);}
;

/* Loops */
loopStatement:
    WHILE LPAREN expression RPAREN block  {$$ = alctree(1015,"loopStatement", 5 ,$1, $2, $3, $4,$5);}
  | FOR LPAREN IDENTIFIER IN expression RPAREN block  {$$ = alctree(1015,"loopStatement", 6 ,$1, $2, $3, $4,$5,$6);}
;

/* Control Structures */
controlStructure:
    IF LPAREN expression RPAREN block %prec LOWER_THAN_ELSE {$$ = alctree(1016, "controlStructure", 5, $1, $2, $3,$4,$5 );}
  | IF LPAREN expression RPAREN block ELSE block {$$ = alctree(1016, "controlStructure", 7 ,$1, $2, $3,$4,$5,$6,$7);}
;

/* Return Statement */
returnStatement:
    RETURN expression SEMICOLON {$$ = alctree(1017, "returnStatement", 3, $1, $2, $3);}
;

/* Class Declaration */
classDeclaration:
    CLASS IDENTIFIER classBody  {$$ = alctree(1018, "classDeclaration", 3, $1, $2, $3);}
;

classBody:
    LCURL classMembers RCURL  {$$ = alctree(1019, "classBody", 3, $1, $2, $3);}
;

classMembers:
    /* empty */ {$$ = NULL;}
  | classMembers classMember  {$$ = alctree(1020, "classMembers", 2, $1, $2);}
;

classMember:
    functionDeclaration {$$ = alctree(1021, "classMember", 1, $1);}
  | variableDeclaration   {$$ = alctree(1021, "classMember", 1, $1);}
;

/* Object Declaration */
objectDeclaration:
    OBJECT IDENTIFIER objectBody  {$$ = alctree(1022, "objectDeclaration", 3, $1, $2, $3);}
;

objectBody:
    LCURL classMembers RCURL  {$$ = alctree(1023, "objectBody", 3, $1, $2, $3);}
;

/* Expressions */
expression:
    functionCall  {$$ = alctree(1024, "expression", 1, $1);}
  | IDENTIFIER    {$$ = $1; }
  | STRING_LITERAL  {$$ = $1;}
  | INTEGER_LITERAL   {$$ = $1;}
;
%%
