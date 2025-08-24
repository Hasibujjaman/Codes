%{
#include<stdio.h>
void yyerror(char *s);
int yylex();

%}
%token NUM ADD SUB
%start cal

%%
cal: exp { $$ = $1; printf("=%d\n", $$);}
   ;
exp: exp ADD NUM {$$ = $1 + $3;}
 | exp SUB NUM {$$ = $1 - $3;}
 | NUM {$$ = $1;}
 ;

%%


int main(){

    yyparse();
    printf("Parsing Finished\n");
}

void yyerror(char *s)
{
    fprintf(stderr, "error: %s\n", s);
}