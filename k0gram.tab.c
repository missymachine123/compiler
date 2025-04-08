/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "k0gram.y"

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

#line 85 "k0gram.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "k0gram.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RESERVED = 3,                   /* RESERVED  */
  YYSYMBOL_DOT = 4,                        /* DOT  */
  YYSYMBOL_COMMA = 5,                      /* COMMA  */
  YYSYMBOL_LPAREN = 6,                     /* LPAREN  */
  YYSYMBOL_RPAREN = 7,                     /* RPAREN  */
  YYSYMBOL_LSQUARE = 8,                    /* LSQUARE  */
  YYSYMBOL_RSQUARE = 9,                    /* RSQUARE  */
  YYSYMBOL_LCURL = 10,                     /* LCURL  */
  YYSYMBOL_RCURL = 11,                     /* RCURL  */
  YYSYMBOL_INCR = 12,                      /* INCR  */
  YYSYMBOL_DECR = 13,                      /* DECR  */
  YYSYMBOL_CONJ = 14,                      /* CONJ  */
  YYSYMBOL_DISJ = 15,                      /* DISJ  */
  YYSYMBOL_EXCL_WS = 16,                   /* EXCL_WS  */
  YYSYMBOL_EXCL_NO_WS = 17,                /* EXCL_NO_WS  */
  YYSYMBOL_COLON = 18,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 19,                 /* SEMICOLON  */
  YYSYMBOL_ASSIGNMENT = 20,                /* ASSIGNMENT  */
  YYSYMBOL_ADD_ASSIGNMENT = 21,            /* ADD_ASSIGNMENT  */
  YYSYMBOL_SUB_ASSIGNMENT = 22,            /* SUB_ASSIGNMENT  */
  YYSYMBOL_MULT_ASSIGNMENT = 23,           /* MULT_ASSIGNMENT  */
  YYSYMBOL_DIV_ASSIGNMENT = 24,            /* DIV_ASSIGNMENT  */
  YYSYMBOL_MOD_ASSIGNMENT = 25,            /* MOD_ASSIGNMENT  */
  YYSYMBOL_ARROW = 26,                     /* ARROW  */
  YYSYMBOL_DOUBLE_ARROW = 27,              /* DOUBLE_ARROW  */
  YYSYMBOL_RANGE = 28,                     /* RANGE  */
  YYSYMBOL_COLONCOLON = 29,                /* COLONCOLON  */
  YYSYMBOL_DOUBLE_SEMICOLON = 30,          /* DOUBLE_SEMICOLON  */
  YYSYMBOL_HASH = 31,                      /* HASH  */
  YYSYMBOL_AT_NO_WS = 32,                  /* AT_NO_WS  */
  YYSYMBOL_AT_POST_WS = 33,                /* AT_POST_WS  */
  YYSYMBOL_AT_PRE_WS = 34,                 /* AT_PRE_WS  */
  YYSYMBOL_AT_BOTH_WS = 35,                /* AT_BOTH_WS  */
  YYSYMBOL_QUEST_WS = 36,                  /* QUEST_WS  */
  YYSYMBOL_QUEST_NO_WS = 37,               /* QUEST_NO_WS  */
  YYSYMBOL_LANGLE = 38,                    /* LANGLE  */
  YYSYMBOL_RANGLE = 39,                    /* RANGLE  */
  YYSYMBOL_LE = 40,                        /* LE  */
  YYSYMBOL_GE = 41,                        /* GE  */
  YYSYMBOL_QUEST_DOT = 42,                 /* QUEST_DOT  */
  YYSYMBOL_EXCL_EQ = 43,                   /* EXCL_EQ  */
  YYSYMBOL_EXCL_EQEQ = 44,                 /* EXCL_EQEQ  */
  YYSYMBOL_AS_SAFE = 45,                   /* AS_SAFE  */
  YYSYMBOL_EQEQ = 46,                      /* EQEQ  */
  YYSYMBOL_EQEQEQ = 47,                    /* EQEQEQ  */
  YYSYMBOL_SINGLE_QUOTE = 48,              /* SINGLE_QUOTE  */
  YYSYMBOL_RETURN_AT = 49,                 /* RETURN_AT  */
  YYSYMBOL_CONTINUE_AT = 50,               /* CONTINUE_AT  */
  YYSYMBOL_BREAK_AT = 51,                  /* BREAK_AT  */
  YYSYMBOL_THIS_AT = 52,                   /* THIS_AT  */
  YYSYMBOL_SUPER_AT = 53,                  /* SUPER_AT  */
  YYSYMBOL_FILES = 54,                     /* FILES  */
  YYSYMBOL_FIELD = 55,                     /* FIELD  */
  YYSYMBOL_PROPERTY = 56,                  /* PROPERTY  */
  YYSYMBOL_GET = 57,                       /* GET  */
  YYSYMBOL_QUEST_COLON = 58,               /* QUEST_COLON  */
  YYSYMBOL_SET = 59,                       /* SET  */
  YYSYMBOL_RECEIVER = 60,                  /* RECEIVER  */
  YYSYMBOL_PARAM = 61,                     /* PARAM  */
  YYSYMBOL_SETPARAM = 62,                  /* SETPARAM  */
  YYSYMBOL_DELEGATE = 63,                  /* DELEGATE  */
  YYSYMBOL_PACKAGE = 64,                   /* PACKAGE  */
  YYSYMBOL_IMPORT = 65,                    /* IMPORT  */
  YYSYMBOL_CLASS = 66,                     /* CLASS  */
  YYSYMBOL_INTERFACE = 67,                 /* INTERFACE  */
  YYSYMBOL_FUN = 68,                       /* FUN  */
  YYSYMBOL_OBJECT = 69,                    /* OBJECT  */
  YYSYMBOL_VAL = 70,                       /* VAL  */
  YYSYMBOL_VAR = 71,                       /* VAR  */
  YYSYMBOL_TYPEALIAS = 72,                 /* TYPEALIAS  */
  YYSYMBOL_CONSTRUCTOR = 73,               /* CONSTRUCTOR  */
  YYSYMBOL_BY = 74,                        /* BY  */
  YYSYMBOL_COMPANION = 75,                 /* COMPANION  */
  YYSYMBOL_INIT = 76,                      /* INIT  */
  YYSYMBOL_THIS = 77,                      /* THIS  */
  YYSYMBOL_SUPER = 78,                     /* SUPER  */
  YYSYMBOL_TYPEOF = 79,                    /* TYPEOF  */
  YYSYMBOL_WHERE = 80,                     /* WHERE  */
  YYSYMBOL_IF = 81,                        /* IF  */
  YYSYMBOL_ELSE = 82,                      /* ELSE  */
  YYSYMBOL_WHEN = 83,                      /* WHEN  */
  YYSYMBOL_TRY = 84,                       /* TRY  */
  YYSYMBOL_CATCH = 85,                     /* CATCH  */
  YYSYMBOL_FINALLY = 86,                   /* FINALLY  */
  YYSYMBOL_FOR = 87,                       /* FOR  */
  YYSYMBOL_DO = 88,                        /* DO  */
  YYSYMBOL_WHILE = 89,                     /* WHILE  */
  YYSYMBOL_THROW = 90,                     /* THROW  */
  YYSYMBOL_RETURN = 91,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 92,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 93,                     /* BREAK  */
  YYSYMBOL_AS = 94,                        /* AS  */
  YYSYMBOL_IS = 95,                        /* IS  */
  YYSYMBOL_IN = 96,                        /* IN  */
  YYSYMBOL_OUT = 97,                       /* OUT  */
  YYSYMBOL_DYNAMIC = 98,                   /* DYNAMIC  */
  YYSYMBOL_PUBLIC = 99,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 100,                  /* PRIVATE  */
  YYSYMBOL_PROTECTED = 101,                /* PROTECTED  */
  YYSYMBOL_INTERNAL = 102,                 /* INTERNAL  */
  YYSYMBOL_ENUM = 103,                     /* ENUM  */
  YYSYMBOL_SEALED = 104,                   /* SEALED  */
  YYSYMBOL_ANNOTATION = 105,               /* ANNOTATION  */
  YYSYMBOL_DATA = 106,                     /* DATA  */
  YYSYMBOL_INNER = 107,                    /* INNER  */
  YYSYMBOL_TAILREC = 108,                  /* TAILREC  */
  YYSYMBOL_OPERATOR = 109,                 /* OPERATOR  */
  YYSYMBOL_INLINE = 110,                   /* INLINE  */
  YYSYMBOL_INFIX = 111,                    /* INFIX  */
  YYSYMBOL_EXTERNAL = 112,                 /* EXTERNAL  */
  YYSYMBOL_SUSPEND = 113,                  /* SUSPEND  */
  YYSYMBOL_OVERRIDE = 114,                 /* OVERRIDE  */
  YYSYMBOL_ABSTRACT = 115,                 /* ABSTRACT  */
  YYSYMBOL_NULL_LITERAL = 116,             /* NULL_LITERAL  */
  YYSYMBOL_FINAL = 117,                    /* FINAL  */
  YYSYMBOL_OPEN = 118,                     /* OPEN  */
  YYSYMBOL_CONST = 119,                    /* CONST  */
  YYSYMBOL_LATEINIT = 120,                 /* LATEINIT  */
  YYSYMBOL_VARARG = 121,                   /* VARARG  */
  YYSYMBOL_NOINLINE = 122,                 /* NOINLINE  */
  YYSYMBOL_CROSSINLINE = 123,              /* CROSSINLINE  */
  YYSYMBOL_REIFIED = 124,                  /* REIFIED  */
  YYSYMBOL_EXPECT = 125,                   /* EXPECT  */
  YYSYMBOL_ACTUAL = 126,                   /* ACTUAL  */
  YYSYMBOL_REAL_LITERAL = 127,             /* REAL_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 128,            /* FLOAT_LITERAL  */
  YYSYMBOL_DOUBLE_LITERAL = 129,           /* DOUBLE_LITERAL  */
  YYSYMBOL_INTEGER_LITERAL = 130,          /* INTEGER_LITERAL  */
  YYSYMBOL_CHARACTER_LITERAL = 131,        /* CHARACTER_LITERAL  */
  YYSYMBOL_HEX_LITERAL = 132,              /* HEX_LITERAL  */
  YYSYMBOL_BIN_LITERAL = 133,              /* BIN_LITERAL  */
  YYSYMBOL_UNSIGNED_LITERAL = 134,         /* UNSIGNED_LITERAL  */
  YYSYMBOL_LONG_LITERAL = 135,             /* LONG_LITERAL  */
  YYSYMBOL_BOOLEAN_LITERAL = 136,          /* BOOLEAN_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 137,           /* STRING_LITERAL  */
  YYSYMBOL_INT = 138,                      /* INT  */
  YYSYMBOL_FLOAT = 139,                    /* FLOAT  */
  YYSYMBOL_BOOLEAN = 140,                  /* BOOLEAN  */
  YYSYMBOL_CHAR = 141,                     /* CHAR  */
  YYSYMBOL_STRING = 142,                   /* STRING  */
  YYSYMBOL_BYTE = 143,                     /* BYTE  */
  YYSYMBOL_T_EOF = 144,                    /* T_EOF  */
  YYSYMBOL_TYPELITERAL = 145,              /* TYPELITERAL  */
  YYSYMBOL_MULT = 146,                     /* MULT  */
  YYSYMBOL_MOD = 147,                      /* MOD  */
  YYSYMBOL_DIV = 148,                      /* DIV  */
  YYSYMBOL_ADD = 149,                      /* ADD  */
  YYSYMBOL_SUB = 150,                      /* SUB  */
  YYSYMBOL_IDENTIFIER = 151,               /* IDENTIFIER  */
  YYSYMBOL_AND = 152,                      /* AND  */
  YYSYMBOL_OR = 153,                       /* OR  */
  YYSYMBOL_LOWER_THAN_ELSE = 154,          /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 155,                 /* $accept  */
  YYSYMBOL_program = 156,                  /* program  */
  YYSYMBOL_topLevelObjects = 157,          /* topLevelObjects  */
  YYSYMBOL_topLevelObject = 158,           /* topLevelObject  */
  YYSYMBOL_opt_functionBody = 159,         /* opt_functionBody  */
  YYSYMBOL_opt_colon_type = 160,           /* opt_colon_type  */
  YYSYMBOL_functionDeclaration = 161,      /* functionDeclaration  */
  YYSYMBOL_functionValueParameters = 162,  /* functionValueParameters  */
  YYSYMBOL_functionValueParameter = 163,   /* functionValueParameter  */
  YYSYMBOL_parameter = 164,                /* parameter  */
  YYSYMBOL_multi_comma_functionParameter = 165, /* multi_comma_functionParameter  */
  YYSYMBOL_opt_functionValueParameter = 166, /* opt_functionValueParameter  */
  YYSYMBOL_type = 167,                     /* type  */
  YYSYMBOL_functionBody = 168,             /* functionBody  */
  YYSYMBOL_block = 169,                    /* block  */
  YYSYMBOL_semis = 170,                    /* semis  */
  YYSYMBOL_semis_statement = 171,          /* semis_statement  */
  YYSYMBOL_optional_statement_sequence = 172, /* optional_statement_sequence  */
  YYSYMBOL_statements = 173,               /* statements  */
  YYSYMBOL_statement = 174,                /* statement  */
  YYSYMBOL_declaration = 175,              /* declaration  */
  YYSYMBOL_val_var = 176,                  /* val_var  */
  YYSYMBOL_opt_modifier = 177,             /* opt_modifier  */
  YYSYMBOL_178_1 = 178,                    /* $@1  */
  YYSYMBOL_parenthesizedType = 179,        /* parenthesizedType  */
  YYSYMBOL_multi_dot_simpleUserType = 180, /* multi_dot_simpleUserType  */
  YYSYMBOL_181_2 = 181,                    /* $@2  */
  YYSYMBOL_userType = 182,                 /* userType  */
  YYSYMBOL_simpleUserType = 183,           /* simpleUserType  */
  YYSYMBOL_multi_quest = 184,              /* multi_quest  */
  YYSYMBOL_185_3 = 185,                    /* $@3  */
  YYSYMBOL_nullableType = 186,             /* nullableType  */
  YYSYMBOL_typeRef_parenthesizedType = 187, /* typeRef_parenthesizedType  */
  YYSYMBOL_opt_eq_exp = 188,               /* opt_eq_exp  */
  YYSYMBOL_189_4 = 189,                    /* $@4  */
  YYSYMBOL_multivariable_variableDeclaration = 190, /* multivariable_variableDeclaration  */
  YYSYMBOL_propertyDeclaration = 191,      /* propertyDeclaration  */
  YYSYMBOL_opt_typeParameters = 192,       /* opt_typeParameters  */
  YYSYMBOL_opt_comma = 193,                /* opt_comma  */
  YYSYMBOL_typeParameters = 194,           /* typeParameters  */
  YYSYMBOL_typeParameter = 195,            /* typeParameter  */
  YYSYMBOL_multi_typeParameter = 196,      /* multi_typeParameter  */
  YYSYMBOL_simpleIdentifier = 197,         /* simpleIdentifier  */
  YYSYMBOL_classDeclaration = 198,         /* classDeclaration  */
  YYSYMBOL_variableDeclaration = 199,      /* variableDeclaration  */
  YYSYMBOL_multiVariableDeclaration = 200, /* multiVariableDeclaration  */
  YYSYMBOL_multi_comma_variableDeclaration = 201, /* multi_comma_variableDeclaration  */
  YYSYMBOL_classBody = 202,                /* classBody  */
  YYSYMBOL_assignmentAndOperator = 203,    /* assignmentAndOperator  */
  YYSYMBOL_assignableExpression = 204,     /* assignableExpression  */
  YYSYMBOL_multi_unaryPrefix = 205,        /* multi_unaryPrefix  */
  YYSYMBOL_206_5 = 206,                    /* $@5  */
  YYSYMBOL_prefixUnaryOperator = 207,      /* prefixUnaryOperator  */
  YYSYMBOL_prefixUnaryExpression = 208,    /* prefixUnaryExpression  */
  YYSYMBOL_parenthesizedAssignableExpression = 209, /* parenthesizedAssignableExpression  */
  YYSYMBOL_assignment = 210,               /* assignment  */
  YYSYMBOL_directly_assign = 211,          /* directly_assign  */
  YYSYMBOL_assignableSuffix = 212,         /* assignableSuffix  */
  YYSYMBOL_typeArguments = 213,            /* typeArguments  */
  YYSYMBOL_multi_comma_typeProjection = 214, /* multi_comma_typeProjection  */
  YYSYMBOL_215_6 = 215,                    /* $@6  */
  YYSYMBOL_typeProjection = 216,           /* typeProjection  */
  YYSYMBOL_directlyAssignableExpression = 217, /* directlyAssignableExpression  */
  YYSYMBOL_parenthesizedDirectlyAssignableExpression = 218, /* parenthesizedDirectlyAssignableExpression  */
  YYSYMBOL_multi_postfixUnarySuffix = 219, /* multi_postfixUnarySuffix  */
  YYSYMBOL_220_7 = 220,                    /* $@7  */
  YYSYMBOL_postfixUnaryExpression = 221,   /* postfixUnaryExpression  */
  YYSYMBOL_postfixUnarySuffix = 222,       /* postfixUnarySuffix  */
  YYSYMBOL_identifier_expression_class = 223, /* identifier_expression_class  */
  YYSYMBOL_navigationSuffix = 224,         /* navigationSuffix  */
  YYSYMBOL_memberAccessOperator = 225,     /* memberAccessOperator  */
  YYSYMBOL_postfixUnaryOperator = 226,     /* postfixUnaryOperator  */
  YYSYMBOL_multi_comma_expression = 227,   /* multi_comma_expression  */
  YYSYMBOL_228_8 = 228,                    /* $@8  */
  YYSYMBOL_indexingSuffix = 229,           /* indexingSuffix  */
  YYSYMBOL_callSuffix = 230,               /* callSuffix  */
  YYSYMBOL_multi_comma_valueArgument = 231, /* multi_comma_valueArgument  */
  YYSYMBOL_232_9 = 232,                    /* $@9  */
  YYSYMBOL_opt_valueArgument = 233,        /* opt_valueArgument  */
  YYSYMBOL_234_10 = 234,                   /* $@10  */
  YYSYMBOL_valueArguments = 235,           /* valueArguments  */
  YYSYMBOL_opt_simpleIdentifier_EQ = 236,  /* opt_simpleIdentifier_EQ  */
  YYSYMBOL_237_11 = 237,                   /* $@11  */
  YYSYMBOL_opt_Multi = 238,                /* opt_Multi  */
  YYSYMBOL_239_12 = 239,                   /* $@12  */
  YYSYMBOL_valueArgument = 240,            /* valueArgument  */
  YYSYMBOL_parenthesizedExpression = 241,  /* parenthesizedExpression  */
  YYSYMBOL_ifExpression = 242,             /* ifExpression  */
  YYSYMBOL_controls = 243,                 /* controls  */
  YYSYMBOL_functionCall = 244,             /* functionCall  */
  YYSYMBOL_dotExpression = 245,            /* dotExpression  */
  YYSYMBOL_functionArguments = 246,        /* functionArguments  */
  YYSYMBOL_variable_multivariable = 247,   /* variable_multivariable  */
  YYSYMBOL_control_structure_body_or_comma = 248, /* control_structure_body_or_comma  */
  YYSYMBOL_loopStatement = 249,            /* loopStatement  */
  YYSYMBOL_controlStructureBody = 250,     /* controlStructureBody  */
  YYSYMBOL_jumpExpression = 251,           /* jumpExpression  */
  YYSYMBOL_multi_whenEntry = 252,          /* multi_whenEntry  */
  YYSYMBOL_whenExpression = 253,           /* whenExpression  */
  YYSYMBOL_whenSubject = 254,              /* whenSubject  */
  YYSYMBOL_multi_comma_whenCondition = 255, /* multi_comma_whenCondition  */
  YYSYMBOL_256_13 = 256,                   /* $@13  */
  YYSYMBOL_whenEntry = 257,                /* whenEntry  */
  YYSYMBOL_whenCondition = 258,            /* whenCondition  */
  YYSYMBOL_rangeTest = 259,                /* rangeTest  */
  YYSYMBOL_classMembers = 260,             /* classMembers  */
  YYSYMBOL_classMember = 261,              /* classMember  */
  YYSYMBOL_expression = 262,               /* expression  */
  YYSYMBOL_disjunction = 263,              /* disjunction  */
  YYSYMBOL_conjunction = 264,              /* conjunction  */
  YYSYMBOL_equality = 265,                 /* equality  */
  YYSYMBOL_comparison = 266,               /* comparison  */
  YYSYMBOL_genericCallLikeComparison = 267, /* genericCallLikeComparison  */
  YYSYMBOL_elvisExpression = 268,          /* elvisExpression  */
  YYSYMBOL_rangeExpression = 269,          /* rangeExpression  */
  YYSYMBOL_additiveExpression = 270,       /* additiveExpression  */
  YYSYMBOL_multiplicativeExpression = 271, /* multiplicativeExpression  */
  YYSYMBOL_primaryExpression = 272,        /* primaryExpression  */
  YYSYMBOL_collectionLiteral = 273,        /* collectionLiteral  */
  YYSYMBOL_comparison_operator = 274,      /* comparison_operator  */
  YYSYMBOL_equality_operator = 275         /* equality_operator  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   794

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  155
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  121
/* YYNRULES -- Number of rules.  */
#define YYNRULES  240
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  379

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   409


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    57,    58,    62,    66,    67,    71,    72,
      77,    78,    83,    87,    91,    95,    96,   100,   101,   102,
     107,   112,   113,   118,   123,   124,   128,   129,   134,   135,
     139,   145,   146,   147,   148,   152,   153,   154,   158,   159,
     163,   164,   164,   169,   175,   176,   176,   180,   185,   186,
     191,   192,   192,   195,   196,   201,   202,   207,   208,   208,
     213,   214,   218,   219,   220,   225,   226,   230,   231,   234,
     238,   243,   244,   248,   252,   253,   257,   258,   262,   265,
     266,   272,   277,   278,   279,   280,   281,   285,   286,   289,
     290,   290,   293,   294,   295,   296,   297,   302,   306,   310,
     314,   315,   319,   320,   324,   328,   329,   329,   334,   335,
     338,   339,   340,   344,   348,   349,   349,   352,   356,   357,
     358,   359,   363,   364,   365,   369,   373,   374,   378,   379,
     380,   384,   385,   385,   389,   393,   397,   398,   398,   401,
     402,   402,   406,   410,   411,   411,   415,   416,   416,   420,
     424,   430,   434,   435,   440,   441,   445,   446,   451,   452,
     453,   457,   458,   462,   463,   467,   468,   469,   474,   475,
     480,   481,   482,   483,   487,   488,   492,   493,   497,   498,
     501,   502,   502,   506,   507,   508,   509,   513,   514,   518,
     522,   523,   527,   528,   533,   537,   538,   542,   543,   547,
     548,   552,   553,   557,   558,   562,   563,   567,   568,   572,
     573,   574,   578,   579,   580,   581,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   600,   601,
     602,   603,   604,   609,   610,   611,   612,   616,   617,   618,
     619
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "RESERVED", "DOT",
  "COMMA", "LPAREN", "RPAREN", "LSQUARE", "RSQUARE", "LCURL", "RCURL",
  "INCR", "DECR", "CONJ", "DISJ", "EXCL_WS", "EXCL_NO_WS", "COLON",
  "SEMICOLON", "ASSIGNMENT", "ADD_ASSIGNMENT", "SUB_ASSIGNMENT",
  "MULT_ASSIGNMENT", "DIV_ASSIGNMENT", "MOD_ASSIGNMENT", "ARROW",
  "DOUBLE_ARROW", "RANGE", "COLONCOLON", "DOUBLE_SEMICOLON", "HASH",
  "AT_NO_WS", "AT_POST_WS", "AT_PRE_WS", "AT_BOTH_WS", "QUEST_WS",
  "QUEST_NO_WS", "LANGLE", "RANGLE", "LE", "GE", "QUEST_DOT", "EXCL_EQ",
  "EXCL_EQEQ", "AS_SAFE", "EQEQ", "EQEQEQ", "SINGLE_QUOTE", "RETURN_AT",
  "CONTINUE_AT", "BREAK_AT", "THIS_AT", "SUPER_AT", "FILES", "FIELD",
  "PROPERTY", "GET", "QUEST_COLON", "SET", "RECEIVER", "PARAM", "SETPARAM",
  "DELEGATE", "PACKAGE", "IMPORT", "CLASS", "INTERFACE", "FUN", "OBJECT",
  "VAL", "VAR", "TYPEALIAS", "CONSTRUCTOR", "BY", "COMPANION", "INIT",
  "THIS", "SUPER", "TYPEOF", "WHERE", "IF", "ELSE", "WHEN", "TRY", "CATCH",
  "FINALLY", "FOR", "DO", "WHILE", "THROW", "RETURN", "CONTINUE", "BREAK",
  "AS", "IS", "IN", "OUT", "DYNAMIC", "PUBLIC", "PRIVATE", "PROTECTED",
  "INTERNAL", "ENUM", "SEALED", "ANNOTATION", "DATA", "INNER", "TAILREC",
  "OPERATOR", "INLINE", "INFIX", "EXTERNAL", "SUSPEND", "OVERRIDE",
  "ABSTRACT", "NULL_LITERAL", "FINAL", "OPEN", "CONST", "LATEINIT",
  "VARARG", "NOINLINE", "CROSSINLINE", "REIFIED", "EXPECT", "ACTUAL",
  "REAL_LITERAL", "FLOAT_LITERAL", "DOUBLE_LITERAL", "INTEGER_LITERAL",
  "CHARACTER_LITERAL", "HEX_LITERAL", "BIN_LITERAL", "UNSIGNED_LITERAL",
  "LONG_LITERAL", "BOOLEAN_LITERAL", "STRING_LITERAL", "INT", "FLOAT",
  "BOOLEAN", "CHAR", "STRING", "BYTE", "T_EOF", "TYPELITERAL", "MULT",
  "MOD", "DIV", "ADD", "SUB", "IDENTIFIER", "AND", "OR", "LOWER_THAN_ELSE",
  "$accept", "program", "topLevelObjects", "topLevelObject",
  "opt_functionBody", "opt_colon_type", "functionDeclaration",
  "functionValueParameters", "functionValueParameter", "parameter",
  "multi_comma_functionParameter", "opt_functionValueParameter", "type",
  "functionBody", "block", "semis", "semis_statement",
  "optional_statement_sequence", "statements", "statement", "declaration",
  "val_var", "opt_modifier", "$@1", "parenthesizedType",
  "multi_dot_simpleUserType", "$@2", "userType", "simpleUserType",
  "multi_quest", "$@3", "nullableType", "typeRef_parenthesizedType",
  "opt_eq_exp", "$@4", "multivariable_variableDeclaration",
  "propertyDeclaration", "opt_typeParameters", "opt_comma",
  "typeParameters", "typeParameter", "multi_typeParameter",
  "simpleIdentifier", "classDeclaration", "variableDeclaration",
  "multiVariableDeclaration", "multi_comma_variableDeclaration",
  "classBody", "assignmentAndOperator", "assignableExpression",
  "multi_unaryPrefix", "$@5", "prefixUnaryOperator",
  "prefixUnaryExpression", "parenthesizedAssignableExpression",
  "assignment", "directly_assign", "assignableSuffix", "typeArguments",
  "multi_comma_typeProjection", "$@6", "typeProjection",
  "directlyAssignableExpression",
  "parenthesizedDirectlyAssignableExpression", "multi_postfixUnarySuffix",
  "$@7", "postfixUnaryExpression", "postfixUnarySuffix",
  "identifier_expression_class", "navigationSuffix",
  "memberAccessOperator", "postfixUnaryOperator", "multi_comma_expression",
  "$@8", "indexingSuffix", "callSuffix", "multi_comma_valueArgument",
  "$@9", "opt_valueArgument", "$@10", "valueArguments",
  "opt_simpleIdentifier_EQ", "$@11", "opt_Multi", "$@12", "valueArgument",
  "parenthesizedExpression", "ifExpression", "controls", "functionCall",
  "dotExpression", "functionArguments", "variable_multivariable",
  "control_structure_body_or_comma", "loopStatement",
  "controlStructureBody", "jumpExpression", "multi_whenEntry",
  "whenExpression", "whenSubject", "multi_comma_whenCondition", "$@13",
  "whenEntry", "whenCondition", "rangeTest", "classMembers", "classMember",
  "expression", "disjunction", "conjunction", "equality", "comparison",
  "genericCallLikeComparison", "elvisExpression", "rangeExpression",
  "additiveExpression", "multiplicativeExpression", "primaryExpression",
  "collectionLiteral", "comparison_operator", "equality_operator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-281)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-141)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -28,  -107,    -9,    28,   102,    22,  -281,  -281,   108,    91,
    -281,  -281,  -281,  -281,    -9,  -107,     6,  -281,  -107,  -281,
    -281,  -281,  -281,  -281,  -281,    -9,   111,  -281,  -281,     6,
    -281,  -281,  -281,  -281,   127,  -281,    18,    -9,    15,  -281,
    -281,   134,   141,  -281,   142,   135,  -281,   171,  -281,  -107,
     135,  -107,     1,   167,  -281,   111,     6,   169,   188,   180,
    -281,  -281,     5,  -107,   162,  -281,  -281,  -107,   196,  -281,
     180,   203,   193,  -281,  -281,  -281,     6,    72,  -281,    34,
    -281,     6,    15,   613,   194,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,   167,   209,  -281,  -281,     6,   211,  -281,
    -281,   305,   613,  -281,  -281,  -281,   212,  -281,   180,   613,
     524,   214,    36,   613,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,    54,  -281,  -281,  -281,  -281,  -281,   103,  -281,  -281,
    -281,   206,   204,    79,    96,  -281,   -22,   195,    44,     7,
    -281,  -281,  -281,    72,  -107,  -281,     1,   185,   643,   216,
     334,   219,  -281,   217,  -281,   108,   207,   183,   431,  -281,
    -281,  -281,   108,   613,   210,  -281,    27,   108,   108,   218,
       6,   222,   221,   226,  -281,    99,   613,   552,  -281,   225,
    -281,    85,   613,    94,   613,   613,   613,  -281,  -281,  -281,
    -281,   613,  -281,  -281,  -281,  -281,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   178,  -281,  -281,  -281,  -281,
    -281,   643,   235,    15,  -281,  -281,   158,   613,  -281,    67,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,   233,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,   613,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,   242,  -281,
     105,  -281,   248,     6,   251,   473,  -281,  -281,   110,  -281,
    -281,   137,   204,    79,    96,  -281,   195,   201,    44,     7,
       7,  -281,  -281,  -281,  -281,    20,  -281,  -281,   246,   263,
    -281,  -281,    19,  -281,  -281,  -281,  -281,   264,   250,  -281,
    -281,   177,   269,   270,   406,  -281,  -281,  -281,   586,  -281,
     334,   259,  -281,  -281,   254,   613,  -281,  -281,  -281,  -281,
     495,   613,   108,   108,   265,   277,  -281,   140,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,   613,   613,   173,
    -281,   282,  -281,  -281,  -281,   208,   613,   334,  -281,    42,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,   613,  -281,
     283,  -281,   284,   287,  -281,  -281,  -281,   613,   280,   334,
     288,   278,    37,   334,  -281,    26,  -281,   334,  -281,  -281,
    -281,  -281,  -281,   334,  -281,  -281,  -281,  -281,  -281
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      41,     0,    66,    40,     0,    41,     3,    36,    25,     0,
      42,    37,    35,    73,    66,     0,     0,    65,     0,     1,
       4,    24,     5,    39,    38,    66,     0,    72,    70,     0,
      51,    55,    56,    45,     0,    51,    49,    66,     0,   190,
      75,    68,     0,    20,    49,    54,    52,    47,    46,     0,
      53,    19,     0,     9,    48,     0,     0,    77,    20,    58,
      60,    61,     0,    67,     0,    43,    50,     0,     0,    16,
      58,     0,     0,   109,   108,   106,     0,     7,    74,    77,
      80,     0,     0,     0,    64,    59,    81,   192,   193,   191,
      71,    69,    44,     9,    18,    13,    12,     0,    68,   107,
       8,    90,     0,    11,     6,    21,    68,    76,    58,     0,
       0,     0,     0,   171,   172,   173,   222,   219,   223,   221,
     220,    73,   217,   212,   216,   226,   218,     0,   224,   227,
      57,   194,   195,   197,   199,   201,   203,   205,   207,   209,
     115,   225,    63,     7,    17,    14,    67,     0,    90,     0,
      90,     0,    30,     0,    27,    25,   217,     0,     0,    91,
      87,    88,    25,     0,     0,   112,   212,    25,    25,     0,
      67,     0,     0,     0,   228,     0,     0,     0,   175,     0,
     170,     0,   160,     0,   160,     0,     0,   239,   240,   237,
     238,     0,   233,   234,   235,   236,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,   116,    10,    15,   105,
     104,    90,     0,     0,   168,   169,     0,     0,    23,    25,
      31,    82,    83,    84,    85,    86,   101,    94,    95,     0,
      92,    93,    89,    97,    32,    99,   100,     0,   110,   103,
     102,    34,    33,    22,    79,    78,    62,   150,     0,   230,
       0,   133,     0,     0,     0,     0,   175,   156,     0,   158,
     157,     0,   196,   198,   200,   202,   206,   204,   208,   210,
     211,   213,   215,   214,   126,   144,   128,   129,     0,     0,
     114,   121,     0,   118,   119,   120,   135,     0,    98,   161,
     162,     0,     0,     0,    90,    96,   132,   229,     0,   231,
      90,     0,   178,   177,     0,     0,   174,   181,   188,   187,
       0,     0,    25,    25,     0,     0,   141,   147,   145,   137,
     130,   127,   124,   122,   125,   123,    98,     0,     0,    90,
      26,    68,   232,   131,   151,   153,     0,    90,   189,     0,
     182,   176,   159,   154,   155,   143,   142,   146,     0,   148,
      68,   138,     0,     0,   164,   165,   163,    67,     0,    90,
       0,   186,     0,    90,   149,   144,   139,    90,   167,   134,
     152,   179,   185,    90,   180,   183,   136,   166,   184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -281,  -281,  -281,   291,   155,   213,   238,   234,   161,  -281,
    -281,  -281,    43,  -281,   -72,  -149,  -281,  -281,  -281,   -98,
     101,  -281,  -281,  -281,  -281,  -281,  -281,  -281,   240,   273,
    -281,    16,  -281,   -31,  -281,   230,  -281,    39,   -97,  -281,
     252,  -281,    -1,  -281,   -54,   104,  -281,   266,  -281,  -122,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,   148,  -281,
    -281,   172,  -281,  -281,  -281,  -281,   -91,  -281,  -281,  -281,
    -281,  -281,    23,  -281,   115,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,   -43,    41,  -281,  -281,  -281,
    -281,   143,  -281,  -281,  -281,  -280,  -281,    69,  -281,  -281,
    -281,  -281,  -281,   -36,  -281,  -281,  -281,   -79,  -281,   144,
     145,   139,   136,   147,   138,   149,    -3,  -281,  -281,  -281,
    -281
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,   103,    77,     7,    53,    69,    70,
      94,    71,    57,   104,   214,    22,   219,   152,   153,   215,
     155,    25,     9,    10,    31,    47,    48,    32,    33,    45,
      46,    43,    35,    84,    85,    59,    11,    16,    64,    17,
      27,    41,   122,    12,    60,    61,   106,    40,   226,   157,
     158,   159,   232,   160,   161,   162,   163,   238,    54,    98,
      99,    75,   164,   165,   205,   206,   123,   280,   324,   281,
     282,   283,   250,   251,   240,   285,   350,   351,   315,   316,
     286,   317,   318,   348,   349,   319,   124,   125,   334,   126,
     127,   258,   291,   355,   167,   216,   128,   255,   129,   179,
     339,   340,   306,   307,   308,    62,    89,   168,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   196,
     191
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,   147,    80,   154,   130,   105,   220,    29,    88,   171,
     166,    29,    29,   234,    28,    36,    86,    37,   241,   242,
     335,    56,    -2,   169,    51,   109,   212,  -140,    44,    15,
     173,   175,    34,   -67,   180,   237,   197,    44,     1,    95,
       2,    65,   177,   109,    13,   110,   178,   362,    68,   356,
      72,    44,    81,    26,    58,    44,    52,   361,   181,   166,
     182,    44,    28,   373,    38,    52,    44,   233,   363,   173,
     294,   105,    42,     2,   198,    44,    55,   172,   -28,   370,
      44,    44,   101,   375,   235,   322,    21,   377,     1,   287,
       2,     3,   102,   378,    18,    74,    44,   252,   254,    79,
     156,     8,    19,   259,   248,   259,     8,   183,   249,   184,
     298,   271,   272,   273,   299,   311,   244,   312,   111,   100,
     112,    39,   187,   188,   107,   189,   190,    21,   113,   114,
     115,    49,   173,   305,   192,   193,   194,   195,   293,    63,
     145,     3,   311,    72,   313,    44,    30,    73,    65,   156,
      30,    30,    13,   202,   203,   204,    13,    13,   296,   289,
      30,    23,    24,   343,   344,   116,    13,   117,   118,    44,
      13,    13,    66,   119,   120,    67,   309,    13,   354,   148,
      52,   110,   274,   101,   275,    76,   237,    81,   121,    74,
     276,   277,    82,   200,   201,   278,   330,   269,   270,   301,
      83,    91,    51,   166,   221,   222,   223,   224,   225,   166,
      96,    97,    44,   142,   144,   279,   146,   170,   186,   333,
     176,   185,   213,   199,   210,   217,   338,  -111,   218,   245,
     236,   309,   342,   247,   358,   256,   257,   243,   166,     1,
     246,     2,   288,   -41,   -41,   260,   166,   292,   352,   353,
     295,   297,    44,   366,   111,   300,   112,   360,   302,   197,
     149,   150,   151,   320,   113,   114,   115,   321,   166,   364,
    -113,   326,   166,   327,   314,   328,   166,   329,   333,   336,
     337,   323,   166,   309,   346,   345,   347,   357,   365,   369,
     359,   367,     3,   156,   368,   371,    20,   372,   207,   156,
      87,   116,    93,   117,   118,   208,   143,    92,    50,   119,
     120,   148,   108,   110,   239,    90,   -29,   290,   209,   331,
     284,    78,   376,   325,   121,   310,   374,   261,   156,   262,
     264,   263,   265,     0,     0,   266,   156,     0,     0,     0,
     148,     0,   110,     0,   101,   267,     0,     0,   268,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,     0,
       0,     0,   156,     0,   314,     0,   156,     0,     0,     0,
       0,     1,   156,     2,     0,   -41,   -41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,     0,   112,     0,
       0,     0,   149,   150,   151,     0,   113,   114,   115,     0,
       1,     0,     2,     0,   -41,   -41,     0,     0,     0,     0,
       0,     0,   148,     0,   110,   111,     0,   112,     0,     0,
       0,   149,   150,   151,     3,   113,   114,   115,     0,     0,
       0,     0,     0,   116,     0,   117,   118,   109,     0,   110,
       0,   119,   120,   227,   228,     0,     0,     0,   229,     0,
       0,     0,     0,     3,     0,     0,   121,     0,     0,     0,
       0,     0,   116,     0,   117,   118,     0,     0,     0,     0,
     119,   120,     1,     0,     2,     0,   -41,   -41,     0,   109,
       0,   110,     0,     0,   303,   121,     0,   111,     0,   112,
       0,     0,     0,   149,   150,   151,     0,   113,   114,   115,
       0,   109,     0,   110,     0,     0,   341,     0,     0,     0,
       0,     0,   111,     0,   112,     0,     0,     0,     0,     0,
       0,     0,   113,   114,   115,     3,     0,     0,     0,     0,
     109,     0,   110,   174,   116,     0,   117,   118,     0,     0,
       0,     0,   119,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,   304,   112,   121,   109,   116,
     110,   117,   118,     0,   113,   114,   115,   119,   120,   305,
       0,     0,     0,     0,     0,     0,   111,   304,   112,     0,
     230,   231,   121,     0,     0,     0,   113,   114,   115,     0,
       0,   305,   109,     0,   110,   332,     0,     0,     0,     0,
       0,   116,     0,   117,   118,   111,     0,   112,     0,   119,
     120,     0,     0,     0,     0,   113,   114,   115,     0,   109,
       0,   110,   253,   116,   121,   117,   118,     0,     0,     0,
       0,   119,   120,   111,     0,   112,     0,     0,     0,     0,
       0,     0,     0,   113,   114,   115,   121,     0,     0,   211,
       0,   110,   116,     0,   117,   118,     0,     0,     0,     0,
     119,   120,     0,     0,     0,     0,     0,   111,     0,   112,
       0,     0,     0,     0,     0,   121,     0,   113,   114,   115,
     116,     0,   117,   118,     0,     0,     0,     0,   119,   120,
       0,     0,     0,     0,   111,     0,   112,     0,     0,     0,
       0,     0,     0,   121,   113,   114,   115,     0,     0,     0,
       0,     0,     0,     0,   116,     0,   117,   118,     0,     0,
       0,     0,   119,   120,   111,     0,   112,     0,     0,     0,
       0,     0,     0,     0,   113,   114,   115,   121,     0,     0,
       0,   116,     0,   117,   118,     0,     0,     0,     0,   119,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,     0,     0,
       0,   116,     0,   117,   118,     0,     0,     0,     0,   119,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121
};

