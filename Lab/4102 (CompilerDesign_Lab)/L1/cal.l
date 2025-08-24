%option noyywrap

%{
#include "cal.tab.h"
%}

digit [0-9]
number ({digit}+)
letter [A-Za-z]
id {letter}({letter}|{digit})*


delim [ \t]
ws {delim}+



%%


{number} {return NUM;}
"+" {return ADD;}
"-" {return SUB;}
"*" {return MUL;}
"=" {return ASS;}
{id} {return ID;}
{ws} {}

%%

