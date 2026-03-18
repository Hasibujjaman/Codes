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
	void yyerror();
	extern int yylex();
%}


%token FUNCTION MAIN STARTKW ENDKW SUPPOSE IS
%token PRINT EQUAL ADDKW SUBKW
%token LPAREN RPAREN COMMA
%token<str_val> ID
%token<int_val> ICONST
%token<int_val> INTEGER

%left ADDKW SUBKW


%start program

%%
program: FUNCTION MAIN LPAREN RPAREN STARTKW statements ENDKW 
        { printf("Accepted\n"); }
        ;

statements: statements statement | /* empty */ ;

statement: decl
         | assignment
         | printstmt
         ;

decl: SUPPOSE ID IS INTEGER
      ;

assignment: ID EQUAL exp;

printstmt: PRINT LPAREN ID RPAREN
      ;

exp: ICONST

  | ID

  | exp ADDKW exp
  | exp SUBKW exp
  ;

%%



int main (int argc, char *argv[])
{
	yyparse();

	return 0;
}


void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}