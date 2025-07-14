%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER

%%
expr:   expr '+' term  { printf("Add\n"); }
    |   term
    ;

term:   NUMBER { printf("Number: %d\n", $1); }
    ;
%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}
