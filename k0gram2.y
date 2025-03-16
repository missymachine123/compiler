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
%token <treeptr> RANGE COLONCOLON DOUBLE_SEMICOLON HASH  AT_NO_WS AT_POST_WS AT_PRE_WS AT_BOTH_WS QUEST_WS QUEST_NO_WS LANGLE RANGLE LE GE QUEST_DOT
%token <treeptr> EXCL_EQ EXCL_EQEQ AS_SAFE EQEQ EQEQEQ SINGLE_QUOTE RETURN_AT CONTINUE_AT BREAK_AT THIS_AT SUPER_AT FILES FIELD PROPERTY GET QUEST_COLON
%token <treeptr> SET RECEIVER PARAM SETPARAM DELEGATE PACKAGE IMPORT CLASS INTERFACE FUN OBJECT VAL VAR TYPEALIAS CONSTRUCTOR BY COMPANION
%token <treeptr> INIT  TYPELITERAL THIS SUPER TYPEOF WHERE IF ELSE WHEN TRY CATCH FINALLY FOR DO WHILE THROW RETURN CONTINUE BREAK AS IS IN OUT DYNAMIC PUBLIC
%token <treeptr> PRIVATE PROTECTED INTERNAL ENUM SEALED ANNOTATION DATA INNER TAILREC OPERATOR INLINE INFIX EXTERNAL SUSPEND OVERRIDE ABSTRACT NULL_LITERAL
%token <treeptr> FINAL OPEN CONST LATEINIT VARARG NOINLINE CROSSINLINE REIFIED EXPECT ACTUAL REAL_LITERAL FLOAT_LITERAL DOUBLE_LITERAL INTEGER_LITERAL CHARACTER_LITERAL
%token <treeptr> HEX_LITERAL BIN_LITERAL UNSIGNED_LITERAL LONG_LITERAL BOOLEAN_LITERAL STRING_LITERAL INT FLOAT BOOLEAN CHAR STRING BYTE T_EOF
%token <treeptr> MULT MOD DIV ADD SUB
%token <treeptr> IDENTIFIER
%debug 

%type <treeptr> opt_semis  declaration  opt_typeParameters opt_comma typeParameters typeParameter  multi_typeParameter simpleIdentifier classDeclaration  semis_statement optional_statement_sequence program topLevelObjects topLevelObject functionDeclaration  type functionBody block statements statement  assignment functionCall functionArguments loopStatement  returnStatement  classBody classMembers classMember objectDeclaration objectBody expression
%type <treeptr>  parameter common_literal literalConstant jumpExpression multi_whenEntry whenExpression ifExpression collectionLiteral  whenSubject multi_comma_whenCondition whenEntry whenCondition rangeTest functionValueParameter functionValueParameters opt_functionValueParameter multi_comma_functionParameter opt_functionBody  opt_eq_exp receiverType parenthesizedType typeRef_parenthesizedType nullableType multi_quest userType multi_dot_simpleUserType  simpleUserType  opt_modifier val_var multivariable_variableDeclaration  parenthesizedExpression propertyDeclaration navigationSuffix identifier_expression_class memberAccessOperator typeArguments directlyAssignableExpression parenthesizedDirectlyAssignableExpression multi_postfixUnarySuffix postfixUnaryExpression postfixUnarySuffix postfixUnaryOperator multi_comma_expression  callSuffix controlStructureBody opt_controStructureBody  control_structure_body_or_comma variable_multivariable valueArgument opt_Multi opt_simpleIdentifier_EQ valueArguments opt_valueArgument multi_comma_valueArgument assignableSuffix multiVariableDeclaration variableDeclaration multi_comma_variableDeclaration  directly_assign  assignableExpression assignmentAndOperator prefixUnaryExpression parenthesizedAssignableExpression indexingSuffix multi_unaryPrefix prefixUnaryOperator multi_comma_typeProjection typeProjection primaryExpression
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

opt_functionBody:
    functionBody {$$ = alctree(1003, "opt_functionBody", 1, $1);}
  | /* empty */ {$$ = NULL;}
  ;

