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
#define YYLAST   712

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  155
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  121
/* YYNRULES -- Number of rules.  */
#define YYNRULES  241
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  378

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
     107,   108,   113,   114,   119,   124,   125,   129,   130,   135,
     136,   140,   146,   147,   148,   149,   153,   154,   155,   159,
     160,   164,   165,   165,   170,   176,   177,   177,   181,   186,
     187,   192,   193,   193,   196,   200,   201,   206,   207,   207,
     212,   213,   217,   218,   219,   224,   225,   229,   230,   233,
     237,   242,   243,   247,   251,   252,   256,   257,   261,   264,
     265,   271,   276,   277,   278,   279,   280,   284,   285,   288,
     289,   289,   292,   293,   294,   295,   296,   301,   305,   309,
     313,   314,   318,   319,   323,   327,   328,   328,   333,   334,
     335,   338,   339,   340,   344,   348,   349,   349,   352,   356,
     357,   358,   359,   363,   364,   365,   369,   373,   374,   378,
     379,   380,   384,   385,   385,   389,   393,   397,   398,   398,
     401,   402,   402,   406,   410,   411,   411,   415,   416,   416,
     420,   424,   430,   434,   435,   440,   441,   445,   446,   451,
     452,   453,   457,   458,   462,   463,   467,   468,   469,   474,
     475,   480,   481,   482,   483,   487,   488,   492,   493,   497,
     498,   501,   502,   502,   506,   507,   508,   509,   513,   514,
     518,   522,   523,   527,   528,   533,   537,   538,   542,   543,
     547,   548,   552,   553,   557,   558,   562,   563,   567,   568,
     572,   573,   574,   578,   579,   580,   581,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   600,
     601,   602,   603,   604,   609,   610,   611,   612,   616,   617,
     618,   619
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

#define YYPACT_NINF (-154)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-142)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -29,  -145,    -7,   -23,    53,    18,  -154,  -154,  -154,   135,
    -154,  -154,  -154,  -154,    -7,  -145,    -2,  -154,  -145,  -154,
    -154,  -154,  -154,    -7,    69,  -154,  -154,    29,  -154,  -154,
    -154,    90,  -154,     3,    -7,    32,  -154,  -154,    94,  -154,
     100,  -154,    75,   112,  -154,  -145,    82,  -154,  -145,    27,
     106,  -154,    69,    29,   110,   128,   115,  -154,  -154,    44,
    -145,   103,  -154,  -145,   139,  -154,  -154,   115,   141,   142,
    -154,   132,  -154,    29,    26,  -154,    73,  -154,    29,    32,
     504,   157,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,
     106,   187,  -154,  -154,    29,  -154,   191,  -154,  -154,    34,
     504,  -154,  -154,  -154,   193,  -154,   115,   504,   471,   195,
      50,   504,  -154,  -154,  -154,  -154,  -154,  -154,  -154,   102,
    -154,  -154,  -154,  -154,  -154,   175,  -154,  -154,  -154,   188,
     201,   196,   274,  -154,   -35,   189,    62,    -8,  -154,  -154,
    -154,    26,  -145,  -154,    27,   168,   561,   210,   218,   221,
    -154,   230,  -154,   213,   209,   198,   312,  -154,  -154,  -154,
     213,   504,   224,  -154,    11,   213,   213,   227,    29,   242,
     231,   245,  -154,    76,   504,   487,  -154,   243,  -154,   107,
     504,   111,   504,   504,   504,  -154,  -154,  -154,  -154,   504,
    -154,  -154,  -154,  -154,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   257,  -154,  -154,  -154,  -154,  -154,   561,
     253,    32,  -154,  -154,   177,   504,  -154,    64,  -154,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,   247,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,   504,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,   263,  -154,   109,
    -154,   269,    29,   271,   339,  -154,  -154,   179,  -154,  -154,
     183,   201,   196,   274,  -154,   189,   225,    62,    -8,    -8,
    -154,  -154,  -154,  -154,    15,  -154,  -154,   262,   281,  -154,
    -154,    10,  -154,  -154,  -154,  -154,   280,   270,  -154,  -154,
     197,   285,   288,   251,  -154,  -154,  -154,   500,  -154,   218,
     276,  -154,  -154,   277,   504,  -154,  -154,  -154,  -154,   390,
     504,   213,   213,   282,   290,  -154,   154,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,   504,   504,    63,  -154,
     303,  -154,  -154,  -154,   234,   504,   218,  -154,    25,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,   504,  -154,   318,
    -154,   319,   321,  -154,  -154,  -154,   504,   322,   218,   323,
     314,   408,   218,  -154,    17,  -154,   218,  -154,  -154,  -154,
    -154,  -154,   218,  -154,  -154,  -154,  -154,  -154
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      42,     0,    66,    41,     0,    42,     3,    37,     5,     0,
      43,    38,    36,    73,    66,     0,     0,    65,     0,     1,
       4,    40,    39,    66,     0,    72,    70,     0,    55,    56,
      46,     0,    52,    50,    66,     0,   191,    75,    68,    21,
       0,    20,    50,    48,    47,     0,    54,    53,    19,     0,
       9,    49,     0,     0,    77,    20,    58,    60,    61,     0,
      67,     0,    44,     0,     0,    51,    16,    58,     0,     0,
     110,   108,   106,     0,     7,    74,    77,    80,     0,     0,
       0,    64,    59,    81,   193,   194,   192,    71,    69,    45,
       9,    18,    13,    12,     0,   109,    68,   107,     8,    90,
       0,    11,     6,    22,    68,    76,    58,     0,     0,     0,
       0,   172,   173,   174,   223,   220,   224,   222,   221,    73,
     218,   213,   217,   227,   219,     0,   225,   228,    57,   195,
     196,   198,   200,   202,   204,   206,   208,   210,   116,   226,
      63,     7,    17,    14,    67,     0,    90,     0,    90,     0,
      31,     0,    28,    26,   218,     0,     0,    91,    87,    88,
      26,     0,     0,   113,   213,    26,    26,     0,    67,     0,
       0,     0,   229,     0,     0,     0,   176,     0,   171,     0,
     161,     0,   161,     0,     0,   240,   241,   238,   239,     0,
     234,   235,   236,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   118,   117,    10,    15,   105,   104,    90,
       0,     0,   169,   170,     0,     0,    24,    26,    25,    32,
      82,    83,    84,    85,    86,   101,    94,    95,     0,    92,
      93,    89,    97,    33,    99,   100,     0,   111,   103,   102,
      35,    34,    23,    79,    78,    62,   151,     0,   231,     0,
     134,     0,     0,     0,     0,   176,   157,     0,   159,   158,
       0,   197,   199,   201,   203,   207,   205,   209,   211,   212,
     214,   216,   215,   127,   145,   129,   130,     0,     0,   115,
     122,     0,   119,   120,   121,   136,     0,    98,   162,   163,
       0,     0,     0,    90,    96,   133,   230,     0,   232,    90,
       0,   179,   178,     0,     0,   175,   182,   189,   188,     0,
       0,    26,    26,     0,     0,   142,   148,   146,   138,   131,
     128,   125,   123,   126,   124,    98,     0,     0,    90,    27,
      68,   233,   132,   152,   154,     0,    90,   190,     0,   183,
     177,   160,   155,   156,   144,   143,   147,     0,   149,    68,
     139,     0,     0,   165,   166,   164,    67,     0,    90,     0,
     187,     0,    90,   150,   145,   140,    90,   168,   135,   153,
     180,   186,    90,   181,   184,   137,   167,   185
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,  -154,  -154,   331,   200,   261,   293,   289,   214,  -154,
    -154,  -154,   160,  -154,   -54,  -153,  -154,  -154,  -154,   -96,
      92,  -154,  -154,  -154,  -154,  -154,  -154,  -154,   295,  -154,
    -154,    54,  -154,   -40,  -154,   283,  -154,    40,   -94,  -154,
     299,  -154,    -1,  -154,   -48,   153,  -154,   315,  -154,  -121,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,   202,  -154,
    -154,   228,  -154,  -154,  -154,  -154,   -91,  -154,  -154,  -154,
    -154,  -154,    78,  -154,   165,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,  -154,    12,    93,  -154,  -154,  -154,
    -154,   203,  -154,  -154,  -154,    61,  -154,   120,  -154,  -154,
    -154,  -154,  -154,    16,  -154,  -154,  -154,   -79,  -154,   207,
     194,   205,   186,   190,   204,   211,    36,  -154,  -154,  -154,
    -154
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,     6,   101,    74,     7,    50,    66,    67,
      91,    68,    54,   102,   212,   219,   217,   150,   151,   213,
     153,    23,     9,    10,    28,    43,    44,    29,    30,    46,
      47,    41,    32,    81,    82,    56,    11,    16,    61,    17,
      25,    38,   120,    12,    57,    58,   104,    37,   225,   155,
     156,   157,   231,   158,   159,   160,   161,   237,    51,    96,
      97,    72,   162,   163,   203,   204,   121,   279,   323,   280,
     281,   282,   249,   250,   239,   284,   349,   350,   314,   315,
     285,   316,   317,   347,   348,   318,   122,   123,   333,   124,
     125,   257,   290,   354,   165,   214,   126,   254,   127,   177,
     338,   339,   305,   306,   307,    59,    86,   166,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   194,
     189
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,   128,   145,   152,    27,    77,    13,   233,   164,    48,
     169,    85,   240,   241,    26,    33,   107,    34,    -2,   236,
     103,   167,  -141,   195,   -67,   210,    42,    92,   171,   173,
     361,    15,   178,    27,    42,    27,    99,     1,    53,     2,
     146,    49,   108,    18,    64,   -30,   100,    69,    42,    49,
      27,   362,    42,    19,    24,    83,   175,   164,    42,    26,
     176,   196,    42,    35,   293,   232,   170,   171,   353,   146,
      31,   108,    42,    99,    52,   -29,   321,    42,    42,    36,
      62,   247,   234,   218,     1,   248,     2,   103,   286,    55,
       3,    78,     8,    42,    45,   251,   253,     8,   154,    60,
       1,   258,     2,   258,   -42,   -42,   179,    62,   180,   270,
     271,   272,     2,    49,   297,   109,    63,   110,   298,    65,
     243,   147,   148,   149,    73,   111,   112,   113,    78,     1,
     171,     2,    79,   -42,   -42,    80,   292,     3,   200,   201,
     202,    69,    88,    42,   109,    48,   110,   154,    93,    13,
     147,   148,   149,     3,   111,   112,   113,   295,   342,   343,
      94,    13,   114,   288,   115,   116,    13,    42,    13,    95,
     117,   118,    39,    70,    39,   308,   140,    39,    13,   181,
      13,   182,     3,    13,   310,   119,   311,    40,   310,    39,
     312,   114,   142,   115,   116,    13,   144,   329,   168,   117,
     118,   174,   164,   183,   300,    21,    22,   208,   164,    71,
      42,   198,   199,    76,   119,   184,   211,   197,   332,   220,
     221,   222,   223,   224,   146,   337,   108,   215,    99,  -112,
     308,   341,   218,    98,   268,   269,   357,   164,   105,   185,
     186,   216,   187,   188,   235,   164,   242,   351,   352,   244,
     245,    42,   246,   255,   143,   365,   359,   146,   256,   108,
     287,   273,   259,   274,   294,   236,   291,   164,   363,   275,
     276,   164,   296,   313,   277,   164,   299,   332,   301,   319,
     322,   164,   308,   195,     1,   320,     2,   325,   -42,   -42,
    -114,   327,   154,   326,   278,   328,   335,   345,   154,   109,
     346,   110,   344,   336,    71,   147,   148,   149,   356,   111,
     112,   113,   190,   191,   192,   193,   358,     1,   107,     2,
     108,   -42,   -42,   364,   226,   227,   366,   154,   367,   228,
     370,   368,   109,   371,   110,   154,    20,     3,   147,   148,
     149,   205,   111,   112,   113,   107,   114,   108,   115,   116,
     302,   141,    84,    90,   117,   118,   206,   154,    89,    87,
     334,   154,   106,   313,   289,   154,   238,    75,   283,   119,
       3,   154,   207,   330,   324,   309,   375,   373,   262,   114,
     264,   115,   116,     0,     0,   260,   266,   117,   118,   355,
     261,     0,     0,   109,   263,   110,   107,   360,   108,   265,
       0,   340,   119,   111,   112,   113,     0,     0,   267,     0,
       0,     0,     0,     0,   107,     0,   108,     0,     0,   369,
     109,   303,   110,   374,     0,     0,     0,   376,     0,     0,
     111,   112,   113,   377,   372,   304,     0,     0,     0,     0,
     114,     0,   115,   116,     0,     0,     0,     0,   117,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   229,   230,   119,     0,     0,     0,   114,     0,   115,
     116,   109,   303,   110,     0,   117,   118,   107,     0,   108,
     172,   111,   112,   113,     0,     0,   304,     0,     0,   109,
     119,   110,     0,   107,     0,   108,     0,     0,     0,   111,
     112,   113,     0,     0,   304,     0,   107,     0,   108,   331,
     107,     0,   108,     0,     0,     0,     0,     0,   114,     0,
     115,   116,     0,     0,     0,     0,   117,   118,     0,     0,
       0,     0,     0,     0,     0,     0,   114,     0,   115,   116,
       0,   119,     0,     0,   117,   118,     0,     0,     0,     0,
       0,     0,   109,     0,   110,     0,     0,   252,     0,   119,
       0,     0,   111,   112,   113,     0,     0,   209,   109,   108,
     110,     0,     0,     0,     0,     0,     0,     0,   111,   112,
     113,   109,     0,   110,     0,   109,     0,   110,     0,     0,
       0,   111,   112,   113,     0,   111,   112,   113,     0,   114,
       0,   115,   116,     0,     0,     0,     0,   117,   118,     0,
       0,     0,     0,     0,     0,   114,     0,   115,   116,     0,
       0,     0,   119,   117,   118,     0,     0,     0,   114,     0,
     115,   116,   114,     0,   115,   116,   117,   118,   119,     0,
     117,   118,   109,     0,   110,     0,     0,     0,     0,     0,
       0,   119,   111,   112,   113,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
       0,   115,   116,     0,     0,     0,     0,   117,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119
};

