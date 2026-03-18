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
     INT = 258,
     IF = 259,
     ELSE = 260,
     WHILE = 261,
     CONTINUE = 262,
     BREAK = 263,
     PRINT = 264,
     DOUBLE = 265,
     CHAR = 266,
     ADDOP = 267,
     SUBOP = 268,
     MULOP = 269,
     DIVOP = 270,
     EQUOP = 271,
     LT = 272,
     LTE = 273,
     GT = 274,
     LPAREN = 275,
     RPAREN = 276,
     LBRACE = 277,
     RBRACE = 278,
     SEMI = 279,
     ASSIGN = 280,
     ID = 281,
     ICONST = 282,
     FCONST = 283,
     CCONST = 284,
     LET = 285,
     AS = 286,
     LOOP = 287,
     UNTIL = 288
   };
#endif
/* Tokens.  */
#define INT 258
#define IF 259
#define ELSE 260
#define WHILE 261
#define CONTINUE 262
#define BREAK 263
#define PRINT 264
#define DOUBLE 265
#define CHAR 266
#define ADDOP 267
#define SUBOP 268
#define MULOP 269
#define DIVOP 270
#define EQUOP 271
#define LT 272
#define LTE 273
#define GT 274
#define LPAREN 275
#define RPAREN 276
#define LBRACE 277
#define RBRACE 278
#define SEMI 279
#define ASSIGN 280
#define ID 281
#define ICONST 282
#define FCONST 283
#define CCONST 284
#define LET 285
#define AS 286
#define LOOP 287
#define UNTIL 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 10 "parser.y"
{
    char str_val[100];
    int int_val;
}
/* Line 1529 of yacc.c.  */
#line 120 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