/* Function Declaration */
functionDeclaration:
    FUN opt_typeParameters receiverType DOT simpleIdentifier functionValueParameters opt_functionBody {$$ = alctree(1003, "functionDeclaration", 7, $1, $2, $3, $4, $5,$6,$7);}
    | FUN opt_typeParameters  simpleIdentifier functionValueParameters opt_functionBody {$$ = alctree(1003, "functionDeclaration", 5, $1, $2, $3, $4, $5);}

;

functionValueParameters:
  LPAREN  opt_functionValueParameter RPAREN {$$ = alctree(1004, "functionValueParameters", 3, $1, $2, $3);}
  ;

functionValueParameter:
  parameter opt_eq_exp {$$ = alctree(1005, "functionValueParameter", 2, $1, $2);}
  ;
  
parameter:
  simpleIdentifier COLON type {$$ = alctree(1005, "parameter", 3, $1, $2, $3);}
  ;
  
multi_comma_functionParameter:
  multi_comma_functionParameter COMMA functionValueParameter {$$ = alctree(1004, "multi_comma_functionParameter", 3, $1, $2,$3);}
  | /* empty */ {$$ = NULL;}
  ;

opt_functionValueParameter:
  functionValueParameter multi_comma_functionParameter COMMA {$$ = alctree(1004, "opt_functionValueParameter", 3, $1, $2, $3);}
  |functionValueParameter multi_comma_functionParameter  {$$ = alctree(1004, "opt_functionValueParameter", 2, $1, $2);}
  | /* empty */ {$$ = NULL;}
  ;

/* Type */
type:
  nullableType {$$ = alctree(1006, "type", 1, $1);}
  | TYPELITERAL

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

opt_semis:
    SEMICOLON {$$ = $1;}
  | {$$ = NULL;}
  ;

semis_statement:
 	semis_statement SEMICOLON statement {$$ = alctree(2000, "semis_statement", 3, $1, $2, $3);}
  |semis_statement  statement {$$ = alctree(2000, "semis_statement", 2, $1, $2);}
	|  {$$ = NULL;}
	;

optional_statement_sequence:
     statement semis_statement  {$$ = alctree(2001, "optional_statement_sequence", 2, $1, $2);}
	|  {$$ = NULL;}
	;

statements:
	optional_statement_sequence SEMICOLON {$$ = alctree(1009, "statements", 2, $1, $2);}
  |optional_statement_sequence  {$$ = alctree(1009, "statements", 1, $1);}
	;

/* Statement */

statement:
    declaration {$$ = alctree(1010, "statement", 1, $1);}
  | assignment  {$$ = alctree(1010, "statement", 1, $1);}
  | expression  {$$ = alctree(1010, "statement", 1, $1); }
  | loopStatement {$$ = alctree(1010, "statement", 1, $1);}
;

declaration:
  classDeclaration {$$ = alctree(1011, "declaration", 1, $1);}
  |functionDeclaration {$$ = alctree(1011, "declaration", 1, $1);}
  | propertyDeclaration {$$ = alctree(1011, "declaration", 1, $1);}
  ;

val_var:
  VAR {$$ = $1;}
  | VAL {$$ = $1;}
  ;

opt_modifier:
  CONST {$$ = $1;}
  | { /* epsilon production */ } {$$ = NULL;}
  ;


receiverType:
  nullableType  {$$ = alctree(1012, "receiverType", 1, $1);}
  ;

parenthesizedType:
  LPAREN type RPAREN {$$ = alctree(1012, "parenthesizedType", 3, $1, $2, $3);}
  ;



multi_dot_simpleUserType:
  multi_dot_simpleUserType DOT simpleUserType {$$ = alctree(1012, "multi_dot_simpleUserType", 3, $1, $2, $3);}
  | { /* epsilon production */ } {$$ = NULL;}
  ;

userType:
  simpleUserType multi_dot_simpleUserType {$$ = alctree(1012, "userType", 2, $1, $2);}
  ;
 

simpleUserType:
  simpleIdentifier typeArguments{$$ = alctree(1012, "simpleUserType", 2, $1,$2);}
  |simpleIdentifier {$$ = alctree(1012, "simpleUserType", 1, $1);}
  ;


multi_quest:
  multi_quest QUEST_NO_WS {$$ = alctree(1012, "multi_quest", 2, $1, $2);}
  | { /* epsilon production */ } {$$ = NULL;}
  ;
nullableType:
  typeRef_parenthesizedType multi_quest {$$ = alctree(1012, "nullableType", 2, $1, $2);}
  ;

