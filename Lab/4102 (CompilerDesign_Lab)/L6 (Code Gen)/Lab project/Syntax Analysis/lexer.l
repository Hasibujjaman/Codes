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
	#include "parser.tab.h"
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
"an"          {}
"integer"     {return INTEGER; }
"equal"       { return EQUAL; }
"add"         { return ADDKW; }
"sub"         { return SUBKW; }
"print"       { return PRINT; }

"("       { return LPAREN; }
")"       { return RPAREN; }
","       { return COMMA; }

{ID}        {return ID;}
{ICONST}    {return ICONST;}

"\n"        { }
[ \t\r\f]+  

.       { yyerror("Unrecognized character"); }
