/* -*-bison-*- */
/* Simple wc implementation in Flex */
%option noyywrap
%option noinput
%option nounput
%option yylineno 
%{
#include "token.h"
%}

spaces_and_tabs         [ \t]+
ExcludeCRLF             [^\r\n]*
LineComment 	        "//"[^\r\n]*
DelimitedComment	"/*"([^*]|"*"+[^/*])*"*"+"/"
DecDigitNoZero          [1-9]
DecDigit                [0-9]
DecDigitOrSeparator     [{DecDigit}_]
NL                      \n|(\r\n?)
WS			[ \t\x0c]
Hidden			[{DelimitedComment}{LineComment}{WS}]
DecDigits		{DecDigit}{DecDigitOrSeparator}*{DecDigit}|{DecDigit}
DoubleExponent          [eE][+-]?{DecDigits}
FloatLiteral		{DoubleLiteral}['f''F']|{DecDigits}['f''F']	
DoubleLiteral		({DecDigits}?"."{DecDigits}{DoubleExponent}?)|{DecDigits}{DoubleExponent}
HexDigit                [0-9a-fA-F]
HexDigitOrSeparator	{HexDigit}|"_"
BinDigit		0|1
BinDigitOrSeparator	{BinDigit}|'_'
IntegerLiteral		{DecDigitNoZero}{DecDigitOrSeparator}*{DecDigit}|{DecDigit}*
HexLiteral           	"0"(['x''X']){HexDigit}{HexDigitOrSeparator}*{HexDigit}|"0"(['x''X']){HexDigit}
BinLiteral           	"0"(['b''B']){BinDigit}{BinDigitOrSeparator}*{BinDigit}|"0"(['b''B']){BinDigit}
UniCharacterLiteral	'\''u'{HexDigit}{HexDigit}{HexDigit}{HexDigit}
EscapeSeq		{UniCharacterLiteral}|{EscapedIdentifier}
LineStrEscapedChar	{EscapedIdentifier}|{UniCharacterLiteral}
Letter			[A-Za-z]
UnicodeDigit		[0-9]
QuotedSymbol		[^\r\n']
Identifier		[a-zA-Z_][a-zA-Z0-9_]*|"`"[^`\r\n]+"`"
LineStrText		[^\\"$]*|"$"
multiline_string_literals     \"\"\"([^"]|\n|\"[^"]|\"\"[^"])*\"\"\" 
EscapedIdentifier	\\[tbrn'\\$] 
ineStringExpression	"${"{NL}*{expression}{NL}*'}'
lineStringContent	{LineStrText}|{LineStrEscapedChar}|{IDENTIFIER}
unsupported             "as?"|"as"|"class"|"!in"|"is"|"!is"|"object"|"package"|"super"|"this"|"throw"|"typealias"|"try"|"typeof"|"field"|"it"
unsupported_op          "@"|"$"|"$"|"`"|"\\"|"#"|"::"|"->"|"=>"|";;"
unsupported_bit         "~"|">>"|"<<"|"&="|"|="|"^="|">>="|"<<="|"&"|"|"|"^"
unsupported_word        "by"|"catch"|"constructor"|"delegate"|"dynamic"|"file"|"finally"|"get"|"init"|"param"|"property"|"reciever"|"set"|"setparam"|"value"|"where"
unsupported_mod         "companion"|"out"|"public"|"private"|"internal"|"enum"|"sealed"|"annotation"|"data"|"inner"|"tailrec"|"operator"|"inline"|"infix"|"external"|"override"|"abstract"|"final"|"open"|"lateinit"|"vararg"|"noinline"|"crossinline"|"reified"|"expect"|"actual"|"protected"
%x 						MULTICOM

%%
\n			        {}
\r 			        {}
'#!'[^{LF}{CR}]+	        {}
{DelimitedComment}	        {}
{LineComment}                   {} 
{multiline_string_literals}     { return STRING_LITERAL; }
{WS}			        {}
{NL}			        {}
"..."                                           { return RESERVED; }
"."					        { return DOT; }
","						{ return COMMA; }
"("						{ return LPAREN; }
")"						{ return RPAREN; }
"["						{ return LSQUARE; }
"]"						{ return RSQUARE; }
"{"						{ return LCURL; }
"}"						{ return RCURL; }
"*"						{ return MULT; }
"%"						{ return MOD; }
"/"						{ return DIV; }
"+"						{ return ADD; }
"-"						{ return SUB; }
"++"					{ return INCR; }
"--"					{ return DECR; }
"&&"					{ return CONJ; }
"||"					{ return DISJ; }
"!"						{ return EXCL_NO_WS; }
":"						{ return COLON; }
";"						{ return SEMICOLON; }
"="						{ return ASSIGNMENT; }
"+="					{ return ADD_ASSIGNMENT; }
"-="					{ return SUB_ASSIGNMENT; }
"*="					{ return MULT_ASSIGNMENT; }
"/="					{ return DIV_ASSIGNMENT; }
"%="					{ return MOD_ASSIGNMENT; }
".."					{ return RANGE; }
"?"{Hidden}				{ return QUEST_WS;}
"?"					{ return QUEST_NO_WS; }
"?."                                    {return QUEST_DOT;}
"?:"                                    { return QUEST_COLON;}
"<"					{ return LANGLE; }
">"					{ return RANGLE; }
"<="					{ return LE; }
">="					{ return GE; }
"!="					{ return EXCL_EQ; }
"!=="					{ return EXCL_EQEQ; }
"=="					{ return EQEQ; }
"==="					{ return EQEQEQ; }
"\'"					{ return SINGLE_QUOTE; } 
"if"                    { return IF;}
"else"                  { return ELSE;}
"when"                  { return WHEN;}
"while"                 { return WHILE;}
"for"                   { return FOR;}
"do"                    { return DO;}
"break"                 { return BREAK;}
"continue"              { return CONTINUE;}
"in"                    { return IN;}
"return"                { return RETURN;}
"fun"                   { return FUN;}
"var"                   { return VAR;}
"val"                   { return VAL;}
"import"                { return IMPORT;}
"const"                 { return CONST;}
"interface"             { return INTERFACE;} 
"Int"|"Short"|"Long"    { return INT;}
"Float"|"Double"        { return FLOAT;}
"Boolean"               { return BOOLEAN;}
"String"                { return STRING;}
"Char"                  { return CHAR;}
"Byte"                  { return BYTE;}
{FloatLiteral}							{ return FLOAT_LITERAL;}
{DoubleLiteral}							{ return FLOAT_LITERAL;}
{IntegerLiteral}                                                { return INTEGER_LITERAL;}  
{HexLiteral}                                                    { return INTEGER_LITERAL;} 
([{IntegerLiteral}{HexLiteral}{BinLiteral}])'L'	                { return INTEGER_LITERAL;}
"true"|"false"						        { return BOOLEAN_LITERAL;}
"null"							        { return NULL_LITERAL;}
["][^"]*["]				                        { return STRING_LITERAL;}
\'({EscapeSeq}|[^\r\n'\\]+)\'                                   { return CHARACTER_LITERAL; }
{unsupported}                           { fprintf(stderr, ":%d: error: the reserved word '%s' is not supported by K0 \n", yylineno, yytext); }
{unsupported_op}                        { fprintf(stderr, ":%d: error: punctuation '%s' is not supported by K0 \n", yylineno, yytext);  }
{unsupported_bit}                       { fprintf(stderr, ":%d: error: the operator '%s' is not supported by K0 \n", yylineno, yytext); }
{unsupported_word}                      { fprintf(stderr, ":%d: error: the keyword '%s' is not supported by K0 \n", yylineno, yytext); }
{unsupported_mod}                      { fprintf(stderr, ":%d: error: the keyword '%s' is not supported by K0 \n", yylineno, yytext); }
"return@"{Identifier}                   { fprintf(stderr, ":%d: error: '%s' is not supported by K0 \n", yylineno, yytext); }
"continue@"{Identifier}                 { fprintf(stderr, ":%d: error: '%s' is not supported by K0 \n", yylineno, yytext); }
"break@"{Identifier}                    { fprintf(stderr, ":%d: error: '%s' is not supported by K0 \n", yylineno, yytext); }
"this@"{Identifier}                     { fprintf(stderr, ":%d: error: '%s' is not supported by K0 \n", yylineno, yytext); }
"super@"{Identifier}                    { fprintf(stderr, ":%d: error: '%s' is not supported by K0 \n", yylineno, yytext);}
[a-zA-Z_][a-zA-Z0-9_]*|"`"[^`\r\n]+"`"	{ return IDENTIFIER; }
.             			        { fprintf(stderr, "Unrecognized token: %s\n", yytext); }
%%
