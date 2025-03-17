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
  YYSYMBOL_receiverType = 179,             /* receiverType  */
  YYSYMBOL_parenthesizedType = 180,        /* parenthesizedType  */
  YYSYMBOL_multi_dot_simpleUserType = 181, /* multi_dot_simpleUserType  */
  YYSYMBOL_182_2 = 182,                    /* $@2  */
  YYSYMBOL_userType = 183,                 /* userType  */
  YYSYMBOL_simpleUserType = 184,           /* simpleUserType  */
  YYSYMBOL_multi_quest = 185,              /* multi_quest  */
  YYSYMBOL_186_3 = 186,                    /* $@3  */
  YYSYMBOL_nullableType = 187,             /* nullableType  */
  YYSYMBOL_typeRef_parenthesizedType = 188, /* typeRef_parenthesizedType  */
  YYSYMBOL_opt_eq_exp = 189,               /* opt_eq_exp  */
  YYSYMBOL_190_4 = 190,                    /* $@4  */
  YYSYMBOL_multivariable_variableDeclaration = 191, /* multivariable_variableDeclaration  */
  YYSYMBOL_propertyDeclaration = 192,      /* propertyDeclaration  */
  YYSYMBOL_opt_typeParameters = 193,       /* opt_typeParameters  */
  YYSYMBOL_opt_comma = 194,                /* opt_comma  */
  YYSYMBOL_typeParameters = 195,           /* typeParameters  */
  YYSYMBOL_typeParameter = 196,            /* typeParameter  */
  YYSYMBOL_multi_typeParameter = 197,      /* multi_typeParameter  */
  YYSYMBOL_simpleIdentifier = 198,         /* simpleIdentifier  */
  YYSYMBOL_classDeclaration = 199,         /* classDeclaration  */
  YYSYMBOL_variableDeclaration = 200,      /* variableDeclaration  */
  YYSYMBOL_multiVariableDeclaration = 201, /* multiVariableDeclaration  */
  YYSYMBOL_multi_comma_variableDeclaration = 202, /* multi_comma_variableDeclaration  */
  YYSYMBOL_classBody = 203,                /* classBody  */
  YYSYMBOL_assignmentAndOperator = 204,    /* assignmentAndOperator  */
  YYSYMBOL_assignableExpression = 205,     /* assignableExpression  */
  YYSYMBOL_multi_unaryPrefix = 206,        /* multi_unaryPrefix  */
  YYSYMBOL_207_5 = 207,                    /* $@5  */
  YYSYMBOL_prefixUnaryOperator = 208,      /* prefixUnaryOperator  */
  YYSYMBOL_prefixUnaryExpression = 209,    /* prefixUnaryExpression  */
  YYSYMBOL_parenthesizedAssignableExpression = 210, /* parenthesizedAssignableExpression  */
  YYSYMBOL_assignment = 211,               /* assignment  */
  YYSYMBOL_directly_assign = 212,          /* directly_assign  */
  YYSYMBOL_assignableSuffix = 213,         /* assignableSuffix  */
  YYSYMBOL_typeArguments = 214,            /* typeArguments  */
  YYSYMBOL_multi_comma_typeProjection = 215, /* multi_comma_typeProjection  */
  YYSYMBOL_216_6 = 216,                    /* $@6  */
  YYSYMBOL_typeProjection = 217,           /* typeProjection  */
  YYSYMBOL_directlyAssignableExpression = 218, /* directlyAssignableExpression  */
  YYSYMBOL_parenthesizedDirectlyAssignableExpression = 219, /* parenthesizedDirectlyAssignableExpression  */
  YYSYMBOL_multi_postfixUnarySuffix = 220, /* multi_postfixUnarySuffix  */
  YYSYMBOL_221_7 = 221,                    /* $@7  */
  YYSYMBOL_postfixUnaryExpression = 222,   /* postfixUnaryExpression  */
  YYSYMBOL_postfixUnarySuffix = 223,       /* postfixUnarySuffix  */
  YYSYMBOL_identifier_expression_class = 224, /* identifier_expression_class  */
  YYSYMBOL_navigationSuffix = 225,         /* navigationSuffix  */
  YYSYMBOL_memberAccessOperator = 226,     /* memberAccessOperator  */
  YYSYMBOL_postfixUnaryOperator = 227,     /* postfixUnaryOperator  */
  YYSYMBOL_multi_comma_expression = 228,   /* multi_comma_expression  */
  YYSYMBOL_229_8 = 229,                    /* $@8  */
  YYSYMBOL_indexingSuffix = 230,           /* indexingSuffix  */
  YYSYMBOL_callSuffix = 231,               /* callSuffix  */
  YYSYMBOL_multi_comma_valueArgument = 232, /* multi_comma_valueArgument  */
  YYSYMBOL_233_9 = 233,                    /* $@9  */
  YYSYMBOL_opt_valueArgument = 234,        /* opt_valueArgument  */
  YYSYMBOL_235_10 = 235,                   /* $@10  */
  YYSYMBOL_valueArguments = 236,           /* valueArguments  */
  YYSYMBOL_opt_simpleIdentifier_EQ = 237,  /* opt_simpleIdentifier_EQ  */
  YYSYMBOL_238_11 = 238,                   /* $@11  */
  YYSYMBOL_opt_Multi = 239,                /* opt_Multi  */
  YYSYMBOL_240_12 = 240,                   /* $@12  */
  YYSYMBOL_valueArgument = 241,            /* valueArgument  */
  YYSYMBOL_parenthesizedExpression = 242,  /* parenthesizedExpression  */
  YYSYMBOL_functionCall = 243,             /* functionCall  */
  YYSYMBOL_functionArguments = 244,        /* functionArguments  */
  YYSYMBOL_variable_multivariable = 245,   /* variable_multivariable  */
  YYSYMBOL_control_structure_body_or_comma = 246, /* control_structure_body_or_comma  */
  YYSYMBOL_loopStatement = 247,            /* loopStatement  */
  YYSYMBOL_controlStructureBody = 248,     /* controlStructureBody  */
  YYSYMBOL_jumpExpression = 249,           /* jumpExpression  */
  YYSYMBOL_classMembers = 250,             /* classMembers  */
  YYSYMBOL_classMember = 251,              /* classMember  */
  YYSYMBOL_objectDeclaration = 252,        /* objectDeclaration  */
  YYSYMBOL_objectBody = 253,               /* objectBody  */
  YYSYMBOL_expression = 254,               /* expression  */
  YYSYMBOL_disjunction = 255,              /* disjunction  */
  YYSYMBOL_conjunction = 256,              /* conjunction  */
  YYSYMBOL_equality = 257,                 /* equality  */
  YYSYMBOL_comparison = 258,               /* comparison  */
  YYSYMBOL_genericCallLikeComparison = 259, /* genericCallLikeComparison  */
  YYSYMBOL_elvisExpression = 260,          /* elvisExpression  */
  YYSYMBOL_rangeExpression = 261,          /* rangeExpression  */
  YYSYMBOL_additiveExpression = 262,       /* additiveExpression  */
  YYSYMBOL_multiplicativeExpression = 263, /* multiplicativeExpression  */
  YYSYMBOL_primaryExpression = 264,        /* primaryExpression  */
  YYSYMBOL_collectionLiteral = 265,        /* collectionLiteral  */
  YYSYMBOL_comparison_operator = 266,      /* comparison_operator  */
  YYSYMBOL_equality_operator = 267         /* equality_operator  */
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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  155
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  220
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  325

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
       0,    53,    53,    57,    58,    62,    63,    64,    68,    69,
      73,    74,    79,    80,    85,    89,    93,    97,    98,   102,
     103,   104,   109,   110,   115,   116,   121,   125,   126,   130,
     131,   136,   137,   141,   142,   150,   151,   152,   153,   154,
     158,   159,   160,   164,   165,   169,   170,   170,   175,   179,
     185,   186,   186,   190,   195,   196,   201,   202,   202,   205,
     209,   210,   215,   216,   216,   221,   222,   226,   227,   228,
     233,   234,   238,   239,   242,   246,   251,   252,   256,   257,
     258,   262,   263,   267,   268,   272,   275,   276,   282,   287,
     288,   289,   290,   291,   295,   296,   299,   300,   300,   303,
     304,   305,   306,   307,   312,   316,   320,   324,   325,   329,
     330,   334,   338,   339,   339,   344,   345,   348,   349,   350,
     354,   358,   359,   359,   362,   366,   367,   368,   369,   373,
     374,   375,   379,   383,   384,   388,   389,   390,   394,   395,
     395,   399,   403,   407,   408,   408,   411,   412,   412,   416,
     420,   421,   421,   425,   426,   426,   430,   434,   451,   457,
     458,   459,   463,   464,   468,   469,   473,   474,   479,   480,
     485,   486,   487,   488,   527,   528,   532,   533,   538,   542,
     547,   551,   552,   556,   557,   561,   562,   566,   567,   571,
     572,   576,   577,   581,   582,   586,   587,   588,   592,   593,
     594,   595,   599,   600,   601,   602,   603,   604,   605,   606,
     610,   611,   612,   613,   614,   619,   620,   621,   622,   626,
     627
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
  "val_var", "opt_modifier", "$@1", "receiverType", "parenthesizedType",
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
  "parenthesizedExpression", "functionCall", "functionArguments",
  "variable_multivariable", "control_structure_body_or_comma",
  "loopStatement", "controlStructureBody", "jumpExpression",
  "classMembers", "classMember", "objectDeclaration", "objectBody",
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

