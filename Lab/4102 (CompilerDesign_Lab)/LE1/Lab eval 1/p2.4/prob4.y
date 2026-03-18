%{
#include <stdio.h>
#include <stdlib.h>

#define yylex rolllex   /* Bison will call rolllex() from Flex */

void yyerror(const char *s);
%}

%union {
    char* str;
}

%token <str> ROLL_NUMBER

%%

input:
      /* empty */
    | input roll_stmt
    ;

roll_stmt:
      ROLL_NUMBER { 
          printf("Accepted roll number: %s\n", $1); 
          free($1); 
      }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter roll numbers: \n");
    yyparse();
    return 0;
}
