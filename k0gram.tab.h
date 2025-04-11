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
    INCR = 267,                    /* INCR  */
    DECR = 268,                    /* DECR  */
    CONJ = 269,                    /* CONJ  */
    DISJ = 270,                    /* DISJ  */
    EXCL_WS = 271,                 /* EXCL_WS  */
    EXCL_NO_WS = 272,              /* EXCL_NO_WS  */
    COLON = 273,                   /* COLON  */
    SEMICOLON = 274,               /* SEMICOLON  */
    ASSIGNMENT = 275,              /* ASSIGNMENT  */
    ADD_ASSIGNMENT = 276,          /* ADD_ASSIGNMENT  */
    SUB_ASSIGNMENT = 277,          /* SUB_ASSIGNMENT  */
    MULT_ASSIGNMENT = 278,         /* MULT_ASSIGNMENT  */
    DIV_ASSIGNMENT = 279,          /* DIV_ASSIGNMENT  */
    MOD_ASSIGNMENT = 280,          /* MOD_ASSIGNMENT  */
    ARROW = 281,                   /* ARROW  */
    DOUBLE_ARROW = 282,            /* DOUBLE_ARROW  */
    RANGE = 283,                   /* RANGE  */
    COLONCOLON = 284,              /* COLONCOLON  */
    DOUBLE_SEMICOLON = 285,        /* DOUBLE_SEMICOLON  */
    HASH = 286,                    /* HASH  */
    AT_NO_WS = 287,                /* AT_NO_WS  */
    AT_POST_WS = 288,              /* AT_POST_WS  */
    AT_PRE_WS = 289,               /* AT_PRE_WS  */
    AT_BOTH_WS = 290,              /* AT_BOTH_WS  */
    QUEST_WS = 291,                /* QUEST_WS  */
    QUEST_NO_WS = 292,             /* QUEST_NO_WS  */
    LANGLE = 293,                  /* LANGLE  */
    RANGLE = 294,                  /* RANGLE  */
    LE = 295,                      /* LE  */
    GE = 296,                      /* GE  */
    QUEST_DOT = 297,               /* QUEST_DOT  */
    EXCL_EQ = 298,                 /* EXCL_EQ  */
    EXCL_EQEQ = 299,               /* EXCL_EQEQ  */
    AS_SAFE = 300,                 /* AS_SAFE  */
    EQEQ = 301,                    /* EQEQ  */
    EQEQEQ = 302,                  /* EQEQEQ  */
    SINGLE_QUOTE = 303,            /* SINGLE_QUOTE  */
    RETURN_AT = 304,               /* RETURN_AT  */
    CONTINUE_AT = 305,             /* CONTINUE_AT  */
    BREAK_AT = 306,                /* BREAK_AT  */
    THIS_AT = 307,                 /* THIS_AT  */
    SUPER_AT = 308,                /* SUPER_AT  */
    FILES = 309,                   /* FILES  */
    FIELD = 310,                   /* FIELD  */
    PROPERTY = 311,                /* PROPERTY  */
    GET = 312,                     /* GET  */
    QUEST_COLON = 313,             /* QUEST_COLON  */
    SET = 314,                     /* SET  */
    RECEIVER = 315,                /* RECEIVER  */
    PARAM = 316,                   /* PARAM  */
    SETPARAM = 317,                /* SETPARAM  */
    DELEGATE = 318,                /* DELEGATE  */
    PACKAGE = 319,                 /* PACKAGE  */
    IMPORT = 320,                  /* IMPORT  */
    CLASS = 321,                   /* CLASS  */
    INTERFACE = 322,               /* INTERFACE  */
    FUN = 323,                     /* FUN  */
    OBJECT = 324,                  /* OBJECT  */
    VAL = 325,                     /* VAL  */
    VAR = 326,                     /* VAR  */
    TYPEALIAS = 327,               /* TYPEALIAS  */
    CONSTRUCTOR = 328,             /* CONSTRUCTOR  */
    BY = 329,                      /* BY  */
    COMPANION = 330,               /* COMPANION  */
    INIT = 331,                    /* INIT  */
    THIS = 332,                    /* THIS  */
    SUPER = 333,                   /* SUPER  */
    TYPEOF = 334,                  /* TYPEOF  */
    WHERE = 335,                   /* WHERE  */
    IF = 336,                      /* IF  */
    ELSE = 337,                    /* ELSE  */
    WHEN = 338,                    /* WHEN  */
    TRY = 339,                     /* TRY  */
    CATCH = 340,                   /* CATCH  */
    FINALLY = 341,                 /* FINALLY  */
    FOR = 342,                     /* FOR  */
    DO = 343,                      /* DO  */
    WHILE = 344,                   /* WHILE  */
    THROW = 345,                   /* THROW  */
    RETURN = 346,                  /* RETURN  */
    CONTINUE = 347,                /* CONTINUE  */
    BREAK = 348,                   /* BREAK  */
    AS = 349,                      /* AS  */
    IS = 350,                      /* IS  */
    IN = 351,                      /* IN  */
    OUT = 352,                     /* OUT  */
    DYNAMIC = 353,                 /* DYNAMIC  */
    PUBLIC = 354,                  /* PUBLIC  */
    PRIVATE = 355,                 /* PRIVATE  */
    PROTECTED = 356,               /* PROTECTED  */
    INTERNAL = 357,                /* INTERNAL  */
    ENUM = 358,                    /* ENUM  */
    SEALED = 359,                  /* SEALED  */
    ANNOTATION = 360,              /* ANNOTATION  */
    DATA = 361,                    /* DATA  */
    INNER = 362,                   /* INNER  */
    TAILREC = 363,                 /* TAILREC  */
    OPERATOR = 364,                /* OPERATOR  */
    INLINE = 365,                  /* INLINE  */
    INFIX = 366,                   /* INFIX  */
    EXTERNAL = 367,                /* EXTERNAL  */
    SUSPEND = 368,                 /* SUSPEND  */
    OVERRIDE = 369,                /* OVERRIDE  */
    ABSTRACT = 370,                /* ABSTRACT  */
    NULL_LITERAL = 371,            /* NULL_LITERAL  */
    FINAL = 372,                   /* FINAL  */
    OPEN = 373,                    /* OPEN  */
    CONST = 374,                   /* CONST  */
    LATEINIT = 375,                /* LATEINIT  */
    VARARG = 376,                  /* VARARG  */
    NOINLINE = 377,                /* NOINLINE  */
    CROSSINLINE = 378,             /* CROSSINLINE  */
    REIFIED = 379,                 /* REIFIED  */
    EXPECT = 380,                  /* EXPECT  */
    ACTUAL = 381,                  /* ACTUAL  */
    REAL_LITERAL = 382,            /* REAL_LITERAL  */
    FLOAT_LITERAL = 383,           /* FLOAT_LITERAL  */
    DOUBLE_LITERAL = 384,          /* DOUBLE_LITERAL  */
    INTEGER_LITERAL = 385,         /* INTEGER_LITERAL  */
    CHARACTER_LITERAL = 386,       /* CHARACTER_LITERAL  */
    HEX_LITERAL = 387,             /* HEX_LITERAL  */
    BIN_LITERAL = 388,             /* BIN_LITERAL  */
    UNSIGNED_LITERAL = 389,        /* UNSIGNED_LITERAL  */
    LONG_LITERAL = 390,            /* LONG_LITERAL  */
    BOOLEAN_LITERAL = 391,         /* BOOLEAN_LITERAL  */
    STRING_LITERAL = 392,          /* STRING_LITERAL  */
    INT = 393,                     /* INT  */
    FLOAT = 394,                   /* FLOAT  */
    BOOLEAN = 395,                 /* BOOLEAN  */
    CHAR = 396,                    /* CHAR  */
    STRING = 397,                  /* STRING  */
    BYTE = 398,                    /* BYTE  */
    T_EOF = 399,                   /* T_EOF  */
    TYPELITERAL = 400,             /* TYPELITERAL  */
    MULT = 401,                    /* MULT  */
    MOD = 402,                     /* MOD  */
    DIV = 403,                     /* DIV  */
    ADD = 404,                     /* ADD  */
    SUB = 405,                     /* SUB  */
    ARRAYTYPELITERAL = 406,        /* ARRAYTYPELITERAL  */
    IDENTIFIER = 407,              /* IDENTIFIER  */
    AND = 408,                     /* AND  */
    OR = 409,                      /* OR  */
    LOWER_THAN_ELSE = 410          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "k0gram.y"

   struct tree *treeptr;

#line 223 "k0gram.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_K0GRAM_TAB_H_INCLUDED  */