static const yytype_int16 yycheck[] =
{
       1,    80,    96,    99,     6,    53,   151,   160,    99,     6,
     104,    59,   165,   166,    15,    16,     6,    18,     0,     8,
      74,   100,     7,    58,     7,   146,    27,    67,   107,   108,
       5,    38,   111,     6,    35,     6,    10,    66,     6,    68,
       6,    38,     8,    66,    45,    11,    20,    48,    49,    38,
       6,    26,    53,     0,    14,    11,     6,   148,    59,    60,
      10,    96,    63,    23,   217,   156,   106,   146,     5,     6,
      16,     8,    73,    10,    34,    11,    66,    78,    79,    10,
       7,     5,   161,    19,    66,     9,    68,   141,   209,    35,
     119,    18,     0,    94,     4,   174,   175,     5,    99,     5,
      66,   180,    68,   182,    70,    71,     4,     7,     6,   200,
     201,   202,    68,    38,     5,    81,     4,    83,     9,    37,
     168,    87,    88,    89,    18,    91,    92,    93,    18,    66,
     209,    68,     4,    70,    71,    20,   215,   119,   146,   147,
     148,   142,    39,   144,    81,     6,    83,   148,     7,   151,
      87,    88,    89,   119,    91,    92,    93,   236,   311,   312,
      18,   151,   128,   211,   130,   131,   151,   168,   151,    37,
     136,   137,   145,   146,   145,   254,    19,   145,   151,     4,
     151,     6,   119,   151,     5,   151,     7,    27,     5,   145,
       7,   128,     5,   130,   131,   151,     5,   293,     5,   136,
     137,     6,   293,    15,   252,    70,    71,    39,   299,    49,
     211,   149,   150,    53,   151,    14,     6,    28,   297,    21,
      22,    23,    24,    25,     6,   304,     8,     6,    10,    20,
     309,   310,    19,    73,   198,   199,   330,   328,    78,    43,
      44,    11,    46,    47,    20,   336,    19,   326,   327,     7,
      19,   252,     7,    10,    94,   349,   335,     6,   151,     8,
       7,     4,   151,     6,    17,     8,    89,   358,   347,    12,
      13,   362,     9,   274,    17,   366,     7,   356,     7,    17,
     281,   372,   361,    58,    66,     4,    68,     7,    70,    71,
      20,     6,   293,    96,    37,     7,    20,     7,   299,    81,
     146,    83,    20,    26,   144,    87,    88,    89,     5,    91,
      92,    93,    38,    39,    40,    41,    82,    66,     6,    68,
       8,    70,    71,     5,    12,    13,     7,   328,     7,    17,
       7,     9,    81,    19,    83,   336,     5,   119,    87,    88,
      89,   141,    91,    92,    93,     6,   128,     8,   130,   131,
      11,    90,    59,    64,   136,   137,   142,   358,    63,    60,
     299,   362,    79,   364,   211,   366,   164,    52,   203,   151,
     119,   372,   144,   295,   281,   255,   364,   361,   184,   128,
     194,   130,   131,    -1,    -1,   182,   196,   136,   137,   328,
     183,    -1,    -1,    81,   189,    83,     6,   336,     8,   195,
      -1,    11,   151,    91,    92,    93,    -1,    -1,   197,    -1,
      -1,    -1,    -1,    -1,     6,    -1,     8,    -1,    -1,   358,
      81,    82,    83,   362,    -1,    -1,    -1,   366,    -1,    -1,
      91,    92,    93,   372,    26,    96,    -1,    -1,    -1,    -1,
     128,    -1,   130,   131,    -1,    -1,    -1,    -1,   136,   137,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,    -1,    -1,    -1,   128,    -1,   130,
     131,    81,    82,    83,    -1,   136,   137,     6,    -1,     8,
       9,    91,    92,    93,    -1,    -1,    96,    -1,    -1,    81,
     151,    83,    -1,     6,    -1,     8,    -1,    -1,    -1,    91,
      92,    93,    -1,    -1,    96,    -1,     6,    -1,     8,     9,
       6,    -1,     8,    -1,    -1,    -1,    -1,    -1,   128,    -1,
     130,   131,    -1,    -1,    -1,    -1,   136,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,   130,   131,
      -1,   151,    -1,    -1,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    83,    -1,    -1,    70,    -1,   151,
      -1,    -1,    91,    92,    93,    -1,    -1,     6,    81,     8,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    81,    -1,    83,    -1,    81,    -1,    83,    -1,    -1,
      -1,    91,    92,    93,    -1,    91,    92,    93,    -1,   128,
      -1,   130,   131,    -1,    -1,    -1,    -1,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   128,    -1,   130,   131,    -1,
      -1,    -1,   151,   136,   137,    -1,    -1,    -1,   128,    -1,
     130,   131,   128,    -1,   130,   131,   136,   137,   151,    -1,
     136,   137,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,   151,    91,    92,    93,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,   130,   131,    -1,    -1,    -1,    -1,   136,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    66,    68,   119,   156,   157,   158,   161,   175,   177,
     178,   191,   198,   151,   197,    38,   192,   194,    66,     0,
     158,    70,    71,   176,   192,   195,   197,     6,   179,   182,
     183,   186,   187,   197,   197,   192,    10,   202,   196,   145,
     167,   186,   197,   180,   181,     4,   184,   185,     6,    38,
     162,   213,   192,     6,   167,   186,   190,   199,   200,   260,
       5,   193,     7,     4,   197,    37,   163,   164,   166,   197,
     146,   167,   216,    18,   160,   202,   167,   199,    18,     4,
      20,   188,   189,    11,   161,   199,   261,   195,    39,   183,
     162,   165,   188,     7,    18,    37,   214,   215,   167,    10,
      20,   159,   168,   169,   201,   167,   190,     6,     8,    81,
      83,    91,    92,    93,   128,   130,   131,   136,   137,   151,
     197,   221,   241,   242,   244,   245,   251,   253,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
      19,   160,     5,   167,     5,   193,     6,    87,    88,    89,
     172,   173,   174,   175,   197,   204,   205,   206,   208,   209,
     210,   211,   217,   218,   221,   249,   262,   262,     5,   193,
     188,   262,     9,   262,     6,     6,    10,   254,   262,     4,
       6,     4,     6,    15,    14,    43,    44,    46,    47,   275,
      38,    39,    40,    41,   274,    58,    96,    28,   149,   150,
     146,   147,   148,   219,   220,   159,   163,   216,    39,     6,
     204,     6,   169,   174,   250,     6,    11,   171,    19,   170,
      21,    22,    23,    24,    25,   203,    12,    13,    17,   149,
     150,   207,   221,   170,   262,    20,     8,   212,   213,   229,
     170,   170,    19,   199,     7,    19,     7,     5,     9,   227,
     228,   262,    70,   262,   252,    10,   151,   246,   262,   151,
     246,   264,   265,   266,   267,   269,   268,   270,   271,   271,
     221,   221,   221,     4,     6,    12,    13,    17,    37,   222,
     224,   225,   226,   229,   230,   235,   204,     7,   199,   200,
     247,    89,   262,   170,    17,   262,     9,     5,     9,     7,
     199,     7,    11,    82,    96,   257,   258,   259,   262,   252,
       5,     7,     7,   197,   233,   234,   236,   237,   240,    17,
       4,    66,   197,   223,   241,     7,    96,     6,     7,   174,
     227,     9,   262,   243,   250,    20,    26,   262,   255,   256,
      11,   262,   170,   170,    20,     7,   146,   238,   239,   231,
     232,   262,   262,     5,   248,   250,     5,   193,    82,   262,
     250,     5,    26,   262,     5,   193,     7,     7,     9,   250,
       7,    19,    26,   258,   250,   240,   250,   250
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   155,   156,   157,   157,   158,   159,   159,   160,   160,
     161,   161,   162,   163,   164,   165,   165,   166,   166,   166,
     167,   167,   168,   168,   169,   170,   170,   171,   171,   172,
     172,   173,   174,   174,   174,   174,   175,   175,   175,   176,
     176,   177,   178,   177,   179,   180,   181,   180,   182,   183,
     183,   184,   185,   184,   186,   187,   187,   188,   189,   188,
     190,   190,   191,   191,   191,   192,   192,   193,   193,   194,
     195,   196,   196,   197,   198,   198,   199,   199,   200,   201,
     201,   202,   203,   203,   203,   203,   203,   204,   204,   205,
     206,   205,   207,   207,   207,   207,   207,   208,   209,   210,
     211,   211,   212,   212,   213,   214,   215,   214,   216,   216,
     216,   217,   217,   217,   218,   219,   220,   219,   221,   222,
     222,   222,   222,   223,   223,   223,   224,   225,   225,   226,
     226,   226,   227,   228,   227,   229,   230,   231,   232,   231,
     233,   234,   233,   235,   236,   237,   236,   238,   239,   238,
     240,   241,   242,   243,   243,   244,   244,   245,   245,   246,
     246,   246,   247,   247,   248,   248,   249,   249,   249,   250,
     250,   251,   251,   251,   251,   252,   252,   253,   253,   254,
     254,   255,   256,   255,   257,   257,   257,   257,   258,   258,
     259,   260,   260,   261,   261,   262,   263,   263,   264,   264,
     265,   265,   266,   266,   267,   267,   268,   268,   269,   269,
     270,   270,   270,   271,   271,   271,   271,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   273,
     273,   273,   273,   273,   274,   274,   274,   274,   275,   275,
     275,   275
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     2,     0,
       8,     6,     3,     2,     3,     3,     0,     3,     2,     0,
       1,     1,     1,     3,     3,     1,     0,     3,     0,     2,
       0,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     0,     1,     3,     3,     0,     1,     2,     2,
       1,     2,     0,     1,     2,     1,     1,     2,     0,     1,
       1,     1,     8,     6,     5,     1,     0,     1,     0,     5,
       1,     3,     0,     1,     5,     4,     3,     1,     5,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     1,     1,     1,     1,     1,     2,     2,     3,     2,
       2,     2,     1,     1,     5,     3,     0,     1,     1,     2,
       1,     2,     1,     1,     3,     2,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       1,     2,     3,     0,     1,     5,     1,     3,     0,     1,
       3,     0,     1,     3,     2,     0,     1,     1,     0,     1,
       3,     3,     5,     3,     1,     5,     5,     3,     3,     1,
       3,     0,     1,     1,     1,     1,     5,     7,     6,     1,
       1,     2,     1,     1,     1,     2,     0,     5,     4,     3,
       6,     3,     0,     1,     4,     5,     4,     3,     1,     1,
       2,     0,     2,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     3,     4,     5,     1,     1,     1,     1,     1,     1,
       1,     1
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
                    {root = (yyvsp[0].treeptr);}
#line 1757 "k0gram.tab.c"
    break;

  case 3: /* topLevelObjects: topLevelObject  */
#line 57 "k0gram.y"
                   {(yyval.treeptr) = alctree(1001, "topLevelObjects", 1, (yyvsp[0].treeptr));}
#line 1763 "k0gram.tab.c"
    break;

  case 4: /* topLevelObjects: topLevelObjects topLevelObject  */
#line 58 "k0gram.y"
                                   {(yyval.treeptr) = alctree(1001, "topLevelObjects", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1769 "k0gram.tab.c"
    break;

  case 5: /* topLevelObject: declaration  */
#line 62 "k0gram.y"
                {(yyval.treeptr) = alctree(1002, "topLevelObject", 1, (yyvsp[0].treeptr));}
#line 1775 "k0gram.tab.c"
    break;

  case 6: /* opt_functionBody: functionBody  */
#line 66 "k0gram.y"
                 {(yyval.treeptr) = alctree(1003, "opt_functionBody", 1, (yyvsp[0].treeptr));}
#line 1781 "k0gram.tab.c"
    break;

  case 7: /* opt_functionBody: %empty  */
#line 67 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1787 "k0gram.tab.c"
    break;

  case 8: /* opt_colon_type: COLON type  */
#line 71 "k0gram.y"
             {(yyval.treeptr) = alctree(1003, "opt_colon_type", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1793 "k0gram.tab.c"
    break;

  case 9: /* opt_colon_type: %empty  */
#line 72 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1799 "k0gram.tab.c"
    break;

  case 10: /* functionDeclaration: FUN opt_typeParameters nullableType DOT simpleIdentifier functionValueParameters opt_colon_type opt_functionBody  */
#line 77 "k0gram.y"
                                                                                                                     {(yyval.treeptr) = alctree(1004, "functionDeclaration", 8, (yyvsp[-7].treeptr), (yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1805 "k0gram.tab.c"
    break;

  case 11: /* functionDeclaration: FUN opt_typeParameters simpleIdentifier functionValueParameters opt_colon_type opt_functionBody  */
#line 78 "k0gram.y"
                                                                                                      {(yyval.treeptr) = alctree(1004, "functionDeclaration",6, (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1811 "k0gram.tab.c"
    break;

  case 12: /* functionValueParameters: LPAREN opt_functionValueParameter RPAREN  */
#line 83 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1005, "functionValueParameters", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1817 "k0gram.tab.c"
    break;

  case 13: /* functionValueParameter: parameter opt_eq_exp  */
#line 87 "k0gram.y"
                       {(yyval.treeptr) = alctree(1006, "functionValueParameter", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1823 "k0gram.tab.c"
    break;

  case 14: /* parameter: simpleIdentifier COLON type  */
#line 91 "k0gram.y"
                              {(yyval.treeptr) = alctree(1007, "parameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1829 "k0gram.tab.c"
    break;

  case 15: /* multi_comma_functionParameter: multi_comma_functionParameter COMMA functionValueParameter  */
#line 95 "k0gram.y"
                                                             {(yyval.treeptr) = alctree(1008, "multi_comma_functionParameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1835 "k0gram.tab.c"
    break;

  case 16: /* multi_comma_functionParameter: %empty  */
#line 96 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1841 "k0gram.tab.c"
    break;

  case 17: /* opt_functionValueParameter: functionValueParameter multi_comma_functionParameter COMMA  */
#line 100 "k0gram.y"
                                                             {(yyval.treeptr) = alctree(1009, "opt_functionValueParameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1847 "k0gram.tab.c"
    break;

  case 18: /* opt_functionValueParameter: functionValueParameter multi_comma_functionParameter  */
#line 101 "k0gram.y"
                                                         {(yyval.treeptr) = alctree(1009, "opt_functionValueParameter", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1853 "k0gram.tab.c"
    break;

  case 19: /* opt_functionValueParameter: %empty  */
#line 102 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1859 "k0gram.tab.c"
    break;

  case 20: /* type: nullableType  */
#line 107 "k0gram.y"
               {(yyval.treeptr) = alctree(1010, "type", 1, (yyvsp[0].treeptr));}
#line 1865 "k0gram.tab.c"
    break;

  case 21: /* type: TYPELITERAL  */
#line 108 "k0gram.y"
               {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1871 "k0gram.tab.c"
    break;

  case 22: /* functionBody: block  */
#line 113 "k0gram.y"
          {(yyval.treeptr) = alctree(1011, "functionBody", 1, (yyvsp[0].treeptr));}
#line 1877 "k0gram.tab.c"
    break;

  case 23: /* functionBody: ASSIGNMENT expression SEMICOLON  */
#line 114 "k0gram.y"
                                    {(yyval.treeptr) = alctree(1011, "functionBody", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1883 "k0gram.tab.c"
    break;

  case 24: /* block: LCURL statements RCURL  */
#line 119 "k0gram.y"
                            {(yyval.treeptr) = alctree(1012, "block", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));  }
#line 1889 "k0gram.tab.c"
    break;

  case 26: /* semis: %empty  */
#line 125 "k0gram.y"
    {(yyval.treeptr) = NULL;}
#line 1895 "k0gram.tab.c"
    break;

  case 27: /* semis_statement: semis_statement semis statement  */
#line 129 "k0gram.y"
                                  {(yyval.treeptr) = alctree(1013, "semis_statement", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1901 "k0gram.tab.c"
    break;

  case 28: /* semis_statement: %empty  */
#line 130 "k0gram.y"
           {(yyval.treeptr) = NULL;}
#line 1907 "k0gram.tab.c"
    break;

  case 29: /* optional_statement_sequence: statement semis_statement  */
#line 135 "k0gram.y"
                                {(yyval.treeptr) = alctree(1014, "optional_statement_sequence", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1913 "k0gram.tab.c"
    break;

  case 30: /* optional_statement_sequence: %empty  */
#line 136 "k0gram.y"
            {(yyval.treeptr) = NULL;}
#line 1919 "k0gram.tab.c"
    break;

  case 31: /* statements: optional_statement_sequence  */
#line 140 "k0gram.y"
                               {(yyval.treeptr) = alctree(1015, "statements", 1, (yyvsp[0].treeptr));}
#line 1925 "k0gram.tab.c"
    break;

  case 32: /* statement: declaration semis  */
#line 146 "k0gram.y"
                     {(yyval.treeptr) = alctree(1016, "statement", 2,(yyvsp[-1].treeptr),(yyvsp[0].treeptr)); }
#line 1931 "k0gram.tab.c"
    break;

  case 33: /* statement: assignment semis  */
#line 147 "k0gram.y"
                      {(yyval.treeptr) = alctree(1016, "statement", 2,(yyvsp[-1].treeptr),(yyvsp[0].treeptr)); }
#line 1937 "k0gram.tab.c"
    break;

  case 34: /* statement: expression semis  */
#line 148 "k0gram.y"
                      {(yyval.treeptr) = alctree(1016, "statement", 2,(yyvsp[-1].treeptr),(yyvsp[0].treeptr)); }
#line 1943 "k0gram.tab.c"
    break;

  case 35: /* statement: loopStatement semis  */
#line 149 "k0gram.y"
                       {(yyval.treeptr) = alctree(1016, "statement", 2,(yyvsp[-1].treeptr),(yyvsp[0].treeptr)); }
#line 1949 "k0gram.tab.c"
    break;

  case 36: /* declaration: classDeclaration  */
#line 153 "k0gram.y"
                   {(yyval.treeptr) = alctree(1017, "declaration", 1, (yyvsp[0].treeptr));}
#line 1955 "k0gram.tab.c"
    break;

  case 37: /* declaration: functionDeclaration  */
#line 154 "k0gram.y"
                       {(yyval.treeptr) = alctree(1017, "declaration", 1, (yyvsp[0].treeptr));}
#line 1961 "k0gram.tab.c"
    break;

  case 38: /* declaration: propertyDeclaration  */
#line 155 "k0gram.y"
                        {(yyval.treeptr) = alctree(1017, "declaration", 1, (yyvsp[0].treeptr));}
#line 1967 "k0gram.tab.c"
    break;

  case 39: /* val_var: VAR  */
#line 159 "k0gram.y"
      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1973 "k0gram.tab.c"
    break;

  case 40: /* val_var: VAL  */
#line 160 "k0gram.y"
        {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1979 "k0gram.tab.c"
    break;

  case 41: /* opt_modifier: CONST  */
#line 164 "k0gram.y"
        {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1985 "k0gram.tab.c"
    break;

  case 42: /* $@1: %empty  */
#line 165 "k0gram.y"
    { /* epsilon production */ }
#line 1991 "k0gram.tab.c"
    break;

  case 43: /* opt_modifier: $@1  */
#line 165 "k0gram.y"
                                 {(yyval.treeptr) = NULL;}
#line 1997 "k0gram.tab.c"
    break;

  case 44: /* parenthesizedType: LPAREN type RPAREN  */
#line 170 "k0gram.y"
                     {(yyval.treeptr) = alctree(1019, "parenthesizedType", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2003 "k0gram.tab.c"
    break;

  case 45: /* multi_dot_simpleUserType: multi_dot_simpleUserType DOT simpleUserType  */
#line 176 "k0gram.y"
                                              {(yyval.treeptr) = alctree(1020, "multi_dot_simpleUserType", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2009 "k0gram.tab.c"
    break;

  case 46: /* $@2: %empty  */
#line 177 "k0gram.y"
    { /* epsilon production */ }
#line 2015 "k0gram.tab.c"
    break;

  case 47: /* multi_dot_simpleUserType: $@2  */
#line 177 "k0gram.y"
                                 {(yyval.treeptr) = NULL;}
#line 2021 "k0gram.tab.c"
    break;

  case 48: /* userType: simpleUserType multi_dot_simpleUserType  */
#line 181 "k0gram.y"
                                          {(yyval.treeptr) = alctree(1021, "userType", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2027 "k0gram.tab.c"
    break;

  case 49: /* simpleUserType: simpleIdentifier typeArguments  */
#line 186 "k0gram.y"
                                {(yyval.treeptr) = alctree(1022, "simpleUserType", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2033 "k0gram.tab.c"
    break;

  case 50: /* simpleUserType: simpleIdentifier  */
#line 187 "k0gram.y"
                    {(yyval.treeptr) = alctree(1022, "simpleUserType", 1, (yyvsp[0].treeptr));}
#line 2039 "k0gram.tab.c"
    break;

  case 51: /* multi_quest: multi_quest QUEST_NO_WS  */
#line 192 "k0gram.y"
                          {(yyval.treeptr) = alctree(1023, "multi_quest", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2045 "k0gram.tab.c"
    break;

  case 52: /* $@3: %empty  */
#line 193 "k0gram.y"
    { /* epsilon production */ }
#line 2051 "k0gram.tab.c"
    break;

  case 53: /* multi_quest: $@3  */
#line 193 "k0gram.y"
                                 {(yyval.treeptr) = NULL;}
#line 2057 "k0gram.tab.c"
    break;

  case 54: /* nullableType: typeRef_parenthesizedType multi_quest  */
#line 196 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1024, "nullableType", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2063 "k0gram.tab.c"
    break;

  case 55: /* typeRef_parenthesizedType: parenthesizedType  */
#line 200 "k0gram.y"
                    {(yyval.treeptr) = alctree(1025, "typeRef_parenthesizedType", 1, (yyvsp[0].treeptr));}
#line 2069 "k0gram.tab.c"
    break;

  case 56: /* typeRef_parenthesizedType: userType  */
#line 201 "k0gram.y"
              {(yyval.treeptr) = alctree(1025, "typeRef_parenthesizedType", 1, (yyvsp[0].treeptr));}
#line 2075 "k0gram.tab.c"
    break;

  case 57: /* opt_eq_exp: ASSIGNMENT expression  */
#line 206 "k0gram.y"
                        {(yyval.treeptr) = alctree(1026, "opt_eq_exp", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2081 "k0gram.tab.c"
    break;

  case 58: /* $@4: %empty  */
#line 207 "k0gram.y"
    { /* epsilon production */ }
#line 2087 "k0gram.tab.c"
    break;

  case 59: /* opt_eq_exp: $@4  */
#line 207 "k0gram.y"
                                 {(yyval.treeptr) = NULL;}
#line 2093 "k0gram.tab.c"
    break;

  case 60: /* multivariable_variableDeclaration: variableDeclaration  */
#line 212 "k0gram.y"
                      {(yyval.treeptr) = alctree(1027, "multivariable_variableDeclaration", 1, (yyvsp[0].treeptr));}
#line 2099 "k0gram.tab.c"
    break;

  case 61: /* multivariable_variableDeclaration: multiVariableDeclaration  */
#line 213 "k0gram.y"
                             {(yyval.treeptr) = alctree(1027, "multivariable_variableDeclaration", 1, (yyvsp[0].treeptr));}
#line 2105 "k0gram.tab.c"
    break;

  case 62: /* propertyDeclaration: opt_modifier val_var opt_typeParameters nullableType DOT multivariable_variableDeclaration opt_eq_exp SEMICOLON  */
#line 217 "k0gram.y"
                                                                                                                    {(yyval.treeptr) = alctree(10028, "propertyDeclaration", 8, (yyvsp[-7].treeptr), (yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2111 "k0gram.tab.c"
    break;

  case 63: /* propertyDeclaration: opt_modifier val_var opt_typeParameters multivariable_variableDeclaration opt_eq_exp SEMICOLON  */
#line 218 "k0gram.y"
                                                                                                   {(yyval.treeptr) = alctree(1028, "propertyDeclaration", 6, (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2117 "k0gram.tab.c"
    break;

  case 64: /* propertyDeclaration: opt_modifier val_var opt_typeParameters multivariable_variableDeclaration opt_eq_exp  */
#line 219 "k0gram.y"
                                                                                         {(yyval.treeptr) = alctree(1028, "propertyDeclaration", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr) );}
#line 2123 "k0gram.tab.c"
    break;

  case 65: /* opt_typeParameters: typeParameters  */
#line 224 "k0gram.y"
                    {(yyval.treeptr) = alctree(1029, "opt_typeParameters", 1, (yyvsp[0].treeptr));}
#line 2129 "k0gram.tab.c"
    break;

  case 66: /* opt_typeParameters: %empty  */
#line 225 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 2135 "k0gram.tab.c"
    break;

  case 67: /* opt_comma: COMMA  */
#line 229 "k0gram.y"
          {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2141 "k0gram.tab.c"
    break;

  case 68: /* opt_comma: %empty  */
#line 230 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 2147 "k0gram.tab.c"
    break;

  case 69: /* typeParameters: LANGLE typeParameter multi_typeParameter opt_comma RANGLE  */
#line 233 "k0gram.y"
                                                              {(yyval.treeptr) = alctree(1030, "typeParameters", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2153 "k0gram.tab.c"
    break;

  case 70: /* typeParameter: simpleIdentifier  */
#line 237 "k0gram.y"
                      {(yyval.treeptr) = alctree(1031, "typeParameter", 1, (yyvsp[0].treeptr));}
#line 2159 "k0gram.tab.c"
    break;

  case 71: /* multi_typeParameter: multi_typeParameter COMMA typeParameter  */
#line 242 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1032, "multi_typeParameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2165 "k0gram.tab.c"
    break;

  case 72: /* multi_typeParameter: %empty  */
#line 243 "k0gram.y"
                 {(yyval.treeptr) = NULL;}
#line 2171 "k0gram.tab.c"
    break;

  case 74: /* classDeclaration: CONST CLASS simpleIdentifier opt_typeParameters classBody  */
#line 251 "k0gram.y"
                                                               {  (yyval.treeptr) = alctree(1033, "classDeclaration", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2177 "k0gram.tab.c"
    break;

  case 75: /* classDeclaration: CLASS simpleIdentifier opt_typeParameters classBody  */
#line 252 "k0gram.y"
                                                          {(yyval.treeptr) = alctree(1033, "classDeclaration", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2183 "k0gram.tab.c"
    break;

  case 76: /* variableDeclaration: type COLON type  */
#line 256 "k0gram.y"
                     {(yyval.treeptr) = alctree(1034, "variableDeclaration", 3, (yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr) );}
#line 2189 "k0gram.tab.c"
    break;

  case 77: /* variableDeclaration: type  */
#line 257 "k0gram.y"
          {(yyval.treeptr) = alctree(1034, "impvariableDeclaration", 1, (yyvsp[0].treeptr));}
#line 2195 "k0gram.tab.c"
    break;

  case 78: /* multiVariableDeclaration: LPAREN variableDeclaration multi_comma_variableDeclaration opt_comma RPAREN  */
#line 261 "k0gram.y"
                                                                               {(yyval.treeptr) = alctree(1035, "multiVariableDeclaration", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2201 "k0gram.tab.c"
    break;

  case 79: /* multi_comma_variableDeclaration: multi_comma_variableDeclaration COMMA variableDeclaration  */
#line 264 "k0gram.y"
                                                             {(yyval.treeptr) = alctree(1036, "multi_comma_variableDeclaration", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2207 "k0gram.tab.c"
    break;

  case 80: /* multi_comma_variableDeclaration: %empty  */
#line 265 "k0gram.y"
    { /* epsilon production */ }
#line 2213 "k0gram.tab.c"
    break;

  case 81: /* classBody: LCURL classMembers RCURL  */
#line 271 "k0gram.y"
                              {(yyval.treeptr) = alctree(1037, "classBody", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2219 "k0gram.tab.c"
    break;

  case 82: /* assignmentAndOperator: ADD_ASSIGNMENT  */
#line 276 "k0gram.y"
                    {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2225 "k0gram.tab.c"
    break;

  case 83: /* assignmentAndOperator: SUB_ASSIGNMENT  */
#line 277 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2231 "k0gram.tab.c"
    break;

  case 84: /* assignmentAndOperator: MULT_ASSIGNMENT  */
#line 278 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2237 "k0gram.tab.c"
    break;

  case 85: /* assignmentAndOperator: DIV_ASSIGNMENT  */
#line 279 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2243 "k0gram.tab.c"
    break;

  case 86: /* assignmentAndOperator: MOD_ASSIGNMENT  */
#line 280 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2249 "k0gram.tab.c"
    break;

  case 87: /* assignableExpression: prefixUnaryExpression  */
#line 284 "k0gram.y"
                        {(yyval.treeptr) = alctree (1038, "assignableExpression", 1, (yyvsp[0].treeptr));}
#line 2255 "k0gram.tab.c"
    break;

  case 88: /* assignableExpression: parenthesizedAssignableExpression  */
#line 285 "k0gram.y"
                                      {(yyval.treeptr) = alctree (1038, "assignableExpression", 1, (yyvsp[0].treeptr));}
#line 2261 "k0gram.tab.c"
    break;

  case 89: /* multi_unaryPrefix: multi_unaryPrefix prefixUnaryOperator  */
#line 288 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1039, "multi_unaryPrefix", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2267 "k0gram.tab.c"
    break;

  case 90: /* $@5: %empty  */
#line 289 "k0gram.y"
    { /* epsilon production */ }
#line 2273 "k0gram.tab.c"
    break;

  case 91: /* multi_unaryPrefix: $@5  */
#line 289 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2279 "k0gram.tab.c"
    break;

  case 92: /* prefixUnaryOperator: ADD  */
#line 292 "k0gram.y"
         {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2285 "k0gram.tab.c"
    break;

  case 93: /* prefixUnaryOperator: SUB  */
#line 293 "k0gram.y"
           {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2291 "k0gram.tab.c"
    break;

  case 94: /* prefixUnaryOperator: INCR  */
#line 294 "k0gram.y"
            {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2297 "k0gram.tab.c"
    break;

  case 95: /* prefixUnaryOperator: DECR  */
#line 295 "k0gram.y"
            {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2303 "k0gram.tab.c"
    break;

  case 96: /* prefixUnaryOperator: EXCL_NO_WS EXCL_NO_WS  */
#line 296 "k0gram.y"
                           { (yyval.treeptr) = alctree(1040, "prefixUnaryOperator", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2309 "k0gram.tab.c"
    break;

  case 97: /* prefixUnaryExpression: multi_unaryPrefix postfixUnaryExpression  */
#line 301 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1041, "prefixUnaryExpression", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2315 "k0gram.tab.c"
    break;

  case 98: /* parenthesizedAssignableExpression: LPAREN assignableExpression RPAREN  */
#line 305 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1042, "parenthesizedAssignableExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2321 "k0gram.tab.c"
    break;

  case 99: /* assignment: directly_assign expression  */
#line 309 "k0gram.y"
                              {(yyval.treeptr) = alctree(1043, "assignment", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2327 "k0gram.tab.c"
    break;

  case 100: /* directly_assign: directlyAssignableExpression ASSIGNMENT  */
#line 313 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1044, "directly_assign", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2333 "k0gram.tab.c"
    break;

  case 101: /* directly_assign: assignableExpression assignmentAndOperator  */
#line 314 "k0gram.y"
                                                  {(yyval.treeptr) = alctree(1044, "directly_assign", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2339 "k0gram.tab.c"
    break;

  case 102: /* assignableSuffix: indexingSuffix  */
#line 318 "k0gram.y"
                    {(yyval.treeptr) = alctree(1045, "assignableSuffix", 1, (yyvsp[0].treeptr));}
#line 2345 "k0gram.tab.c"
    break;

  case 103: /* assignableSuffix: typeArguments  */
#line 319 "k0gram.y"
                    {(yyval.treeptr) = alctree(1045, "assignableSuffix", 1, (yyvsp[0].treeptr));}
#line 2351 "k0gram.tab.c"
    break;

  case 104: /* typeArguments: LANGLE typeProjection multi_comma_typeProjection opt_comma RANGLE  */
#line 323 "k0gram.y"
                                                                       {(yyval.treeptr) = alctree(1046, "typeArguments", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2357 "k0gram.tab.c"
    break;

  case 105: /* multi_comma_typeProjection: multi_comma_typeProjection COMMA typeProjection  */
#line 327 "k0gram.y"
                                                  {(yyval.treeptr) = alctree(1047, "multi_comma_typeProjection", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2363 "k0gram.tab.c"
    break;

  case 106: /* $@6: %empty  */
#line 328 "k0gram.y"
    { /* epsilon production */ }
#line 2369 "k0gram.tab.c"
    break;

  case 107: /* multi_comma_typeProjection: $@6  */
#line 328 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2375 "k0gram.tab.c"
    break;

  case 108: /* typeProjection: type  */
#line 333 "k0gram.y"
        {(yyval.treeptr) = alctree(1048, "typeProjection", 1, (yyvsp[0].treeptr));}
#line 2381 "k0gram.tab.c"
    break;

  case 109: /* typeProjection: type QUEST_NO_WS  */
#line 334 "k0gram.y"
                     {(yyval.treeptr) = alctree(1048, "nullable", 1, (yyvsp[-1].treeptr));}
#line 2387 "k0gram.tab.c"
    break;

  case 110: /* typeProjection: MULT  */
#line 335 "k0gram.y"
          {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2393 "k0gram.tab.c"
    break;

  case 111: /* directlyAssignableExpression: postfixUnaryExpression assignableSuffix  */
#line 338 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1049, "directlyAssignableExpression", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2399 "k0gram.tab.c"
    break;

  case 112: /* directlyAssignableExpression: simpleIdentifier  */
#line 339 "k0gram.y"
                        {(yyval.treeptr) = alctree(1049, "directlyAssignableExpression", 1, (yyvsp[0].treeptr));}
#line 2405 "k0gram.tab.c"
    break;

  case 113: /* directlyAssignableExpression: parenthesizedDirectlyAssignableExpression  */
#line 340 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1049, "directlyAssignableExpression", 1, (yyvsp[0].treeptr));}
#line 2411 "k0gram.tab.c"
    break;

  case 114: /* parenthesizedDirectlyAssignableExpression: LPAREN assignableExpression RPAREN  */
#line 344 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1050, "parenthesizedDirectlyAssignableExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2417 "k0gram.tab.c"
    break;

  case 115: /* multi_postfixUnarySuffix: multi_postfixUnarySuffix postfixUnarySuffix  */
#line 348 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1051, "multi_postfixUnarySuffix", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2423 "k0gram.tab.c"
    break;

  case 116: /* $@7: %empty  */
#line 349 "k0gram.y"
      { /* epsilon production */ }
#line 2429 "k0gram.tab.c"
    break;

  case 117: /* multi_postfixUnarySuffix: $@7  */
#line 349 "k0gram.y"
                                    {(yyval.treeptr) = NULL;}
#line 2435 "k0gram.tab.c"
    break;

  case 118: /* postfixUnaryExpression: primaryExpression multi_postfixUnarySuffix  */
#line 352 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1052, "postfixUnaryExpression", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2441 "k0gram.tab.c"
    break;

  case 119: /* postfixUnarySuffix: postfixUnaryOperator  */
#line 356 "k0gram.y"
                        {(yyval.treeptr) = alctree(1053, "postfixUnarySuffix", 1, (yyvsp[0].treeptr));}
#line 2447 "k0gram.tab.c"
    break;

  case 120: /* postfixUnarySuffix: indexingSuffix  */
#line 357 "k0gram.y"
                    {(yyval.treeptr) = alctree(1053, "postfixUnarySuffix", 1, (yyvsp[0].treeptr));}
#line 2453 "k0gram.tab.c"
    break;

  case 121: /* postfixUnarySuffix: callSuffix  */
#line 358 "k0gram.y"
               {(yyval.treeptr) = alctree(1053, "postfixUnarySuffix", 1, (yyvsp[0].treeptr));}
#line 2459 "k0gram.tab.c"
    break;

  case 122: /* postfixUnarySuffix: navigationSuffix  */
#line 359 "k0gram.y"
                    {(yyval.treeptr) = alctree(1053, "postfixUnarySuffix", 1, (yyvsp[0].treeptr));}
#line 2465 "k0gram.tab.c"
    break;

  case 123: /* identifier_expression_class: simpleIdentifier  */
#line 363 "k0gram.y"
                   {(yyval.treeptr) = alctree(1054, "identifier_expression_class", 1, (yyvsp[0].treeptr));}
#line 2471 "k0gram.tab.c"
    break;

  case 124: /* identifier_expression_class: parenthesizedExpression  */
#line 364 "k0gram.y"
                             {(yyval.treeptr) = alctree(1054, "identifier_expression_class", 1, (yyvsp[0].treeptr));}
#line 2477 "k0gram.tab.c"
    break;

  case 125: /* identifier_expression_class: CLASS  */
#line 365 "k0gram.y"
          {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2483 "k0gram.tab.c"
    break;

  case 126: /* navigationSuffix: memberAccessOperator identifier_expression_class  */
#line 369 "k0gram.y"
                                                   {(yyval.treeptr) = alctree(1055, "navigationSuffix", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2489 "k0gram.tab.c"
    break;

  case 127: /* memberAccessOperator: DOT  */
#line 373 "k0gram.y"
      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2495 "k0gram.tab.c"
    break;

  case 128: /* memberAccessOperator: QUEST_NO_WS DOT  */
#line 374 "k0gram.y"
                    {(yyval.treeptr) = alctree(1056, "memberAccessOperator", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2501 "k0gram.tab.c"
    break;

  case 129: /* postfixUnaryOperator: INCR  */
#line 378 "k0gram.y"
          { (yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2507 "k0gram.tab.c"
    break;

  case 130: /* postfixUnaryOperator: DECR  */
#line 379 "k0gram.y"
            { (yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2513 "k0gram.tab.c"
    break;

  case 131: /* postfixUnaryOperator: EXCL_NO_WS EXCL_NO_WS  */
#line 380 "k0gram.y"
                            { (yyval.treeptr) = alctree(1057, "postfixUnaryOperator", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2519 "k0gram.tab.c"
    break;

  case 132: /* multi_comma_expression: multi_comma_expression COMMA expression  */
#line 384 "k0gram.y"
                                          {(yyval.treeptr) = alctree(1058, "multi_comma_expression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2525 "k0gram.tab.c"
    break;

  case 133: /* $@8: %empty  */
#line 385 "k0gram.y"
    { /* epsilon production */ }
#line 2531 "k0gram.tab.c"
    break;

  case 134: /* multi_comma_expression: $@8  */
#line 385 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2537 "k0gram.tab.c"
    break;

  case 135: /* indexingSuffix: LSQUARE expression multi_comma_expression opt_comma RSQUARE  */
#line 389 "k0gram.y"
                                                                {(yyval.treeptr) = alctree(1059, "indexingSuffix", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2543 "k0gram.tab.c"
    break;

  case 136: /* callSuffix: valueArguments  */
#line 393 "k0gram.y"
                  {(yyval.treeptr) = alctree(1060, "callSuffix", 1, (yyvsp[0].treeptr));}
#line 2549 "k0gram.tab.c"
    break;

  case 137: /* multi_comma_valueArgument: multi_comma_valueArgument COMMA valueArgument  */
#line 397 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1061, "multi_comma_valueArgument", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2555 "k0gram.tab.c"
    break;

  case 138: /* $@9: %empty  */
#line 398 "k0gram.y"
    { /* epsilon production */ }
#line 2561 "k0gram.tab.c"
    break;

  case 139: /* multi_comma_valueArgument: $@9  */
#line 398 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2567 "k0gram.tab.c"
    break;

  case 140: /* opt_valueArgument: valueArgument multi_comma_valueArgument opt_comma  */
#line 401 "k0gram.y"
                                                    {(yyval.treeptr) = alctree(1062, "opt_valueArgument", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2573 "k0gram.tab.c"
    break;

  case 141: /* $@10: %empty  */
#line 402 "k0gram.y"
    { /* epsilon production */ }
#line 2579 "k0gram.tab.c"
    break;

  case 142: /* opt_valueArgument: $@10  */
#line 402 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2585 "k0gram.tab.c"
    break;

  case 143: /* valueArguments: LPAREN opt_valueArgument RPAREN  */
#line 406 "k0gram.y"
                                    {(yyval.treeptr) = alctree(1063, "valueArguments", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2591 "k0gram.tab.c"
    break;

  case 144: /* opt_simpleIdentifier_EQ: simpleIdentifier ASSIGNMENT  */
#line 410 "k0gram.y"
                                {(yyval.treeptr) = alctree(1064, "opt_simpleIdentifier_EQ", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2597 "k0gram.tab.c"
    break;

  case 145: /* $@11: %empty  */
#line 411 "k0gram.y"
      { /* epsilon production */ }
#line 2603 "k0gram.tab.c"
    break;

  case 146: /* opt_simpleIdentifier_EQ: $@11  */
#line 411 "k0gram.y"
                                    {(yyval.treeptr) = NULL;}
#line 2609 "k0gram.tab.c"
    break;

  case 147: /* opt_Multi: MULT  */
#line 415 "k0gram.y"
        {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2615 "k0gram.tab.c"
    break;

  case 148: /* $@12: %empty  */
#line 416 "k0gram.y"
    { /* epsilon production */ }
#line 2621 "k0gram.tab.c"
    break;

  case 149: /* opt_Multi: $@12  */
#line 416 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2627 "k0gram.tab.c"
    break;

  case 150: /* valueArgument: opt_simpleIdentifier_EQ opt_Multi expression  */
#line 420 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1065, "valueArgument", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2633 "k0gram.tab.c"
    break;

  case 151: /* parenthesizedExpression: LPAREN expression RPAREN  */
#line 424 "k0gram.y"
                              {(yyval.treeptr) = alctree(1066, "parenthesizedExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2639 "k0gram.tab.c"
    break;

  case 152: /* ifExpression: IF LPAREN expression RPAREN controls  */
#line 430 "k0gram.y"
                                       {(yyval.treeptr) = alctree(1011,"ifExpression",5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2645 "k0gram.tab.c"
    break;

  case 153: /* controls: controlStructureBody ELSE controlStructureBody  */
#line 434 "k0gram.y"
                                                 {(yyval.treeptr) = alctree(1012,"controls",3,(yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2651 "k0gram.tab.c"
    break;

  case 154: /* controls: controlStructureBody  */
#line 435 "k0gram.y"
                         {(yyval.treeptr) = alctree(1012,"controls",1,(yyvsp[0].treeptr));}
#line 2657 "k0gram.tab.c"
    break;

  case 155: /* functionCall: IDENTIFIER LPAREN functionArguments RPAREN semis  */
#line 440 "k0gram.y"
                                                       {(yyval.treeptr) = alctree(1068, "functionCall", 4, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),(yyvsp[-1].treeptr));}
#line 2663 "k0gram.tab.c"
    break;

  case 156: /* functionCall: dotExpression LPAREN functionArguments RPAREN semis  */
#line 441 "k0gram.y"
                                                          {(yyval.treeptr) = alctree(1068, "methodCall", 4, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr));}
#line 2669 "k0gram.tab.c"
    break;

  case 157: /* dotExpression: IDENTIFIER DOT IDENTIFIER  */
#line 445 "k0gram.y"
                              {(yyval.treeptr) = alctree(3000, "dotExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2675 "k0gram.tab.c"
    break;

  case 158: /* dotExpression: dotExpression DOT IDENTIFIER  */
#line 446 "k0gram.y"
                                   {(yyval.treeptr) = alctree(3000, "dotExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2681 "k0gram.tab.c"
    break;

  case 159: /* functionArguments: expression  */
#line 451 "k0gram.y"
              {(yyval.treeptr) = alctree(1069, "functionArguments", 1, (yyvsp[0].treeptr));}
#line 2687 "k0gram.tab.c"
    break;

  case 160: /* functionArguments: functionArguments COMMA expression  */
#line 452 "k0gram.y"
                                       {(yyval.treeptr) = alctree(1070, "functionArguments", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2693 "k0gram.tab.c"
    break;

  case 161: /* functionArguments: %empty  */
#line 453 "k0gram.y"
              {(yyval.treeptr) = NULL;}
#line 2699 "k0gram.tab.c"
    break;

  case 162: /* variable_multivariable: variableDeclaration  */
#line 457 "k0gram.y"
                     {(yyval.treeptr) = alctree(1071,"variable_multivariable", 1, (yyvsp[0].treeptr));}
#line 2705 "k0gram.tab.c"
    break;

  case 163: /* variable_multivariable: multiVariableDeclaration  */
#line 458 "k0gram.y"
                              {(yyval.treeptr) = alctree(1071,"variable_multivariable", 1, (yyvsp[0].treeptr));}
#line 2711 "k0gram.tab.c"
    break;

  case 164: /* control_structure_body_or_comma: controlStructureBody  */
#line 462 "k0gram.y"
                        {(yyval.treeptr) = alctree(1072,"control_structure_body_or_comma", 1, (yyvsp[0].treeptr));}
#line 2717 "k0gram.tab.c"
    break;

  case 165: /* control_structure_body_or_comma: COMMA  */
#line 463 "k0gram.y"
          {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 2723 "k0gram.tab.c"
    break;

  case 166: /* loopStatement: WHILE LPAREN expression RPAREN control_structure_body_or_comma  */
#line 467 "k0gram.y"
                                                                    {(yyval.treeptr) = alctree(1073,"loopStatement", 5 ,(yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2729 "k0gram.tab.c"
    break;

  case 167: /* loopStatement: FOR LPAREN variable_multivariable IN expression RPAREN controlStructureBody  */
#line 468 "k0gram.y"
                                                                                   {(yyval.treeptr) = alctree(1073,"loopStatement", 7 ,(yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr),(yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2735 "k0gram.tab.c"
    break;

  case 168: /* loopStatement: DO controlStructureBody WHILE LPAREN expression RPAREN  */
#line 469 "k0gram.y"
                                                              {(yyval.treeptr) = alctree(1073,"loopStatement", 6 ,(yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 2741 "k0gram.tab.c"
    break;

  case 169: /* controlStructureBody: block  */
#line 474 "k0gram.y"
         {(yyval.treeptr) = alctree(1074, "controlStructureBody", 1, (yyvsp[0].treeptr));}
#line 2747 "k0gram.tab.c"
    break;

  case 170: /* controlStructureBody: statement  */
#line 475 "k0gram.y"
              {(yyval.treeptr) = alctree(1074, "controlStructureBody", 1, (yyvsp[0].treeptr));}
#line 2753 "k0gram.tab.c"
    break;

  case 171: /* jumpExpression: RETURN expression  */
#line 480 "k0gram.y"
                    {(yyval.treeptr) = alctree(1075, "jumpExpression", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2759 "k0gram.tab.c"
    break;

  case 175: /* multi_whenEntry: multi_whenEntry whenEntry  */
#line 487 "k0gram.y"
                            {(yyval.treeptr) = alctree(1076, "multi_whenEntry", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2765 "k0gram.tab.c"
    break;

  case 176: /* multi_whenEntry: %empty  */
#line 488 "k0gram.y"
      {(yyval.treeptr) = NULL;}
#line 2771 "k0gram.tab.c"
    break;

  case 177: /* whenExpression: WHEN whenSubject LCURL multi_whenEntry RCURL  */
#line 492 "k0gram.y"
                                               {(yyval.treeptr) = alctree(1077, "whenExpression", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2777 "k0gram.tab.c"
    break;

  case 178: /* whenExpression: WHEN LCURL multi_whenEntry RCURL  */
#line 493 "k0gram.y"
                                     {(yyval.treeptr) = alctree(1078, "whenExpression", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2783 "k0gram.tab.c"
    break;

  case 179: /* whenSubject: LPAREN expression RPAREN  */
#line 497 "k0gram.y"
                           {(yyval.treeptr) = alctree(1079, "whenSubject", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2789 "k0gram.tab.c"
    break;

  case 180: /* whenSubject: LPAREN VAL variableDeclaration ASSIGNMENT expression RPAREN  */
#line 498 "k0gram.y"
                                                                 {(yyval.treeptr) = alctree(1079, "whenSubject", 6, (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2795 "k0gram.tab.c"
    break;

  case 181: /* multi_comma_whenCondition: multi_comma_whenCondition COMMA whenCondition  */
#line 501 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1080, "multi_comma_whenCondition", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2801 "k0gram.tab.c"
    break;

  case 182: /* $@13: %empty  */
#line 502 "k0gram.y"
    { /* epsilon production */ }
#line 2807 "k0gram.tab.c"
    break;

  case 183: /* multi_comma_whenCondition: $@13  */
#line 502 "k0gram.y"
                                  {(yyval.treeptr) = NULL;}
#line 2813 "k0gram.tab.c"
    break;

  case 184: /* whenEntry: whenCondition multi_comma_whenCondition ARROW controlStructureBody  */
#line 506 "k0gram.y"
                                                                      {(yyval.treeptr) = alctree(1011, "whenEntry", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2819 "k0gram.tab.c"
    break;

  case 185: /* whenEntry: whenCondition multi_comma_whenCondition COMMA ARROW controlStructureBody  */
#line 507 "k0gram.y"
                                                                              {(yyval.treeptr) = alctree(1011, "whenEntry", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2825 "k0gram.tab.c"
    break;

  case 186: /* whenEntry: ELSE ARROW controlStructureBody SEMICOLON  */
#line 508 "k0gram.y"
                                              {(yyval.treeptr) = alctree(1011, "whenEntry", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2831 "k0gram.tab.c"
    break;

  case 187: /* whenEntry: ELSE ARROW controlStructureBody  */
#line 509 "k0gram.y"
                                      {(yyval.treeptr) = alctree(1011, "whenEntry", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2837 "k0gram.tab.c"
    break;

  case 188: /* whenCondition: expression  */
#line 513 "k0gram.y"
             {(yyval.treeptr) = alctree(1080, "whenCondition", 1, (yyvsp[0].treeptr));}
#line 2843 "k0gram.tab.c"
    break;

  case 189: /* whenCondition: rangeTest  */
#line 514 "k0gram.y"
              {(yyval.treeptr) = alctree(1080, "whenCondition", 1, (yyvsp[0].treeptr));}
#line 2849 "k0gram.tab.c"
    break;

  case 190: /* rangeTest: IN expression  */
#line 518 "k0gram.y"
                {(yyval.treeptr) = alctree(1081, "rangeTest", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2855 "k0gram.tab.c"
    break;

  case 191: /* classMembers: %empty  */
#line 522 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 2861 "k0gram.tab.c"
    break;

  case 192: /* classMembers: classMembers classMember  */
#line 523 "k0gram.y"
                              {(yyval.treeptr) = alctree(1082, "classMembers", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2867 "k0gram.tab.c"
    break;

  case 193: /* classMember: functionDeclaration  */
#line 527 "k0gram.y"
                        {(yyval.treeptr) = alctree(1083, "classMember", 1, (yyvsp[0].treeptr));}
#line 2873 "k0gram.tab.c"
    break;

  case 194: /* classMember: variableDeclaration  */
#line 528 "k0gram.y"
                          {(yyval.treeptr) = alctree(1083, "classMember", 1, (yyvsp[0].treeptr));}
#line 2879 "k0gram.tab.c"
    break;

  case 195: /* expression: disjunction  */
#line 533 "k0gram.y"
              {(yyval.treeptr) = alctree(1086, "expression", 1, (yyvsp[0].treeptr));}
#line 2885 "k0gram.tab.c"
    break;

  case 196: /* disjunction: conjunction  */
#line 537 "k0gram.y"
              {(yyval.treeptr) = alctree(1087, "disjuction", 1, (yyvsp[0].treeptr));}
#line 2891 "k0gram.tab.c"
    break;

  case 197: /* disjunction: disjunction DISJ conjunction  */
#line 538 "k0gram.y"
                                 {(yyval.treeptr) = alctree(1087, "disjuction", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2897 "k0gram.tab.c"
    break;

  case 198: /* conjunction: equality  */
#line 542 "k0gram.y"
           {(yyval.treeptr) = alctree(1088, "conjuction", 1, (yyvsp[0].treeptr));}
#line 2903 "k0gram.tab.c"
    break;

  case 199: /* conjunction: conjunction CONJ equality  */
#line 543 "k0gram.y"
                              {(yyval.treeptr) = alctree(1088, "conjuction", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2909 "k0gram.tab.c"
    break;

  case 200: /* equality: comparison  */
#line 547 "k0gram.y"
             {(yyval.treeptr) = alctree(1089, "equality", 1, (yyvsp[0].treeptr));}
#line 2915 "k0gram.tab.c"
    break;

  case 201: /* equality: equality equality_operator comparison  */
#line 548 "k0gram.y"
                                            {(yyval.treeptr) = alctree(1089, "equality", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2921 "k0gram.tab.c"
    break;

  case 202: /* comparison: genericCallLikeComparison  */
#line 552 "k0gram.y"
                                {(yyval.treeptr) = alctree(1090, "comparison", 1, (yyvsp[0].treeptr));}
#line 2927 "k0gram.tab.c"
    break;

  case 203: /* comparison: comparison comparison_operator genericCallLikeComparison  */
#line 553 "k0gram.y"
                                                               {(yyval.treeptr) = alctree(1090, "comparison", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2933 "k0gram.tab.c"
    break;

  case 204: /* genericCallLikeComparison: elvisExpression  */
#line 557 "k0gram.y"
                      {(yyval.treeptr) = alctree(1091, "genericCallLikeComparison", 1, (yyvsp[0].treeptr));}
#line 2939 "k0gram.tab.c"
    break;

  case 205: /* genericCallLikeComparison: elvisExpression IN elvisExpression  */
#line 558 "k0gram.y"
                                         {(yyval.treeptr) = alctree(1091, "genericCallLikeComparison", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2945 "k0gram.tab.c"
    break;

  case 206: /* elvisExpression: rangeExpression  */
#line 562 "k0gram.y"
                      {(yyval.treeptr) = alctree(1092, "elvisExpression", 1, (yyvsp[0].treeptr));}
#line 2951 "k0gram.tab.c"
    break;

  case 207: /* elvisExpression: elvisExpression QUEST_COLON rangeExpression  */
#line 563 "k0gram.y"
                                                   {(yyval.treeptr) = alctree(1092, "elvisExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2957 "k0gram.tab.c"
    break;

  case 208: /* rangeExpression: additiveExpression  */
#line 567 "k0gram.y"
                         {(yyval.treeptr) = alctree(1093, "rangeExpression", 1, (yyvsp[0].treeptr));}
#line 2963 "k0gram.tab.c"
    break;

  case 209: /* rangeExpression: rangeExpression RANGE additiveExpression  */
#line 568 "k0gram.y"
                                               {(yyval.treeptr) = alctree(1093, "rangeExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2969 "k0gram.tab.c"
    break;

  case 210: /* additiveExpression: multiplicativeExpression  */
#line 572 "k0gram.y"
                             {(yyval.treeptr) = alctree(1094, "additiveExpression", 1, (yyvsp[0].treeptr));}
#line 2975 "k0gram.tab.c"
    break;

  case 211: /* additiveExpression: additiveExpression ADD multiplicativeExpression  */
#line 573 "k0gram.y"
                                                      {(yyval.treeptr) = alctree(1094, "additiveExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2981 "k0gram.tab.c"
    break;

  case 212: /* additiveExpression: additiveExpression SUB multiplicativeExpression  */
#line 574 "k0gram.y"
                                                      {(yyval.treeptr) = alctree(1094, "additiveExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2987 "k0gram.tab.c"
    break;

  case 213: /* multiplicativeExpression: postfixUnaryExpression  */
#line 578 "k0gram.y"
                         {(yyval.treeptr) = alctree(1095, "multiplicativeExpression", 1, (yyvsp[0].treeptr));}
#line 2993 "k0gram.tab.c"
    break;

  case 214: /* multiplicativeExpression: multiplicativeExpression MULT postfixUnaryExpression  */
#line 579 "k0gram.y"
                                                         {(yyval.treeptr) = alctree(1095, "multiplicativeExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 2999 "k0gram.tab.c"
    break;

  case 215: /* multiplicativeExpression: multiplicativeExpression DIV postfixUnaryExpression  */
#line 580 "k0gram.y"
                                                        {(yyval.treeptr) = alctree(1095, "multiplicativeExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3005 "k0gram.tab.c"
    break;

  case 216: /* multiplicativeExpression: multiplicativeExpression MOD postfixUnaryExpression  */
#line 581 "k0gram.y"
                                                        {(yyval.treeptr) = alctree(1095, "multiplicativeExpression", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3011 "k0gram.tab.c"
    break;

  case 217: /* primaryExpression: parenthesizedExpression  */
#line 585 "k0gram.y"
                          { (yyval.treeptr) = alctree(1035, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3017 "k0gram.tab.c"
    break;

  case 218: /* primaryExpression: simpleIdentifier  */
#line 586 "k0gram.y"
                       { (yyval.treeptr) = alctree(1035, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3023 "k0gram.tab.c"
    break;

  case 219: /* primaryExpression: functionCall  */
#line 587 "k0gram.y"
                   { (yyval.treeptr) = alctree(1035, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3029 "k0gram.tab.c"
    break;

  case 225: /* primaryExpression: jumpExpression  */
#line 593 "k0gram.y"
                      {(yyval.treeptr) = alctree(1011, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3035 "k0gram.tab.c"
    break;

  case 226: /* primaryExpression: collectionLiteral  */
#line 594 "k0gram.y"
                        {(yyval.treeptr) = alctree(1011, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3041 "k0gram.tab.c"
    break;

  case 227: /* primaryExpression: ifExpression  */
#line 595 "k0gram.y"
                   {(yyval.treeptr) = alctree(1011, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3047 "k0gram.tab.c"
    break;

  case 228: /* primaryExpression: whenExpression  */
#line 596 "k0gram.y"
                       {(yyval.treeptr) = alctree(1067, "primaryExpression", 1, (yyvsp[0].treeptr));}
#line 3053 "k0gram.tab.c"
    break;

  case 229: /* collectionLiteral: LSQUARE RSQUARE  */
#line 600 "k0gram.y"
                  {(yyval.treeptr) = alctree(1011, "collectionLiteral", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3059 "k0gram.tab.c"
    break;

  case 230: /* collectionLiteral: LSQUARE expression COMMA RSQUARE  */
#line 601 "k0gram.y"
                                     {(yyval.treeptr) = alctree(1011, "collectionLiteral", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3065 "k0gram.tab.c"
    break;

  case 231: /* collectionLiteral: LSQUARE expression RSQUARE  */
#line 602 "k0gram.y"
                               {(yyval.treeptr) = alctree(1011, "collectionLiteral", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3071 "k0gram.tab.c"
    break;

  case 232: /* collectionLiteral: LSQUARE expression multi_comma_expression RSQUARE  */
#line 603 "k0gram.y"
                                                      {(yyval.treeptr) = alctree(1011, "collectionLiteral", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3077 "k0gram.tab.c"
    break;

  case 233: /* collectionLiteral: LSQUARE expression multi_comma_expression COMMA RSQUARE  */
#line 604 "k0gram.y"
                                                            {(yyval.treeptr) = alctree(1011, "collectionLiteral", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 3083 "k0gram.tab.c"
    break;


#line 3087 "k0gram.tab.c"

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
