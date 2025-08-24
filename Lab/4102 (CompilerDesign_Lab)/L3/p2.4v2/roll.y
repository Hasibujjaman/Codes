%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror(const char *s) { fprintf(stderr, "Rejected\n"); }

int check_roll(char *roll) {
    char series[3], dept[3], rollnum[4];
    strncpy(series, roll, 2); series[2] = '\0';
    strncpy(dept, roll+2, 2); dept[2] = '\0';
    strncpy(rollnum, roll+4, 3); rollnum[3] = '\0';

    int s = atoi(series);
    int d = atoi(dept);
    int r = atoi(rollnum);

    if (s >= 16 && s <= 20 && d >= 0 && d <= 10 && r >= 1 && r <= 180)
        return 1;
    return 0;
}
%}

%union {
   char* sval;
}

%token <sval> ROLL_STRING
%start program

%%
program : roll_list
        ;

roll_list : roll_list roll_number
          | roll_number
          ;

roll_number : ROLL_STRING {
                if (check_roll($1))
                    printf("%s -> Accepted\n", $1);
                else
                    printf("%s -> Rejected\n", $1);
             }
           ;

%%
int main() {
   return yyparse();
}
