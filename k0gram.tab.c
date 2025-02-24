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
    struct tree *alctree(int prodrule, const char *symbolname, int nkids, ...);

#line 82 "k0gram.tab.c"

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
  YYSYMBOL_MULT = 145,                     /* MULT  */
  YYSYMBOL_MOD = 146,                      /* MOD  */
  YYSYMBOL_DIV = 147,                      /* DIV  */
  YYSYMBOL_ADD = 148,                      /* ADD  */
  YYSYMBOL_SUB = 149,                      /* SUB  */
  YYSYMBOL_IDENTIFIER = 150,               /* IDENTIFIER  */
  YYSYMBOL_AND = 151,                      /* AND  */
  YYSYMBOL_OR = 152,                       /* OR  */
  YYSYMBOL_LOWER_THAN_ELSE = 153,          /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 154,                 /* $accept  */
  YYSYMBOL_program = 155,                  /* program  */
  YYSYMBOL_topLevelObjects = 156,          /* topLevelObjects  */
  YYSYMBOL_topLevelObject = 157,           /* topLevelObject  */
  YYSYMBOL_functionDeclaration = 158,      /* functionDeclaration  */
  YYSYMBOL_functionParameters = 159,       /* functionParameters  */
  YYSYMBOL_functionParameter = 160,        /* functionParameter  */
  YYSYMBOL_type = 161,                     /* type  */
  YYSYMBOL_functionBody = 162,             /* functionBody  */
  YYSYMBOL_block = 163,                    /* block  */
  YYSYMBOL_statements = 164,               /* statements  */
  YYSYMBOL_statement = 165,                /* statement  */
  YYSYMBOL_variableDeclaration = 166,      /* variableDeclaration  */
  YYSYMBOL_assignment = 167,               /* assignment  */
  YYSYMBOL_functionCall = 168,             /* functionCall  */
  YYSYMBOL_functionArguments = 169,        /* functionArguments  */
  YYSYMBOL_loopStatement = 170,            /* loopStatement  */
  YYSYMBOL_controlStructure = 171,         /* controlStructure  */
  YYSYMBOL_returnStatement = 172,          /* returnStatement  */
  YYSYMBOL_classDeclaration = 173,         /* classDeclaration  */
  YYSYMBOL_classBody = 174,                /* classBody  */
  YYSYMBOL_classMembers = 175,             /* classMembers  */
  YYSYMBOL_classMember = 176,              /* classMember  */
  YYSYMBOL_objectDeclaration = 177,        /* objectDeclaration  */
  YYSYMBOL_objectBody = 178,               /* objectBody  */
  YYSYMBOL_expression = 179                /* expression  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  154
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   408


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
     145,   146,   147,   148,   149,   150,   151,   152,   153
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    46,    47,    51,    52,    53,    58,    59,
      64,    65,    66,    70,    75,    76,    77,    78,    79,    80,
      85,    86,    91,    96,    97,    98,   102,   103,   104,   105,
     106,   107,   108,   109,   114,   119,   124,   129,   130,   131,
     136,   137,   142,   143,   148,   153,   157,   161,   162,   166,
     167,   172,   176,   181,   182,   183,   184
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
  "BOOLEAN", "CHAR", "STRING", "BYTE", "T_EOF", "MULT", "MOD", "DIV",
  "ADD", "SUB", "IDENTIFIER", "AND", "OR", "LOWER_THAN_ELSE", "$accept",
  "program", "topLevelObjects", "topLevelObject", "functionDeclaration",
  "functionParameters", "functionParameter", "type", "functionBody",
  "block", "statements", "statement", "variableDeclaration", "assignment",
  "functionCall", "functionArguments", "loopStatement", "controlStructure",
  "returnStatement", "classDeclaration", "classBody", "classMembers",
  "classMember", "objectDeclaration", "objectBody", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-134)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,  -133,  -128,  -127,    29,   -22,  -134,  -134,  -134,  -134,
      23,    28,    26,  -134,  -134,  -134,  -134,  -110,  -134,  -134,
     -10,    30,     4,  -134,    -9,  -134,    33,  -134,  -134,  -134,
     -98,  -110,    17,  -134,   -98,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,   -98,  -125,  -134,  -134,  -134,   -11,
      -4,  -134,  -134,    47,  -134,    35,  -134,    49,    50,    51,
    -125,     1,    41,    42,    43,  -134,  -134,  -134,    44,  -134,
    -125,  -134,  -125,   -86,  -125,    46,  -125,  -134,  -134,  -134,
    -134,     8,  -134,    59,   -29,    61,  -134,    52,  -125,  -134,
      62,  -125,    62,  -134,  -134,   -13,    66,  -134,    62,    62,
    -134,  -134
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     3,     5,     6,     7,
       0,     0,     0,     1,     4,    47,    45,    10,    47,    51,
       0,     0,     0,    11,     0,    46,     0,    49,    50,    48,
       0,     0,     0,    52,     0,    19,    16,    15,    17,    18,
      14,    13,    12,    23,     0,     0,     8,    20,    34,     0,
       0,    56,    55,    54,    53,     0,    22,     0,     0,     0,
       0,    54,    25,     0,    28,    31,    32,    33,    29,     9,
      37,    21,     0,     0,     0,     0,     0,    24,    26,    27,
      30,     0,    38,     0,     0,     0,    44,     0,     0,    36,
       0,     0,     0,    35,    39,    42,     0,    40,     0,     0,
      43,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,    69,   -16,  -134,    48,   -24,    25,   -49,
    -134,  -134,    32,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,    64,  -134,  -134,  -134,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    22,    23,    41,    46,    47,
      49,    62,    28,    64,    54,    81,    65,    66,    67,     8,
      16,    20,    29,     9,    19,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    25,    33,    68,    27,    51,    43,    70,    27,    31,
      48,    32,    52,    88,    75,    89,    45,    10,    35,    34,
      50,    76,    11,    12,    82,    53,    83,    43,    85,    13,
      87,    36,    37,    15,    17,    44,    18,    45,    38,    39,
      21,    95,    94,    97,     1,    96,     2,     3,    30,   100,
     101,    34,    40,    70,    71,    72,    73,    74,     2,     2,
      77,    78,    79,    80,    84,    86,    90,    91,    92,    98,
      57,    93,    43,    99,    14,    69,    58,     0,    59,    42,
      60,    63,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
      26,    26
};

static const yytype_int16 yycheck[] =
{
      11,    11,    11,    49,    20,   130,    10,     6,    24,     5,
      34,     7,   137,     5,    60,     7,    20,   150,   116,    18,
      44,    20,   150,   150,    70,   150,    72,    10,    74,     0,
      76,   129,   130,    10,     6,    18,    10,    20,   136,   137,
     150,    90,    88,    92,    66,    91,    68,    69,    18,    98,
      99,    18,   150,     6,    19,     6,     6,     6,    68,    68,
      19,    19,    19,    19,   150,    19,     7,    96,     7,    82,
      81,    19,    10,     7,     5,    50,    87,    -1,    89,    31,
      91,    49,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     150,   150
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    68,    69,   155,   156,   157,   158,   173,   177,
     150,   150,   150,     0,   157,    10,   174,     6,    10,   178,
     175,   150,   159,   160,   175,    11,   150,   158,   166,   176,
      18,     5,     7,    11,    18,   116,   129,   130,   136,   137,
     150,   161,   160,    10,    18,    20,   162,   163,   161,   164,
     161,   130,   137,   150,   168,   179,    11,    81,    87,    89,
      91,   150,   165,   166,   167,   170,   171,   172,   179,   162,
       6,    19,     6,     6,     6,   179,    20,    19,    19,    19,
      19,   169,   179,   179,   150,   179,    19,   179,     5,     7,
       7,    96,     7,    19,   179,   163,   179,   163,    82,     7,
     163,   163
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   154,   155,   156,   156,   157,   157,   157,   158,   158,
     159,   159,   159,   160,   161,   161,   161,   161,   161,   161,
     162,   162,   163,   164,   164,   164,   165,   165,   165,   165,
     165,   165,   165,   165,   166,   167,   168,   169,   169,   169,
     170,   170,   171,   171,   172,   173,   174,   175,   175,   176,
     176,   177,   178,   179,   179,   179,   179
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     6,     8,
       0,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     0,     3,     2,     2,     2,     1,     1,
       2,     1,     1,     1,     3,     4,     4,     0,     1,     3,
       5,     7,     5,     7,     3,     3,     3,     0,     2,     1,
       1,     3,     3,     1,     1,     1,     1
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
#line 42 "k0gram.y"
                    {root = (yyvsp[0].treeptr);}
#line 1355 "k0gram.tab.c"
    break;

  case 3: /* topLevelObjects: topLevelObject  */
