%option noinput
%option nounput  
%option yylineno 
%{
#include "token.h"
int line = 1;
void set_token(int category, const char* text);

struct token {
   int category;
   char *text; 
   int lineno;
   char *filename;
   int ival;
   double dval;
   char *sval;
};

extern struct token yytoken;

%}
WS                      [ \t\f]+
CR                      \r
NL                      \n
LF                      \f
SHEBANG_LINE            "#!"[^\r\n]*
float_literal           [0-9]*"."[0-9]+[lL]?
scientific              [0-9]+"."[0-9]+[eE][+-]?[0-9]+
int_literal             [0-9]+[lL]?
hex_literal             0[xX][0-9a-fA-F]+                
LineComment             \/\/[^\r\n]*
DelimitedComment        (\/\*([^*]|\*[^\/])*\*\/)
hidden                  ((\/\*([^*]|\*[^\/])*\*\/)|\/\/[^\r\n]*|[ \t\f]+)
char_literals           \'[A-Za-z0-9]\'
line_string_literals    \"([^\"\\]|\\.)*\"
multiline_string_literals     \"\"\"([^"]|\n|\"[^"]|\"\"[^"])*\"\"\" 
escaped                 "\\"("t"|"n"|"b"|"r"|"0"|"$"|\\)
boolean_literal         "true"|"false"
unsupported             "as?"|"as"|"class"|"!in"|"is"|"!is"|"object"|"package"|"super"|"this"|"throw"|"typealias"|"try"|"typeof"|"tfield"|"it"
unsupported_op          "@"|"$"|"$"|"`"|"\\"|"#"
unsupported_bit         "~"|">>"|"<<"|"&="|"|="|"^="|">>="|"<<="|"&"|"|"|"^"
unsupported_word        "by"|"catch"|"constructor"|"delagate"|"dynamic"|"field"|"file"|"finally"|"get"|"init"|"param"|"property"|"reciever"|"set"|"setparam"|"value"|"where"           
%%
{scientific}            { fprintf(stderr, "%s:%d: error: Scientific Notation '%s' is not supported by K0 \n", yytoken.filename, yylineno, yytext); exit(1);}
{int_literal}           { set_token(IntegerLiteral, yytext); return IntegerLiteral;}
{float_literal}         { set_token(FloatLiteral, yytext); return FloatLiteral;}
{hex_literal}           { set_token(FloatLiteral, yytext); return FloatLiteral;}
{LineComment}           { }
{DelimitedComment}      { }
{char_literals}         { set_token(CharacterLiteral, yytext); return CharacterLiteral; }
{line_string_literals}  { set_token(stringLiteral, yytext); return stringLiteral; }
{multiline_string_literals}     { set_token(stringLiteral, yytext); return stringLiteral; }
{boolean_literal}       { set_token(BooleanLiteral, yytext); return BooleanLiteral; }
{escaped}       { set_token(EscapedIdentifier, yytext); return EscapedIdentifier; }
"+"             { set_token(ADD, yytext); return ADD; }
"-"             { set_token(SUB, yytext); return SUB; }
"/"             { set_token(DIV, yytext); return DIV; }
"*"             { set_token(MULT, yytext); return MULT; }
"%"             { set_token(MOD, yytext); return MOD; }
"="             { set_token(ASSIGNMENT, yytext); return ASSIGNMENT; }
"+="            { set_token(ADD_ASSIGNMENT, yytext); return ADD_ASSIGNMENT; }
"-="            { set_token(SUB_ASSIGNMENT, yytext); return SUB_ASSIGNMENT; }
"*="            { set_token(MULT_ASSIGNMENT, yytext); return MULT_ASSIGNMENT; }
"/="            { set_token(DIV_ASSIGNMENT, yytext); return DIV_ASSIGNMENT; }
"%="            { set_token(MOD_ASSIGNMENT, yytext); return MOD_ASSIGNMENT; }
"{"             { set_token(LCURL, yytext); return LCURL; }
"}"             { set_token(RCURL, yytext); return RCURL; }
"]"             { set_token(RSQUARE, yytext); return RSQUARE; }
"["             { set_token(LSQUARE, yytext); return LSQUARE; }
"("             { set_token(LPAREN, yytext); return LPAREN; }
")"             { set_token(RPAREN, yytext); return RPAREN; }
","             { set_token(COMMA, yytext); return COMMA;}
"."             { set_token(DOT, yytext); return DOT;}
"++"            { set_token(INCR, yytext); return INCR;}
"--"            { set_token(DECR, yytext); return DECR;}
"&&"            { set_token(CONJ, yytext); return CONJ;}
"||"            { set_token(DISJ, yytext); return DISJ;}
"!"             { set_token(EXCL_NO_WS, yytext); return EXCL_NO_WS;}
"!!"            { set_token(DOUBLE_BANG, yytext); return DOUBLE_BANG;}
":"             { set_token(COLON, yytext); return COLON;}
";"             { set_token(SEMICOLON, yytext); return SEMICOLON;}
"->"            { set_token(ARROW, yytext); return ARROW;}
"=>"            { set_token(DOUBLE_ARROW, yytext); return DOUBLE_ARROW;}
"::"            { set_token(COLONCOLON, yytext); return COLONCOLON;}
".."            { set_token(RANGE, yytext); return RANGE;}
"?"{hidden}     { set_token(QUEST_WS, yytext); return QUEST_WS;}
"?"             { set_token(QUEST_NO_WS, yytext); return QUEST_NO_WS;}
"?."            { set_token(QUEST_DOT, yytext); return QUEST_DOT;}
"?:"            { set_token(QUEST_COLON, yytext); return QUEST_COLON;}
"<"             { set_token(LANGLE, yytext); return LANGLE;}
">"             { set_token(RANGLE, yytext); return RANGLE;}
"<="            { set_token(LE, yytext); return LE;}
">="            { set_token(GE, yytext); return GE;}
"!="            { set_token(EXCL_EQ, yytext); return EXCL_EQ;}
"!=="           { set_token(EXCL_EQEQ, yytext); return EXCL_EQEQ;}
"=="            { set_token(EQEQ, yytext); return EQEQ;}
"==="           { set_token(EQEQEQ, yytext); return EQEQEQ;}
"\'"            { set_token(SINGLE_QUOTE, yytext); return SINGLE_QUOTE;}
"if"            { set_token(IF, yytext); return IF;}
"else"          { set_token(ELSE, yytext); return ELSE;}
"when"          { set_token(WHEN, yytext); return WHEN;}
"while"         { set_token(WHILE, yytext); return WHILE;}
"for"           { set_token(FOR, yytext); return FOR;}
"do"            { set_token(DO, yytext); return DO;}
"break"         { set_token(BREAK, yytext); return BREAK;}
"continue"      { set_token(CONTINUE, yytext); return CONTINUE;}
"in"            { set_token(IN, yytext); return IN;}
"return"        { set_token(RETURN, yytext); return RETURN;}
"fun"           { set_token(FUN, yytext); return FUN;}
"var"           { set_token(VAR, yytext); return VAR;}
"val"           { set_token(VAL, yytext); return VAL;}
"import"        { set_token(IMPORT, yytext); return IMPORT;}
"const"         { set_token(CONST, yytext); return CONST;}
"null"          { set_token(NullLiteral, yytext); return NullLiteral;}
\'[A-Za-z0-9]+\'        { fprintf(stderr, "%s:%d: error:'%s' char literal cannot have more than 1 character\n", yytoken.filename, yylineno, yytext); exit(1);}
{unsupported}   { fprintf(stderr, "%s:%d: error: the reserved word '%s' is not supported by K0 \n", yytoken.filename, yylineno, yytext); exit(1);}
{unsupported_op}        { fprintf(stderr, "%s:%d: error: punctuation '%s' is not supported by K0 \n", yytoken.filename, yylineno, yytext); exit(1); }
{unsupported_bit}       { fprintf(stderr, "%s:%d: error: the operator '%s' is not supported by K0 \n", yytoken.filename, yylineno, yytext); exit(1);}
{unsupported_word}      { fprintf(stderr, "%s:%d: error: the keyword '%s' is not supported by K0 \n", yytoken.filename, yylineno, yytext); exit(1);}
\n		{ line++; }
{WS}            { }
[A-Za-z0-9]+	{ set_token(Identifier, yytext); return Identifier;}
.		{ fprintf(stderr, "%s:%d: error: '%s' is not a K0 reserved word\n", yytoken.filename, yylineno, yytext); exit(1); }
%%
