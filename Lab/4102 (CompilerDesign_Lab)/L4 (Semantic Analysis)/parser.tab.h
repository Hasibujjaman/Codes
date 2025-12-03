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
     GT = 273,
     LPAREN = 274,
     RPAREN = 275,
     LBRACE = 276,
     RBRACE = 277,
     SEMI = 278,
     ASSIGN = 279,
     ID = 280,
     ICONST = 281,
     FCONST = 282,
     CCONST = 283
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
#define GT 273
#define LPAREN 274
#define RPAREN 275
#define LBRACE 276
#define RBRACE 277
#define SEMI 278
#define ASSIGN 279
#define ID 280
#define ICONST 281
#define FCONST 282
#define CCONST 283




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 10 "parser.y"
{
    char str_val[100];
    int int_val;
}
/* Line 1529 of yacc.c.  */
#line 110 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

