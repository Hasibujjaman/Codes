%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s) { fprintf(stderr, "Error: %s\n", s); }
%}


%token SUB VRB ADJ OBJ
%start program



%%
program : stmt_list { printf("Accepted\n"); }
        ;

stmt_list : stmt
          | stmt_list stmt
          ;

stmt : SUB VRB ADJ OBJ
     ;
%%
int main() {
   return yyparse();
}
