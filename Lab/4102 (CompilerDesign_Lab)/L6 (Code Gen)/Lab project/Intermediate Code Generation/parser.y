%{
// Roll: 2003001
//Q1.  Consider following Code Snippet:

// function main () 

// start

//        suppose A is an integer

//        suppose  B is an integer

//        A equal 2

//        B equal 3 add A sub 5

//        print(B)

// end

// Design Lexical Analysis, Syntax Analysis, Intermediate Code Generation and Code Generation part of compiler based on the code snippet.
%}

%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
    #include "symtab.c"
    #include "codeGen.c"
	void yyerror();
	extern int lineno;
	extern int yylex();
%}

%union
{
    char str_val[100];
    int int_val;
}

%token FUNCTION MAIN STARTKW ENDKW SUPPOSE IS
%token PRINT EQUAL ADDKW SUBKW
%token LPAREN RPAREN COMMA
%token<str_val> ID
%token<int_val> ICONST
%token<int_val> INTEGER

%left ADDKW SUBKW

%type<int_val> exp assignment printstmt decl

%start program

%%
program: { gen_code(START, -1); } FUNCTION MAIN LPAREN RPAREN STARTKW statements ENDKW { gen_code(HALT, -1); }
  ;

statements: statements statement | /* empty */ ;

statement: decl
         | assignment
         | printstmt
         ;

decl: SUPPOSE ID IS INTEGER
      {
        insert($2, $4);
      }
      ;

assignment: ID EQUAL exp
      {
        int address = idcheck($1);
        if(address != -1)
        {
            gen_code(STORE, address);
        }
        else yyerror();
      }
      ;

printstmt: PRINT LPAREN ID RPAREN
      {
        int address = idcheck($3);
        if(address != -1)
        {
            gen_code(PRINT_OP, address);
        }
        else yyerror();
      }
      ;

exp: ICONST
    {
        gen_code(LD_INT, $1);
    }
  | ID
    {
        int address = idcheck($1);
        if(address != -1) gen_code(LD_VAR, address);
        else yyerror();
    }
  | exp ADDKW exp { gen_code(ADD, -1); }
  | exp SUBKW exp { gen_code(SUB, -1); }
  ;

%%

void yyerror ()
{
	printf("Syntax error at line %d\n", lineno);
	exit(1);
}

int main (int argc, char *argv[])
{
	if(yyparse()==0)
        printf("Parsing finished!\n");

    printf("============= INTERMEDIATE CODE===============\n");
    print_code();

	return 0;
}
