%{
    #include<stdio.h>

    void yyerror(const char *s);
    int yylex();
%}

%token NUM ADD SUB MUL ID ASS 
%start S








%%
S: exp | V;

exp: exp ADD NUM
    |exp SUB NUM
    |exp MUL NUM
    |ID
    |NUM
    ;
V: ID ASS exp

%%

int main(){
    yyparse();
    printf("Parsing Finished\n");

}

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}