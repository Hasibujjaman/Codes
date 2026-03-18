%{
// Roll: 2003001
//Q1.  Consider following Code Snippet:

// function main () 

// start

//        suppose A is an integer

//        suppose  B is an integer

//        A equal 2

//        B equal 3 add A sub 5

//        print(B)

// end

// Design Lexical Analysis, Syntax Analysis, Intermediate Code Generation and Code Generation part of compiler based on the code snippet.
%}

%option noyywrap

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "parser.tab.h"
	int lineno = 1;
	void yyerror();
%}

alpha     [a-zA-Z]
digit     [0-9]
alnum     {alpha}|{digit}

ID        {alpha}{alnum}*
ICONST    [0-9]+
%%

"//".*        { }

"function"    { return FUNCTION; }
"main"        { return MAIN; }
"start"       { return STARTKW; }
"end"         { return ENDKW; }
"suppose"     { return SUPPOSE; }
"is"          { return IS; }
"an"          { /* optional article, ignore */ }
"integer"     { yylval.int_val = 1; return INTEGER; }
"equal"       { return EQUAL; }
"add"         { return ADDKW; }
"sub"         { return SUBKW; }
"print"       { return PRINT; }

"("       { return LPAREN; }
")"       { return RPAREN; }
","       { return COMMA; }

{ID}        {strcpy(yylval.str_val, yytext); return ID;}
{ICONST}    {yylval.int_val=atoi(yytext); return ICONST;}

"\n"        { lineno += 1; }
[ \t\r\f]+  

.       { yyerror("Unrecognized character"); }
