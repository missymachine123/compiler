/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_K0GRAM_TAB_H_INCLUDED
# define YY_YY_K0GRAM_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    RESERVED = 258,                /* RESERVED  */
    DOT = 259,                     /* DOT  */
    COMMA = 260,                   /* COMMA  */
    LPAREN = 261,                  /* LPAREN  */
    RPAREN = 262,                  /* RPAREN  */
    LSQUARE = 263,                 /* LSQUARE  */
    RSQUARE = 264,                 /* RSQUARE  */
    LCURL = 265,                   /* LCURL  */
    RCURL = 266,                   /* RCURL  */
    MULT = 267,                    /* MULT  */
    MOD = 268,                     /* MOD  */
    DIV = 269,                     /* DIV  */
    ADD = 270,                     /* ADD  */
    SUB = 271,                     /* SUB  */
    INCR = 272,                    /* INCR  */
    DECR = 273,                    /* DECR  */
    CONJ = 274,                    /* CONJ  */
    DISJ = 275,                    /* DISJ  */
    EXCL_WS = 276,                 /* EXCL_WS  */
    EXCL_NO_WS = 277,              /* EXCL_NO_WS  */
    COLON = 278,                   /* COLON  */
    SEMICOLON = 279,               /* SEMICOLON  */
    ASSIGNMENT = 280,              /* ASSIGNMENT  */
    ADD_ASSIGNMENT = 281,          /* ADD_ASSIGNMENT  */
    SUB_ASSIGNMENT = 282,          /* SUB_ASSIGNMENT  */
    MULT_ASSIGNMENT = 283,         /* MULT_ASSIGNMENT  */
    DIV_ASSIGNMENT = 284,          /* DIV_ASSIGNMENT  */
    MOD_ASSIGNMENT = 285,          /* MOD_ASSIGNMENT  */
    ARROW = 286,                   /* ARROW  */
    DOUBLE_ARROW = 287,            /* DOUBLE_ARROW  */
    RANGE = 288,                   /* RANGE  */
    COLONCOLON = 289,              /* COLONCOLON  */
    DOUBLE_SEMICOLON = 290,        /* DOUBLE_SEMICOLON  */
    HASH = 291,                    /* HASH  */
    AT_NO_WS = 292,                /* AT_NO_WS  */
    AT_POST_WS = 293,              /* AT_POST_WS  */
    AT_PRE_WS = 294,               /* AT_PRE_WS  */
    AT_BOTH_WS = 295,              /* AT_BOTH_WS  */
    QUEST_WS = 296,                /* QUEST_WS  */
    QUEST_NO_WS = 297,             /* QUEST_NO_WS  */
    LANGLE = 298,                  /* LANGLE  */
    RANGLE = 299,                  /* RANGLE  */
    LE = 300,                      /* LE  */
    GE = 301,                      /* GE  */
    QUEST_DOT = 302,               /* QUEST_DOT  */
    EXCL_EQ = 303,                 /* EXCL_EQ  */
    EXCL_EQEQ = 304,               /* EXCL_EQEQ  */
    AS_SAFE = 305,                 /* AS_SAFE  */
    EQEQ = 306,                    /* EQEQ  */
    EQEQEQ = 307,                  /* EQEQEQ  */
    SINGLE_QUOTE = 308,            /* SINGLE_QUOTE  */
    RETURN_AT = 309,               /* RETURN_AT  */
    CONTINUE_AT = 310,             /* CONTINUE_AT  */
    BREAK_AT = 311,                /* BREAK_AT  */
    THIS_AT = 312,                 /* THIS_AT  */
    SUPER_AT = 313,                /* SUPER_AT  */
    FILES = 314,                   /* FILES  */
    FIELD = 315,                   /* FIELD  */
    PROPERTY = 316,                /* PROPERTY  */
    GET = 317,                     /* GET  */
    QUEST_COLON = 318,             /* QUEST_COLON  */
    SET = 319,                     /* SET  */
    RECEIVER = 320,                /* RECEIVER  */
    PARAM = 321,                   /* PARAM  */
    SETPARAM = 322,                /* SETPARAM  */
    DELEGATE = 323,                /* DELEGATE  */
    PACKAGE = 324,                 /* PACKAGE  */
    IMPORT = 325,                  /* IMPORT  */
    CLASS = 326,                   /* CLASS  */
    INTERFACE = 327,               /* INTERFACE  */
    FUN = 328,                     /* FUN  */
    OBJECT = 329,                  /* OBJECT  */
    VAL = 330,                     /* VAL  */
    VAR = 331,                     /* VAR  */
    TYPEALIAS = 332,               /* TYPEALIAS  */
    CONSTRUCTOR = 333,             /* CONSTRUCTOR  */
    BY = 334,                      /* BY  */
    COMPANION = 335,               /* COMPANION  */
    INIT = 336,                    /* INIT  */
    THIS = 337,                    /* THIS  */
    SUPER = 338,                   /* SUPER  */
    TYPEOF = 339,                  /* TYPEOF  */
    WHERE = 340,                   /* WHERE  */
    IF = 341,                      /* IF  */
    ELSE = 342,                    /* ELSE  */
    WHEN = 343,                    /* WHEN  */
    TRY = 344,                     /* TRY  */
    CATCH = 345,                   /* CATCH  */
    FINALLY = 346,                 /* FINALLY  */
    FOR = 347,                     /* FOR  */
    DO = 348,                      /* DO  */
    WHILE = 349,                   /* WHILE  */
    THROW = 350,                   /* THROW  */
    RETURN = 351,                  /* RETURN  */
    CONTINUE = 352,                /* CONTINUE  */
    BREAK = 353,                   /* BREAK  */
    AS = 354,                      /* AS  */
    IS = 355,                      /* IS  */
    IN = 356,                      /* IN  */
    OUT = 357,                     /* OUT  */
    DYNAMIC = 358,                 /* DYNAMIC  */
    PUBLIC = 359,                  /* PUBLIC  */
    PRIVATE = 360,                 /* PRIVATE  */
    PROTECTED = 361,               /* PROTECTED  */
    INTERNAL = 362,                /* INTERNAL  */
    ENUM = 363,                    /* ENUM  */
    SEALED = 364,                  /* SEALED  */
    ANNOTATION = 365,              /* ANNOTATION  */
    DATA = 366,                    /* DATA  */
    INNER = 367,                   /* INNER  */
    TAILREC = 368,                 /* TAILREC  */
    OPERATOR = 369,                /* OPERATOR  */
    INLINE = 370,                  /* INLINE  */
    INFIX = 371,                   /* INFIX  */
    EXTERNAL = 372,                /* EXTERNAL  */
    SUSPEND = 373,                 /* SUSPEND  */
    OVERRIDE = 374,                /* OVERRIDE  */
    ABSTRACT = 375,                /* ABSTRACT  */
    NULL_LITERAL = 376,            /* NULL_LITERAL  */
    FINAL = 377,                   /* FINAL  */
    OPEN = 378,                    /* OPEN  */
    CONST = 379,                   /* CONST  */
    LATEINIT = 380,                /* LATEINIT  */
    VARARG = 381,                  /* VARARG  */
    NOINLINE = 382,                /* NOINLINE  */
    CROSSINLINE = 383,             /* CROSSINLINE  */
    REIFIED = 384,                 /* REIFIED  */
    EXPECT = 385,                  /* EXPECT  */
    ACTUAL = 386,                  /* ACTUAL  */
    REAL_LITERAL = 387,            /* REAL_LITERAL  */
    FLOAT_LITERAL = 388,           /* FLOAT_LITERAL  */
    DOUBLE_LITERAL = 389,          /* DOUBLE_LITERAL  */
    INTEGER_LITERAL = 390,         /* INTEGER_LITERAL  */
    CHARACTER_LITERAL = 391,       /* CHARACTER_LITERAL  */
    HEX_LITERAL = 392,             /* HEX_LITERAL  */
    BIN_LITERAL = 393,             /* BIN_LITERAL  */
    UNSIGNED_LITERAL = 394,        /* UNSIGNED_LITERAL  */
    LONG_LITERAL = 395,            /* LONG_LITERAL  */
    BOOLEAN_LITERAL = 396,         /* BOOLEAN_LITERAL  */
    IDENTIFIER = 397,              /* IDENTIFIER  */
    STRING_LITERAL = 398,          /* STRING_LITERAL  */
    INT = 399,                     /* INT  */
    FLOAT = 400,                   /* FLOAT  */
    BOOLEAN = 401,                 /* BOOLEAN  */
    CHAR = 402,                    /* CHAR  */
    STRING = 403,                  /* STRING  */
    BYTE = 404,                    /* BYTE  */
    T_EOF = 405,                   /* T_EOF  */
    AND = 406,                     /* AND  */
    OR = 407,                      /* OR  */
    LOWER_THAN_ELSE = 408          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 8 "k0gram.y"

   struct tree *treeptr;

#line 221 "k0gram.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_K0GRAM_TAB_H_INCLUDED  */
