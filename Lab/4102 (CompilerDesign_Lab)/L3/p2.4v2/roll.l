%option noyywrap

%{
#include "roll.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%%
[0-9]{7}   { yylval.sval = strdup(yytext); return ROLL_STRING; }
[ \t\n]+   ;    // ignore whitespace
.          { }
%%