#line 46 "k0gram.y"
                   {(yyval.treeptr) = alctree(1001, "topLevelObjects", 1, (yyvsp[0].treeptr));}
#line 1361 "k0gram.tab.c"
    break;

  case 4: /* topLevelObjects: topLevelObjects topLevelObject  */
#line 47 "k0gram.y"
                                   {(yyval.treeptr) = alctree(1001, "topLevelObjects", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1367 "k0gram.tab.c"
    break;

  case 5: /* topLevelObject: functionDeclaration  */
#line 51 "k0gram.y"
                        {(yyval.treeptr) = alctree(1002, "topLevelObject", 1, (yyvsp[0].treeptr));}
#line 1373 "k0gram.tab.c"
    break;

  case 6: /* topLevelObject: classDeclaration  */
#line 52 "k0gram.y"
                     {(yyval.treeptr) = alctree(1002, "topLevelObject", 1, (yyvsp[0].treeptr));}
#line 1379 "k0gram.tab.c"
    break;

  case 7: /* topLevelObject: objectDeclaration  */
#line 53 "k0gram.y"
                      {(yyval.treeptr) = alctree(1002, "topLevelObject", 1, (yyvsp[0].treeptr));}
#line 1385 "k0gram.tab.c"
    break;

  case 8: /* functionDeclaration: FUN IDENTIFIER LPAREN functionParameters RPAREN functionBody  */
#line 58 "k0gram.y"
                                                                 {(yyval.treeptr) = alctree(1003, "functionDeclaration", 6, (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1391 "k0gram.tab.c"
    break;

  case 9: /* functionDeclaration: FUN IDENTIFIER LPAREN functionParameters RPAREN COLON type functionBody  */
#line 59 "k0gram.y"
                                                                             {(yyval.treeptr) = alctree(1003, "functionDeclaration", 7, (yyvsp[-7].treeptr), (yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),(yyvsp[-1].treeptr));}
#line 1397 "k0gram.tab.c"
    break;

  case 10: /* functionParameters: %empty  */
#line 64 "k0gram.y"
               {(yyval.treeptr) = NULL;}
#line 1403 "k0gram.tab.c"
    break;

  case 11: /* functionParameters: functionParameter  */
#line 65 "k0gram.y"
                      {(yyval.treeptr) = alctree(1004, "functionParameters", 1, (yyvsp[0].treeptr));}
#line 1409 "k0gram.tab.c"
    break;

  case 12: /* functionParameters: functionParameters COMMA functionParameter  */
#line 66 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1004, "functionParameters", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1415 "k0gram.tab.c"
    break;

  case 13: /* functionParameter: IDENTIFIER COLON type  */
#line 70 "k0gram.y"
                        {(yyval.treeptr) = alctree(1005, "functionParameter", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1421 "k0gram.tab.c"
    break;

  case 14: /* type: IDENTIFIER  */
#line 75 "k0gram.y"
                {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1427 "k0gram.tab.c"
    break;

  case 15: /* type: INTEGER_LITERAL  */
#line 76 "k0gram.y"
                    {(yyval.treeptr) =  (yyvsp[0].treeptr);}
#line 1433 "k0gram.tab.c"
    break;

  case 16: /* type: DOUBLE_LITERAL  */
#line 77 "k0gram.y"
                    {(yyval.treeptr) =  (yyvsp[0].treeptr);}
#line 1439 "k0gram.tab.c"
    break;

  case 17: /* type: BOOLEAN_LITERAL  */
#line 78 "k0gram.y"
                    {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1445 "k0gram.tab.c"
    break;

  case 18: /* type: STRING_LITERAL  */
#line 79 "k0gram.y"
                    {(yyval.treeptr) =  (yyvsp[0].treeptr);}
#line 1451 "k0gram.tab.c"
    break;

  case 19: /* type: NULL_LITERAL  */
#line 80 "k0gram.y"
                  {(yyval.treeptr) =  (yyvsp[0].treeptr);}
#line 1457 "k0gram.tab.c"
    break;

  case 20: /* functionBody: block  */
#line 85 "k0gram.y"
          {(yyval.treeptr) = alctree(1007, "functionBody", 1, (yyvsp[0].treeptr));}
#line 1463 "k0gram.tab.c"
    break;

  case 21: /* functionBody: ASSIGNMENT expression SEMICOLON  */
#line 86 "k0gram.y"
                                    {(yyval.treeptr) = alctree(1007, "functionBody", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1469 "k0gram.tab.c"
    break;

  case 22: /* block: LCURL statements RCURL  */
#line 91 "k0gram.y"
                            {(yyval.treeptr) = alctree(1008, "block", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));  }
#line 1475 "k0gram.tab.c"
    break;

  case 23: /* statements: %empty  */
#line 96 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1481 "k0gram.tab.c"
    break;

  case 24: /* statements: statements statement SEMICOLON  */
#line 97 "k0gram.y"
                                    {(yyval.treeptr) = alctree(1009, "statements", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1487 "k0gram.tab.c"
    break;

  case 25: /* statements: statements statement  */
#line 98 "k0gram.y"
                          {(yyval.treeptr) = alctree(1009, "statements", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1493 "k0gram.tab.c"
    break;

  case 26: /* statement: variableDeclaration SEMICOLON  */
#line 102 "k0gram.y"
                                  {(yyval.treeptr) = alctree(1010, "statement", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1499 "k0gram.tab.c"
    break;

  case 27: /* statement: assignment SEMICOLON  */
#line 103 "k0gram.y"
                          {(yyval.treeptr) = alctree(1010, "statement", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1505 "k0gram.tab.c"
    break;

  case 28: /* statement: assignment  */
#line 104 "k0gram.y"
                {(yyval.treeptr) = alctree(1010, "statement", 1, (yyvsp[0].treeptr));}
#line 1511 "k0gram.tab.c"
    break;

  case 29: /* statement: expression  */
#line 105 "k0gram.y"
                {(yyval.treeptr) = alctree(1010, "statement", 1, (yyvsp[0].treeptr)); }
#line 1517 "k0gram.tab.c"
    break;

  case 30: /* statement: expression SEMICOLON  */
#line 106 "k0gram.y"
                          {(yyval.treeptr) = alctree(1010, "statement", 2, (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1523 "k0gram.tab.c"
    break;

  case 31: /* statement: loopStatement  */
#line 107 "k0gram.y"
                  {(yyval.treeptr) = alctree(1010, "statement", 1, (yyvsp[0].treeptr));}
#line 1529 "k0gram.tab.c"
    break;

  case 32: /* statement: controlStructure  */
#line 108 "k0gram.y"
                        {(yyval.treeptr) = alctree(1010, "statement", 1, (yyvsp[0].treeptr));}
#line 1535 "k0gram.tab.c"
    break;

  case 33: /* statement: returnStatement  */
#line 109 "k0gram.y"
                    {(yyval.treeptr) = alctree(1010, "statement", 1, (yyvsp[0].treeptr));}
#line 1541 "k0gram.tab.c"
    break;

  case 34: /* variableDeclaration: IDENTIFIER COLON type  */
#line 114 "k0gram.y"
                          {(yyval.treeptr) = alctree(1011, "variableDeclaration", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1547 "k0gram.tab.c"
    break;

  case 35: /* assignment: IDENTIFIER ASSIGNMENT expression SEMICOLON  */
#line 119 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1012, "assignment", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1553 "k0gram.tab.c"
    break;

  case 36: /* functionCall: IDENTIFIER LPAREN functionArguments RPAREN  */
#line 124 "k0gram.y"
                                                {(yyval.treeptr) = alctree(1013, "functionCall", 4, (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1559 "k0gram.tab.c"
    break;

  case 37: /* functionArguments: %empty  */
#line 129 "k0gram.y"
               {(yyval.treeptr) = NULL;}
#line 1565 "k0gram.tab.c"
    break;

  case 38: /* functionArguments: expression  */
#line 130 "k0gram.y"
                {(yyval.treeptr) = alctree(1014, "functionArguments", 1, (yyvsp[0].treeptr));}
#line 1571 "k0gram.tab.c"
    break;

  case 39: /* functionArguments: functionArguments COMMA expression  */
#line 131 "k0gram.y"
                                        {(yyval.treeptr) = alctree(1014, "functionArguments", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1577 "k0gram.tab.c"
    break;

  case 40: /* loopStatement: WHILE LPAREN expression RPAREN block  */
#line 136 "k0gram.y"
                                          {(yyval.treeptr) = alctree(1015,"loopStatement", 5 ,(yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr), (yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1583 "k0gram.tab.c"
    break;

  case 41: /* loopStatement: FOR LPAREN IDENTIFIER IN expression RPAREN block  */
#line 137 "k0gram.y"
                                                      {(yyval.treeptr) = alctree(1015,"loopStatement", 6 ,(yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr), (yyvsp[-3].treeptr),(yyvsp[-2].treeptr),(yyvsp[-1].treeptr));}
#line 1589 "k0gram.tab.c"
    break;

  case 42: /* controlStructure: IF LPAREN expression RPAREN block  */
#line 142 "k0gram.y"
                                                            {(yyval.treeptr) = alctree(1016, "controlStructure", 5, (yyvsp[-4].treeptr), (yyvsp[-3].treeptr), (yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr) );}
#line 1595 "k0gram.tab.c"
    break;

  case 43: /* controlStructure: IF LPAREN expression RPAREN block ELSE block  */
#line 143 "k0gram.y"
                                                 {(yyval.treeptr) = alctree(1016, "controlStructure", 7 ,(yyvsp[-6].treeptr), (yyvsp[-5].treeptr), (yyvsp[-4].treeptr),(yyvsp[-3].treeptr),(yyvsp[-2].treeptr),(yyvsp[-1].treeptr),(yyvsp[0].treeptr));}
#line 1601 "k0gram.tab.c"
    break;

  case 44: /* returnStatement: RETURN expression SEMICOLON  */
#line 148 "k0gram.y"
                                {(yyval.treeptr) = alctree(1017, "returnStatement", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1607 "k0gram.tab.c"
    break;

  case 45: /* classDeclaration: CLASS IDENTIFIER classBody  */
#line 153 "k0gram.y"
                                {(yyval.treeptr) = alctree(1018, "classDeclaration", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1613 "k0gram.tab.c"
    break;

  case 46: /* classBody: LCURL classMembers RCURL  */
#line 157 "k0gram.y"
                              {(yyval.treeptr) = alctree(1019, "classBody", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1619 "k0gram.tab.c"
    break;

  case 47: /* classMembers: %empty  */
#line 161 "k0gram.y"
                {(yyval.treeptr) = NULL;}
#line 1625 "k0gram.tab.c"
    break;

  case 48: /* classMembers: classMembers classMember  */
#line 162 "k0gram.y"
                              {(yyval.treeptr) = alctree(1020, "classMembers", 2, (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1631 "k0gram.tab.c"
    break;

  case 49: /* classMember: functionDeclaration  */
#line 166 "k0gram.y"
                        {(yyval.treeptr) = alctree(1021, "classMember", 1, (yyvsp[0].treeptr));}
#line 1637 "k0gram.tab.c"
    break;

  case 50: /* classMember: variableDeclaration  */
#line 167 "k0gram.y"
                          {(yyval.treeptr) = alctree(1021, "classMember", 1, (yyvsp[0].treeptr));}
#line 1643 "k0gram.tab.c"
    break;

  case 51: /* objectDeclaration: OBJECT IDENTIFIER objectBody  */
#line 172 "k0gram.y"
                                  {(yyval.treeptr) = alctree(1022, "objectDeclaration", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1649 "k0gram.tab.c"
    break;

  case 52: /* objectBody: LCURL classMembers RCURL  */
#line 176 "k0gram.y"
                              {(yyval.treeptr) = alctree(1023, "objectBody", 3, (yyvsp[-2].treeptr), (yyvsp[-1].treeptr), (yyvsp[0].treeptr));}
#line 1655 "k0gram.tab.c"
    break;

  case 53: /* expression: functionCall  */
#line 181 "k0gram.y"
                  {(yyval.treeptr) = alctree(1024, "expression", 1, (yyvsp[0].treeptr));}
#line 1661 "k0gram.tab.c"
    break;

  case 54: /* expression: IDENTIFIER  */
#line 182 "k0gram.y"
                  {(yyval.treeptr) = (yyvsp[0].treeptr); }
#line 1667 "k0gram.tab.c"
    break;

  case 55: /* expression: STRING_LITERAL  */
#line 183 "k0gram.y"
                    {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1673 "k0gram.tab.c"
    break;

  case 56: /* expression: INTEGER_LITERAL  */
#line 184 "k0gram.y"
                      {(yyval.treeptr) = (yyvsp[0].treeptr);}
#line 1679 "k0gram.tab.c"
    break;


#line 1683 "k0gram.tab.c"

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

#line 186 "k0gram.y"

