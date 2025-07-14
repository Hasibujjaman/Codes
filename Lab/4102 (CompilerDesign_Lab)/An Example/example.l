%{
#include "example.tab.h"
%}

%%
[0-9]+    { yylval = atoi(yytext); return NUMBER; }
[ \t\n]   ;  // Ignore whitespace
.         { return yytext[0]; }
%%
