/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PRINT = 258,
     SCAN = 259,
     ADDOP = 260,
     SUBOP = 261,
     MULOP = 262,
     DIVOP = 263,
     EQUOP = 264,
     LT = 265,
     GT = 266,
     AND = 267,
     OR = 268,
     LPAREN = 269,
     RPAREN = 270,
     LBRACE = 271,
     RBRACE = 272,
     SEMI = 273,
     ASSIGN = 274,
     ELSE = 275,
     COMMA = 276,
     DEF = 277,
     MAIN = 278,
     CHECK_BALANCE = 279,
     TRUE = 280,
     FALSE = 281,
     INT = 282,
     FLOAT = 283,
     BOOL = 284,
     REACTION = 285,
     IF = 286,
     WHILE = 287,
     ID = 288,
     STRING = 289,
     ICONST = 290,
     FCONST = 291,
     IFX = 292
   };
#endif
/* Tokens.  */
#define PRINT 258
#define SCAN 259
#define ADDOP 260
#define SUBOP 261
#define MULOP 262
#define DIVOP 263
#define EQUOP 264
#define LT 265
#define GT 266
#define AND 267
#define OR 268
#define LPAREN 269
#define RPAREN 270
#define LBRACE 271
#define RBRACE 272
#define SEMI 273
#define ASSIGN 274
#define ELSE 275
#define COMMA 276
#define DEF 277
#define MAIN 278
#define CHECK_BALANCE 279
#define TRUE 280
#define FALSE 281
#define INT 282
#define FLOAT 283
#define BOOL 284
#define REACTION 285
#define IF 286
#define WHILE 287
#define ID 288
#define STRING 289
#define ICONST 290
#define FCONST 291
#define IFX 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "parser.y"
{
    char str_val[256];
    int int_val;
    double float_val;
}
/* Line 1529 of yacc.c.  */
#line 129 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

