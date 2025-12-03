%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "symtab.h"
	#include "parser.tab.h"
	
	int lineno = 1; // initialize to 1
	void yyerror();
%}

/* Start conditions for block comments */
%x COMMENT

ALPHA     [A-Za-z_]
DIGIT     [0-9]
ID        {ALPHA}({ALPHA}|{DIGIT})*
FCONST    {DIGIT}+\.{DIGIT}+
ICONST    {DIGIT}+
ESC       \\.
STRING    \"([^\"\\]|{ESC})*\"
%%

"//".*                { /* line comment */ }

"/*"                  { BEGIN(COMMENT); }
<COMMENT>"*/"         { BEGIN(INITIAL); }
<COMMENT>"\n"        { lineno += 1; }
<COMMENT>.             { /* eat comment body */ }

"int"                 { yylval.int_val=INT_TYPE; return INT; }
"float"               { yylval.int_val=REAL_TYPE; return FLOAT; }
"bool"                { yylval.int_val=BOOL_TYPE; return BOOL; }
"reaction"            { yylval.int_val=REACTION_TYPE; return REACTION; }
"def"                 { return DEF; }
"main"                { return MAIN; }
"true"                { yylval.int_val=1; return TRUE; }
"false"               { yylval.int_val=0; return FALSE; }
"check_balance"       { return CHECK_BALANCE; }
"if"                  { return IF; }
"else"                { return ELSE; }
"while"               { return WHILE; }
"print"               { return PRINT; }
"scan"                { return SCAN; }

"=="                  { return EQUOP; }
"&&"                  { return AND; }
"||"                  { return OR; }
">"                   { return GT; }
"<"                   { return LT; }
"+"                   { return ADDOP; }
"-"                   { return SUBOP; }
"*"                   { return MULOP; }
"/"                   { return DIVOP; }

"("                   { return LPAREN; }
")"                   { return RPAREN; }
"{"                   { return LBRACE; }
"}"                   { return RBRACE; }
","                   { return COMMA; }
";"                   { return SEMI; }
"="                   { return ASSIGN; }

{ID}                  {
                        size_t n = yyleng; if(n > sizeof(yylval.str_val)-1) n = sizeof(yylval.str_val)-1;
                        strncpy(yylval.str_val, yytext, n);
                        yylval.str_val[n] = '\0';
                        return ID;
                      }
{FCONST}              { yylval.float_val=atof(yytext); return FCONST; }
{ICONST}              { yylval.int_val=atoi(yytext); return ICONST; }
{STRING}              {
                        /* strip quotes preserving escapes */
                        size_t len = yyleng;
                        if(len >= 2) {
                            size_t n = len - 2; if(n > sizeof(yylval.str_val)-1) n = sizeof(yylval.str_val)-1;
                            /* simple unescape: copy as-is without surrounding quotes */
                            strncpy(yylval.str_val, yytext+1, n);
                            yylval.str_val[n] = '\0';
                        } else {
                            yylval.str_val[0] = '\0';
                        }
                        return STRING;
                      }

"\n"                 { lineno += 1; }
[ \t\r\f]+         { /* skip whitespace */ }

.                     { yyerror("Unrecognized character"); }
