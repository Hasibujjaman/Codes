%{
#include "prob4.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%option noyywrap
%option prefix="roll"   /* avoids macOS yytext duplicate symbol issues */

%%

/* Match valid roll numbers: (16-20)(00-10)(001-180) */
(16|17|18|19|20)(0[0-9]|10)(0[0-9][1-9]|1[0-7][0-9]|180) {
    yylval.str = strdup(rolltext);  /* use rolltext with prefix */
    return ROLL_NUMBER;
}

/* Skip whitespace */
[ \t\n]+  ;

/* Unknown token */
. { printf("Unknown token: %s\n", rolltext); }

%%
