%option noyywrap

%{
#include "prog.tab.h"
#include <stdio.h>
%}


%%
"RUET"          { printf("%s -> UNIVERSITY\n", yytext); return UNIVERSITY; }
"CUET"          { printf("%s -> UNIVERSITY\n", yytext); return UNIVERSITY; }
"BUET"          { printf("%s -> UNIVERSITY\n", yytext); return UNIVERSITY; }
"University"    { printf("%s -> UNIVERSITY_NAME\n", yytext); return UNIVERSITY_NAME; }
"of"            { printf("%s -> OF\n", yytext); return OF; }
"CSE"           { printf("%s -> DEPT\n", yytext); return DEPT; }
"EEE"           { printf("%s -> DEPT\n", yytext); return DEPT; }

[0-9]{1,3}      { printf("%s -> NUMBER\n", yytext); return NUMBER; }
":"             { printf("%s -> COLON\n", yytext); return COLON; }
"-"             { printf("%s -> DASH\n", yytext); return DASH; }
"Series"        { printf("%s -> SERIES\n", yytext); return SERIES; }
"Department_Codes" { printf("%s -> DEPT_CODE\n", yytext); return DEPT_CODE; }
"Roll_Numbers"  { printf("%s -> ROLL_NUM\n", yytext); return ROLL_NUM; }

[ \t\n]+        ;   // ignore whitespace
.   { /* ignore any truly unknown single char */ }

%%
