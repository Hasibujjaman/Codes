%option noyywrap

%{
#include "prog.tab.h"
#include <stdio.h>
%}


letter [A-Za-z]
subject He|I|YOU
verb HAS|HAVE|HAD
adj two|three|four
object \$({letter}+)\$

delim [ \t\n]
ws {delim}+


%%
{subject} {return SUB;}
{verb} {return VRB;}
{adj} {return ADJ;}
{object} {return OBJ;}
{ws} {}
%%