typeRef_parenthesizedType:
  parenthesizedType {$$ = alctree(1012, "typeRef_parenthesizedType", 1, $1);}
  |  userType {$$ = alctree(1012, "typeRef_parenthesizedType", 1, $1);} //TypeReferfence
  ;
 

opt_eq_exp:
  ASSIGNMENT expression {$$ = alctree(1012, "opt_eq_exp", 2, $1, $2);} 
  | { /* epsilon production */ } {$$ = NULL;}
  ;


multivariable_variableDeclaration:
  variableDeclaration {$$ = alctree(1012, "multivariable_variableDeclaration", 1, $1);}
  | multiVariableDeclaration {$$ = alctree(1012, "multivariable_variableDeclaration", 1, $1);}
  ;

propertyDeclaration:
  opt_modifier val_var opt_typeParameters receiverType DOT multivariable_variableDeclaration opt_eq_exp SEMICOLON {$$ = alctree(1012, "propertyDeclaration", 8, $1, $2, $3, $4, $5, $6, $7,$8);}
  |  opt_modifier val_var opt_typeParameters multivariable_variableDeclaration opt_eq_exp SEMICOLON {$$ = alctree(1012, "propertyDeclaration", 6, $1, $2, $3, $4, $5, $6);}
  | opt_modifier val_var opt_typeParameters multivariable_variableDeclaration opt_eq_exp {$$ = alctree(1012, "propertyDeclaration", 5, $1, $2, $3, $4, $5 );}

  ;
  

opt_typeParameters:
    typeParameters  {$$ = alctree(1012, "opt_typeParameters", 1, $1);} 
  | /* empty */ {$$ = NULL;}    
;

opt_comma:
    COMMA {$$ = $1;}
  | /* empty */ {$$ = NULL;}
  ;
typeParameters:
    LANGLE typeParameter multi_typeParameter opt_comma RANGLE {$$ = alctree(1012, "typeParameters", 5, $1, $2, $3, $4, $5);}
;

typeParameter:
    simpleIdentifier  {$$ = alctree(1012, "typeParameter", 1, $1);}
;


multi_typeParameter:
  multi_typeParameter COMMA typeParameter   {$$ = alctree(1012, "multi_typeParameter", 3, $1, $2,$3);}
  |  /* empty */ {$$ = NULL;}
;

simpleIdentifier:
  IDENTIFIER 
  | IMPORT  
  | CONST 
;

classDeclaration:
    CONST CLASS simpleIdentifier opt_typeParameters classBody  {  $$ = alctree(1018, "classDeclaration", 5, $1, $2, $3,$4,$5);}
    |CLASS simpleIdentifier opt_typeParameters classBody  {$$ = alctree(1018, "classDeclaration", 4, $1, $2, $3,$4);}

/* Variable Declaration */
variableDeclaration:
    type COLON type  {$$ = alctree(1011, "variableDeclaration", 1, $1);}
  | type  {$$ = alctree(1011, "variableDeclaration", 1, $1);}

;
multiVariableDeclaration:
   LPAREN variableDeclaration multi_comma_variableDeclaration opt_comma RPAREN {$$ = alctree(1011, "multiVariableDeclaration", 5, $1, $2, $3, $4, $5);}

multi_comma_variableDeclaration:
  multi_comma_variableDeclaration COMMA variableDeclaration  {$$ = alctree(1011, "multi_comma_variableDeclaration", 3, $1, $2, $3);}
  | { /* epsilon production */ }
  ;



assignmentAndOperator:
    ADD_ASSIGNMENT  {$$ = $1;}
    | SUB_ASSIGNMENT  {$$ = $1;}
    | MULT_ASSIGNMENT {$$ = $1;}
    | DIV_ASSIGNMENT  {$$ = $1;}
    | MOD_ASSIGNMENT  {$$ = $1;}
    ;

assignableExpression:
  prefixUnaryExpression {$$ = alctree (1011, "assignableExpression", 1, $1);}
  | parenthesizedAssignableExpression {$$ = alctree (1011, "assignableExpression", 1, $1);}