#define YYPACT_NINF (-276)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-148)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -33,   -49,    19,  -127,    -2,    78,   -33,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,    19,   -49,    59,  -276,    75,   -49,
    -276,  -276,    89,  -276,  -276,    46,   108,  -276,  -276,  -276,
    -276,  -276,     7,  -276,  -276,    19,  -276,  -276,   111,  -276,
     115,  -276,    93,   -49,   137,  -276,   106,  -276,   -49,    16,
     109,  -276,   134,    89,   222,   -49,   110,  -276,   166,   -49,
    -276,  -276,   161,   179,   175,  -276,  -276,  -276,    46,    30,
    -276,  -276,   176,  -276,  -276,  -276,  -276,  -276,  -276,   109,
    -276,   190,   145,  -276,  -276,  -276,    46,   193,  -276,  -276,
      55,   145,  -276,  -276,  -276,    46,    30,   -49,   145,    22,
     145,  -276,  -276,  -276,  -276,  -276,   194,  -276,  -276,  -276,
    -276,  -276,   188,   197,    45,   253,  -276,   -50,   184,   -16,
      -9,  -276,  -276,  -276,    16,   168,   196,   158,   207,   212,
     -11,    31,  -276,   202,   220,  -276,  -276,    87,  -276,  -276,
    -276,  -276,   312,    26,  -276,  -276,  -276,  -276,   145,   203,
    -276,    41,  -276,  -276,   205,  -276,  -276,  -276,   225,  -276,
      79,  -276,   145,   145,   145,  -276,  -276,   145,  -276,  -276,
    -276,  -276,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   294,  -276,  -276,  -276,  -276,   158,   232,    95,   145,
    -276,  -276,    71,  -276,  -276,    19,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,   227,  -276,  -276,  -276,  -276,  -276,
    -276,   145,  -276,  -276,  -276,  -276,  -276,   236,  -276,    99,
    -276,   123,  -276,   197,    45,   253,  -276,   184,   189,   -16,
      -9,    -9,  -276,  -276,  -276,  -276,    90,  -276,  -276,   241,
     258,  -276,  -276,   103,  -276,  -276,  -276,  -276,   263,   246,
      46,  -276,  -276,   178,   270,  -276,   348,    95,  -276,  -276,
    -276,    97,  -276,   145,  -276,   261,   276,  -276,   138,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,    80,  -276,
     145,   251,  -276,   285,   293,   161,  -276,  -276,   296,  -276,
    -276,  -276,  -276,  -276,  -276,   145,  -276,   298,  -276,   299,
     292,  -276,  -276,  -276,  -276,  -276,    95,   286,   145,   303,
    -276,   213,  -276,    46,   301,   259,   161,  -276,  -276,  -276,
    -276,  -276,  -276,   304,  -276
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    71,     0,     0,     0,     2,     3,     5,     6,
       7,    79,    80,    78,    71,     0,     0,    70,     0,     0,
       1,     4,     0,    77,    75,     0,     0,    60,    61,    51,
      48,    57,    55,   174,   178,    71,   174,    82,    73,    23,
       0,    22,    55,     0,    53,    52,    59,    58,    21,     0,
      11,    54,     0,     0,     0,    72,     0,    49,     0,     0,
      56,    18,    63,     0,     0,   116,   115,   113,     0,     9,
     179,   176,    84,   177,   175,    81,    88,    76,    74,    11,
      50,    20,     0,    15,    64,    14,     0,    73,   114,    10,
       0,     0,    13,     8,    24,     0,     9,    19,     0,     0,
     171,   172,   173,   207,   205,   206,   203,   198,   202,   204,
     208,    62,   180,   181,   183,   185,   187,   189,   191,   193,
     195,   122,   209,    16,    72,     0,     0,    97,     0,     0,
      45,   203,    41,    34,     0,    30,    35,     0,    47,    42,
     118,    40,     0,     0,    98,    94,    95,    36,     0,     0,
     119,   198,    38,    37,     0,    83,    12,    17,     0,   210,
       0,   170,   161,     0,     0,   219,   220,     0,   215,   216,
     217,   218,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   123,   112,   111,    39,    97,     0,     0,     0,
      33,    26,    28,    44,    43,    71,    89,    90,    91,    92,
      93,   108,   101,   102,     0,    99,   100,    96,   104,   106,
     107,     0,   117,   110,   109,    25,   157,     0,   212,     0,
     140,     0,   159,   182,   184,   186,   188,   192,   190,   194,
     196,   197,   199,   201,   200,   133,   151,   135,   136,     0,
       0,   121,   128,     0,   125,   126,   127,   142,     0,   105,
       0,   162,   163,     0,     0,    27,     0,     0,   103,   139,
     211,     0,   213,     0,   158,     0,     0,   148,   154,   152,
     144,   137,   134,   131,   129,   132,   130,   105,    84,    87,
       0,     0,    29,     0,    22,    63,    65,    66,    73,   214,
     138,   160,   150,   149,   153,     0,   155,    73,   145,    73,
       0,   165,   168,   169,   166,   164,     0,    69,    72,     0,
     156,   151,   146,    72,     0,     0,    63,    68,   141,   143,
      86,    85,   167,     0,    67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -276,  -276,  -276,   307,   219,   239,    23,   262,   229,  -276,
    -276,  -276,   -24,  -276,  -255,  -276,  -276,  -276,  -276,   -86,
    -276,  -276,  -276,  -276,    82,  -276,  -276,  -276,  -276,   269,
    -276,  -276,   -14,  -276,  -275,  -276,    39,  -276,    -8,   -80,
    -276,   300,  -276,    -1,    53,  -177,   159,  -276,   305,  -276,
    -110,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,   206,
    -276,  -276,   235,  -276,  -276,  -276,  -276,   -85,  -276,  -276,
    -276,  -276,  -276,    94,  -276,   181,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,    52,   125,  -276,  -276,
    -276,  -276,  -276,    51,  -276,   333,  -276,  -276,  -276,   -79,
    -276,   208,   210,   209,   200,   201,   204,   211,     3,  -276,
    -276,  -276,  -276
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     5,     6,     7,    92,    69,   132,    50,    61,    62,
      81,    63,    72,    93,    94,   256,   192,   133,   134,   303,
     136,   195,   137,   138,    26,    27,    44,    45,    28,    29,
      46,    47,    41,    31,    83,    84,   285,   139,    16,    56,
      17,    23,    38,    42,   141,    73,   287,   299,    37,   201,
     142,   143,   144,   207,   145,   146,   147,   148,   212,    51,
      87,    88,    67,   149,   150,   181,   182,   107,   241,   275,
     242,   243,   244,   219,   220,   214,   246,   297,   298,   266,
     267,   247,   268,   269,   295,   296,   270,   108,   109,   221,
     253,   304,   152,   305,   110,    52,    74,    10,    34,   153,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   172,   167
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    40,    30,   111,   135,   151,    22,   125,   173,   -80,
     307,   251,   154,    48,    24,    32,    11,   187,    35,   158,
     160,   161,    25,     8,    18,    66,   302,    53,    98,     8,
      99,   159,    98,     1,    99,     2,     3,   162,   202,   203,
      90,   323,    58,   204,    89,    49,   174,    64,   158,   211,
      91,   -78,    25,     9,    24,    19,   126,    15,   208,     9,
     302,   127,   123,    99,    19,    25,   -32,   -97,   -97,   209,
      12,   155,   -97,   279,   -32,    71,   248,    71,    20,    49,
     286,    11,   -31,   222,   217,    33,     4,    57,   218,   140,
     255,   165,   166,   232,   233,   234,    64,  -147,    95,    36,
      66,   250,    13,    98,   261,    99,   289,   158,   262,    98,
     254,    11,    43,   100,   101,   102,    55,   100,   101,   102,
      11,     1,    57,     2,    11,   -46,   -46,    68,   263,   286,
     264,    49,   259,   176,   177,    12,   320,   178,   179,   180,
      25,    59,   128,    60,   129,    70,   100,   101,   102,    78,
     103,    98,   104,    99,   103,    11,   104,   193,   194,   105,
      11,    39,    65,   105,   186,    12,    99,    13,    11,   273,
     282,   151,    48,   106,   130,   205,   206,   106,    12,   230,
     231,    82,   290,   103,   291,   104,    85,   257,   100,   101,
     102,    39,   105,    86,    95,    97,   151,    13,   124,    11,
     162,   300,     2,   163,   -97,   -97,   131,   184,   309,    12,
      13,   164,   175,   188,    12,   185,   310,   312,   189,   314,
     -72,   190,    12,   210,   215,   103,   278,   104,    25,   290,
     151,   191,   216,    76,   105,   265,   100,   101,   102,   249,
      39,    13,   274,   284,   258,   260,    13,   173,   106,   100,
     101,   102,   126,    12,    13,   140,   301,   127,   271,    99,
     126,    90,   272,   -97,   -97,   127,  -120,    99,   -97,    90,
     277,   -97,   -97,   103,   280,   104,   -97,   281,    11,    39,
     140,   292,   105,   293,   294,    13,   103,    11,   104,   306,
       2,   168,   169,   170,   171,   105,   106,   -48,   235,   315,
     236,   308,   211,   311,   313,   317,   237,   238,   321,   106,
     265,   239,   318,    21,   140,   156,    11,     1,    96,     2,
      79,   -46,   -46,   324,    11,     1,   157,     2,    80,   -46,
     -46,   240,    12,   196,   197,   198,   199,   200,   128,   283,
     129,    12,   100,   101,   102,   316,   128,   252,   129,   126,
     100,   101,   102,   288,   127,    77,    99,   213,    75,   183,
     -97,   -97,   245,   319,    13,   -97,   322,    39,   276,    54,
     130,   223,   226,    13,   224,   228,   225,   227,   130,   103,
       0,   104,     0,     0,     0,     0,   229,   103,   105,   104,
       0,     0,     0,     0,     0,     0,   105,     0,     0,     0,
     -97,   -97,   131,     0,     0,     0,     0,     0,   -97,   -97,
     131,     0,     0,    11,     1,     0,     2,     0,   -46,   -46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,   129,     0,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,   104,     0,
       0,     0,     0,     0,     0,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -97,   -97,   131
};

