%{
    extern int yylex(void);
    extern int yyerror(char *s);
    #define YYDEBUG 1
    #include "tree.h"
    void printnode();
    struct tree *root;
    void treeprint(struct tree *t, int depth);
    extern void eat_to_newline(void);
    struct tree *alctree(int prodrule, const char *symbolname, int nkids, ...);
    extern void printsyms(struct tree *t);
    #define BAD_TOKEN 257  // Define BAD_TOKEN with the appropriate value
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
%token <treeptr> HEX_LITERAL BIN_LITERAL UNSIGNED_LITERAL LONG_LITERAL  BOOLEAN_LITERAL STRING_LITERAL INT FLOAT BOOLEAN CHAR STRING BYTE T_EOF TYPELITERAL 
%token <treeptr> MULT MOD DIV ADD SUB
%token <treeptr> IDENTIFIER
%debug 

%type <treeptr> program topLevelObjects topLevelObject functionDeclaration  type functionBody block statements statement variableDeclaration assignment functionCall functionArguments  
%type <treeptr> loopStatement  expression  disjunction  conjunction equality comparison genericCallLikeComparison elvisExpression rangeExpression primaryExpression dotExpression
%type <treeptr>  declaration opt_typeParameters opt_comma typeParameters typeParameter multi_typeParameter simpleIdentifier classDeclaration semis_statement optional_statement_sequence parameter  rangeTest 
%type <treeptr> functionValueParameter functionValueParameters opt_functionValueParameter multi_comma_functionParameter opt_functionBody opt_eq_exp  parenthesizedType 
%type <treeptr> typeRef_parenthesizedType nullableType multi_quest userType multi_dot_simpleUserType simpleUserType opt_modifier val_var multivariable_variableDeclaration parenthesizedExpression propertyDeclaration navigationSuffix identifier_expression_class
%type <treeptr> memberAccessOperator typeArguments directlyAssignableExpression parenthesizedDirectlyAssignableExpression multi_postfixUnarySuffix postfixUnaryExpression postfixUnarySuffix postfixUnaryOperator multi_comma_expression callSuffix controlStructureBody 
%type <treeptr>  control_structure_body_or_comma semis variable_multivariable valueArgument opt_Multi opt_simpleIdentifier_EQ valueArguments opt_valueArgument multi_comma_valueArgument assignableSuffix multiVariableDeclaration multi_comma_variableDeclaration
%type <treeptr> directly_assign classMembers  classBody classMember opt_colon_type  assignableExpression assignmentAndOperator prefixUnaryExpression parenthesizedAssignableExpression indexingSuffix multi_unaryPrefix prefixUnaryOperator multi_comma_typeProjection typeProjection equality_operator
%type <treeptr> collectionLiteral whenCondition whenSubject whenEntry multi_comma_whenCondition multi_whenEntry whenExpression comparison_operator additiveExpression multiplicativeExpression jumpExpression ifExpression controls
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
    declaration {$$ = alctree(1002, "topLevelObject", 1, $1);}
 ;

opt_functionBody:
    functionBody {$$ = alctree(1003, "opt_functionBody", 1, $1);}
  | /* empty */ {$$ = NULL;}
  ;

opt_colon_type:
  COLON type {$$ = alctree(1003, "opt_colon_type", 2, $1, $2);}
  | /* empty */ {$$ = NULL;}
  ;

/* Function Declaration */
functionDeclaration:
    FUN opt_typeParameters nullableType DOT simpleIdentifier functionValueParameters opt_colon_type opt_functionBody {$$ = alctree(1004, "functionDeclaration", 8, $1, $2, $3, $4, $5, $6, $7, $8);}
    | FUN opt_typeParameters simpleIdentifier functionValueParameters opt_colon_type opt_functionBody {$$ = alctree(1004, "functionDeclaration",6, $1, $2, $3, $4, $5, $6);}

;

functionValueParameters:
  LPAREN  opt_functionValueParameter RPAREN {$$ = alctree(1005, "functionValueParameters", 3, $1, $2, $3);}
  ;

functionValueParameter:
  parameter opt_eq_exp {$$ = alctree(1006, "functionValueParameter", 2, $1, $2);}
  ;
  
parameter:
  simpleIdentifier COLON type {$$ = alctree(1007, "parameter", 3, $1, $2, $3);}
  ;
  
multi_comma_functionParameter:
  multi_comma_functionParameter COMMA functionValueParameter {$$ = alctree(1008, "multi_comma_functionParameter", 3, $1, $2,$3);}
  | /* empty */ {$$ = NULL;}
  ;

opt_functionValueParameter:
  functionValueParameter multi_comma_functionParameter COMMA {$$ = alctree(1009, "opt_functionValueParameter", 3, $1, $2, $3);}
  |functionValueParameter multi_comma_functionParameter  {$$ = alctree(1009, "opt_functionValueParameter", 2, $1, $2);}
  | /* empty */ {$$ = NULL;}
  ;

/* Type */
type:
  nullableType {$$ = alctree(1010, "type", 1, $1);}
  |TYPELITERAL {$$ = $1;}
;

/* Function Body */
functionBody:
    block {$$ = alctree(1011, "functionBody", 1, $1);}
  | ASSIGNMENT expression SEMICOLON {$$ = alctree(1011, "functionBody", 3, $1, $2, $3);}
;

/* Block of Code */
block:
    LCURL statements RCURL  {$$ = alctree(1012, "block", 3, $1, $2, $3);  }
;


semis:
  SEMICOLON
  | {$$ = NULL;}
  ; 

semis_statement:
  semis_statement semis statement {$$ = alctree(1013, "semis_statement", 3, $1, $2, $3);}
	|  {$$ = NULL;}
	;
 

optional_statement_sequence:
     statement semis_statement  {$$ = alctree(1014, "optional_statement_sequence", 2, $1, $2);}
	|   {$$ = NULL;}
	;

statements:
  optional_statement_sequence  {$$ = alctree(1015, "statements", 1, $1);}
	;

/* Statement */

statement:
    declaration semis{$$ = alctree(1016, "statement", 2,$1,$2); }
  | assignment semis  {$$ = alctree(1016, "statement", 2,$1,$2); }
  | expression semis  {$$ = alctree(1016, "statement", 2,$1,$2); }
  | loopStatement semis{$$ = alctree(1016, "statement", 2,$1,$2); }
;

declaration:
  classDeclaration {$$ = alctree(1017, "declaration", 1, $1);}
  |functionDeclaration {$$ = alctree(1017, "declaration", 1, $1);}
  | propertyDeclaration {$$ = alctree(1017, "declaration", 1, $1);}
  ;

val_var:
  VAR {$$ = $1;}
  | VAL {$$ = $1;}
  ;

opt_modifier:
  CONST {$$ = $1;}
  | { /* epsilon production */ } {$$ = NULL;}
  ;
 

parenthesizedType:
  LPAREN type RPAREN {$$ = alctree(1019, "parenthesizedType", 3, $1, $2, $3);}
  ;



multi_dot_simpleUserType:
  multi_dot_simpleUserType DOT simpleUserType {$$ = alctree(1020, "multi_dot_simpleUserType", 3, $1, $2, $3);}
  | { /* epsilon production */ } {$$ = NULL;}
  ;

userType:
  simpleUserType multi_dot_simpleUserType {$$ = alctree(1021, "userType", 2, $1, $2);}
  ;
 

simpleUserType:
  simpleIdentifier typeArguments{$$ = alctree(1022, "simpleUserType", 2, $1,$2);}
  |simpleIdentifier {$$ = alctree(1022, "simpleUserType", 1, $1);}
  ;


multi_quest:
  multi_quest QUEST_NO_WS {$$ = alctree(1023, "multi_quest", 2, $1, $2);}
  | { /* epsilon production */ } {$$ = NULL;}
  ;
nullableType:
  typeRef_parenthesizedType multi_quest {$$ = alctree(1024, "nullableType", 2, $1, $2);}
  ;

typeRef_parenthesizedType:
  parenthesizedType {$$ = alctree(1025, "typeRef_parenthesizedType", 1, $1);}
  |  userType {$$ = alctree(1025, "typeRef_parenthesizedType", 1, $1);} //TypeReferfence
  ;
 

opt_eq_exp:
  ASSIGNMENT expression {$$ = alctree(1026, "opt_eq_exp", 2, $1, $2);} 
  | { /* epsilon production */ } {$$ = NULL;}
  ;


multivariable_variableDeclaration:
  variableDeclaration {$$ = alctree(1027, "multivariable_variableDeclaration", 1, $1);}
  | multiVariableDeclaration {$$ = alctree(1027, "multivariable_variableDeclaration", 1, $1);}
  ;

propertyDeclaration:
    opt_modifier val_var opt_typeParameters nullableType DOT multivariable_variableDeclaration opt_eq_exp SEMICOLON {$$ = alctree(10028, "propertyDeclaration", 8, $1, $2, $3, $4, $5, $6, $7,$8);}
  | opt_modifier val_var opt_typeParameters multivariable_variableDeclaration opt_eq_exp SEMICOLON {$$ = alctree(1028, "propertyDeclaration", 6, $1, $2, $3, $4, $5, $6);}
  | opt_modifier val_var opt_typeParameters multivariable_variableDeclaration opt_eq_exp {$$ = alctree(1028, "propertyDeclaration", 5, $1, $2, $3, $4, $5 );}
  ;
  

opt_typeParameters:
    typeParameters  {$$ = alctree(1029, "opt_typeParameters", 1, $1);} 
  | /* empty */ {$$ = NULL;}    
;

opt_comma:
    COMMA {$$ = $1;}
  | /* empty */ {$$ = NULL;}
  ;
typeParameters:
    LANGLE typeParameter multi_typeParameter opt_comma RANGLE {$$ = alctree(1030, "typeParameters", 5, $1, $2, $3, $4, $5);}
;

typeParameter:
    simpleIdentifier  {$$ = alctree(1031, "typeParameter", 1, $1);}
;


multi_typeParameter:
  multi_typeParameter COMMA typeParameter   {$$ = alctree(1032, "multi_typeParameter", 3, $1, $2,$3);}
  |  /* empty */ {$$ = NULL;}
;

simpleIdentifier:
  IDENTIFIER 
;

classDeclaration:
    CONST CLASS simpleIdentifier opt_typeParameters classBody  {  $$ = alctree(1033, "classDeclaration", 5, $1, $2, $3,$4,$5);}
    |CLASS simpleIdentifier opt_typeParameters classBody  {$$ = alctree(1033, "classDeclaration", 4, $1, $2, $3,$4);}

/* Variable Declaration */
variableDeclaration:
    type COLON type  {$$ = alctree(1034, "variableDeclaration", 3, $1,$2,$3 );}
  | type  {$$ = alctree(1034, "impvariableDeclaration", 1, $1);}

;
multiVariableDeclaration:
   LPAREN variableDeclaration multi_comma_variableDeclaration opt_comma RPAREN {$$ = alctree(1035, "multiVariableDeclaration", 5, $1, $2, $3, $4, $5);}

multi_comma_variableDeclaration:
  multi_comma_variableDeclaration COMMA variableDeclaration  {$$ = alctree(1036, "multi_comma_variableDeclaration", 3, $1, $2, $3);}
  | { /* epsilon production */ }
  ;



classBody:
    LCURL classMembers RCURL  {$$ = alctree(1037, "classBody", 3, $1, $2, $3);}
;


assignmentAndOperator:
    ADD_ASSIGNMENT  {$$ = $1;}
    | SUB_ASSIGNMENT  {$$ = $1;}
    | MULT_ASSIGNMENT {$$ = $1;}
    | DIV_ASSIGNMENT  {$$ = $1;}
    | MOD_ASSIGNMENT  {$$ = $1;}
    ;

assignableExpression:
  prefixUnaryExpression {$$ = alctree (1038, "assignableExpression", 1, $1);}
  | parenthesizedAssignableExpression {$$ = alctree (1038, "assignableExpression", 1, $1);}

multi_unaryPrefix:
  multi_unaryPrefix prefixUnaryOperator {$$ = alctree(1039, "multi_unaryPrefix", 2, $1, $2);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;
prefixUnaryOperator:
    ADD  {$$ = $1;}
    | SUB  {$$ = $1;}
    | INCR  {$$ = $1;}
    | DECR  {$$ = $1;}
    |EXCL_NO_WS EXCL_NO_WS { $$ = alctree(1040, "prefixUnaryOperator", 2, $1,$2);}
    ;


prefixUnaryExpression:
  multi_unaryPrefix postfixUnaryExpression  {$$ = alctree(1041, "prefixUnaryExpression", 2, $1, $2);}
  ;

parenthesizedAssignableExpression:
    LPAREN assignableExpression RPAREN  {$$ = alctree(1042, "parenthesizedAssignableExpression", 3, $1, $2, $3);}
    ;
/* Assignment */
assignment:
  directly_assign expression  {$$ = alctree(1043, "assignment", 2, $1, $2);}
  ;

directly_assign:
    directlyAssignableExpression ASSIGNMENT {$$ = alctree(1044, "directly_assign", 2, $1, $2);}
    | assignableExpression assignmentAndOperator  {$$ = alctree(1044, "directly_assign", 2, $1, $2);}
    ;

assignableSuffix:
    indexingSuffix  {$$ = alctree(1045, "assignableSuffix", 1, $1);}
    | typeArguments {$$ = alctree(1045, "assignableSuffix", 1, $1);}
    ;

typeArguments:
    LANGLE typeProjection multi_comma_typeProjection opt_comma RANGLE  {$$ = alctree(1046, "typeArguments", 5, $1, $2, $3, $4, $5);}
    ; 

multi_comma_typeProjection: 
  multi_comma_typeProjection COMMA typeProjection {$$ = alctree(1047, "multi_comma_typeProjection", 3, $1, $2, $3);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;


typeProjection:
  type  {$$ = alctree(1048, "typeProjection", 1, $1);}
  | MULT  {$$ = $1;}  
  ;
directlyAssignableExpression:
    postfixUnaryExpression assignableSuffix {$$ = alctree(1049, "directlyAssignableExpression", 2, $1, $2);}
    | simpleIdentifier  {$$ = alctree(1049, "directlyAssignableExpression", 1, $1);}
    | parenthesizedDirectlyAssignableExpression {$$ = alctree(1049, "directlyAssignableExpression", 1, $1);}
    ;

parenthesizedDirectlyAssignableExpression:
    LPAREN assignableExpression RPAREN  {$$ = alctree(1050, "parenthesizedDirectlyAssignableExpression", 3, $1, $2, $3);}
    ;

multi_postfixUnarySuffix:
    multi_postfixUnarySuffix postfixUnarySuffix {$$ = alctree(1051, "multi_postfixUnarySuffix", 2, $1, $2);}
    | { /* epsilon production */ }  {$$ = NULL;}
    ;
postfixUnaryExpression:
    primaryExpression multi_postfixUnarySuffix  {$$ = alctree(1052, "postfixUnaryExpression", 2, $1, $2);}
    ;

postfixUnarySuffix:
  postfixUnaryOperator  {$$ = alctree(1053, "postfixUnarySuffix", 1, $1);}
  |indexingSuffix   {$$ = alctree(1053, "postfixUnarySuffix", 1, $1);}
  |callSuffix  {$$ = alctree(1053, "postfixUnarySuffix", 1, $1);}
  |navigationSuffix {$$ = alctree(1053, "postfixUnarySuffix", 1, $1);}
  ;
  
identifier_expression_class:
  simpleIdentifier {$$ = alctree(1054, "identifier_expression_class", 1, $1);}
  | parenthesizedExpression  {$$ = alctree(1054, "identifier_expression_class", 1, $1);}
  | CLASS {$$ = $1;}
  ;

navigationSuffix:
  memberAccessOperator identifier_expression_class {$$ = alctree(1055, "navigationSuffix", 2, $1, $2);}
  ;

memberAccessOperator:
  DOT {$$ = $1;}
  | QUEST_NO_WS DOT {$$ = alctree(1056, "memberAccessOperator", 2, $1, $2);}
  ;

postfixUnaryOperator:
    INCR  { $$ = $1;}
    | DECR  { $$ = $1;}
    | EXCL_NO_WS EXCL_NO_WS { $$ = alctree(1057, "postfixUnaryOperator", 2, $1,$2);}
    ;

multi_comma_expression:
  multi_comma_expression COMMA expression {$$ = alctree(1058, "multi_comma_expression", 3, $1, $2, $3);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;

indexingSuffix:
    LSQUARE expression multi_comma_expression opt_comma RSQUARE {$$ = alctree(1059, "indexingSuffix", 5, $1, $2, $3, $4, $5);}
    ;

callSuffix:
  valueArguments  {$$ = alctree(1060, "callSuffix", 1, $1);}
  ;
  
multi_comma_valueArgument:
  multi_comma_valueArgument COMMA valueArgument {$$ = alctree(1061, "multi_comma_valueArgument", 3, $1, $2, $3);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;
opt_valueArgument:
  valueArgument multi_comma_valueArgument opt_comma {$$ = alctree(1062, "opt_valueArgument", 3, $1, $2, $3);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;

valueArguments:
    LPAREN opt_valueArgument RPAREN {$$ = alctree(1063, "valueArguments", 3, $1, $2, $3);}
    ; 

opt_simpleIdentifier_EQ:
    simpleIdentifier ASSIGNMENT {$$ = alctree(1064, "opt_simpleIdentifier_EQ", 2, $1, $2);}
    | { /* epsilon production */ }  {$$ = NULL;}
    ;

opt_Multi:  
  MULT  {$$ = $1;}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;

valueArgument:
  opt_simpleIdentifier_EQ opt_Multi expression  {$$ = alctree(1065, "valueArgument", 3, $1, $2, $3);}
  ;

parenthesizedExpression:
    LPAREN expression RPAREN  {$$ = alctree(1066, "parenthesizedExpression", 3, $1, $2, $3);}

    ;

    
ifExpression:
  IF LPAREN expression RPAREN controls {$$ = alctree(1011,"ifExpression",5, $1, $2, $3, $4, $5);}
  ;
  
controls:
  controlStructureBody ELSE controlStructureBody {$$ = alctree(1012,"controls",3,$1, $2, $3);}
  | controlStructureBody {$$ = alctree(1012,"controls",1,$1);}


/* Function Call */
functionCall:
    IDENTIFIER LPAREN functionArguments RPAREN semis   {$$ = alctree(1068, "functionCall", 4, $1, $2, $3,$4);}
    | dotExpression LPAREN functionArguments RPAREN semis {$$ = alctree(1068, "methodCall", 4, $1, $2, $3, $4);}  
;

dotExpression:
    IDENTIFIER DOT IDENTIFIER {$$ = alctree(3000, "dotExpression", 3, $1, $2, $3);}
    | dotExpression DOT IDENTIFIER {$$ = alctree(3000, "dotExpression", 3, $1, $2, $3);}
    ;

/* Function Arguments */
functionArguments:
  expression  {$$ = alctree(1069, "functionArguments", 1, $1);}
  |functionArguments COMMA expression  {$$ = alctree(1070, "functionArguments", 3, $1, $2, $3);}
  |/* empty */{$$ = NULL;}
;

variable_multivariable:
  variableDeclaration{$$ = alctree(1071,"variable_multivariable", 1, $1);}
  | multiVariableDeclaration  {$$ = alctree(1071,"variable_multivariable", 1, $1);}
  ;

control_structure_body_or_comma:
  controlStructureBody  {$$ = alctree(1072,"control_structure_body_or_comma", 1, $1);}
  | COMMA {$$ = $1;}
  ;
/* Loops */
loopStatement:
    WHILE LPAREN expression RPAREN control_structure_body_or_comma  {$$ = alctree(1073,"loopStatement", 5 ,$1, $2, $3, $4,$5);}
    | FOR LPAREN variable_multivariable IN expression RPAREN controlStructureBody  {$$ = alctree(1073,"loopStatement", 7 ,$1, $2, $3, $4,$5,$6,$7);}
    | DO controlStructureBody WHILE LPAREN expression RPAREN  {$$ = alctree(1073,"loopStatement", 6 ,$1, $2, $3, $4,$5,$6);}
;


controlStructureBody:
  block  {$$ = alctree(1074, "controlStructureBody", 1, $1);}
  | statement {$$ = alctree(1074, "controlStructureBody", 1, $1);}
  ;
 

jumpExpression:
  RETURN expression {$$ = alctree(1075, "jumpExpression", 2, $1, $2);}
  | RETURN
  | CONTINUE
  | BREAK
  ;

multi_whenEntry:
  multi_whenEntry whenEntry {$$ = alctree(1076, "multi_whenEntry", 2, $1, $2);}
  |   {$$ = NULL;}
  ;

whenExpression:
  WHEN whenSubject LCURL multi_whenEntry RCURL {$$ = alctree(1077, "whenExpression", 5, $1, $2, $3, $4, $5);}
  | WHEN LCURL multi_whenEntry RCURL {$$ = alctree(1078, "whenExpression", 4, $1, $2, $3, $4);}
   ;

whenSubject:
  LPAREN expression RPAREN {$$ = alctree(1079, "whenSubject", 3, $1, $2, $3);}
  |  LPAREN VAL variableDeclaration ASSIGNMENT expression RPAREN {$$ = alctree(1079, "whenSubject", 6, $1, $2, $3, $4, $5, $6);}

multi_comma_whenCondition:
  multi_comma_whenCondition COMMA whenCondition {$$ = alctree(1080, "multi_comma_whenCondition", 3, $1, $2, $3);}
  | { /* epsilon production */ }  {$$ = NULL;}
  ;

whenEntry:
  whenCondition multi_comma_whenCondition ARROW controlStructureBody  {$$ = alctree(1011, "whenEntry", 4, $1, $2, $3, $4);}
  | whenCondition multi_comma_whenCondition COMMA ARROW controlStructureBody  {$$ = alctree(1011, "whenEntry", 5, $1, $2, $3, $4, $5);}
  | ELSE ARROW controlStructureBody SEMICOLON {$$ = alctree(1011, "whenEntry", 4, $1, $2, $3, $4);}
  | ELSE ARROW controlStructureBody   {$$ = alctree(1011, "whenEntry", 3, $1, $2, $3);}
  ;

whenCondition:
  expression {$$ = alctree(1080, "whenCondition", 1, $1);}
  | rangeTest {$$ = alctree(1080, "whenCondition", 1, $1);}
  ;

rangeTest:
  IN expression {$$ = alctree(1081, "rangeTest", 2, $1, $2);}
  ;

classMembers:
    /* empty */ {$$ = NULL;}
  | classMembers classMember  {$$ = alctree(1082, "classMembers", 2, $1, $2);}
;

classMember:
    functionDeclaration {$$ = alctree(1083, "classMember", 1, $1);}
  | variableDeclaration   {$$ = alctree(1083, "classMember", 1, $1);}
;

/* Expressions */
expression:
  disjunction {$$ = alctree(1086, "expression", 1, $1);}
;

disjunction:
  conjunction {$$ = alctree(1087, "disjuction", 1, $1);}
  | disjunction DISJ conjunction {$$ = alctree(1087, "disjuction", 3, $1, $2, $3);}
  ;

conjunction: 
  equality {$$ = alctree(1088, "conjuction", 1, $1);}
  | conjunction CONJ equality {$$ = alctree(1088, "conjuction", 3, $1, $2, $3);}
  ;

equality:
  comparison {$$ = alctree(1089, "equality", 1, $1);}
    | equality equality_operator comparison {$$ = alctree(1089, "equality", 3, $1, $2, $3);}
    ;

comparison
    : genericCallLikeComparison {$$ = alctree(1090, "comparison", 1, $1);}
    | comparison comparison_operator genericCallLikeComparison {$$ = alctree(1090, "comparison", 3, $1, $2, $3);}
    ;

genericCallLikeComparison
    : elvisExpression {$$ = alctree(1091, "genericCallLikeComparison", 1, $1);}
    | elvisExpression IN elvisExpression {$$ = alctree(1091, "genericCallLikeComparison", 3, $1, $2, $3);}
    ;

elvisExpression
    : rangeExpression {$$ = alctree(1092, "elvisExpression", 1, $1);}
    | elvisExpression QUEST_COLON rangeExpression  {$$ = alctree(1092, "elvisExpression", 3, $1, $2, $3);}
    ;

rangeExpression
    : additiveExpression {$$ = alctree(1093, "rangeExpression", 1, $1);}
    | rangeExpression RANGE additiveExpression {$$ = alctree(1093, "rangeExpression", 3, $1, $2, $3);}
    ;

additiveExpression: 
    multiplicativeExpression {$$ = alctree(1094, "additiveExpression", 1, $1);}
    | additiveExpression ADD multiplicativeExpression {$$ = alctree(1094, "additiveExpression", 3, $1, $2, $3);}
    | additiveExpression SUB multiplicativeExpression {$$ = alctree(1094, "additiveExpression", 3, $1, $2, $3);}
    ;

multiplicativeExpression:
  postfixUnaryExpression {$$ = alctree(1095, "multiplicativeExpression", 1, $1);}
  | multiplicativeExpression MULT postfixUnaryExpression {$$ = alctree(1095, "multiplicativeExpression", 3, $1, $2, $3);}
  | multiplicativeExpression DIV postfixUnaryExpression {$$ = alctree(1095, "multiplicativeExpression", 3, $1, $2, $3);}
  | multiplicativeExpression MOD postfixUnaryExpression {$$ = alctree(1095, "multiplicativeExpression", 3, $1, $2, $3);}
  ; 

primaryExpression:
  parenthesizedExpression { $$ = alctree(1035, "primaryExpression", 1, $1);}
    | simpleIdentifier { $$ = alctree(1035, "primaryExpression", 1, $1);} 
    | functionCall { $$ = alctree(1035, "primaryExpression", 1, $1);}
    | INTEGER_LITERAL 
    | STRING_LITERAL 
    | BOOLEAN_LITERAL
    | FLOAT_LITERAL
    | CHARACTER_LITERAL
    | jumpExpression  {$$ = alctree(1011, "primaryExpression", 1, $1);}
    | collectionLiteral {$$ = alctree(1011, "primaryExpression", 1, $1);}
    | ifExpression {$$ = alctree(1011, "primaryExpression", 1, $1);}
    | whenExpression   {$$ = alctree(1067, "primaryExpression", 1, $1);}
    ; 

collectionLiteral:
  LSQUARE RSQUARE {$$ = alctree(1011, "collectionLiteral", 2, $1, $2);}
  | LSQUARE expression COMMA RSQUARE {$$ = alctree(1011, "collectionLiteral", 4, $1, $2, $3, $4);}
  | LSQUARE expression RSQUARE {$$ = alctree(1011, "collectionLiteral", 3, $1, $2, $3);}
  | LSQUARE expression multi_comma_expression RSQUARE {$$ = alctree(1011, "collectionLiteral", 4, $1, $2, $3, $4);}
  | LSQUARE expression multi_comma_expression COMMA RSQUARE {$$ = alctree(1011, "collectionLiteral", 5, $1, $2, $3, $4, $5);}
  ;


comparison_operator: 
  LANGLE 
  |RANGLE 
  |LE 
  |GE 
  ;

equality_operator:
  EQEQ
  |EQEQEQ
  |EXCL_EQ
  | EXCL_EQEQ
  ;
  
// postfix_unary_operator: 
//   INCR
//   | DECR
//   ;
%%
const char *yyname(int sym)
{ 
   return yytname[sym-RESERVED+3];
}