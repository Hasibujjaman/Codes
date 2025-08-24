%option noyywrap

%{
#include "prog.tab.h"
%}
delim [ \t\n]
ws {delim}+
digit [0-9]
number {digit}+
us [_]
letter [A-Za-z]
id ({letter}|{us})({letter}|{us}|{digit})*


%%
{ws} {}
{number} {return NUM;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"int" {printf("int\n"); return INT;}
{id} {return ID;}
"+" {return ADD;}
"-" {return SUB;}
"(" {return LP;}
")" {return RP;}
"{" {return LB;}
"}" {return RB;}
"==" {return EQUAL;}
"=" {return ASSIGN;}
";" {return SEMI;}
%%