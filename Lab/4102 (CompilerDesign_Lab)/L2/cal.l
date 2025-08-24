%option noyywrap

%{
#include "cal.tab.h"
%}

digit [0-9]
number ({digit}+)
letter [A-Za-z]
id {letter}({letter}|{digit})*
string_literal \"[^"]*\"

delim [ \t\n]
ws {delim}+



%%

{number} {return NUM;}
"+" {return ADD;}
"-" {return SUB;}
"*" {return MUL;}
"=" {return ASS;}
"<" {return LT;}
"==" {return EQ;}
"++" {return INC;}
{id} {return ID;}
{string_literal} {return STRING;}
"int" {return INT;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"printf" {return PRINTF;}
"(" {return LP;}
")" {return RP;}
"{" {return LB;}
"}" {return RB;}
";" {return SEMI;}
"," {return COMMA;}

{ws} {}

%%

