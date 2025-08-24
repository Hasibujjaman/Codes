%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s) { fprintf(stderr, "Error: %s\n", s); }
%}

%union {
   int ival;
}

%token <ival> NUMBER
%token UNIVERSITY UNIVERSITY_NAME DEPT SERIES DEPT_CODE ROLL_NUM OF
%token COLON DASH

%start program

%%
program : stmt_list { printf("Accepted\n"); }
        ;

stmt_list : stmt
          | stmt_list stmt
          ;

stmt : UNIVERSITY DEPT NUMBER
     | UNIVERSITY_NAME OF UNIVERSITY_NAME
     | UNIVERSITY_NAME
     | NUMBER DASH NUMBER
     | SERIES COLON NUMBER "series" "to" NUMBER "series"
     | DEPT_CODE COLON NUMBER "to" NUMBER
     | ROLL_NUM COLON NUMBER "to" NUMBER
     ;
%%
int main() {
   return yyparse();
}
