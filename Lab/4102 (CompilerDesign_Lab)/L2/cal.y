%{
    #include<stdio.h>

    void yyerror(const char *s);
    int yylex();
%}

%token NUM ADD SUB MUL ID ASS LT EQ INC STRING INT IF ELSE WHILE PRINTF LP RP LB RB SEMI COMMA
%start program








%%

program: statement_list
    ;

statement_list: statement_list statement
    | statement
    ;

statement: declaration SEMI
    | assignment SEMI
    | if_statement
    | while_statement
    | expression_statement SEMI
    ;

declaration: INT ID ASS expression
    | INT ID
    ;

assignment: ID ASS expression
    ;

if_statement: IF LP expression RP LB statement_list RB
    | IF LP expression RP LB statement_list RB ELSE LB statement_list RB
    | IF LP expression RP LB statement_list RB ELSE if_statement
    ;

while_statement: WHILE LP expression RP LB statement_list RB
    ;

expression_statement: function_call
    | ID INC
    ;

function_call: PRINTF LP STRING RP
    | PRINTF LP STRING COMMA expression RP
    ;

expression: expression LT expression
    | expression EQ expression
    | expression ADD expression
    | expression SUB expression
    | expression MUL expression
    | ID
    | NUM
    | LP expression RP
    ;

%%

int main(){
    yyparse();
    printf("Parsing Finished\n");

}

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}