multi_unaryPrefix:
  multi_unaryPrefix prefixUnaryOperator {$$ = alctree(1011, "multi_unaryPrefix", 2, $1, $2);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;
prefixUnaryOperator:
    ADD  {$$ = $1;}
    | SUB  {$$ = $1;}
    | INCR  {$$ = $1;}
    | DECR  {$$ = $1;}
    |EXCL_NO_WS EXCL_NO_WS { $$ = alctree(1011, "prefixUnaryOperator", 2, $1,$2);}
    ;


prefixUnaryExpression:
  multi_unaryPrefix postfixUnaryExpression  {$$ = alctree(1011, "prefixUnaryExpression", 2, $1, $2);}
  ;

parenthesizedAssignableExpression:
    LPAREN assignableExpression RPAREN  {$$ = alctree(1011, "parenthesizedAssignableExpression", 3, $1, $2, $3);}
    ;
/* Assignment */
assignment:
  directly_assign expression  {$$ = alctree(1011, "assignment", 2, $1, $2);}
  ;

directly_assign:
    directlyAssignableExpression ASSIGNMENT {$$ = alctree(1011, "directly_assign", 2, $1, $2);}
    | assignableExpression assignmentAndOperator  {$$ = alctree(1011, "directly_assign", 2, $1, $2);}
    ;

assignableSuffix:
    indexingSuffix  {$$ = alctree(1011, "assignableSuffix", 1, $1);}
    | typeArguments {$$ = alctree(1011, "assignableSuffix", 1, $1);}
    ;

typeArguments:
    LANGLE typeProjection multi_comma_typeProjection opt_comma RANGLE  {$$ = alctree(1011, "typeArguments", 5, $1, $2, $3, $4, $5);}
    ; 

multi_comma_typeProjection: 
  multi_comma_typeProjection COMMA typeProjection {$$ = alctree(1011, "multi_comma_typeProjection", 3, $1, $2, $3);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;


typeProjection:
  type  {$$ = alctree(1011, "typeProjection", 1, $1);}
  | MULT  {$$ = $1;}  
  ;
directlyAssignableExpression:
    postfixUnaryExpression assignableSuffix {$$ = alctree(1011, "directlyAssignableExpression", 2, $1, $2);}
    | simpleIdentifier  {$$ = alctree(1011, "directlyAssignableExpression", 1, $1);}
    | parenthesizedDirectlyAssignableExpression {$$ = alctree(1011, "directlyAssignableExpression", 1, $1);}
    ;

parenthesizedDirectlyAssignableExpression:
    LPAREN assignableExpression RPAREN  {$$ = alctree(1011, "parenthesizedDirectlyAssignableExpression", 3, $1, $2, $3);}
    ;

multi_postfixUnarySuffix:
    multi_postfixUnarySuffix postfixUnarySuffix {$$ = alctree(1011, "multi_postfixUnarySuffix", 2, $1, $2);}
    | { /* epsilon production */ }  {$$ = NULL;}
    ;
postfixUnaryExpression:
    primaryExpression multi_postfixUnarySuffix  {$$ = alctree(1011, "postfixUnaryExpression", 2, $1, $2);}
    ;

postfixUnarySuffix:
  postfixUnaryOperator  {$$ = alctree(1011, "postfixUnarySuffix", 1, $1);}
  |indexingSuffix   {$$ = alctree(1011, "postfixUnarySuffix", 1, $1);}
  |callSuffix  {$$ = alctree(1011, "postfixUnarySuffix", 1, $1);}
  |navigationSuffix {$$ = alctree(1011, "postfixUnarySuffix", 1, $1);}
  ;
  
identifier_expression_class:
  simpleIdentifier {$$ = alctree(1011, "identifier_expression_class", 1, $1);}
  | parenthesizedExpression  {$$ = alctree(1011, "identifier_expression_class", 1, $1);}
  | CLASS {$$ = $1;}
  ;

navigationSuffix:
  memberAccessOperator identifier_expression_class {$$ = alctree(1011, "navigationSuffix", 2, $1, $2);}
  ;

memberAccessOperator:
  DOT {$$ = $1;}
  | QUEST_NO_WS DOT {$$ = alctree(1011, "memberAccessOperator", 2, $1, $2);}
  ;

postfixUnaryOperator:
    INCR  { $$ = $1;}
    | DECR  { $$ = $1;}
    | EXCL_NO_WS EXCL_NO_WS { $$ = alctree(1011, "postfixUnaryOperator", 2, $1,$2);}
    ;

multi_comma_expression:
  multi_comma_expression COMMA expression {$$ = alctree(1011, "multi_comma_expression", 3, $1, $2, $3);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;

indexingSuffix:
    LSQUARE expression multi_comma_expression opt_comma RSQUARE {$$ = alctree(1011, "indexingSuffix", 5, $1, $2, $3, $4, $5);}
    ;

callSuffix:
  valueArguments  {$$ = alctree(1011, "callSuffix", 1, $1);}
  ;
  
multi_comma_valueArgument:
  multi_comma_valueArgument COMMA valueArgument {$$ = alctree(1011, "multi_comma_valueArgument", 3, $1, $2, $3);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;
opt_valueArgument:
  valueArgument multi_comma_valueArgument opt_comma {$$ = alctree(1011, "opt_valueArgument", 3, $1, $2, $3);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;

valueArguments:
    LPAREN opt_valueArgument RPAREN {$$ = alctree(1011, "valueArguments", 3, $1, $2, $3);}
    ; 

opt_simpleIdentifier_EQ:
    simpleIdentifier ASSIGNMENT {$$ = alctree(1011, "opt_simpleIdentifier_EQ", 2, $1, $2);}
    | { /* epsilon production */ }  {$$ = NULL;}
    ;

opt_Multi:  
  MULT  {$$ = $1;}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;

valueArgument:
  opt_simpleIdentifier_EQ opt_Multi expression  {$$ = alctree(1011, "valueArgument", 3, $1, $2, $3);}
  ;

parenthesizedExpression:
    LPAREN expression RPAREN  {$$ = alctree(1011, "parenthesizedExpression", 3, $1, $2, $3);}
    ;


jumpExpression:
  RETURN expression {alctree(1011, "jumpExpression", 2, $1, $2);}
  | RETURN
  | CONTINUE
  | BREAK
  ;


ifExpression:
    IF LPAREN expression RPAREN ELSE SEMICOLON controlStructureBody {$$ = alctree(1011, "ifExpression", 7, $1, $2, $3, $4, $5, $6,$7);}
  | IF LPAREN expression RPAREN controlStructureBody ELSE controlStructureBody  {$$ = alctree(1011, "ifExpression", 7, $1, $2, $3, $4, $5, $6,$7);}
  | IF LPAREN expression RPAREN controlStructureBody SEMICOLON ELSE controlStructureBody  {$$ = alctree(1011, "ifExpression", 8, $1, $2, $3, $4, $5, $6,$7,$8);}
  | IF LPAREN expression RPAREN SEMICOLON ELSE controlStructureBody  {$$ = alctree(1011, "ifExpression", 7, $1, $2, $3, $4, $5, $6,$7);}
  | IF LPAREN expression RPAREN controlStructureBody  {$$ = alctree(1011, "ifExpression", 5, $1, $2, $3, $4, $5);}
  | IF LPAREN expression RPAREN SEMICOLON
  ;

collectionLiteral:
  LPAREN RPAREN {$$ = alctree(1011, "collectionLiteral", 2, $1, $2);}
  | LPAREN expression COMMA RPAREN {$$ = alctree(1011, "collectionLiteral", 4, $1, $2, $3, $4);}
  | LPAREN expression multi_comma_expression RPAREN {$$ = alctree(1011, "collectionLiteral", 4, $1, $2, $3, $4);}
  | LSQUARE expression multi_comma_expression COMMA RSQUARE {$$ = alctree(1011, "collectionLiteral", 5, $1, $2, $3, $4, $5);}
  ;



multi_whenEntry:
  multi_whenEntry whenEntry {$$ = alctree(1011, "multi_whenEntry", 2, $1, $2);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;

whenExpression:
  WHEN whenSubject LCURL multi_whenEntry RCURL {$$ = alctree(1011, "whenExpression", 5, $1, $2, $3, $4, $5);}
  | WHEN LCURL multi_whenEntry RCURL {$$ = alctree(1011, "whenExpression", 4, $1, $2, $3, $4);}
   ;

whenSubject:
  LPAREN expression RPAREN {$$ = alctree(1011, "whenSubject", 3, $1, $2, $3);}
  |  LPAREN VAL variableDeclaration ASSIGNMENT expression RPAREN {$$ = alctree(1011, "whenSubject", 6, $1, $2, $3, $4, $5, $6);}

multi_comma_whenCondition:
  multi_comma_whenCondition COMMA whenCondition {$$ = alctree(1011, "multi_comma_whenCondition", 3, $1, $2, $3);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;

whenEntry:
  whenCondition multi_comma_whenCondition ARROW controlStructureBody  {$$ = alctree(1011, "whenEntry", 4, $1, $2, $3, $4);}
  | whenCondition multi_comma_whenCondition COMMA ARROW controlStructureBody  {$$ = alctree(1011, "whenEntry", 5, $1, $2, $3, $4, $5);}
  | ELSE ARROW controlStructureBody SEMICOLON {$$ = alctree(1011, "whenEntry", 4, $1, $2, $3, $4);}
  | ELSE ARROW controlStructureBody   {$$ = alctree(1011, "whenEntry", 3, $1, $2, $3);}
  ;

whenCondition:
  expression {$$ = alctree(1011, "whenCondition", 1, $1);}
  | rangeTest {$$ = alctree(1011, "whenCondition", 1, $1);}
  ;

rangeTest:
  IN expression {$$ = alctree(1011, "rangeTest", 2, $1, $2);}
  ;
   
/* Function Call */
functionCall:
    IDENTIFIER LPAREN functionArguments RPAREN  {$$ = alctree(1013, "functionCall", 4, $1, $2, $3,$4);}
;

/* Function Arguments */
functionArguments:
  expression  {$$ = alctree(1014, "functionArguments", 1, $1);}
  |functionArguments COMMA expression  {$$ = alctree(1014, "functionArguments", 3, $1, $2, $3);}
  |/* empty */{$$ = NULL;}
;

variable_multivariable:
  variableDeclaration{$$ = alctree(1015,"variable_multivariable", 1, $1);}
  | multiVariableDeclaration  {$$ = alctree(1015,"variable_multivariable", 1, $1);}
  ;

control_structure_body_or_comma:
  controlStructureBody  {$$ = alctree(1015,"control_structure_body_or_comma", 1, $1);}
  | COMMA {$$ = $1;}
  ;
/* Loops */
loopStatement:
    WHILE LPAREN expression RPAREN control_structure_body_or_comma  {$$ = alctree(1015,"loopStatement", 5 ,$1, $2, $3, $4,$5);}
  | FOR LPAREN variable_multivariable IN expression RPAREN opt_controStructureBody  {$$ = alctree(1015,"loopStatement", 6 ,$1, $2, $3, $4,$5,$6);}
;


opt_controStructureBody:
  controlStructureBody  {$$ = alctree(1017, "opt_controStructureBody", 1, $1);}
  | {$$ = NULL;}
  ;

controlStructureBody:
  block  {$$ = alctree(1017, "controlStructureBody", 1, $1);}
  | statement {$$ = alctree(1017, "controlStructureBody", 1, $1);}
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

common_literal:
  INTEGER_LITERAL
  |STRING_LITERAL
  |FLOAT_LITERAL
/* Expressions */

expression:
    functionCall  {$$ = alctree(1024, "expression", 1, $1);}
  | IDENTIFIER    {$$ = $1; printnode($1);}
  | common_literal {$$ = alctree(1024, "expression", 1, $1);}
;

literalConstant:
  BOOLEAN_LITERAL
  | common_literal  {$$ = alctree(1011, "literalConstant", 1, $1);}
  | FLOAT_LITERAL
  | NULL_LITERAL
  | CHARACTER_LITERAL
  ;

primaryExpression:
  simpleIdentifier {$$ = alctree(1011, "primaryExpression", 1, $1);}
  | literalConstant {$$ = alctree(1011, "primaryExpression", 1, $1);}
  | parenthesizedExpression {$$ = alctree(1011, "primaryExpression", 1, $1);}
  | jumpExpression  {$$ = alctree(1011, "primaryExpression", 1, $1);}
  | collectionLiteral {$$ = alctree(1011, "primaryExpression", 1, $1);}
  | ifExpression  {$$ = alctree(1011, "primaryExpression", 1, $1);}
  | whenExpression  {$$ = alctree(1011, "primaryExpression", 1, $1);}
  ;
%%
