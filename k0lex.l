%option noyywrap
%option noinput
%option nounput
%option yylineno 
%{
	#include "k0gram.tab.h"
    #include "tree.h"

    extern struct token yytoken;
    char *descape(const char* yytext);
    int alctoken(int category);
    int yyival;
    double yydval;
    char *yysval;
    char* removeSeparators(char* yytext);
    int yyerror(char *s);
%}

spaces_and_tabs         [ \t]+
ExcludeCRLF             [^\r\n]*
LineComment 	        "//"[^\r\n]*
DelimitedComment	    "/*"([^*]|"*"+[^/*])*"*"+"/"
DecDigitNoZero          [1-9]
DecDigit                [0-9]
DecDigitOrSeparator     [{DecDigit}_]
NL                      \n|(\r\n?)
WS			            [ \t\x0c]
Hidden			        [{DelimitedComment}{LineComment}{WS}]
DecDigits		        {DecDigit}{DecDigitOrSeparator}*{DecDigit}|{DecDigit}
DoubleExponent          [eE][+-]?{DecDigits}
FloatLiteral		    {DoubleLiteral}['f''F']|{DecDigits}['f''F']	
DoubleLiteral		    ({DecDigits}?"."{DecDigits}{DoubleExponent}?)|{DecDigits}{DoubleExponent}
HexDigit                [0-9a-fA-F]
HexDigitOrSeparator	    {HexDigit}|"_"
BinDigit		        [01]
BinDigitOrSeparator	    {BinDigit}|"_"
IntegerLiteral		    {DecDigitNoZero}{DecDigitOrSeparator}*{DecDigit}|{DecDigit}*
HexLiteral           	"0"([xX]){HexDigit}{HexDigitOrSeparator}*{HexDigit}|"0"([xX]){HexDigit}
BinLiteral           	"0"([bB]){BinDigit}{BinDigitOrSeparator}*{BinDigit}|"0"([bB]){BinDigit}
UniCharacterLiteral	    '\''u'{HexDigit}{HexDigit}{HexDigit}{HexDigit}
EscapeSeq		        {UniCharacterLiteral}|{EscapedIdentifier}
LineStrEscapedChar	    {EscapedIdentifier}|{UniCharacterLiteral}
Letter			        [A-Za-z]
UnicodeDigit		    [0-9]
QuotedSymbol		    [^\r\n']
Identifier		        [a-zA-Z_][a-zA-Z0-9_]*|"`"[^`\r\n]+"`"
LineStrText		        [^\\"$]*|"$"
multiline_string_literals     \"\"\"([^"]|\n|\"[^"]|\"\"[^"])*\"\"\" 
EscapedIdentifier	    \\[tbrn'\\$] 
ineStringExpression	    "${"{NL}*{expression}{NL}*'}'
lineStringContent	    {LineStrText}|{LineStrEscapedChar}|{IDENTIFIER}
unsupported             "as?"|"as"|"class"|"!in"|"is"|"!is"|"object"|"package"|"super"|"this"|"throw"|"typealias"|"try"|"typeof"|"field"|"it"
unsupported_op          "@"|"$"|"$"|"`"|"\\"|"#"|"::"|"=>"|";;"
unsupported_bit         "~"|">>"|"<<"|"&="|"|="|"^="|">>="|"<<="|"&"|"|"|"^"
unsupported_word        "by"|"catch"|"constructor"|"delegate"|"dynamic"|"file"|"finally"|"init"|"param"|"property"|"reciever"|"set"|"setparam"|"value"|"where"
unsupported_mod         "companion"|"out"|"public"|"private"|"internal"|"enum"|"sealed"|"annotation"|"data"|"inner"|"tailrec"|"operator"|"inline"|"infix"|"external"|"override"|"abstract"|"final"|"open"|"lateinit"|"vararg"|"noinline"|"crossinline"|"reified"|"expect"|"actual"|"protected"
%x 						MULTICOM

%%
\n			                {}
\r 			                {}
'#!'[^{LF}{CR}]+	        {}
{DelimitedComment}	        {}
{LineComment}               {} 
{multiline_string_literals}     { yysval = descape(yytext);return alctoken(STRING_LITERAL); }
{WS}			            {}
{NL}			            {}
"..."                   { return alctoken(RESERVED); }
"."					    { return alctoken(DOT); }
"->"                    { return alctoken(ARROW); }
","						{ return alctoken(COMMA); }
"("						{ return alctoken(LPAREN); }
")"						{ return alctoken(RPAREN); }
"["						{ return alctoken(LSQUARE); }
"]"						{ return alctoken(RSQUARE); }
"{"						{ return alctoken(LCURL); }
"}"						{ return alctoken(RCURL); }
"*"						{ return alctoken(MULT); }
"%"						{ return alctoken(MOD); }
"/"						{ return alctoken(DIV); }
"+"						{ return alctoken(ADD); }
"-"						{ return alctoken(SUB); }
"++"					{ return alctoken(INCR); }
"--"					{ return alctoken(DECR); }
"&&"					{ return alctoken(CONJ); }
"||"					{ return alctoken(DISJ); }
"!"						{ return alctoken(EXCL_NO_WS); }
":"						{ return alctoken(COLON); }
";"						{ return alctoken(SEMICOLON); }
"="						{ return alctoken(ASSIGNMENT); }
"+="					{ return alctoken(ADD_ASSIGNMENT); }
"-="					{ return alctoken(SUB_ASSIGNMENT); }
"*="					{ return alctoken(MULT_ASSIGNMENT); }
"/="					{ return alctoken(DIV_ASSIGNMENT); }
"%="					{ return alctoken(MOD_ASSIGNMENT); }
".."					{ return alctoken(RANGE); }
"?"{Hidden}				{ return alctoken(QUEST_WS);}
"?"					    { return alctoken(QUEST_NO_WS); }
"?."                    { return alctoken(QUEST_DOT);}
"?:"                    { return alctoken(QUEST_COLON);}
"<"					    { return alctoken(LANGLE); }
">"					    { return alctoken(RANGLE); }
"<="					{ return alctoken(LE); }
">="					{ return alctoken(GE); }
"!="					{ return alctoken(EXCL_EQ); }
"!=="					{ return alctoken(EXCL_EQEQ); }
"=="					{ return alctoken(EQEQ); }
"==="					{ return alctoken(EQEQEQ); }
"\'"					{ return alctoken(SINGLE_QUOTE); } 
"if"                    { return alctoken(IF);}
"else"                  { return alctoken(ELSE);}
"when"                  { return alctoken(WHEN);}
"while"                 { return alctoken(WHILE);}
"for"                   { return alctoken(FOR);}
"do"                    { return alctoken(DO);}
"break"                 { return alctoken(BREAK);}
"continue"              { return alctoken(CONTINUE);}
"in"                    { return alctoken(IN);}
"return"                { return alctoken(RETURN);}
"fun"                   { return alctoken(FUN);}
"var"                   { return alctoken(VAR);}
"val"                   { return alctoken(VAL);}
"import"                { return alctoken(IMPORT);}
"const"                 { return alctoken(CONST);}
"interface"             { return alctoken(INTERFACE);} 
"Float"|"Double"|"Int"|"Short"|"Long"|"Boolean"|"Char"|"Byte"    { return alctoken(TYPELITERAL);} 
"-"?{FloatLiteral}							{ yydval = atof(removeSeparators(yytext)); return alctoken(FLOAT_LITERAL);}
"-"?{DoubleLiteral}							{ yydval = atof(removeSeparators(yytext)); return alctoken(FLOAT_LITERAL);}
"-"?{IntegerLiteral}                                                { yyival = atoi(removeSeparators(yytext));  return alctoken(INTEGER_LITERAL);}  
{HexLiteral}                                                    { yyival = (int)strtol(removeSeparators(yytext), NULL, 16); return alctoken(INTEGER_LITERAL);} 
{BinLiteral}                                                    { yyival = (int)strtol(removeSeparators(yytext+2), NULL, 2); return alctoken(INTEGER_LITERAL);}
"-"?([{IntegerLiteral}{HexLiteral}{BinLiteral}])'L'	                { return alctoken(INTEGER_LITERAL);}
"true"|"false"						                            { return alctoken(BOOLEAN_LITERAL);}
"null"							                                { return alctoken(NULL_LITERAL);}
["][^"]*["]				                                        { yysval = descape(yytext);return alctoken(STRING_LITERAL);}
\'({EscapeSeq}|[^\r\n'\\]+)\'                                   { return alctoken(CHARACTER_LITERAL); }
{unsupported}                           { fprintf(stderr, ":%d: error: the reserved word '%s' is not supported by K0 \n", yylineno, yytext); }
{unsupported_op}                        { fprintf(stderr, ":%d: error: punctuation '%s' is not supported by K0 \n", yylineno, yytext);  }
{unsupported_bit}                       { fprintf(stderr, ":%d: error: the operator '%s' is not supported by K0 \n", yylineno, yytext); }
{unsupported_word}                      { fprintf(stderr, ":%d: error: the keyword '%s' is not supported by K0 \n", yylineno, yytext); }
{unsupported_mod}                       { fprintf(stderr, ":%d: error: the keyword '%s' is not supported by K0 \n", yylineno, yytext); }
"return@"{Identifier}                   { fprintf(stderr, ":%d: error: '%s' is not supported by K0 \n", yylineno, yytext); }
"continue@"{Identifier}                 { fprintf(stderr, ":%d: error: '%s' is not supported by K0 \n", yylineno, yytext); }
"break@"{Identifier}                    { fprintf(stderr, ":%d: error: '%s' is not supported by K0 \n", yylineno, yytext); }
"this@"{Identifier}                     { fprintf(stderr, ":%d: error: '%s' is not supported by K0 \n", yylineno, yytext); }
"super@"{Identifier}                    { fprintf(stderr, ":%d: error: '%s' is not supported by K0 \n", yylineno, yytext);}
[a-zA-Z_][a-zA-Z0-9_]*|"`"[^`\r\n]+"`"	{ return alctoken(IDENTIFIER); }
.             			                { fprintf(stderr, "Unrecognized token: %s\n", yytext); }

%%