static const yytype_int16 yycheck[] =
{
       1,    25,    16,    82,    90,    90,    14,    87,    58,    20,
     285,   188,    91,     6,    15,    16,    65,   127,    19,    98,
      99,   100,     6,     0,   151,    49,   281,    35,     6,     6,
       8,     9,     6,    66,     8,    68,    69,     6,    12,    13,
      10,   316,    43,    17,    68,    38,    96,    48,   127,     8,
      20,    20,     6,     0,    55,    66,     1,    38,   143,     6,
     315,     6,    86,     8,    66,     6,    11,    12,    13,   148,
     119,    95,    17,   250,    19,    52,   186,    54,     0,    38,
     257,    65,    11,   162,     5,    10,   119,     7,     9,    90,
      19,    46,    47,   178,   179,   180,    97,     7,    18,    10,
     124,     6,   151,     6,     5,     8,     9,   186,     9,     6,
     189,    65,     4,    91,    92,    93,     5,    91,    92,    93,
      65,    66,     7,    68,    65,    70,    71,    18,     5,   306,
       7,    38,   211,   149,   150,   119,   313,   146,   147,   148,
       6,     4,    87,    37,    89,    11,    91,    92,    93,    39,
     128,     6,   130,     8,   128,    65,   130,    70,    71,   137,
      65,   145,   146,   137,     6,   119,     8,   151,    65,    66,
     256,   256,     6,   151,   119,   149,   150,   151,   119,   176,
     177,    20,   261,   128,   263,   130,     7,   195,    91,    92,
      93,   145,   137,    18,    18,     5,   281,   151,     5,    65,
       6,   280,    68,    15,   149,   150,   151,    39,   288,   119,
     151,    14,    28,     6,   119,    19,   295,   297,     6,   299,
       7,    19,   119,    20,    19,   128,   250,   130,     6,   308,
     315,    11,     7,    11,   137,   236,    91,    92,    93,     7,
     145,   151,   243,   257,    17,     9,   151,    58,   151,    91,
      92,    93,     1,   119,   151,   256,     5,     6,    17,     8,
       1,    10,     4,    12,    13,     6,    20,     8,    17,    10,
       7,    12,    13,   128,    96,   130,    17,     7,    65,   145,
     281,    20,   137,     7,   146,   151,   128,    65,   130,     4,
      68,    38,    39,    40,    41,   137,   151,     4,     4,     7,
       6,     5,     8,     5,     5,    19,    12,    13,     7,   151,
     311,    17,     9,     6,   315,    96,    65,    66,    79,    68,
      58,    70,    71,    19,    65,    66,    97,    68,    59,    70,
      71,    37,   119,    21,    22,    23,    24,    25,    87,   257,
      89,   119,    91,    92,    93,   306,    87,   188,    89,     1,
      91,    92,    93,   259,     6,    55,     8,   151,    53,   124,
      12,    13,   181,   311,   151,    17,   315,   145,   243,    36,
     119,   163,   172,   151,   164,   174,   167,   173,   119,   128,
      -1,   130,    -1,    -1,    -1,    -1,   175,   128,   137,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
     149,   150,   151,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,    -1,    -1,    65,    66,    -1,    68,    -1,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,    89,    -1,    91,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    66,    68,    69,   119,   156,   157,   158,   161,   199,
     252,    65,   119,   151,   198,    38,   193,   195,   151,    66,
       0,   158,   193,   196,   198,     6,   179,   180,   183,   184,
     187,   188,   198,    10,   253,   198,    10,   203,   197,   145,
     167,   187,   198,     4,   181,   182,   185,   186,     6,    38,
     162,   214,   250,   193,   250,     5,   194,     7,   198,     4,
      37,   163,   164,   166,   198,   146,   167,   217,    18,   160,
      11,   161,   167,   200,   251,   203,    11,   196,    39,   162,
     184,   165,    20,   189,   190,     7,    18,   215,   216,   167,
      10,    20,   159,   168,   169,    18,   160,     5,     6,     8,
      91,    92,    93,   128,   130,   137,   151,   222,   242,   243,
     249,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   167,     5,   194,     1,     6,    87,    89,
     119,   151,   161,   172,   173,   174,   175,   177,   178,   192,
     198,   199,   205,   206,   207,   209,   210,   211,   212,   218,
     219,   222,   247,   254,   254,   167,   159,   163,   254,     9,
     254,   254,     6,    15,    14,    46,    47,   267,    38,    39,
      40,    41,   266,    58,    96,    28,   149,   150,   146,   147,
     148,   220,   221,   217,    39,    19,     6,   205,     6,     6,
      19,    11,   171,    70,    71,   176,    21,    22,    23,    24,
      25,   204,    12,    13,    17,   149,   150,   208,   222,   254,
      20,     8,   213,   214,   230,    19,     7,     5,     9,   228,
     229,   244,   254,   256,   257,   258,   259,   261,   260,   262,
     263,   263,   222,   222,   222,     4,     6,    12,    13,    17,
      37,   223,   225,   226,   227,   230,   231,   236,   205,     7,
       6,   200,   201,   245,   254,    19,   170,   193,    17,   254,
       9,     5,     9,     5,     7,   198,   234,   235,   237,   238,
     241,    17,     4,    66,   198,   224,   242,     7,   167,   200,
      96,     7,   174,   179,   187,   191,   200,   201,   228,     9,
     254,   254,    20,     7,   146,   239,   240,   232,   233,   202,
     254,     5,   169,   174,   246,   248,     4,   189,     5,   194,
     254,     5,   194,     5,   194,     7,   191,    19,     9,   241,
     200,     7,   248,   189,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   155,   156,   157,   157,   158,   158,   158,   159,   159,
     160,   160,   161,   161,   162,   163,   164,   165,   165,   166,
     166,   166,   167,   167,   168,   168,   169,   170,   170,   171,
     171,   172,   172,   173,   173,   174,   174,   174,   174,   174,
     175,   175,   175,   176,   176,   177,   178,   177,   179,   180,
     181,   182,   181,   183,   184,   184,   185,   186,   185,   187,
     188,   188,   189,   190,   189,   191,   191,   192,   192,   192,
     193,   193,   194,   194,   195,   196,   197,   197,   198,   198,
     198,   199,   199,   200,   200,   201,   202,   202,   203,   204,
     204,   204,   204,   204,   205,   205,   206,   207,   206,   208,
     208,   208,   208,   208,   209,   210,   211,   212,   212,   213,
     213,   214,   215,   216,   215,   217,   217,   218,   218,   218,
     219,   220,   221,   220,   222,   223,   223,   223,   223,   224,
     224,   224,   225,   226,   226,   227,   227,   227,   228,   229,
     228,   230,   231,   232,   233,   232,   234,   235,   234,   236,
     237,   238,   237,   239,   240,   239,   241,   242,   243,   244,
     244,   244,   245,   245,   246,   246,   247,   247,   248,   248,
     249,   249,   249,   249,   250,   250,   251,   251,   252,   253,
     254,   255,   255,   256,   256,   257,   257,   258,   258,   259,
     259,   260,   260,   261,   261,   262,   262,   262,   263,   263,
     263,   263,   264,   264,   264,   264,   264,   264,   264,   264,
     265,   265,   265,   265,   265,   266,   266,   266,   266,   267,
     267
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     0,
       2,     0,     8,     6,     3,     2,     3,     3,     0,     3,
       2,     0,     1,     1,     1,     3,     3,     1,     0,     3,
       0,     2,     0,     2,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     3,
       3,     0,     1,     2,     2,     1,     2,     0,     1,     2,
       1,     1,     2,     0,     1,     1,     1,     8,     6,     5,
       1,     0,     1,     0,     5,     1,     3,     0,     1,     1,
       1,     5,     4,     3,     1,     5,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     1,     1,
       1,     1,     1,     2,     2,     3,     2,     2,     2,     1,
       1,     5,     3,     0,     1,     1,     1,     2,     1,     1,
       3,     2,     0,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     1,     2,     3,     0,
       1,     5,     1,     3,     0,     1,     3,     0,     1,     3,
       2,     0,     1,     1,     0,     1,     3,     3,     4,     1,
       3,     0,     1,     1,     1,     1,     5,     7,     1,     1,
       2,     1,     1,     1,     0,     2,     1,     1,     3,     3,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     3,     4,     5,     1,     1,     1,     1,     1,
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
                    {root = (yyvsp[0].treeptr); /*treeprint(root, 1); */}
#line 1680 "k0gram.tab.c"
    break;

  case 3: /* topLevelObjects: topLevelObject  */
#line 57 "k0gram.y"
                   {(yyval.treeptr) = alctree(1001, "topLevelObjects", 1, (yyvsp[0].treeptr));}
#line 1686 "k0gram.tab.c"
    break;

  case 4: /* topLevelObjects: topLevelObjects topLevelObject  */
#line 58 "k0gram.y"
                                   {(yyval.treeptr) = alctree(1001, "topLevelObjects", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1692 "k0gram.tab.c"
    break;

  case 5: /* topLevelObject: functionDeclaration  */
#line 62 "k0gram.y"
                        {(yyval.treeptr) = alctree(1002, "topLevelObject", 1, (yyvsp[0].treeptr));}
#line 1698 "k0gram.tab.c"
    break;

  case 6: /* topLevelObject: classDeclaration  */
#line 63 "k0gram.y"
                     {(yyval.treeptr) = alctree(1002, "topLevelObject", 1, (yyvsp[0].treeptr));}
#line 1704 "k0gram.tab.c"
    break;

  case 7: /* topLevelObject: objectDeclaration  */
#line 64 "k0gram.y"
                      {(yyval.treeptr) = alctree(1002, "topLevelObject", 1, (yyvsp[0].treeptr));}
#line 1710 "k0gram.tab.c"
    break;

  case 8: /* opt_functionBody: functionBody  */
#line 68 "k0gram.y"
                 {(yyval.treeptr) = alctree(1003, "opt_functionBody", 1, (yyvsp[0].treeptr));}
#line 1716 "k0gram.tab.c"
    break;

  case 9: /* opt_functionBody: %empty  */
#line 69 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1722 "k0gram.tab.c"
    break;

  case 10: /* opt_colon_type: COLON type  */
#line 73 "k0gram.y"
             {(yyval.treeptr) = alctree(1003, "opt_colon_type", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1728 "k0gram.tab.c"
    break;

  case 11: /* opt_colon_type: %empty  */
#line 74 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1734 "k0gram.tab.c"
    break;

  case 12: /* functionDeclaration: FUN opt_typeParameters receiverType DOT simpleIdentifier functionValueParameters opt_colon_type opt_functionBody  */
#line 79 "k0gram.y"
                                                                                                                     {(yyval.treeptr) = alctree(1004, "functionDeclaration", 8, (yyvsp[-7].treeptr), (yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1740 "k0gram.tab.c"
    break;

  case 13: /* functionDeclaration: FUN opt_typeParameters simpleIdentifier functionValueParameters opt_colon_type opt_functionBody  */
#line 80 "k0gram.y"
                                                                                                      {(yyval.treeptr) = alctree(1004, "functionDeclaration",6, (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1746 "k0gram.tab.c"
    break;

  case 14: /* functionValueParameters: LPAREN opt_functionValueParameter RPAREN  */
#line 85 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1005, "functionValueParameters", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1752 "k0gram.tab.c"
    break;

  case 15: /* functionValueParameter: parameter opt_eq_exp  */
#line 89 "k0gram.y"
                       {(yyval.treeptr) = alctree(1006, "functionValueParameter", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1758 "k0gram.tab.c"
    break;

  case 16: /* parameter: simpleIdentifier COLON type  */
#line 93 "k0gram.y"
                              {(yyval.treeptr) = alctree(1007, "parameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1764 "k0gram.tab.c"
    break;

  case 17: /* multi_comma_functionParameter: multi_comma_functionParameter COMMA functionValueParameter  */
#line 97 "k0gram.y"
                                                             {(yyval.treeptr) = alctree(1008, "multi_comma_functionParameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1770 "k0gram.tab.c"
    break;

  case 18: /* multi_comma_functionParameter: %empty  */
#line 98 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1776 "k0gram.tab.c"
    break;

  case 19: /* opt_functionValueParameter: functionValueParameter multi_comma_functionParameter COMMA  */
#line 102 "k0gram.y"
                                                             {(yyval.treeptr) = alctree(1009, "opt_functionValueParameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1782 "k0gram.tab.c"
    break;

  case 20: /* opt_functionValueParameter: functionValueParameter multi_comma_functionParameter  */
#line 103 "k0gram.y"
                                                         {(yyval.treeptr) = alctree(1009, "opt_functionValueParameter", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1788 "k0gram.tab.c"
    break;

  case 21: /* opt_functionValueParameter: %empty  */
#line 104 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1794 "k0gram.tab.c"
    break;

  case 22: /* type: nullableType  */
#line 109 "k0gram.y"
               {(yyval.treeptr) = alctree(1010, "type", 1, (yyvsp[0].treeptr));}
#line 1800 "k0gram.tab.c"
    break;

  case 23: /* type: TYPELITERAL  */
#line 110 "k0gram.y"
               {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1806 "k0gram.tab.c"
    break;

  case 24: /* functionBody: block  */
#line 115 "k0gram.y"
          {(yyval.treeptr) = alctree(1011, "functionBody", 1, (yyvsp[0].treeptr));}
#line 1812 "k0gram.tab.c"
    break;

  case 25: /* functionBody: ASSIGNMENT expression SEMICOLON  */
#line 116 "k0gram.y"
                                    {(yyval.treeptr) = alctree(1011, "functionBody", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1818 "k0gram.tab.c"
    break;

  case 26: /* block: LCURL statements RCURL  */
#line 121 "k0gram.y"
                            {(yyval.treeptr) = alctree(1012, "block", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));  }
#line 1824 "k0gram.tab.c"
    break;

  case 28: /* semis: %empty  */
#line 126 "k0gram.y"
    {(yyval.treeptr) = NULL;}
#line 1830 "k0gram.tab.c"
    break;

  case 29: /* semis_statement: semis_statement semis statement  */
#line 130 "k0gram.y"
                                  {(yyval.treeptr) = alctree(1013, "semis_statement", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1836 "k0gram.tab.c"
    break;

  case 30: /* semis_statement: %empty  */
#line 131 "k0gram.y"
           {(yyval.treeptr) = NULL;}
#line 1842 "k0gram.tab.c"
    break;

  case 31: /* optional_statement_sequence: statement semis_statement  */
#line 136 "k0gram.y"
                                {(yyval.treeptr) = alctree(1014, "optional_statement_sequence", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1848 "k0gram.tab.c"
    break;

  case 32: /* optional_statement_sequence: %empty  */
#line 137 "k0gram.y"
            {(yyval.treeptr) = NULL;}
#line 1854 "k0gram.tab.c"
    break;

  case 33: /* statements: optional_statement_sequence SEMICOLON  */
#line 141 "k0gram.y"
                                              {(yyval.treeptr) = alctree(1015, "statements", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1860 "k0gram.tab.c"
    break;

  case 34: /* statements: optional_statement_sequence  */
#line 142 "k0gram.y"
                                {(yyval.treeptr) = alctree(1015, "statements", 1, (yyvsp[0].treeptr));}
#line 1866 "k0gram.tab.c"
    break;

  case 35: /* statement: declaration  */
#line 150 "k0gram.y"
                {(yyval.treeptr) = alctree(1016, "statement", 1, (yyvsp[0].treeptr));}
#line 1872 "k0gram.tab.c"
    break;

  case 36: /* statement: assignment  */
#line 151 "k0gram.y"
                {(yyval.treeptr) = alctree(1016, "statement", 1, (yyvsp[0].treeptr));}
#line 1878 "k0gram.tab.c"
    break;

  case 37: /* statement: expression  */
#line 152 "k0gram.y"
                {(yyval.treeptr) = alctree(1016, "statement", 1, (yyvsp[0].treeptr)); }
#line 1884 "k0gram.tab.c"
    break;

  case 38: /* statement: loopStatement  */
#line 153 "k0gram.y"
                  {(yyval.treeptr) = alctree(1016, "statement", 1, (yyvsp[0].treeptr));}
#line 1890 "k0gram.tab.c"
    break;

  case 39: /* statement: error SEMICOLON  */
#line 154 "k0gram.y"
                    {(yyval.treeptr) = alctree(1016, "statement", 1, (yyvsp[0].treeptr));}
#line 1896 "k0gram.tab.c"
    break;

  case 40: /* declaration: classDeclaration  */
#line 158 "k0gram.y"
                   {(yyval.treeptr) = alctree(1017, "declaration", 1, (yyvsp[0].treeptr));}
#line 1902 "k0gram.tab.c"
    break;

  case 41: /* declaration: functionDeclaration  */
#line 159 "k0gram.y"
                       {(yyval.treeptr) = alctree(1017, "declaration", 1, (yyvsp[0].treeptr));}
#line 1908 "k0gram.tab.c"
    break;

  case 42: /* declaration: propertyDeclaration  */
#line 160 "k0gram.y"
                        {(yyval.treeptr) = alctree(1017, "declaration", 1, (yyvsp[0].treeptr));}
#line 1914 "k0gram.tab.c"
    break;

  case 43: /* val_var: VAR  */
#line 164 "k0gram.y"
      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1920 "k0gram.tab.c"
    break;

  case 44: /* val_var: VAL  */
#line 165 "k0gram.y"
        {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1926 "k0gram.tab.c"
    break;

  case 45: /* opt_modifier: CONST  */
#line 169 "k0gram.y"
        {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1932 "k0gram.tab.c"
    break;

  case 46: /* $@1: %empty  */
#line 170 "k0gram.y"
    { /* epsilon production */ }
#line 1938 "k0gram.tab.c"
    break;

  case 47: /* opt_modifier: $@1  */
#line 170 "k0gram.y"
                                 {(yyval.treeptr) = NULL;}
#line 1944 "k0gram.tab.c"
    break;

  case 48: /* receiverType: nullableType  */
#line 175 "k0gram.y"
                {(yyval.treeptr) = alctree(1018, "receiverType", 1, (yyvsp[0].treeptr));}
#line 1950 "k0gram.tab.c"
    break;

  case 49: /* parenthesizedType: LPAREN type RPAREN  */
#line 179 "k0gram.y"
                     {(yyval.treeptr) = alctree(1019, "parenthesizedType", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1956 "k0gram.tab.c"
    break;

  case 50: /* multi_dot_simpleUserType: multi_dot_simpleUserType DOT simpleUserType  */
#line 185 "k0gram.y"
                                              {(yyval.treeptr) = alctree(1020, "multi_dot_simpleUserType", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1962 "k0gram.tab.c"
    break;

  case 51: /* $@2: %empty  */
#line 186 "k0gram.y"
    { /* epsilon production */ }
#line 1968 "k0gram.tab.c"
    break;

  case 52: /* multi_dot_simpleUserType: $@2  */
#line 186 "k0gram.y"
                                 {(yyval.treeptr) = NULL;}
#line 1974 "k0gram.tab.c"
    break;

  case 53: /* userType: simpleUserType multi_dot_simpleUserType  */
#line 190 "k0gram.y"
                                          {(yyval.treeptr) = alctree(1021, "userType", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1980 "k0gram.tab.c"
    break;

  case 54: /* simpleUserType: simpleIdentifier typeArguments  */
#line 195 "k0gram.y"
                                {(yyval.treeptr) = alctree(1022, "simpleUserType", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1986 "k0gram.tab.c"
    break;

  case 55: /* simpleUserType: simpleIdentifier  */
#line 196 "k0gram.y"
                    {(yyval.treeptr) = alctree(1022, "simpleUserType", 1, (yyvsp[0].treeptr));}
#line 1992 "k0gram.tab.c"
    break;

  case 56: /* multi_quest: multi_quest QUEST_NO_WS  */
#line 201 "k0gram.y"
                          {(yyval.treeptr) = alctree(1023, "multi_quest", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1998 "k0gram.tab.c"
    break;

  case 57: /* $@3: %empty  */
#line 202 "k0gram.y"
    { /* epsilon production */ }
#line 2004 "k0gram.tab.c"
    break;

  case 58: /* multi_quest: $@3  */
#line 202 "k0gram.y"
                                 {(yyval.treeptr) = NULL;}
#line 2010 "k0gram.tab.c"
    break;

  case 59: /* nullableType: typeRef_parenthesizedType multi_quest  */
#line 205 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1024, "nullableType", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2016 "k0gram.tab.c"
    break;

  case 60: /* typeRef_parenthesizedType: parenthesizedType  */
#line 209 "k0gram.y"
                    {(yyval.treeptr) = alctree(1025, "typeRef_parenthesizedType", 1, (yyvsp[0].treeptr));}
#line 2022 "k0gram.tab.c"
    break;

  case 61: /* typeRef_parenthesizedType: userType  */
#line 210 "k0gram.y"
              {(yyval.treeptr) = alctree(1025, "typeRef_parenthesizedType", 1, (yyvsp[0].treeptr));}
#line 2028 "k0gram.tab.c"
    break;

  case 62: /* opt_eq_exp: ASSIGNMENT expression  */
#line 215 "k0gram.y"
                        {(yyval.treeptr) = alctree(1026, "opt_eq_exp", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2034 "k0gram.tab.c"
    break;

  case 63: /* $@4: %empty  */
#line 216 "k0gram.y"
    { /* epsilon production */ }
#line 2040 "k0gram.tab.c"
    break;

  case 64: /* opt_eq_exp: $@4  */
#line 216 "k0gram.y"
                                 {(yyval.treeptr) = NULL;}
#line 2046 "k0gram.tab.c"
    break;

  case 65: /* multivariable_variableDeclaration: variableDeclaration  */
#line 221 "k0gram.y"
                      {(yyval.treeptr) = alctree(1027, "multivariable_variableDeclaration", 1, (yyvsp[0].treeptr));}
#line 2052 "k0gram.tab.c"
    break;

  case 66: /* multivariable_variableDeclaration: multiVariableDeclaration  */
#line 222 "k0gram.y"
                             {(yyval.treeptr) = alctree(1027, "multivariable_variableDeclaration", 1, (yyvsp[0].treeptr));}
#line 2058 "k0gram.tab.c"
    break;

  case 67: /* propertyDeclaration: opt_modifier val_var opt_typeParameters receiverType DOT multivariable_variableDeclaration opt_eq_exp SEMICOLON  */
#line 226 "k0gram.y"
                                                                                                                    {(yyval.treeptr) = alctree(1028, "propertyDeclaration", 8, (yyvsp[-7].treeptr), (yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2064 "k0gram.tab.c"
    break;

  case 68: /* propertyDeclaration: opt_modifier val_var opt_typeParameters multivariable_variableDeclaration opt_eq_exp SEMICOLON  */
#line 227 "k0gram.y"
                                                                                                   {(yyval.treeptr) = alctree(1028, "propertyDeclaration", 6, (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2070 "k0gram.tab.c"
    break;

  case 69: /* propertyDeclaration: opt_modifier val_var opt_typeParameters multivariable_variableDeclaration opt_eq_exp  */
#line 228 "k0gram.y"
                                                                                         {(yyval.treeptr) = alctree(1028, "propertyDeclaration", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr) );}
#line 2076 "k0gram.tab.c"
    break;

  case 70: /* opt_typeParameters: typeParameters  */
#line 233 "k0gram.y"
                    {(yyval.treeptr) = alctree(1029, "opt_typeParameters", 1, (yyvsp[0].treeptr));}
#line 2082 "k0gram.tab.c"
    break;

  case 71: /* opt_typeParameters: %empty  */
#line 234 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 2088 "k0gram.tab.c"
    break;

  case 72: /* opt_comma: COMMA  */
#line 238 "k0gram.y"
          {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2094 "k0gram.tab.c"
    break;

  case 73: /* opt_comma: %empty  */
#line 239 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 2100 "k0gram.tab.c"
    break;

  case 74: /* typeParameters: LANGLE typeParameter multi_typeParameter opt_comma RANGLE  */
#line 242 "k0gram.y"
                                                              {(yyval.treeptr) = alctree(1030, "typeParameters", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2106 "k0gram.tab.c"
    break;

  case 75: /* typeParameter: simpleIdentifier  */
#line 246 "k0gram.y"
                      {(yyval.treeptr) = alctree(1031, "typeParameter", 1, (yyvsp[0].treeptr));}
#line 2112 "k0gram.tab.c"
    break;

  case 76: /* multi_typeParameter: multi_typeParameter COMMA typeParameter  */
#line 251 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1032, "multi_typeParameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2118 "k0gram.tab.c"
    break;

  case 77: /* multi_typeParameter: %empty  */
#line 252 "k0gram.y"
                 {(yyval.treeptr) = NULL;}
#line 2124 "k0gram.tab.c"
    break;

  case 81: /* classDeclaration: CONST CLASS simpleIdentifier opt_typeParameters classBody  */
#line 262 "k0gram.y"
                                                               {  (yyval.treeptr) = alctree(1033, "classDeclaration", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2130 "k0gram.tab.c"
    break;

  case 82: /* classDeclaration: CLASS simpleIdentifier opt_typeParameters classBody  */
#line 263 "k0gram.y"
                                                          {(yyval.treeptr) = alctree(1033, "classDeclaration", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2136 "k0gram.tab.c"
    break;

  case 83: /* variableDeclaration: type COLON type  */
#line 267 "k0gram.y"
                     {(yyval.treeptr) = alctree(1034, "variableDeclaration", 1, (yyvsp[-2].treeptr));}
#line 2142 "k0gram.tab.c"
    break;

  case 84: /* variableDeclaration: type  */
#line 268 "k0gram.y"
          {(yyval.treeptr) = alctree(1034, "variableDeclaration", 1, (yyvsp[0].treeptr));}
#line 2148 "k0gram.tab.c"
    break;

  case 85: /* multiVariableDeclaration: LPAREN variableDeclaration multi_comma_variableDeclaration opt_comma RPAREN  */
#line 272 "k0gram.y"
                                                                               {(yyval.treeptr) = alctree(1035, "multiVariableDeclaration", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2154 "k0gram.tab.c"
    break;

  case 86: /* multi_comma_variableDeclaration: multi_comma_variableDeclaration COMMA variableDeclaration  */
#line 275 "k0gram.y"
                                                             {(yyval.treeptr) = alctree(1036, "multi_comma_variableDeclaration", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2160 "k0gram.tab.c"
    break;

  case 87: /* multi_comma_variableDeclaration: %empty  */
#line 276 "k0gram.y"
    { /* epsilon production */ }
#line 2166 "k0gram.tab.c"
    break;

  case 88: /* classBody: LCURL classMembers RCURL  */
#line 282 "k0gram.y"
                              {(yyval.treeptr) = alctree(1037, "classBody", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2172 "k0gram.tab.c"
    break;

  case 89: /* assignmentAndOperator: ADD_ASSIGNMENT  */
#line 287 "k0gram.y"
                    {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2178 "k0gram.tab.c"
    break;

  case 90: /* assignmentAndOperator: SUB_ASSIGNMENT  */
#line 288 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2184 "k0gram.tab.c"
    break;

  case 91: /* assignmentAndOperator: MULT_ASSIGNMENT  */
#line 289 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2190 "k0gram.tab.c"
    break;

  case 92: /* assignmentAndOperator: DIV_ASSIGNMENT  */
#line 290 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2196 "k0gram.tab.c"
    break;

  case 93: /* assignmentAndOperator: MOD_ASSIGNMENT  */
#line 291 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2202 "k0gram.tab.c"
    break;

  case 94: /* assignableExpression: prefixUnaryExpression  */
#line 295 "k0gram.y"
                        {(yyval.treeptr) = alctree (1038, "assignableExpression", 1, (yyvsp[0].treeptr));}
#line 2208 "k0gram.tab.c"
    break;

  case 95: /* assignableExpression: parenthesizedAssignableExpression  */
#line 296 "k0gram.y"
                                      {(yyval.treeptr) = alctree (1038, "assignableExpression", 1, (yyvsp[0].treeptr));}
#line 2214 "k0gram.tab.c"
    break;

  case 96: /* multi_unaryPrefix: multi_unaryPrefix prefixUnaryOperator  */
#line 299 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1039, "multi_unaryPrefix", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2220 "k0gram.tab.c"
    break;

  case 97: /* $@5: %empty  */
#line 300 "k0gram.y"
    { /* epsilon production */ }
#line 2226 "k0gram.tab.c"
    break;

  case 98: /* multi_unaryPrefix: $@5  */
#line 300 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2232 "k0gram.tab.c"
    break;

  case 99: /* prefixUnaryOperator: ADD  */
#line 303 "k0gram.y"
         {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2238 "k0gram.tab.c"
    break;

  case 100: /* prefixUnaryOperator: SUB  */
#line 304 "k0gram.y"
           {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2244 "k0gram.tab.c"
    break;

  case 101: /* prefixUnaryOperator: INCR  */
#line 305 "k0gram.y"
            {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2250 "k0gram.tab.c"
    break;

  case 102: /* prefixUnaryOperator: DECR  */
#line 306 "k0gram.y"
            {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2256 "k0gram.tab.c"
    break;

  case 103: /* prefixUnaryOperator: EXCL_NO_WS EXCL_NO_WS  */
#line 307 "k0gram.y"
                           { (yyval.treeptr) = alctree(1040, "prefixUnaryOperator", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2262 "k0gram.tab.c"
    break;

  case 104: /* prefixUnaryExpression: multi_unaryPrefix postfixUnaryExpression  */
#line 312 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1041, "prefixUnaryExpression", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2268 "k0gram.tab.c"
    break;

  case 105: /* parenthesizedAssignableExpression: LPAREN assignableExpression RPAREN  */
#line 316 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1042, "parenthesizedAssignableExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2274 "k0gram.tab.c"
    break;

  case 106: /* assignment: directly_assign expression  */
#line 320 "k0gram.y"
                              {(yyval.treeptr) = alctree(1043, "assignment", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2280 "k0gram.tab.c"
    break;

  case 107: /* directly_assign: directlyAssignableExpression ASSIGNMENT  */
#line 324 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1044, "directly_assign", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2286 "k0gram.tab.c"
    break;

  case 108: /* directly_assign: assignableExpression assignmentAndOperator  */
#line 325 "k0gram.y"
                                                  {(yyval.treeptr) = alctree(1044, "directly_assign", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2292 "k0gram.tab.c"
    break;

  case 109: /* assignableSuffix: indexingSuffix  */
#line 329 "k0gram.y"
                    {(yyval.treeptr) = alctree(1045, "assignableSuffix", 1, (yyvsp[0].treeptr));}
#line 2298 "k0gram.tab.c"
    break;

  case 110: /* assignableSuffix: typeArguments  */
#line 330 "k0gram.y"
                    {(yyval.treeptr) = alctree(1045, "assignableSuffix", 1, (yyvsp[0].treeptr));}
#line 2304 "k0gram.tab.c"
    break;

  case 111: /* typeArguments: LANGLE typeProjection multi_comma_typeProjection opt_comma RANGLE  */
#line 334 "k0gram.y"
                                                                       {(yyval.treeptr) = alctree(1046, "typeArguments", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2310 "k0gram.tab.c"
    break;

  case 112: /* multi_comma_typeProjection: multi_comma_typeProjection COMMA typeProjection  */
#line 338 "k0gram.y"
                                                  {(yyval.treeptr) = alctree(1047, "multi_comma_typeProjection", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2316 "k0gram.tab.c"
    break;

  case 113: /* $@6: %empty  */
#line 339 "k0gram.y"
    { /* epsilon production */ }
#line 2322 "k0gram.tab.c"
    break;

  case 114: /* multi_comma_typeProjection: $@6  */
#line 339 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2328 "k0gram.tab.c"
    break;

  case 115: /* typeProjection: type  */
#line 344 "k0gram.y"
        {(yyval.treeptr) = alctree(1048, "typeProjection", 1, (yyvsp[0].treeptr));}
#line 2334 "k0gram.tab.c"
    break;

  case 116: /* typeProjection: MULT  */
#line 345 "k0gram.y"
          {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2340 "k0gram.tab.c"
    break;

  case 117: /* directlyAssignableExpression: postfixUnaryExpression assignableSuffix  */
#line 348 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1049, "directlyAssignableExpression", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2346 "k0gram.tab.c"
    break;

  case 118: /* directlyAssignableExpression: simpleIdentifier  */
#line 349 "k0gram.y"
                        {(yyval.treeptr) = alctree(1049, "directlyAssignableExpression", 1, (yyvsp[0].treeptr));}
#line 2352 "k0gram.tab.c"
    break;

  case 119: /* directlyAssignableExpression: parenthesizedDirectlyAssignableExpression  */
#line 350 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1049, "directlyAssignableExpression", 1, (yyvsp[0].treeptr));}
#line 2358 "k0gram.tab.c"
    break;

  case 120: /* parenthesizedDirectlyAssignableExpression: LPAREN assignableExpression RPAREN  */
#line 354 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1050, "parenthesizedDirectlyAssignableExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2364 "k0gram.tab.c"
    break;

  case 121: /* multi_postfixUnarySuffix: multi_postfixUnarySuffix postfixUnarySuffix  */
#line 358 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1051, "multi_postfixUnarySuffix", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2370 "k0gram.tab.c"
    break;

  case 122: /* $@7: %empty  */
#line 359 "k0gram.y"
      { /* epsilon production */ }
#line 2376 "k0gram.tab.c"
    break;

  case 123: /* multi_postfixUnarySuffix: $@7  */
#line 359 "k0gram.y"
                                    {(yyval.treeptr) = NULL;}
#line 2382 "k0gram.tab.c"
    break;

  case 124: /* postfixUnaryExpression: primaryExpression multi_postfixUnarySuffix  */
#line 362 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1052, "postfixUnaryExpression", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2388 "k0gram.tab.c"
    break;

  case 125: /* postfixUnarySuffix: postfixUnaryOperator  */
#line 366 "k0gram.y"
                        {(yyval.treeptr) = alctree(1053, "postfixUnarySuffix", 1, (yyvsp[0].treeptr));}
#line 2394 "k0gram.tab.c"
    break;

  case 126: /* postfixUnarySuffix: indexingSuffix  */
#line 367 "k0gram.y"
                    {(yyval.treeptr) = alctree(1053, "postfixUnarySuffix", 1, (yyvsp[0].treeptr));}
#line 2400 "k0gram.tab.c"
    break;

  case 127: /* postfixUnarySuffix: callSuffix  */
#line 368 "k0gram.y"
               {(yyval.treeptr) = alctree(1053, "postfixUnarySuffix", 1, (yyvsp[0].treeptr));}
#line 2406 "k0gram.tab.c"
    break;

  case 128: /* postfixUnarySuffix: navigationSuffix  */
#line 369 "k0gram.y"
                    {(yyval.treeptr) = alctree(1053, "postfixUnarySuffix", 1, (yyvsp[0].treeptr));}
#line 2412 "k0gram.tab.c"
    break;

  case 129: /* identifier_expression_class: simpleIdentifier  */
#line 373 "k0gram.y"
                   {(yyval.treeptr) = alctree(1054, "identifier_expression_class", 1, (yyvsp[0].treeptr));}
#line 2418 "k0gram.tab.c"
    break;

  case 130: /* identifier_expression_class: parenthesizedExpression  */
#line 374 "k0gram.y"
                             {(yyval.treeptr) = alctree(1054, "identifier_expression_class", 1, (yyvsp[0].treeptr));}
#line 2424 "k0gram.tab.c"
    break;

  case 131: /* identifier_expression_class: CLASS  */
#line 375 "k0gram.y"
          {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2430 "k0gram.tab.c"
    break;

  case 132: /* navigationSuffix: memberAccessOperator identifier_expression_class  */
#line 379 "k0gram.y"
                                                   {(yyval.treeptr) = alctree(1055, "navigationSuffix", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2436 "k0gram.tab.c"
    break;

  case 133: /* memberAccessOperator: DOT  */
#line 383 "k0gram.y"
      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2442 "k0gram.tab.c"
    break;

  case 134: /* memberAccessOperator: QUEST_NO_WS DOT  */
#line 384 "k0gram.y"
                    {(yyval.treeptr) = alctree(1056, "memberAccessOperator", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2448 "k0gram.tab.c"
    break;

  case 135: /* postfixUnaryOperator: INCR  */
#line 388 "k0gram.y"
          { (yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2454 "k0gram.tab.c"
    break;

  case 136: /* postfixUnaryOperator: DECR  */
#line 389 "k0gram.y"
            { (yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2460 "k0gram.tab.c"
    break;

  case 137: /* postfixUnaryOperator: EXCL_NO_WS EXCL_NO_WS  */
#line 390 "k0gram.y"
                            { (yyval.treeptr) = alctree(1057, "postfixUnaryOperator", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2466 "k0gram.tab.c"
    break;

  case 138: /* multi_comma_expression: multi_comma_expression COMMA expression  */
#line 394 "k0gram.y"
                                          {(yyval.treeptr) = alctree(1058, "multi_comma_expression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2472 "k0gram.tab.c"
    break;

  case 139: /* $@8: %empty  */
#line 395 "k0gram.y"
    { /* epsilon production */ }
#line 2478 "k0gram.tab.c"
    break;

  case 140: /* multi_comma_expression: $@8  */
#line 395 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2484 "k0gram.tab.c"
    break;

  case 141: /* indexingSuffix: LSQUARE expression multi_comma_expression opt_comma RSQUARE  */
#line 399 "k0gram.y"
                                                                {(yyval.treeptr) = alctree(1059, "indexingSuffix", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2490 "k0gram.tab.c"
    break;

  case 142: /* callSuffix: valueArguments  */
#line 403 "k0gram.y"
                  {(yyval.treeptr) = alctree(1060, "callSuffix", 1, (yyvsp[0].treeptr));}
#line 2496 "k0gram.tab.c"
    break;

  case 143: /* multi_comma_valueArgument: multi_comma_valueArgument COMMA valueArgument  */
#line 407 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1061, "multi_comma_valueArgument", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2502 "k0gram.tab.c"
    break;

  case 144: /* $@9: %empty  */
#line 408 "k0gram.y"
    { /* epsilon production */ }
#line 2508 "k0gram.tab.c"
    break;

  case 145: /* multi_comma_valueArgument: $@9  */
#line 408 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2514 "k0gram.tab.c"
    break;

  case 146: /* opt_valueArgument: valueArgument multi_comma_valueArgument opt_comma  */
#line 411 "k0gram.y"
                                                    {(yyval.treeptr) = alctree(1062, "opt_valueArgument", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2520 "k0gram.tab.c"
    break;

  case 147: /* $@10: %empty  */
#line 412 "k0gram.y"
    { /* epsilon production */ }
#line 2526 "k0gram.tab.c"
    break;

  case 148: /* opt_valueArgument: $@10  */
#line 412 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2532 "k0gram.tab.c"
    break;

  case 149: /* valueArguments: LPAREN opt_valueArgument RPAREN  */
#line 416 "k0gram.y"
                                    {(yyval.treeptr) = alctree(1063, "valueArguments", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2538 "k0gram.tab.c"
    break;

  case 150: /* opt_simpleIdentifier_EQ: simpleIdentifier ASSIGNMENT  */
#line 420 "k0gram.y"
                                {(yyval.treeptr) = alctree(1064, "opt_simpleIdentifier_EQ", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2544 "k0gram.tab.c"
    break;

  case 151: /* $@11: %empty  */
#line 421 "k0gram.y"
      { /* epsilon production */ }
#line 2550 "k0gram.tab.c"
    break;

  case 152: /* opt_simpleIdentifier_EQ: $@11  */
#line 421 "k0gram.y"
                                    {(yyval.treeptr) = NULL;}
#line 2556 "k0gram.tab.c"
    break;

  case 153: /* opt_Multi: MULT  */
#line 425 "k0gram.y"
        {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2562 "k0gram.tab.c"
    break;

  case 154: /* $@12: %empty  */
#line 426 "k0gram.y"
    { /* epsilon production */ }
#line 2568 "k0gram.tab.c"
    break;

  case 155: /* opt_Multi: $@12  */
#line 426 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2574 "k0gram.tab.c"
    break;

  case 156: /* valueArgument: opt_simpleIdentifier_EQ opt_Multi expression  */
#line 430 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1065, "valueArgument", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2580 "k0gram.tab.c"
    break;

  case 157: /* parenthesizedExpression: LPAREN expression RPAREN  */
#line 434 "k0gram.y"
                              {(yyval.treeptr) = alctree(1066, "parenthesizedExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2586 "k0gram.tab.c"
    break;

  case 158: /* functionCall: IDENTIFIER LPAREN functionArguments RPAREN  */
#line 451 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1068, "functionCall", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2592 "k0gram.tab.c"
    break;

  case 159: /* functionArguments: expression  */
#line 457 "k0gram.y"
              {(yyval.treeptr) = alctree(1069, "functionArguments", 1, (yyvsp[0].treeptr));}
#line 2598 "k0gram.tab.c"
    break;

  case 160: /* functionArguments: functionArguments COMMA expression  */
#line 458 "k0gram.y"
                                       {(yyval.treeptr) = alctree(1070, "functionArguments", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2604 "k0gram.tab.c"
    break;

  case 161: /* functionArguments: %empty  */
#line 459 "k0gram.y"
              {(yyval.treeptr) = NULL;}
#line 2610 "k0gram.tab.c"
    break;

  case 162: /* variable_multivariable: variableDeclaration  */
#line 463 "k0gram.y"
                     {(yyval.treeptr) = alctree(1071,"variable_multivariable", 1, (yyvsp[0].treeptr));}
#line 2616 "k0gram.tab.c"
    break;

  case 163: /* variable_multivariable: multiVariableDeclaration  */
#line 464 "k0gram.y"
                              {(yyval.treeptr) = alctree(1071,"variable_multivariable", 1, (yyvsp[0].treeptr));}
#line 2622 "k0gram.tab.c"
    break;

  case 164: /* control_structure_body_or_comma: controlStructureBody  */
#line 468 "k0gram.y"
                        {(yyval.treeptr) = alctree(1072,"control_structure_body_or_comma", 1, (yyvsp[0].treeptr));}
#line 2628 "k0gram.tab.c"
    break;

  case 165: /* control_structure_body_or_comma: COMMA  */
#line 469 "k0gram.y"
          {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2634 "k0gram.tab.c"
    break;

  case 166: /* loopStatement: WHILE LPAREN expression RPAREN control_structure_body_or_comma  */
#line 473 "k0gram.y"
                                                                    {(yyval.treeptr) = alctree(1073,"loopStatement", 5 ,(yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2640 "k0gram.tab.c"
    break;

  case 167: /* loopStatement: FOR LPAREN variable_multivariable IN expression RPAREN controlStructureBody  */
#line 474 "k0gram.y"
                                                                                   {(yyval.treeptr) = alctree(1073,"loopStatement", 7 ,(yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr),(yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2646 "k0gram.tab.c"
    break;

  case 168: /* controlStructureBody: block  */
#line 479 "k0gram.y"
         {(yyval.treeptr) = alctree(1074, "controlStructureBody", 1, (yyvsp[0].treeptr));}
#line 2652 "k0gram.tab.c"
    break;

  case 169: /* controlStructureBody: statement  */
#line 480 "k0gram.y"
              {(yyval.treeptr) = alctree(1074, "controlStructureBody", 1, (yyvsp[0].treeptr));}
#line 2658 "k0gram.tab.c"
    break;

  case 170: /* jumpExpression: RETURN expression  */
#line 485 "k0gram.y"
                    {alctree(1075, "jumpExpression", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2664 "k0gram.tab.c"
    break;

  case 174: /* classMembers: %empty  */
#line 527 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 2670 "k0gram.tab.c"
    break;

  case 175: /* classMembers: classMembers classMember  */
#line 528 "k0gram.y"
                              {(yyval.treeptr) = alctree(1082, "classMembers", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2676 "k0gram.tab.c"
    break;

  case 176: /* classMember: functionDeclaration  */
#line 532 "k0gram.y"
                        {(yyval.treeptr) = alctree(1083, "classMember", 1, (yyvsp[0].treeptr));}
#line 2682 "k0gram.tab.c"
    break;

  case 177: /* classMember: variableDeclaration  */
#line 533 "k0gram.y"
                          {(yyval.treeptr) = alctree(1083, "classMember", 1, (yyvsp[0].treeptr));}
#line 2688 "k0gram.tab.c"
    break;

  case 178: /* objectDeclaration: OBJECT IDENTIFIER objectBody  */
#line 538 "k0gram.y"
                                  {(yyval.treeptr) = alctree(1084, "objectDeclaration", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2694 "k0gram.tab.c"
    break;

  case 179: /* objectBody: LCURL classMembers RCURL  */
#line 542 "k0gram.y"
                              {(yyval.treeptr) = alctree(1085, "objectBody", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2700 "k0gram.tab.c"
    break;

  case 180: /* expression: disjunction  */
#line 547 "k0gram.y"
              {(yyval.treeptr) = alctree(1086, "expression", 1, (yyvsp[0].treeptr));}
#line 2706 "k0gram.tab.c"
    break;

  case 181: /* disjunction: conjunction  */
#line 551 "k0gram.y"
              {(yyval.treeptr) = alctree(1087, "disjuction", 1, (yyvsp[0].treeptr));}
#line 2712 "k0gram.tab.c"
    break;

  case 182: /* disjunction: disjunction DISJ conjunction  */
#line 552 "k0gram.y"
                                 {(yyval.treeptr) = alctree(1087, "disjuction", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2718 "k0gram.tab.c"
    break;

  case 183: /* conjunction: equality  */
#line 556 "k0gram.y"
           {(yyval.treeptr) = alctree(1088, "conjuction", 1, (yyvsp[0].treeptr));}
#line 2724 "k0gram.tab.c"
    break;

  case 184: /* conjunction: conjunction CONJ equality  */
#line 557 "k0gram.y"
                              {(yyval.treeptr) = alctree(1088, "conjuction", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2730 "k0gram.tab.c"
    break;

  case 185: /* equality: comparison  */
#line 561 "k0gram.y"
             {(yyval.treeptr) = alctree(1028, "equality", 1, (yyvsp[0].treeptr));}
#line 2736 "k0gram.tab.c"
    break;

  case 186: /* equality: equality equality_operator comparison  */
#line 562 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1028, "equality", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2742 "k0gram.tab.c"
    break;

  case 187: /* comparison: genericCallLikeComparison  */
#line 566 "k0gram.y"
                                {(yyval.treeptr) = alctree(1029, "comparison", 1, (yyvsp[0].treeptr));}
#line 2748 "k0gram.tab.c"
    break;

  case 188: /* comparison: comparison comparison_operator genericCallLikeComparison  */
#line 567 "k0gram.y"
                                                               {(yyval.treeptr) = alctree(1028, "comparison", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2754 "k0gram.tab.c"
    break;

  case 189: /* genericCallLikeComparison: elvisExpression  */
#line 571 "k0gram.y"
                      {(yyval.treeptr) = alctree(1029, "genericCallLikeComparison", 1, (yyvsp[0].treeptr));}
#line 2760 "k0gram.tab.c"
    break;

  case 190: /* genericCallLikeComparison: elvisExpression IN elvisExpression  */
#line 572 "k0gram.y"
                                         {(yyval.treeptr) = alctree(1029, "genericCallLikeComparison", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2766 "k0gram.tab.c"
    break;

  case 191: /* elvisExpression: rangeExpression  */
#line 576 "k0gram.y"
                      {(yyval.treeptr) = alctree(1030, "elvisExpression", 1, (yyvsp[0].treeptr));}
#line 2772 "k0gram.tab.c"
    break;

  case 192: /* elvisExpression: elvisExpression QUEST_COLON rangeExpression  */
#line 577 "k0gram.y"
                                                   {(yyval.treeptr) = alctree(1030, "elvisExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2778 "k0gram.tab.c"
    break;

  case 193: /* rangeExpression: additiveExpression  */
#line 581 "k0gram.y"
                         {(yyval.treeptr) = alctree(1031, "rangeExpression", 1, (yyvsp[0].treeptr));}
#line 2784 "k0gram.tab.c"
    break;

  case 194: /* rangeExpression: rangeExpression RANGE additiveExpression  */
#line 582 "k0gram.y"
                                               {(yyval.treeptr) = alctree(1031, "rangeExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2790 "k0gram.tab.c"
    break;

  case 195: /* additiveExpression: multiplicativeExpression  */
#line 586 "k0gram.y"
                             {(yyval.treeptr) = alctree(1032, "additiveExpression", 1, (yyvsp[0].treeptr));}
#line 2796 "k0gram.tab.c"
    break;

  case 196: /* additiveExpression: additiveExpression ADD multiplicativeExpression  */
#line 587 "k0gram.y"
                                                      {(yyval.treeptr) = alctree(1032, "additiveExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2802 "k0gram.tab.c"
    break;

  case 197: /* additiveExpression: additiveExpression SUB multiplicativeExpression  */
#line 588 "k0gram.y"
                                                      {(yyval.treeptr) = alctree(1032, "additiveExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2808 "k0gram.tab.c"
    break;

  case 198: /* multiplicativeExpression: postfixUnaryExpression  */
#line 592 "k0gram.y"
                         {(yyval.treeptr) = alctree(1033, "multiplicativeExpression", 1, (yyvsp[0].treeptr));}
#line 2814 "k0gram.tab.c"
    break;

  case 199: /* multiplicativeExpression: multiplicativeExpression MULT postfixUnaryExpression  */
#line 593 "k0gram.y"
                                                         {(yyval.treeptr) = alctree(1033, "multiplicativeExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2820 "k0gram.tab.c"
    break;

  case 200: /* multiplicativeExpression: multiplicativeExpression DIV postfixUnaryExpression  */
#line 594 "k0gram.y"
                                                        {(yyval.treeptr) = alctree(1033, "multiplicativeExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2826 "k0gram.tab.c"
    break;

  case 201: /* multiplicativeExpression: multiplicativeExpression MOD postfixUnaryExpression  */
#line 595 "k0gram.y"
                                                        {(yyval.treeptr) = alctree(1033, "multiplicativeExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2832 "k0gram.tab.c"
    break;

  case 202: /* primaryExpression: parenthesizedExpression  */
#line 599 "k0gram.y"
                          { (yyval.treeptr) = alctree(1035, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 2838 "k0gram.tab.c"
    break;

  case 204: /* primaryExpression: functionCall  */
#line 601 "k0gram.y"
                   { (yyval.treeptr) = alctree(1035, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 2844 "k0gram.tab.c"
    break;

  case 208: /* primaryExpression: jumpExpression  */
#line 605 "k0gram.y"
                      {(yyval.treeptr) = alctree(1011, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 2850 "k0gram.tab.c"
    break;

  case 209: /* primaryExpression: collectionLiteral  */
#line 606 "k0gram.y"
                        {(yyval.treeptr) = alctree(1011, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 2856 "k0gram.tab.c"
    break;

  case 210: /* collectionLiteral: LSQUARE RSQUARE  */
#line 610 "k0gram.y"
                  {(yyval.treeptr) = alctree(1011, "collectionLiteral", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2862 "k0gram.tab.c"
    break;

  case 211: /* collectionLiteral: LSQUARE expression COMMA RSQUARE  */
#line 611 "k0gram.y"
                                     {(yyval.treeptr) = alctree(1011, "collectionLiteral", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2868 "k0gram.tab.c"
    break;

  case 212: /* collectionLiteral: LSQUARE expression RSQUARE  */
#line 612 "k0gram.y"
                               {(yyval.treeptr) = alctree(1011, "collectionLiteral", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2874 "k0gram.tab.c"
    break;

  case 213: /* collectionLiteral: LSQUARE expression multi_comma_expression RSQUARE  */
#line 613 "k0gram.y"
                                                      {(yyval.treeptr) = alctree(1011, "collectionLiteral", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2880 "k0gram.tab.c"
    break;

  case 214: /* collectionLiteral: LSQUARE expression multi_comma_expression COMMA RSQUARE  */
#line 614 "k0gram.y"
                                                            {(yyval.treeptr) = alctree(1011, "collectionLiteral", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2886 "k0gram.tab.c"
    break;


#line 2890 "k0gram.tab.c"

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

#line 634 "k0gram.y"

const char *yyname(int sym)
{ 
   return yytname[sym-RESERVED+3];
}