static const yytype_int16 yycheck[] =
{
       1,    98,    56,   101,    83,    77,   155,     6,    62,   106,
     101,     6,     6,   162,    15,    16,    11,    18,   167,   168,
     300,     6,     0,   102,     6,     6,   148,     7,    29,    38,
     109,   110,    16,     7,   113,     8,    58,    38,    66,    70,
      68,     7,     6,     6,   151,     8,    10,     5,    49,   329,
      51,    52,    18,    14,    38,    56,    38,   337,     4,   150,
       6,    62,    63,    26,    25,    38,    67,   158,    26,   148,
     219,   143,    29,    68,    96,    76,    37,   108,    11,   359,
      81,    82,    10,   363,   163,    66,    19,   367,    66,   211,
      68,   119,    20,   373,    66,    52,    97,   176,   177,    56,
     101,     0,     0,   182,     5,   184,     5,     4,     9,     6,
       5,   202,   203,   204,     9,     5,   170,     7,    81,    76,
      83,    10,    43,    44,    81,    46,    47,    19,    91,    92,
      93,     4,   211,    96,    38,    39,    40,    41,   217,     5,
      97,   119,     5,   144,     7,   146,   145,   146,     7,   150,
     145,   145,   151,   146,   147,   148,   151,   151,   237,   213,
     145,    70,    71,   312,   313,   128,   151,   130,   131,   170,
     151,   151,    37,   136,   137,     4,   255,   151,     5,     6,
      38,     8,     4,    10,     6,    18,     8,    18,   151,   146,
      12,    13,     4,   149,   150,    17,   294,   200,   201,   253,
      20,    39,     6,   294,    21,    22,    23,    24,    25,   300,
       7,    18,   213,    19,     5,    37,     5,     5,    14,   298,
       6,    15,     6,    28,    39,     6,   305,    20,    11,     7,
      20,   310,   311,     7,   331,    10,   151,    19,   329,    66,
      19,    68,     7,    70,    71,   151,   337,    89,   327,   328,
      17,     9,   253,   350,    81,     7,    83,   336,     7,    58,
      87,    88,    89,    17,    91,    92,    93,     4,   359,   348,
      20,     7,   363,    96,   275,     6,   367,     7,   357,    20,
      26,   282,   373,   362,     7,    20,   146,     5,     5,     9,
      82,     7,   119,   294,     7,     7,     5,    19,   143,   300,
      62,   128,    68,   130,   131,   144,    93,    67,    35,   136,
     137,     6,    82,     8,   166,    63,    11,   213,   146,   296,
     205,    55,   365,   282,   151,   256,   362,   184,   329,   185,
     191,   186,   196,    -1,    -1,   197,   337,    -1,    -1,    -1,
       6,    -1,     8,    -1,    10,   198,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   359,    -1,
      -1,    -1,   363,    -1,   365,    -1,   367,    -1,    -1,    -1,
      -1,    66,   373,    68,    -1,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    83,    -1,
      -1,    -1,    87,    88,    89,    -1,    91,    92,    93,    -1,
      66,    -1,    68,    -1,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,     8,    81,    -1,    83,    -1,    -1,
      -1,    87,    88,    89,   119,    91,    92,    93,    -1,    -1,
      -1,    -1,    -1,   128,    -1,   130,   131,     6,    -1,     8,
      -1,   136,   137,    12,    13,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,   119,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,   128,    -1,   130,   131,    -1,    -1,    -1,    -1,
     136,   137,    66,    -1,    68,    -1,    70,    71,    -1,     6,
      -1,     8,    -1,    -1,    11,   151,    -1,    81,    -1,    83,
      -1,    -1,    -1,    87,    88,    89,    -1,    91,    92,    93,
      -1,     6,    -1,     8,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,   119,    -1,    -1,    -1,    -1,
       6,    -1,     8,     9,   128,    -1,   130,   131,    -1,    -1,
      -1,    -1,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,   151,     6,   128,
       8,   130,   131,    -1,    91,    92,    93,   136,   137,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,
     149,   150,   151,    -1,    -1,    -1,    91,    92,    93,    -1,
      -1,    96,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,   128,    -1,   130,   131,    81,    -1,    83,    -1,   136,
     137,    -1,    -1,    -1,    -1,    91,    92,    93,    -1,     6,
      -1,     8,    70,   128,   151,   130,   131,    -1,    -1,    -1,
      -1,   136,   137,    81,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,   151,    -1,    -1,     6,
      -1,     8,   128,    -1,   130,   131,    -1,    -1,    -1,    -1,
     136,   137,    -1,    -1,    -1,    -1,    -1,    81,    -1,    83,
      -1,    -1,    -1,    -1,    -1,   151,    -1,    91,    92,    93,
     128,    -1,   130,   131,    -1,    -1,    -1,    -1,   136,   137,
      -1,    -1,    -1,    -1,    81,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,   151,    91,    92,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,    -1,   130,   131,    -1,    -1,
      -1,    -1,   136,   137,    81,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,   151,    -1,    -1,
      -1,   128,    -1,   130,   131,    -1,    -1,    -1,    -1,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,   130,   131,    -1,    -1,    -1,    -1,   136,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   151
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    66,    68,   119,   156,   157,   158,   161,   175,   177,
     178,   191,   198,   151,   197,    38,   192,   194,    66,     0,
     158,    19,   170,    70,    71,   176,   192,   195,   197,     6,
     145,   179,   182,   183,   186,   187,   197,   197,   192,    10,
     202,   196,   167,   186,   197,   184,   185,   180,   181,     4,
     184,     6,    38,   162,   213,   192,     6,   167,   186,   190,
     199,   200,   260,     5,   193,     7,    37,     4,   197,   163,
     164,   166,   197,   146,   167,   216,    18,   160,   202,   167,
     199,    18,     4,    20,   188,   189,    11,   161,   199,   261,
     195,    39,   183,   162,   165,   188,     7,    18,   214,   215,
     167,    10,    20,   159,   168,   169,   201,   167,   190,     6,
       8,    81,    83,    91,    92,    93,   128,   130,   131,   136,
     137,   151,   197,   221,   241,   242,   244,   245,   251,   253,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,    19,   160,     5,   167,     5,   193,     6,    87,
      88,    89,   172,   173,   174,   175,   197,   204,   205,   206,
     208,   209,   210,   211,   217,   218,   221,   249,   262,   262,
       5,   193,   188,   262,     9,   262,     6,     6,    10,   254,
     262,     4,     6,     4,     6,    15,    14,    43,    44,    46,
      47,   275,    38,    39,    40,    41,   274,    58,    96,    28,
     149,   150,   146,   147,   148,   219,   220,   159,   163,   216,
      39,     6,   204,     6,   169,   174,   250,     6,    11,   171,
     170,    21,    22,    23,    24,    25,   203,    12,    13,    17,
     149,   150,   207,   221,   170,   262,    20,     8,   212,   213,
     229,   170,   170,    19,   199,     7,    19,     7,     5,     9,
     227,   228,   262,    70,   262,   252,    10,   151,   246,   262,
     151,   246,   264,   265,   266,   267,   269,   268,   270,   271,
     271,   221,   221,   221,     4,     6,    12,    13,    17,    37,
     222,   224,   225,   226,   229,   230,   235,   204,     7,   199,
     200,   247,    89,   262,   170,    17,   262,     9,     5,     9,
       7,   199,     7,    11,    82,    96,   257,   258,   259,   262,
     252,     5,     7,     7,   197,   233,   234,   236,   237,   240,
      17,     4,    66,   197,   223,   241,     7,    96,     6,     7,
     174,   227,     9,   262,   243,   250,    20,    26,   262,   255,
     256,    11,   262,   170,   170,    20,     7,   146,   238,   239,
     231,   232,   262,   262,     5,   248,   250,     5,   193,    82,
     262,   250,     5,    26,   262,     5,   193,     7,     7,     9,
     250,     7,    19,    26,   258,   250,   240,   250,   250
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   155,   156,   157,   157,   158,   159,   159,   160,   160,
     161,   161,   162,   163,   164,   165,   165,   166,   166,   166,
     167,   168,   168,   169,   170,   170,   171,   171,   172,   172,
     173,   174,   174,   174,   174,   175,   175,   175,   176,   176,
     177,   178,   177,   179,   180,   181,   180,   182,   183,   183,
     184,   185,   184,   186,   186,   187,   187,   188,   189,   188,
     190,   190,   191,   191,   191,   192,   192,   193,   193,   194,
     195,   196,   196,   197,   198,   198,   199,   199,   200,   201,
     201,   202,   203,   203,   203,   203,   203,   204,   204,   205,
     206,   205,   207,   207,   207,   207,   207,   208,   209,   210,
     211,   211,   212,   212,   213,   214,   215,   214,   216,   216,
     217,   217,   217,   218,   219,   220,   219,   221,   222,   222,
     222,   222,   223,   223,   223,   224,   225,   225,   226,   226,
     226,   227,   228,   227,   229,   230,   231,   232,   231,   233,
     234,   233,   235,   236,   237,   236,   238,   239,   238,   240,
     241,   242,   243,   243,   244,   244,   245,   245,   246,   246,
     246,   247,   247,   248,   248,   249,   249,   249,   250,   250,
     251,   251,   251,   251,   252,   252,   253,   253,   254,   254,
     255,   256,   255,   257,   257,   257,   257,   258,   258,   259,
     260,   260,   261,   261,   262,   263,   263,   264,   264,   265,
     265,   266,   266,   267,   267,   268,   268,   269,   269,   270,
     270,   270,   271,   271,   271,   271,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   273,   273,
     273,   273,   273,   274,   274,   274,   274,   275,   275,   275,
     275
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     0,     2,     0,
       8,     6,     3,     2,     3,     3,     0,     3,     2,     0,
       1,     1,     3,     3,     1,     0,     3,     0,     2,     0,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     0,     1,     3,     3,     0,     1,     2,     2,     1,
       2,     0,     1,     2,     2,     1,     1,     2,     0,     1,
       1,     1,     8,     6,     5,     1,     0,     1,     0,     5,
       1,     3,     0,     1,     5,     4,     3,     1,     5,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     1,     1,     1,     1,     1,     2,     2,     3,     2,
       2,     2,     1,     1,     5,     3,     0,     1,     1,     1,
       2,     1,     1,     3,     2,     0,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     1,
       2,     3,     0,     1,     5,     1,     3,     0,     1,     3,
       0,     1,     3,     2,     0,     1,     1,     0,     1,     3,
       3,     5,     3,     1,     5,     5,     3,     3,     1,     3,
       0,     1,     1,     1,     1,     5,     7,     6,     1,     1,
       2,     1,     1,     1,     2,     0,     5,     4,     3,     6,
       3,     0,     1,     4,     5,     4,     3,     1,     1,     2,
       0,     2,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       3,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: topLevelObjects  */
#line 53 "k0gram.y"
                    {root = (yyvsp[0].treeptr); (yyval.treeptr) = alctree(1000, "program", 1, (yyvsp[0].treeptr));}
#line 1773 "k0gram.tab.c"
    break;

  case 3: /* topLevelObjects: topLevelObject  */
#line 57 "k0gram.y"
                   {(yyval.treeptr) = alctree(1001, "topLevelObjects", 1, (yyvsp[0].treeptr));}
#line 1779 "k0gram.tab.c"
    break;

  case 4: /* topLevelObjects: topLevelObjects topLevelObject  */
#line 58 "k0gram.y"
                                   {(yyval.treeptr) = alctree(1001, "topLevelObjects", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1785 "k0gram.tab.c"
    break;

  case 5: /* topLevelObject: declaration semis  */
#line 62 "k0gram.y"
                     {(yyval.treeptr) = alctree(1002, "topLevelObject", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1791 "k0gram.tab.c"
    break;

  case 6: /* opt_functionBody: functionBody  */
#line 66 "k0gram.y"
                 {(yyval.treeptr) = alctree(1003, "opt_functionBody", 1, (yyvsp[0].treeptr));}
#line 1797 "k0gram.tab.c"
    break;

  case 7: /* opt_functionBody: %empty  */
#line 67 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1803 "k0gram.tab.c"
    break;

  case 8: /* opt_colon_type: COLON type  */
#line 71 "k0gram.y"
             {(yyval.treeptr) = alctree(1100, "opt_colon_type", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1809 "k0gram.tab.c"
    break;

  case 9: /* opt_colon_type: %empty  */
#line 72 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1815 "k0gram.tab.c"
    break;

  case 10: /* functionDeclaration: FUN opt_typeParameters nullableType DOT simpleIdentifier functionValueParameters opt_colon_type opt_functionBody  */
#line 77 "k0gram.y"
                                                                                                                     {(yyval.treeptr) = alctree(1004, "functionDeclaration", 8, (yyvsp[-7].treeptr), (yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1821 "k0gram.tab.c"
    break;

  case 11: /* functionDeclaration: FUN opt_typeParameters simpleIdentifier functionValueParameters opt_colon_type opt_functionBody  */
#line 78 "k0gram.y"
                                                                                                      {(yyval.treeptr) = alctree(1004, "functionDeclaration",6, (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1827 "k0gram.tab.c"
    break;

  case 12: /* functionValueParameters: LPAREN opt_functionValueParameter RPAREN  */
#line 83 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1005, "functionValueParameters", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1833 "k0gram.tab.c"
    break;

  case 13: /* functionValueParameter: parameter opt_eq_exp  */
#line 87 "k0gram.y"
                       {(yyval.treeptr) = alctree(1006, "functionValueParameter", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1839 "k0gram.tab.c"
    break;

  case 14: /* parameter: simpleIdentifier COLON type  */
#line 91 "k0gram.y"
                              {(yyval.treeptr) = alctree(1007, "parameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1845 "k0gram.tab.c"
    break;

  case 15: /* multi_comma_functionParameter: multi_comma_functionParameter COMMA functionValueParameter  */
#line 95 "k0gram.y"
                                                             {(yyval.treeptr) = alctree(1008, "multi_comma_functionParameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1851 "k0gram.tab.c"
    break;

  case 16: /* multi_comma_functionParameter: %empty  */
#line 96 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1857 "k0gram.tab.c"
    break;

  case 17: /* opt_functionValueParameter: functionValueParameter multi_comma_functionParameter COMMA  */
#line 100 "k0gram.y"
                                                             {(yyval.treeptr) = alctree(1009, "opt_functionValueParameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1863 "k0gram.tab.c"
    break;

  case 18: /* opt_functionValueParameter: functionValueParameter multi_comma_functionParameter  */
#line 101 "k0gram.y"
                                                         {(yyval.treeptr) = alctree(1009, "opt_functionValueParameter", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1869 "k0gram.tab.c"
    break;

  case 19: /* opt_functionValueParameter: %empty  */
#line 102 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1875 "k0gram.tab.c"
    break;

  case 20: /* type: nullableType  */
#line 107 "k0gram.y"
               {(yyval.treeptr) = alctree(1010, "type", 1, (yyvsp[0].treeptr));}
#line 1881 "k0gram.tab.c"
    break;

  case 21: /* functionBody: block  */
#line 112 "k0gram.y"
          {(yyval.treeptr) = alctree(1011, "functionBody", 1, (yyvsp[0].treeptr));}
#line 1887 "k0gram.tab.c"
    break;

  case 22: /* functionBody: ASSIGNMENT expression SEMICOLON  */
#line 113 "k0gram.y"
                                    {(yyval.treeptr) = alctree(1011, "functionBody", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1893 "k0gram.tab.c"
    break;

  case 23: /* block: LCURL statements RCURL  */
#line 118 "k0gram.y"
                            {(yyval.treeptr) = alctree(1012, "block", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));  }
#line 1899 "k0gram.tab.c"
    break;

  case 25: /* semis: %empty  */
#line 124 "k0gram.y"
    {(yyval.treeptr) = NULL;}
#line 1905 "k0gram.tab.c"
    break;

  case 26: /* semis_statement: semis_statement semis statement  */
#line 128 "k0gram.y"
                                  {(yyval.treeptr) = alctree(1013, "semis_statement", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1911 "k0gram.tab.c"
    break;

  case 27: /* semis_statement: %empty  */
#line 129 "k0gram.y"
           {(yyval.treeptr) = NULL;}
#line 1917 "k0gram.tab.c"
    break;

  case 28: /* optional_statement_sequence: statement semis_statement  */
#line 134 "k0gram.y"
                                {(yyval.treeptr) = alctree(1014, "optional_statement_sequence", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1923 "k0gram.tab.c"
    break;

  case 29: /* optional_statement_sequence: %empty  */
#line 135 "k0gram.y"
            {(yyval.treeptr) = NULL;}
#line 1929 "k0gram.tab.c"
    break;

  case 30: /* statements: optional_statement_sequence  */
#line 139 "k0gram.y"
                               {(yyval.treeptr) = alctree(1015, "statements", 1, (yyvsp[0].treeptr));}
#line 1935 "k0gram.tab.c"
    break;

  case 31: /* statement: declaration semis  */
#line 145 "k0gram.y"
                     {(yyval.treeptr) = alctree(1016, "statement", 2,(yyvsp[-1].treeptr),(yyvsp[0].treeptr)); }
#line 1941 "k0gram.tab.c"
    break;

  case 32: /* statement: assignment semis  */
#line 146 "k0gram.y"
                      {(yyval.treeptr) = alctree(1016, "statement", 2,(yyvsp[-1].treeptr),(yyvsp[0].treeptr)); }
#line 1947 "k0gram.tab.c"
    break;

  case 33: /* statement: expression semis  */
#line 147 "k0gram.y"
                      {(yyval.treeptr) = alctree(1016, "statement", 2,(yyvsp[-1].treeptr),(yyvsp[0].treeptr)); }
#line 1953 "k0gram.tab.c"
    break;

  case 34: /* statement: loopStatement semis  */
#line 148 "k0gram.y"
                       {(yyval.treeptr) = alctree(1016, "statement", 2,(yyvsp[-1].treeptr),(yyvsp[0].treeptr)); }
#line 1959 "k0gram.tab.c"
    break;

  case 35: /* declaration: classDeclaration  */
#line 152 "k0gram.y"
                   {(yyval.treeptr) = alctree(1017, "declaration", 1, (yyvsp[0].treeptr));}
#line 1965 "k0gram.tab.c"
    break;

  case 36: /* declaration: functionDeclaration  */
#line 153 "k0gram.y"
                       {(yyval.treeptr) = alctree(1017, "declaration", 1, (yyvsp[0].treeptr));}
#line 1971 "k0gram.tab.c"
    break;

  case 37: /* declaration: propertyDeclaration  */
#line 154 "k0gram.y"
                        {(yyval.treeptr) = alctree(1017, "declaration", 1, (yyvsp[0].treeptr));}
#line 1977 "k0gram.tab.c"
    break;

  case 38: /* val_var: VAR  */
#line 158 "k0gram.y"
      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1983 "k0gram.tab.c"
    break;

  case 39: /* val_var: VAL  */
#line 159 "k0gram.y"
        {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1989 "k0gram.tab.c"
    break;

  case 40: /* opt_modifier: CONST  */
#line 163 "k0gram.y"
        {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1995 "k0gram.tab.c"
    break;

  case 41: /* $@1: %empty  */
#line 164 "k0gram.y"
    { /* epsilon production */ }
#line 2001 "k0gram.tab.c"
    break;

  case 42: /* opt_modifier: $@1  */
#line 164 "k0gram.y"
                                 {(yyval.treeptr) = NULL;}
#line 2007 "k0gram.tab.c"
    break;

  case 43: /* parenthesizedType: LPAREN type RPAREN  */
#line 169 "k0gram.y"
                     {(yyval.treeptr) = alctree(1019, "parenthesizedType", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2013 "k0gram.tab.c"
    break;

  case 44: /* multi_dot_simpleUserType: multi_dot_simpleUserType DOT simpleUserType  */
#line 175 "k0gram.y"
                                              {(yyval.treeptr) = alctree(1020, "multi_dot_simpleUserType", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2019 "k0gram.tab.c"
    break;

  case 45: /* $@2: %empty  */
#line 176 "k0gram.y"
    { /* epsilon production */ }
#line 2025 "k0gram.tab.c"
    break;

  case 46: /* multi_dot_simpleUserType: $@2  */
#line 176 "k0gram.y"
                                 {(yyval.treeptr) = NULL;}
#line 2031 "k0gram.tab.c"
    break;

  case 47: /* userType: simpleUserType multi_dot_simpleUserType  */
#line 180 "k0gram.y"
                                          {(yyval.treeptr) = alctree(1021, "userType", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2037 "k0gram.tab.c"
    break;

  case 48: /* simpleUserType: simpleIdentifier typeArguments  */
#line 185 "k0gram.y"
                                {(yyval.treeptr) = alctree(1022, "simpleUserType", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2043 "k0gram.tab.c"
    break;

  case 49: /* simpleUserType: simpleIdentifier  */
#line 186 "k0gram.y"
                    {(yyval.treeptr) = alctree(1022, "simpleUserType", 1, (yyvsp[0].treeptr));}
#line 2049 "k0gram.tab.c"
    break;

  case 50: /* multi_quest: multi_quest QUEST_NO_WS  */
#line 191 "k0gram.y"
                          {(yyval.treeptr) = alctree(1023, "multi_quest", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2055 "k0gram.tab.c"
    break;

  case 51: /* $@3: %empty  */
#line 192 "k0gram.y"
    { /* epsilon production */ }
#line 2061 "k0gram.tab.c"
    break;

  case 52: /* multi_quest: $@3  */
#line 192 "k0gram.y"
                                 {(yyval.treeptr) = NULL;}
#line 2067 "k0gram.tab.c"
    break;

  case 53: /* nullableType: typeRef_parenthesizedType multi_quest  */
#line 195 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1024, "nullableType", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2073 "k0gram.tab.c"
    break;

  case 54: /* nullableType: TYPELITERAL multi_quest  */
#line 196 "k0gram.y"
                           {(yyval.treeptr) = alctree(1024, "nullableType", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2079 "k0gram.tab.c"
    break;

  case 55: /* typeRef_parenthesizedType: parenthesizedType  */
#line 201 "k0gram.y"
                    {(yyval.treeptr) = alctree(1025, "typeRef_parenthesizedType", 1, (yyvsp[0].treeptr));}
#line 2085 "k0gram.tab.c"
    break;

  case 56: /* typeRef_parenthesizedType: userType  */
#line 202 "k0gram.y"
              {(yyval.treeptr) = alctree(1025, "typeRef_parenthesizedType", 1, (yyvsp[0].treeptr));}
#line 2091 "k0gram.tab.c"
    break;

  case 57: /* opt_eq_exp: ASSIGNMENT expression  */
#line 207 "k0gram.y"
                        {(yyval.treeptr) = alctree(1026, "opt_eq_exp", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2097 "k0gram.tab.c"
    break;

  case 58: /* $@4: %empty  */
#line 208 "k0gram.y"
    { /* epsilon production */ }
#line 2103 "k0gram.tab.c"
    break;

  case 59: /* opt_eq_exp: $@4  */
#line 208 "k0gram.y"
                                 {(yyval.treeptr) = NULL;}
#line 2109 "k0gram.tab.c"
    break;

  case 60: /* multivariable_variableDeclaration: variableDeclaration  */
#line 213 "k0gram.y"
                      {(yyval.treeptr) = alctree(1027, "multivariable_variableDeclaration", 1, (yyvsp[0].treeptr));}
#line 2115 "k0gram.tab.c"
    break;

  case 61: /* multivariable_variableDeclaration: multiVariableDeclaration  */
#line 214 "k0gram.y"
                             {(yyval.treeptr) = alctree(1027, "multivariable_variableDeclaration", 1, (yyvsp[0].treeptr));}
#line 2121 "k0gram.tab.c"
    break;

  case 62: /* propertyDeclaration: opt_modifier val_var opt_typeParameters nullableType DOT multivariable_variableDeclaration opt_eq_exp SEMICOLON  */
#line 218 "k0gram.y"
                                                                                                                    {(yyval.treeptr) = alctree(1028, "propertyDeclaration", 8, (yyvsp[-7].treeptr), (yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2127 "k0gram.tab.c"
    break;

  case 63: /* propertyDeclaration: opt_modifier val_var opt_typeParameters multivariable_variableDeclaration opt_eq_exp SEMICOLON  */
#line 219 "k0gram.y"
                                                                                                   {(yyval.treeptr) = alctree(1028, "propertyDeclaration", 6, (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2133 "k0gram.tab.c"
    break;

  case 64: /* propertyDeclaration: opt_modifier val_var opt_typeParameters multivariable_variableDeclaration opt_eq_exp  */
#line 220 "k0gram.y"
                                                                                         {(yyval.treeptr) = alctree(1028, "propertyDeclaration", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr) );}
#line 2139 "k0gram.tab.c"
    break;

  case 65: /* opt_typeParameters: typeParameters  */
#line 225 "k0gram.y"
                    {(yyval.treeptr) = alctree(1029, "opt_typeParameters", 1, (yyvsp[0].treeptr));}
#line 2145 "k0gram.tab.c"
    break;

  case 66: /* opt_typeParameters: %empty  */
#line 226 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 2151 "k0gram.tab.c"
    break;

  case 67: /* opt_comma: COMMA  */
#line 230 "k0gram.y"
          {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2157 "k0gram.tab.c"
    break;

  case 68: /* opt_comma: %empty  */
#line 231 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 2163 "k0gram.tab.c"
    break;

  case 69: /* typeParameters: LANGLE typeParameter multi_typeParameter opt_comma RANGLE  */
#line 234 "k0gram.y"
                                                              {(yyval.treeptr) = alctree(1030, "typeParameters", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2169 "k0gram.tab.c"
    break;

  case 70: /* typeParameter: simpleIdentifier  */
#line 238 "k0gram.y"
                      {(yyval.treeptr) = alctree(1031, "typeParameter", 1, (yyvsp[0].treeptr));}
#line 2175 "k0gram.tab.c"
    break;

  case 71: /* multi_typeParameter: multi_typeParameter COMMA typeParameter  */
#line 243 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1032, "multi_typeParameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2181 "k0gram.tab.c"
    break;

  case 72: /* multi_typeParameter: %empty  */
#line 244 "k0gram.y"
                 {(yyval.treeptr) = NULL;}
#line 2187 "k0gram.tab.c"
    break;

  case 74: /* classDeclaration: CONST CLASS simpleIdentifier opt_typeParameters classBody  */
#line 252 "k0gram.y"
                                                               {  (yyval.treeptr) = alctree(1033, "classDeclaration", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2193 "k0gram.tab.c"
    break;

  case 75: /* classDeclaration: CLASS simpleIdentifier opt_typeParameters classBody  */
#line 253 "k0gram.y"
                                                          {(yyval.treeptr) = alctree(1033, "classDeclaration", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2199 "k0gram.tab.c"
    break;

  case 76: /* variableDeclaration: type COLON type  */
#line 257 "k0gram.y"
                     {(yyval.treeptr) = alctree(1034, "variableDeclaration", 3, (yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr) );}
#line 2205 "k0gram.tab.c"
    break;

  case 77: /* variableDeclaration: type  */
#line 258 "k0gram.y"
          {(yyval.treeptr) = alctree(1034, "variableDeclaration", 1, (yyvsp[0].treeptr));}
#line 2211 "k0gram.tab.c"
    break;

  case 78: /* multiVariableDeclaration: LPAREN variableDeclaration multi_comma_variableDeclaration opt_comma RPAREN  */
#line 262 "k0gram.y"
                                                                               {(yyval.treeptr) = alctree(1035, "multiVariableDeclaration", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2217 "k0gram.tab.c"
    break;

  case 79: /* multi_comma_variableDeclaration: multi_comma_variableDeclaration COMMA variableDeclaration  */
#line 265 "k0gram.y"
                                                             {(yyval.treeptr) = alctree(1036, "multi_comma_variableDeclaration", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2223 "k0gram.tab.c"
    break;

  case 80: /* multi_comma_variableDeclaration: %empty  */
#line 266 "k0gram.y"
    { /* epsilon production */ }
#line 2229 "k0gram.tab.c"
    break;

  case 81: /* classBody: LCURL classMembers RCURL  */
#line 272 "k0gram.y"
                              {(yyval.treeptr) = alctree(1037, "classBody", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2235 "k0gram.tab.c"
    break;

  case 82: /* assignmentAndOperator: ADD_ASSIGNMENT  */
#line 277 "k0gram.y"
                    {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2241 "k0gram.tab.c"
    break;

  case 83: /* assignmentAndOperator: SUB_ASSIGNMENT  */
#line 278 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2247 "k0gram.tab.c"
    break;

  case 84: /* assignmentAndOperator: MULT_ASSIGNMENT  */
#line 279 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2253 "k0gram.tab.c"
    break;

  case 85: /* assignmentAndOperator: DIV_ASSIGNMENT  */
#line 280 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2259 "k0gram.tab.c"
    break;

  case 86: /* assignmentAndOperator: MOD_ASSIGNMENT  */
#line 281 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2265 "k0gram.tab.c"
    break;

  case 87: /* assignableExpression: prefixUnaryExpression  */
#line 285 "k0gram.y"
                        {(yyval.treeptr) = alctree (1038, "assignableExpression", 1, (yyvsp[0].treeptr));}
#line 2271 "k0gram.tab.c"
    break;

  case 88: /* assignableExpression: parenthesizedAssignableExpression  */
#line 286 "k0gram.y"
                                      {(yyval.treeptr) = alctree (1038, "assignableExpression", 1, (yyvsp[0].treeptr));}
#line 2277 "k0gram.tab.c"
    break;

  case 89: /* multi_unaryPrefix: multi_unaryPrefix prefixUnaryOperator  */
#line 289 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1039, "multi_unaryPrefix", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2283 "k0gram.tab.c"
    break;

  case 90: /* $@5: %empty  */
#line 290 "k0gram.y"
    { /* epsilon production */ }
#line 2289 "k0gram.tab.c"
    break;

  case 91: /* multi_unaryPrefix: $@5  */
#line 290 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2295 "k0gram.tab.c"
    break;

  case 92: /* prefixUnaryOperator: ADD  */
#line 293 "k0gram.y"
         {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2301 "k0gram.tab.c"
    break;

  case 93: /* prefixUnaryOperator: SUB  */
#line 294 "k0gram.y"
           {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2307 "k0gram.tab.c"
    break;

  case 94: /* prefixUnaryOperator: INCR  */
#line 295 "k0gram.y"
            {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2313 "k0gram.tab.c"
    break;

  case 95: /* prefixUnaryOperator: DECR  */
#line 296 "k0gram.y"
            {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2319 "k0gram.tab.c"
    break;

  case 96: /* prefixUnaryOperator: EXCL_NO_WS EXCL_NO_WS  */
#line 297 "k0gram.y"
                           { (yyval.treeptr) = alctree(1040, "prefixUnaryOperator", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2325 "k0gram.tab.c"
    break;

  case 97: /* prefixUnaryExpression: multi_unaryPrefix postfixUnaryExpression  */
#line 302 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1041, "prefixUnaryExpression", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2331 "k0gram.tab.c"
    break;

  case 98: /* parenthesizedAssignableExpression: LPAREN assignableExpression RPAREN  */
#line 306 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1042, "parenthesizedAssignableExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2337 "k0gram.tab.c"
    break;

  case 99: /* assignment: directly_assign expression  */
#line 310 "k0gram.y"
                              {(yyval.treeptr) = alctree(1043, "assignment", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2343 "k0gram.tab.c"
    break;

  case 100: /* directly_assign: directlyAssignableExpression ASSIGNMENT  */
#line 314 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1044, "directly_assign", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2349 "k0gram.tab.c"
    break;

  case 101: /* directly_assign: assignableExpression assignmentAndOperator  */
#line 315 "k0gram.y"
                                                  {(yyval.treeptr) = alctree(1044, "directly_assign", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2355 "k0gram.tab.c"
    break;

  case 102: /* assignableSuffix: indexingSuffix  */
#line 319 "k0gram.y"
                    {(yyval.treeptr) = alctree(1045, "assignableSuffix", 1, (yyvsp[0].treeptr));}
#line 2361 "k0gram.tab.c"
    break;

  case 103: /* assignableSuffix: typeArguments  */
#line 320 "k0gram.y"
                    {(yyval.treeptr) = alctree(1045, "assignableSuffix", 1, (yyvsp[0].treeptr));}
#line 2367 "k0gram.tab.c"
    break;

  case 104: /* typeArguments: LANGLE typeProjection multi_comma_typeProjection opt_comma RANGLE  */
#line 324 "k0gram.y"
                                                                       {(yyval.treeptr) = alctree(1046, "typeArguments", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2373 "k0gram.tab.c"
    break;

  case 105: /* multi_comma_typeProjection: multi_comma_typeProjection COMMA typeProjection  */
#line 328 "k0gram.y"
                                                  {(yyval.treeptr) = alctree(1047, "multi_comma_typeProjection", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2379 "k0gram.tab.c"
    break;

  case 106: /* $@6: %empty  */
#line 329 "k0gram.y"
    { /* epsilon production */ }
#line 2385 "k0gram.tab.c"
    break;

  case 107: /* multi_comma_typeProjection: $@6  */
#line 329 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2391 "k0gram.tab.c"
    break;

  case 108: /* typeProjection: type  */
#line 334 "k0gram.y"
        {(yyval.treeptr) = alctree(1048, "typeProjection", 1, (yyvsp[0].treeptr));}
#line 2397 "k0gram.tab.c"
    break;

  case 109: /* typeProjection: MULT  */
#line 335 "k0gram.y"
          {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2403 "k0gram.tab.c"
    break;

  case 110: /* directlyAssignableExpression: postfixUnaryExpression assignableSuffix  */
#line 338 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1049, "directlyAssignableExpression", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2409 "k0gram.tab.c"
    break;

  case 111: /* directlyAssignableExpression: simpleIdentifier  */
#line 339 "k0gram.y"
                        {(yyval.treeptr) = alctree(1049, "directlyAssignableExpression", 1, (yyvsp[0].treeptr));}
#line 2415 "k0gram.tab.c"
    break;

  case 112: /* directlyAssignableExpression: parenthesizedDirectlyAssignableExpression  */
#line 340 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1049, "directlyAssignableExpression", 1, (yyvsp[0].treeptr));}
#line 2421 "k0gram.tab.c"
    break;

  case 113: /* parenthesizedDirectlyAssignableExpression: LPAREN assignableExpression RPAREN  */
#line 344 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1050, "parenthesizedDirectlyAssignableExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2427 "k0gram.tab.c"
    break;

  case 114: /* multi_postfixUnarySuffix: multi_postfixUnarySuffix postfixUnarySuffix  */
#line 348 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1051, "multi_postfixUnarySuffix", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2433 "k0gram.tab.c"
    break;

  case 115: /* $@7: %empty  */
#line 349 "k0gram.y"
      { /* epsilon production */ }
#line 2439 "k0gram.tab.c"
    break;

  case 116: /* multi_postfixUnarySuffix: $@7  */
#line 349 "k0gram.y"
                                    {(yyval.treeptr) = NULL;}
#line 2445 "k0gram.tab.c"
    break;

  case 117: /* postfixUnaryExpression: primaryExpression multi_postfixUnarySuffix  */
#line 352 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1052, "postfixUnaryExpression", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2451 "k0gram.tab.c"
    break;

  case 118: /* postfixUnarySuffix: postfixUnaryOperator  */
#line 356 "k0gram.y"
                        {(yyval.treeptr) = alctree(1053, "postfixUnarySuffix", 1, (yyvsp[0].treeptr));}
#line 2457 "k0gram.tab.c"
    break;

  case 119: /* postfixUnarySuffix: indexingSuffix  */
#line 357 "k0gram.y"
                    {(yyval.treeptr) = alctree(1053, "postfixUnarySuffix", 1, (yyvsp[0].treeptr));}
#line 2463 "k0gram.tab.c"
    break;

  case 120: /* postfixUnarySuffix: callSuffix  */
#line 358 "k0gram.y"
               {(yyval.treeptr) = alctree(1053, "postfixUnarySuffix", 1, (yyvsp[0].treeptr));}
#line 2469 "k0gram.tab.c"
    break;

  case 121: /* postfixUnarySuffix: navigationSuffix  */
#line 359 "k0gram.y"
                    {(yyval.treeptr) = alctree(1053, "postfixUnarySuffix", 1, (yyvsp[0].treeptr));}
#line 2475 "k0gram.tab.c"
    break;

  case 122: /* identifier_expression_class: simpleIdentifier  */
#line 363 "k0gram.y"
                   {(yyval.treeptr) = alctree(1054, "identifier_expression_class", 1, (yyvsp[0].treeptr));}
#line 2481 "k0gram.tab.c"
    break;

  case 123: /* identifier_expression_class: parenthesizedExpression  */
#line 364 "k0gram.y"
                             {(yyval.treeptr) = alctree(1054, "identifier_expression_class", 1, (yyvsp[0].treeptr));}
#line 2487 "k0gram.tab.c"
    break;

  case 124: /* identifier_expression_class: CLASS  */
#line 365 "k0gram.y"
          {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2493 "k0gram.tab.c"
    break;

  case 125: /* navigationSuffix: memberAccessOperator identifier_expression_class  */
#line 369 "k0gram.y"
                                                   {(yyval.treeptr) = alctree(1055, "navigationSuffix", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2499 "k0gram.tab.c"
    break;

  case 126: /* memberAccessOperator: DOT  */
#line 373 "k0gram.y"
      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2505 "k0gram.tab.c"
    break;

  case 127: /* memberAccessOperator: QUEST_NO_WS DOT  */
#line 374 "k0gram.y"
                    {(yyval.treeptr) = alctree(1056, "memberAccessOperator", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2511 "k0gram.tab.c"
    break;

  case 128: /* postfixUnaryOperator: INCR  */
#line 378 "k0gram.y"
          { (yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2517 "k0gram.tab.c"
    break;

  case 129: /* postfixUnaryOperator: DECR  */
#line 379 "k0gram.y"
            { (yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2523 "k0gram.tab.c"
    break;

  case 130: /* postfixUnaryOperator: EXCL_NO_WS EXCL_NO_WS  */
#line 380 "k0gram.y"
                            { (yyval.treeptr) = alctree(1057, "postfixUnaryOperator", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2529 "k0gram.tab.c"
    break;

  case 131: /* multi_comma_expression: multi_comma_expression COMMA expression  */
#line 384 "k0gram.y"
                                          {(yyval.treeptr) = alctree(1058, "multi_comma_expression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2535 "k0gram.tab.c"
    break;

  case 132: /* $@8: %empty  */
#line 385 "k0gram.y"
    { /* epsilon production */ }
#line 2541 "k0gram.tab.c"
    break;

  case 133: /* multi_comma_expression: $@8  */
#line 385 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2547 "k0gram.tab.c"
    break;

  case 134: /* indexingSuffix: LSQUARE expression multi_comma_expression opt_comma RSQUARE  */
#line 389 "k0gram.y"
                                                                {(yyval.treeptr) = alctree(1059, "indexingSuffix", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2553 "k0gram.tab.c"
    break;

  case 135: /* callSuffix: valueArguments  */
#line 393 "k0gram.y"
                  {(yyval.treeptr) = alctree(1060, "callSuffix", 1, (yyvsp[0].treeptr));}
#line 2559 "k0gram.tab.c"
    break;

  case 136: /* multi_comma_valueArgument: multi_comma_valueArgument COMMA valueArgument  */
#line 397 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1061, "multi_comma_valueArgument", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2565 "k0gram.tab.c"
    break;

  case 137: /* $@9: %empty  */
#line 398 "k0gram.y"
    { /* epsilon production */ }
#line 2571 "k0gram.tab.c"
    break;

  case 138: /* multi_comma_valueArgument: $@9  */
#line 398 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2577 "k0gram.tab.c"
    break;

  case 139: /* opt_valueArgument: valueArgument multi_comma_valueArgument opt_comma  */
#line 401 "k0gram.y"
                                                    {(yyval.treeptr) = alctree(1062, "opt_valueArgument", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2583 "k0gram.tab.c"
    break;

  case 140: /* $@10: %empty  */
#line 402 "k0gram.y"
    { /* epsilon production */ }
#line 2589 "k0gram.tab.c"
    break;

  case 141: /* opt_valueArgument: $@10  */
#line 402 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2595 "k0gram.tab.c"
    break;

  case 142: /* valueArguments: LPAREN opt_valueArgument RPAREN  */
#line 406 "k0gram.y"
                                    {(yyval.treeptr) = alctree(1063, "valueArguments", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2601 "k0gram.tab.c"
    break;

  case 143: /* opt_simpleIdentifier_EQ: simpleIdentifier ASSIGNMENT  */
#line 410 "k0gram.y"
                                {(yyval.treeptr) = alctree(1064, "opt_simpleIdentifier_EQ", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2607 "k0gram.tab.c"
    break;

  case 144: /* $@11: %empty  */
#line 411 "k0gram.y"
      { /* epsilon production */ }
#line 2613 "k0gram.tab.c"
    break;

  case 145: /* opt_simpleIdentifier_EQ: $@11  */
#line 411 "k0gram.y"
                                    {(yyval.treeptr) = NULL;}
#line 2619 "k0gram.tab.c"
    break;

  case 146: /* opt_Multi: MULT  */
#line 415 "k0gram.y"
        {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2625 "k0gram.tab.c"
    break;

  case 147: /* $@12: %empty  */
#line 416 "k0gram.y"
    { /* epsilon production */ }
#line 2631 "k0gram.tab.c"
    break;

  case 148: /* opt_Multi: $@12  */
#line 416 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2637 "k0gram.tab.c"
    break;

  case 149: /* valueArgument: opt_simpleIdentifier_EQ opt_Multi expression  */
#line 420 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1065, "valueArgument", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2643 "k0gram.tab.c"
    break;

  case 150: /* parenthesizedExpression: LPAREN expression RPAREN  */
#line 424 "k0gram.y"
                              {(yyval.treeptr) = alctree(1066, "parenthesizedExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2649 "k0gram.tab.c"
    break;

  case 151: /* ifExpression: IF LPAREN expression RPAREN controls  */
#line 430 "k0gram.y"
                                       {(yyval.treeptr) = alctree(1011,"ifExpression",5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2655 "k0gram.tab.c"
    break;

  case 152: /* controls: controlStructureBody ELSE controlStructureBody  */
#line 434 "k0gram.y"
                                                 {(yyval.treeptr) = alctree(1012,"controls",3,(yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2661 "k0gram.tab.c"
    break;

  case 153: /* controls: controlStructureBody  */
#line 435 "k0gram.y"
                         {(yyval.treeptr) = alctree(1012,"controls",1,(yyvsp[0].treeptr));}
#line 2667 "k0gram.tab.c"
    break;

  case 154: /* functionCall: IDENTIFIER LPAREN functionArguments RPAREN semis  */
#line 440 "k0gram.y"
                                                       {(yyval.treeptr) = alctree(1068, "functionCall", 4, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),(yyvsp[-1].treeptr));}
#line 2673 "k0gram.tab.c"
    break;

  case 155: /* functionCall: dotExpression LPAREN functionArguments RPAREN semis  */
#line 441 "k0gram.y"
                                                          {(yyval.treeptr) = alctree(1068, "methodCall", 4, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr));}
#line 2679 "k0gram.tab.c"
    break;

  case 156: /* dotExpression: IDENTIFIER DOT IDENTIFIER  */
#line 445 "k0gram.y"
                              {(yyval.treeptr) = alctree(3000, "dotExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2685 "k0gram.tab.c"
    break;

  case 157: /* dotExpression: dotExpression DOT IDENTIFIER  */
#line 446 "k0gram.y"
                                   {(yyval.treeptr) = alctree(3000, "dotExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2691 "k0gram.tab.c"
    break;

  case 158: /* functionArguments: expression  */
#line 451 "k0gram.y"
              {(yyval.treeptr) = alctree(1069, "functionArguments", 1, (yyvsp[0].treeptr));}
#line 2697 "k0gram.tab.c"
    break;

  case 159: /* functionArguments: functionArguments COMMA expression  */
#line 452 "k0gram.y"
                                       {(yyval.treeptr) = alctree(1070, "functionArguments", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2703 "k0gram.tab.c"
    break;

  case 160: /* functionArguments: %empty  */
#line 453 "k0gram.y"
              {(yyval.treeptr) = NULL;}
#line 2709 "k0gram.tab.c"
    break;

  case 161: /* variable_multivariable: variableDeclaration  */
#line 457 "k0gram.y"
                     {(yyval.treeptr) = alctree(1071,"variable_multivariable", 1, (yyvsp[0].treeptr));}
#line 2715 "k0gram.tab.c"
    break;

  case 162: /* variable_multivariable: multiVariableDeclaration  */
#line 458 "k0gram.y"
                              {(yyval.treeptr) = alctree(1071,"variable_multivariable", 1, (yyvsp[0].treeptr));}
#line 2721 "k0gram.tab.c"
    break;

  case 163: /* control_structure_body_or_comma: controlStructureBody  */
#line 462 "k0gram.y"
                        {(yyval.treeptr) = alctree(1072,"control_structure_body_or_comma", 1, (yyvsp[0].treeptr));}
#line 2727 "k0gram.tab.c"
    break;

  case 164: /* control_structure_body_or_comma: COMMA  */
#line 463 "k0gram.y"
          {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2733 "k0gram.tab.c"
    break;

  case 165: /* loopStatement: WHILE LPAREN expression RPAREN control_structure_body_or_comma  */
#line 467 "k0gram.y"
                                                                    {(yyval.treeptr) = alctree(1073,"loopStatement", 5 ,(yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2739 "k0gram.tab.c"
    break;

  case 166: /* loopStatement: FOR LPAREN variable_multivariable IN expression RPAREN controlStructureBody  */
#line 468 "k0gram.y"
                                                                                   {(yyval.treeptr) = alctree(1073,"loopStatement", 7 ,(yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr),(yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2745 "k0gram.tab.c"
    break;

  case 167: /* loopStatement: DO controlStructureBody WHILE LPAREN expression RPAREN  */
#line 469 "k0gram.y"
                                                              {(yyval.treeptr) = alctree(1073,"loopStatement", 6 ,(yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2751 "k0gram.tab.c"
    break;

  case 168: /* controlStructureBody: block  */
#line 474 "k0gram.y"
         {(yyval.treeptr) = alctree(1074, "controlStructureBody", 1, (yyvsp[0].treeptr));}
#line 2757 "k0gram.tab.c"
    break;

  case 169: /* controlStructureBody: statement  */
#line 475 "k0gram.y"
              {(yyval.treeptr) = alctree(1074, "controlStructureBody", 1, (yyvsp[0].treeptr));}
#line 2763 "k0gram.tab.c"
    break;

  case 170: /* jumpExpression: RETURN expression  */
#line 480 "k0gram.y"
                    {(yyval.treeptr) = alctree(1075, "jumpExpression", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2769 "k0gram.tab.c"
    break;

  case 174: /* multi_whenEntry: multi_whenEntry whenEntry  */
#line 487 "k0gram.y"
                            {(yyval.treeptr) = alctree(1076, "multi_whenEntry", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2775 "k0gram.tab.c"
    break;

  case 175: /* multi_whenEntry: %empty  */
#line 488 "k0gram.y"
      {(yyval.treeptr) = NULL;}
#line 2781 "k0gram.tab.c"
    break;

  case 176: /* whenExpression: WHEN whenSubject LCURL multi_whenEntry RCURL  */
#line 492 "k0gram.y"
                                               {(yyval.treeptr) = alctree(1077, "whenExpression", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2787 "k0gram.tab.c"
    break;

  case 177: /* whenExpression: WHEN LCURL multi_whenEntry RCURL  */
#line 493 "k0gram.y"
                                     {(yyval.treeptr) = alctree(1078, "whenExpression", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2793 "k0gram.tab.c"
    break;

  case 178: /* whenSubject: LPAREN expression RPAREN  */
#line 497 "k0gram.y"
                           {(yyval.treeptr) = alctree(1079, "whenSubject", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2799 "k0gram.tab.c"
    break;

  case 179: /* whenSubject: LPAREN VAL variableDeclaration ASSIGNMENT expression RPAREN  */
#line 498 "k0gram.y"
                                                                 {(yyval.treeptr) = alctree(1079, "whenSubject", 6, (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2805 "k0gram.tab.c"
    break;

  case 180: /* multi_comma_whenCondition: multi_comma_whenCondition COMMA whenCondition  */
#line 501 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1080, "multi_comma_whenCondition", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2811 "k0gram.tab.c"
    break;

  case 181: /* $@13: %empty  */
#line 502 "k0gram.y"
    { /* epsilon production */ }
#line 2817 "k0gram.tab.c"
    break;

  case 182: /* multi_comma_whenCondition: $@13  */
#line 502 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2823 "k0gram.tab.c"
    break;

  case 183: /* whenEntry: whenCondition multi_comma_whenCondition ARROW controlStructureBody  */
#line 506 "k0gram.y"
                                                                      {(yyval.treeptr) = alctree(1011, "whenEntry", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2829 "k0gram.tab.c"
    break;

  case 184: /* whenEntry: whenCondition multi_comma_whenCondition COMMA ARROW controlStructureBody  */
#line 507 "k0gram.y"
                                                                              {(yyval.treeptr) = alctree(1011, "whenEntry", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2835 "k0gram.tab.c"
    break;

  case 185: /* whenEntry: ELSE ARROW controlStructureBody SEMICOLON  */
#line 508 "k0gram.y"
                                              {(yyval.treeptr) = alctree(1011, "whenEntry", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2841 "k0gram.tab.c"
    break;

  case 186: /* whenEntry: ELSE ARROW controlStructureBody  */
#line 509 "k0gram.y"
                                      {(yyval.treeptr) = alctree(1011, "whenEntry", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2847 "k0gram.tab.c"
    break;

  case 187: /* whenCondition: expression  */
#line 513 "k0gram.y"
             {(yyval.treeptr) = alctree(1080, "whenCondition", 1, (yyvsp[0].treeptr));}
#line 2853 "k0gram.tab.c"
    break;

  case 188: /* whenCondition: rangeTest  */
#line 514 "k0gram.y"
              {(yyval.treeptr) = alctree(1080, "whenCondition", 1, (yyvsp[0].treeptr));}
#line 2859 "k0gram.tab.c"
    break;

  case 189: /* rangeTest: IN expression  */
#line 518 "k0gram.y"
                {(yyval.treeptr) = alctree(1081, "rangeTest", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2865 "k0gram.tab.c"
    break;

  case 190: /* classMembers: %empty  */
#line 522 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 2871 "k0gram.tab.c"
    break;

  case 191: /* classMembers: classMembers classMember  */
#line 523 "k0gram.y"
                              {(yyval.treeptr) = alctree(1082, "classMembers", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2877 "k0gram.tab.c"
    break;

  case 192: /* classMember: functionDeclaration  */
#line 527 "k0gram.y"
                        {(yyval.treeptr) = alctree(1083, "classMember", 1, (yyvsp[0].treeptr));}
#line 2883 "k0gram.tab.c"
    break;

  case 193: /* classMember: variableDeclaration  */
#line 528 "k0gram.y"
                          {(yyval.treeptr) = alctree(1083, "classMember", 1, (yyvsp[0].treeptr));}
#line 2889 "k0gram.tab.c"
    break;

  case 194: /* expression: disjunction  */
#line 533 "k0gram.y"
              {(yyval.treeptr) = alctree(1086, "expression", 1, (yyvsp[0].treeptr));}
#line 2895 "k0gram.tab.c"
    break;

  case 195: /* disjunction: conjunction  */
#line 537 "k0gram.y"
              {(yyval.treeptr) = alctree(1087, "disjuction", 1, (yyvsp[0].treeptr));}
#line 2901 "k0gram.tab.c"
    break;

  case 196: /* disjunction: disjunction DISJ conjunction  */
#line 538 "k0gram.y"
                                 {(yyval.treeptr) = alctree(1087, "disjuction", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2907 "k0gram.tab.c"
    break;

  case 197: /* conjunction: equality  */
#line 542 "k0gram.y"
           {(yyval.treeptr) = alctree(1088, "conjuction", 1, (yyvsp[0].treeptr));}
#line 2913 "k0gram.tab.c"
    break;

  case 198: /* conjunction: conjunction CONJ equality  */
#line 543 "k0gram.y"
                              {(yyval.treeptr) = alctree(1088, "conjuction", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2919 "k0gram.tab.c"
    break;

  case 199: /* equality: comparison  */
#line 547 "k0gram.y"
             {(yyval.treeptr) = alctree(1089, "equality", 1, (yyvsp[0].treeptr));}
#line 2925 "k0gram.tab.c"
    break;

  case 200: /* equality: equality equality_operator comparison  */
#line 548 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1089, "equality", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2931 "k0gram.tab.c"
    break;

  case 201: /* comparison: genericCallLikeComparison  */
#line 552 "k0gram.y"
                                {(yyval.treeptr) = alctree(1090, "comparison", 1, (yyvsp[0].treeptr));}
#line 2937 "k0gram.tab.c"
    break;

  case 202: /* comparison: comparison comparison_operator genericCallLikeComparison  */
#line 553 "k0gram.y"
                                                               {(yyval.treeptr) = alctree(1090, "comparison", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2943 "k0gram.tab.c"
    break;

  case 203: /* genericCallLikeComparison: elvisExpression  */
#line 557 "k0gram.y"
                      {(yyval.treeptr) = alctree(1091, "genericCallLikeComparison", 1, (yyvsp[0].treeptr));}
#line 2949 "k0gram.tab.c"
    break;

  case 204: /* genericCallLikeComparison: elvisExpression IN elvisExpression  */
#line 558 "k0gram.y"
                                         {(yyval.treeptr) = alctree(1091, "genericCallLikeComparison", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2955 "k0gram.tab.c"
    break;

  case 205: /* elvisExpression: rangeExpression  */
#line 562 "k0gram.y"
                      {(yyval.treeptr) = alctree(1092, "elvisExpression", 1, (yyvsp[0].treeptr));}
#line 2961 "k0gram.tab.c"
    break;

  case 206: /* elvisExpression: elvisExpression QUEST_COLON rangeExpression  */
#line 563 "k0gram.y"
                                                   {(yyval.treeptr) = alctree(1092, "elvisExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2967 "k0gram.tab.c"
    break;

  case 207: /* rangeExpression: additiveExpression  */
#line 567 "k0gram.y"
                         {(yyval.treeptr) = alctree(1093, "rangeExpression", 1, (yyvsp[0].treeptr));}
#line 2973 "k0gram.tab.c"
    break;

  case 208: /* rangeExpression: rangeExpression RANGE additiveExpression  */
#line 568 "k0gram.y"
                                               {(yyval.treeptr) = alctree(1093, "rangeExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2979 "k0gram.tab.c"
    break;

  case 209: /* additiveExpression: multiplicativeExpression  */
#line 572 "k0gram.y"
                             {(yyval.treeptr) = alctree(1094, "additiveExpression", 1, (yyvsp[0].treeptr));}
#line 2985 "k0gram.tab.c"
    break;

  case 210: /* additiveExpression: additiveExpression ADD multiplicativeExpression  */
#line 573 "k0gram.y"
                                                      {(yyval.treeptr) = alctree(1094, "additiveExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2991 "k0gram.tab.c"
    break;

  case 211: /* additiveExpression: additiveExpression SUB multiplicativeExpression  */
#line 574 "k0gram.y"
                                                      {(yyval.treeptr) = alctree(1094, "additiveExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2997 "k0gram.tab.c"
    break;

  case 212: /* multiplicativeExpression: postfixUnaryExpression  */
#line 578 "k0gram.y"
                         {(yyval.treeptr) = alctree(1095, "multiplicativeExpression", 1, (yyvsp[0].treeptr));}
#line 3003 "k0gram.tab.c"
    break;

  case 213: /* multiplicativeExpression: multiplicativeExpression MULT postfixUnaryExpression  */
#line 579 "k0gram.y"
                                                         {(yyval.treeptr) = alctree(1095, "multiplicativeExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3009 "k0gram.tab.c"
    break;

  case 214: /* multiplicativeExpression: multiplicativeExpression DIV postfixUnaryExpression  */
#line 580 "k0gram.y"
                                                        {(yyval.treeptr) = alctree(1095, "multiplicativeExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3015 "k0gram.tab.c"
    break;

  case 215: /* multiplicativeExpression: multiplicativeExpression MOD postfixUnaryExpression  */
#line 581 "k0gram.y"
                                                        {(yyval.treeptr) = alctree(1095, "multiplicativeExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3021 "k0gram.tab.c"
    break;

  case 216: /* primaryExpression: parenthesizedExpression  */
#line 585 "k0gram.y"
                          { (yyval.treeptr) = alctree(1035, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3027 "k0gram.tab.c"
    break;

  case 217: /* primaryExpression: simpleIdentifier  */
#line 586 "k0gram.y"
                       { (yyval.treeptr) = alctree(1035, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3033 "k0gram.tab.c"
    break;

  case 218: /* primaryExpression: functionCall  */
#line 587 "k0gram.y"
                   { (yyval.treeptr) = alctree(1035, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3039 "k0gram.tab.c"
    break;

  case 224: /* primaryExpression: jumpExpression  */
#line 593 "k0gram.y"
                      {(yyval.treeptr) = alctree(1011, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3045 "k0gram.tab.c"
    break;

  case 225: /* primaryExpression: collectionLiteral  */
#line 594 "k0gram.y"
                        {(yyval.treeptr) = alctree(1011, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3051 "k0gram.tab.c"
    break;

  case 226: /* primaryExpression: ifExpression  */
#line 595 "k0gram.y"
                   {(yyval.treeptr) = alctree(1011, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3057 "k0gram.tab.c"
    break;

  case 227: /* primaryExpression: whenExpression  */
#line 596 "k0gram.y"
                       {(yyval.treeptr) = alctree(1067, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3063 "k0gram.tab.c"
    break;

  case 228: /* collectionLiteral: LSQUARE RSQUARE  */
#line 600 "k0gram.y"
                  {(yyval.treeptr) = alctree(1011, "collectionLiteral", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3069 "k0gram.tab.c"
    break;

  case 229: /* collectionLiteral: LSQUARE expression COMMA RSQUARE  */
#line 601 "k0gram.y"
                                     {(yyval.treeptr) = alctree(1011, "collectionLiteral", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3075 "k0gram.tab.c"
    break;

  case 230: /* collectionLiteral: LSQUARE expression RSQUARE  */
#line 602 "k0gram.y"
                               {(yyval.treeptr) = alctree(1011, "collectionLiteral", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3081 "k0gram.tab.c"
    break;

  case 231: /* collectionLiteral: LSQUARE expression multi_comma_expression RSQUARE  */
#line 603 "k0gram.y"
                                                      {(yyval.treeptr) = alctree(1011, "collectionLiteral", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3087 "k0gram.tab.c"
    break;

  case 232: /* collectionLiteral: LSQUARE expression multi_comma_expression COMMA RSQUARE  */
#line 604 "k0gram.y"
                                                            {(yyval.treeptr) = alctree(1011, "collectionLiteral", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3093 "k0gram.tab.c"
    break;


#line 3097 "k0gram.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 626 "k0gram.y"

const char *yyname(int sym)
{ 
   return yytname[sym-RESERVED+3];
}
