%{
#include<stdio.h>
void yyerror(char *s);
int yylex();

%}
%token NUM ADD SUB IF ELSE WHILE ID LP RP LB RB EQUAL ASSIGN SEMI INT
%start statements

%%
statements: statements statement
           |
           ;
           
statement: IF LP exp RP LB statements RB ELSE LB statements RB
          | IF LP exp RP LB statements RB 
          | WHILE LP exp RP LB statements RB
          | id_declare
          ;

exp: exp EQUAL exp
    | exp ADD exp
    | exp SUB exp
    | ID
    | NUM
    ;

id_declare: INT ID ASSIGN NUM SEMI
           | ID ASSIGN exp SEMI
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