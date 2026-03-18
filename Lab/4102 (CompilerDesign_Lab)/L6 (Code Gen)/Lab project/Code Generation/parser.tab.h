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
     FUNCTION = 258,
     MAIN = 259,
     STARTKW = 260,
     ENDKW = 261,
     SUPPOSE = 262,
     IS = 263,
     PRINT = 264,
     EQUAL = 265,
     ADDKW = 266,
     SUBKW = 267,
     LPAREN = 268,
     RPAREN = 269,
     COMMA = 270,
     ID = 271,
     ICONST = 272,
     INTEGER = 273
   };
#endif
/* Tokens.  */
#define FUNCTION 258
#define MAIN 259
#define STARTKW 260
#define ENDKW 261
#define SUPPOSE 262
#define IS 263
#define PRINT 264
#define EQUAL 265
#define ADDKW 266
#define SUBKW 267
#define LPAREN 268
#define RPAREN 269
#define COMMA 270
#define ID 271
#define ICONST 272
#define INTEGER 273




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 36 "parser.y"
{
    char str_val[100];
    int int_val;
}
/* Line 1529 of yacc.c.  */
#line 90 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

