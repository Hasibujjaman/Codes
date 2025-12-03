%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
    #include "symtab.c"
    #include "codeGen.c"
	void yyerror();
	extern int lineno;
	extern int yylex();

    int decl_type = UNDEF_TYPE; /* current declaration type */
    int current_if_label = -1;  /* carry IF label into else part */
%}

%union
{
    char str_val[256];
    int int_val;
    double float_val;
}

%token PRINT SCAN
%token ADDOP SUBOP MULOP DIVOP EQUOP LT GT AND OR
%token LPAREN RPAREN LBRACE RBRACE SEMI ASSIGN ELSE COMMA
%token DEF MAIN
%token CHECK_BALANCE
%token TRUE FALSE
%token<int_val> INT FLOAT BOOL REACTION IF WHILE
%token<str_val> ID STRING
%token<int_val> ICONST
%token<float_val> FCONST

%left OR
%left AND
%left LT GT EQUOP /* relational and equality */
%left ADDOP SUBOP
%left MULOP DIVOP

%nonassoc ELSE
%nonassoc IFX

%type<int_val> expr logical_exp relational_exp additive_exp multiplicative_exp primary reaction_literal check_balance_call
%type<int_val> type bool_literal
%type<int_val> M

%start program

%%
program
    : MAIN LBRACE top_stmts RBRACE { gen_code(HALT, -1); }
    ;

top_stmts
    : /* empty */ { gen_code(START, -1); }
    | top_stmts stmt
    ;

stmt_list
    : /* empty */
    | stmt_list stmt
    ;

stmt
    : declaration
    | assignment
    | print_stmt
    | scan_stmt
    | if_stmt
    | while_stmt
    ;

declaration
    : DEF type { decl_type = $2; } id_list SEMI
    ;

type
    : INT      { $$ = INT_TYPE; }
    | FLOAT    { $$ = REAL_TYPE; }
    | BOOL     { $$ = BOOL_TYPE; }
    | REACTION { $$ = REACTION_TYPE; }
    ;

id_list
    : ID                         { insert($1, decl_type); }
    | id_list COMMA ID           { insert($3, decl_type); }
    ;

assignment
    : ID ASSIGN expr SEMI
      {
        int address = idcheck($1);
        if(address != -1)
            gen_code(STORE, address);
        else yyerror();
      }
    ;

print_stmt
    : PRINT LPAREN ID RPAREN SEMI
      {
        int address = idcheck($3);
        if(address != -1)
            gen_code(PRINT_INT_VALUE, address);
        else yyerror();
      }
    ;

scan_stmt
    : SCAN LPAREN ID RPAREN SEMI
      {
        int address = idcheck($3);
        if(address != -1)
            gen_code(SCAN_INT_VALUE, address);
        else yyerror();
      }
    ;

expr
    : logical_exp
    ;

logical_exp
    : relational_exp
    | logical_exp AND relational_exp { gen_code(MUL, -1); /* boolean AND via multiply */ }
    | logical_exp OR  relational_exp { gen_code(ADD, -1); /* boolean OR via add (>0 true) */ }
    ;

relational_exp
    : additive_exp
    | relational_exp GT    additive_exp { gen_code(GT_OP, gen_label()); }
    | relational_exp LT    additive_exp { gen_code(LT_OP, gen_label()); }
    | relational_exp EQUOP additive_exp { gen_code(EQ_OP, gen_label()); }
    | LPAREN relational_exp RPAREN { /* allow parenthesized relational in place */ }
    ;

additive_exp
    : multiplicative_exp
    | additive_exp ADDOP multiplicative_exp { gen_code(ADD, -1); }
    | additive_exp SUBOP multiplicative_exp { gen_code(SUB, -1); }
    ;

multiplicative_exp
    : primary
    | multiplicative_exp MULOP primary { gen_code(MUL, -1); }
    | multiplicative_exp DIVOP primary { gen_code(DIV, -1); }
    ;

primary
    : ICONST             { gen_code(LD_INT, $1); }
    | ID                 { int address = idcheck($1); if(address!=-1) gen_code(LD_VAR, address); else yyerror(); }
    | FCONST             { /* float literal: treat as int truncated for now */ gen_code(LD_INT, (int)$1); }
    | bool_literal       { gen_code(LD_INT, $1); }
    | reaction_literal   { /* placeholder already emitted */ }
    | check_balance_call { /* LD_INT emitted in call */ }
    | LPAREN expr RPAREN { /* group */ }
    ;

bool_literal
    : TRUE { $$ = 1; }
    | FALSE { $$ = 0; }
    ;

reaction_literal
    : STRING { /* push placeholder for reaction value (address-independent) */ gen_code(LD_INT, 0); }
    ;

check_balance_call
    : CHECK_BALANCE LPAREN reaction_literal RPAREN { /* naive true for now */ gen_code(LD_INT, 1); }
    | CHECK_BALANCE LPAREN STRING RPAREN           { gen_code(LD_INT, 1); }
    | CHECK_BALANCE LPAREN ID RPAREN               { gen_code(LD_INT, 1); }
    ;

if_stmt
    : IF LPAREN expr RPAREN M { gen_code(IF_START, $5); } block else_part { gen_code(ELSE_END, $5); }
    ;

else_part
    : ELSE { gen_code(ELSE_START, current_if_label); } block
    | /* empty */ { gen_code(ELSE_START, current_if_label); }
    ;

block
    : LBRACE stmt_list RBRACE
    ;

while_stmt
    : WHILE M { gen_code(WHILE_LABEL, $2); } LPAREN expr RPAREN { gen_code(WHILE_START, $2); } block { gen_code(WHILE_END, $2); }
    ;

M
    : /* empty */ { $$ = gen_label(); current_if_label = $$; }
    ;

%%

void yyerror ()
{
	printf("Syntax error at line %d\n", lineno);
	exit(1);
}

int main (int argc, char *argv[])
{
	yyparse();
	printf("Parsing finished!\n");

    printf("============= INTERMEDIATE CODE===============\n");
    print_code();

    printf("============= ASM CODE===============\n");
    print_assembly();

	return 0;
}
