/* * parser.y: Bison parser for the Sci-PL language
 */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Abstract Syntax Tree (AST) Node Structure --- */
/* This is a simplified AST node, inspired by syllabus examples [cite: 371] */
typedef struct Node {
    char *nodeType;     /* Type of the node (e.g., "IF", "+", "ID") */
    char *sValue;       /* For T_ID, T_REACTION_LITERAL */
    double fValue;      /* For T_FLOAT_LITERAL */
    int iValue;         /* For T_INT_LITERAL */
    
    struct Node *left;  /* Left child */
    struct Node *mid;   /* Middle child (for IF-ELSE) */
    struct Node *right; /* Right child */
} Node;

/* --- AST Helper Functions --- */
Node* makeNode(char *type, Node *left, Node *right, Node *mid);
Node* makeLeaf_s(char *type, char *sval); /* String leaf */
Node* makeLeaf_i(char *type, int ival);   /* Int leaf */
Node* makeLeaf_f(char *type, double fval); /* Float leaf */
void printTree(Node *node, int indent);

/* --- External Declarations --- */
extern int yylex();     /* The lexer function */
extern int yylineno;    /* From lexer */
void yyerror(const char *s); /* Error reporting function */

Node *astRoot = NULL;   /* Global pointer to the root of the AST */

%}

/* --- YACC/BISON Declarations --- */

/* * The %union defines the yylval variable used by the lexer and parser
 * to pass values.
 */
%union {
    int iValue;         /* Integer value */
    double fValue;      /* Float value */
    char *sValue;       /* String value (for ID, REACTION) */
    struct Node *nValue; /* Pointer to an AST node */
}

/* * --- Token Definitions ---
 * We must specify which union field each token uses.
 */
%token <sValue> T_ID T_REACTION_LITERAL
%token <iValue> T_INT_LITERAL
%token <fValue> T_FLOAT_LITERAL

%token T_MAIN T_DEF
%token T_INT T_FLOAT T_BOOL T_REACTION
%token T_IF T_ELSE T_WHILE
%token T_CHECK_BALANCE

%token T_ASSIGN
%token T_PLUS T_MINUS T_STAR T_SLASH
%token T_GT T_LT T_AND T_OR
%token T_LBRACE T_RBRACE T_LPAREN T_RPAREN
%token T_SEMICOLON T_COMMA

/* * --- Non-Terminal Type Definitions ---
 * We specify that these grammar rules return an AST node.
 */
%type <nValue> Program BlockList Block MainBlock Statements Statement
%type <nValue> Declaration Type VarList Assignment IfStatement WhileStatement
%type <nValue> Expression LogicalTerm RelationalExpr ArithmeticExpr Term Factor
%type <nValue> FunctionCall

/* * --- Operator Precedence and Associativity ---
 * This is crucial for parsing expressions correctly.
 */
%left T_OR
%left T_AND
%left T_GT T_LT  /* Relational ops [cite: 506] */
%left T_PLUS T_MINUS
%left T_STAR T_SLASH
%right UMINUS     /* Unary minus (not in spec, but in syllabus [cite: 28]) */

/* --- Start Symbol --- */
%start Program

%%
/* --- Grammar Rules --- */

/* * The top-level structure. Based on the source code ,
 * a program is a list of blocks (main, if, while).
 */
Program: BlockList 
    { 
        $$ = $1; 
        astRoot = $$; /* Save the root for main() */
    }
;

BlockList: BlockList Block
    { 
        $$ = makeNode("BLOCK_LIST", $1, $2, NULL); 
    }
    | %empty
    {
        $$ = NULL;
    }
;

Block: MainBlock     { $$ = $1; }
     | IfStatement   { $$ = $1; }
     | WhileStatement { $$ = $1; }
;

MainBlock: T_MAIN T_LBRACE Statements T_RBRACE
    {
        $$ = makeNode("MAIN_BLOCK", $3, NULL, NULL);
    }
;

/* A list of statements inside a block */
Statements: Statements Statement
    {
        $$ = makeNode("STMT_LIST", $1, $2, NULL);
    }
    | %empty
    {
        $$ = NULL;
    }
;

/* Individual statement types */
Statement: Declaration     { $$ = $1; }
         | Assignment      { $$ = $1; }
         | IfStatement     { $$ = $1; }
         | WhileStatement  { $$ = $1; }
;

/* Variable Declaration: def type id, id, ... ; [cite: 551] */
Declaration: T_DEF Type VarList T_SEMICOLON
    {
        $$ = makeNode("DECLARATION", $2, $3, NULL);
    }
;

Type: T_INT      { $$ = makeNode("TYPE_INT", NULL, NULL, NULL); }
    | T_FLOAT    { $$ = makeNode("TYPE_FLOAT", NULL, NULL, NULL); }
    | T_BOOL     { $$ = makeNode("TYPE_BOOL", NULL, NULL, NULL); }
    | T_REACTION { $$ = makeNode("TYPE_REACTION", NULL, NULL, NULL); }
;

/* Variable list (left-recursive for efficiency) */
VarList: VarList T_COMMA T_ID
    {
        $$ = makeNode("VAR_LIST", $1, makeLeaf_s("ID", $3), NULL);
        /* $3 is freed by makeLeaf_s */
    }
    | T_ID
    {
        $$ = makeLeaf_s("ID", $1);
        /* $1 is freed by makeLeaf_s */
    }
;

/* Assignment: id = expression; [cite: 552] */
Assignment: T_ID T_ASSIGN Expression T_SEMICOLON
    {
        $$ = makeNode("=", makeLeaf_s("ID", $1), $3, NULL);
        /* $1 is freed by makeLeaf_s */
    }
;

/* If-Else Statement [cite: 509, 553] */
IfStatement: T_IF T_LPAREN Expression T_RPAREN T_LBRACE Statements T_RBRACE T_ELSE T_LBRACE Statements T_RBRACE
    {
        $$ = makeNode("IF_ELSE", $3, $6, $9); /* (cond, then, else) */
    }
    /* Dangling-else is handled by default (shift) */
    | T_IF T_LPAREN Expression T_RPAREN T_LBRACE Statements T_RBRACE
    {
        $$ = makeNode("IF", $3, $6, NULL); /* (cond, then) */
    }
;

/* While Statement [cite: 509, 553] */
WhileStatement: T_WHILE T_LPAREN Expression T_RPAREN T_LBRACE Statements T_RBRACE
    {
        $$ = makeNode("WHILE", $3, $6, NULL); /* (cond, body) */
    }
;

/* --- Expressions --- */
/* Based on precedence rules */
Expression: LogicalTerm
    { $$ = $1; }
;

LogicalTerm: LogicalTerm T_OR LogicalTerm
    {
        $$ = makeNode("||", $1, $3, NULL);
    }
    | LogicalTerm T_AND LogicalTerm
    {
        $$ = makeNode("&&", $1, $3, NULL);
    }
    | RelationalExpr
    {
        $$ = $1;
    }
;

RelationalExpr: ArithmeticExpr T_GT ArithmeticExpr
    {
        $$ = makeNode(">", $1, $3, NULL);
    }
    | ArithmeticExpr T_LT ArithmeticExpr
    {
        $$ = makeNode("<", $1, $3, NULL);
    }
    | ArithmeticExpr
    {
        $$ = $1;
    }
;

ArithmeticExpr: ArithmeticExpr T_PLUS ArithmeticExpr
    {
        $$ = makeNode("+", $1, $3, NULL);
    }
    | ArithmeticExpr T_MINUS ArithmeticExpr
    {
        $$ = makeNode("-", $1, $3, NULL);
    }
    | Term
    {
        $$ = $1;
    }
;

Term: Term T_STAR Term
    {
        $$ = makeNode("*", $1, $3, NULL);
    }
    | Term T_SLASH Term
    {
        $$ = makeNode("/", $1, $3, NULL);
    }
    | Factor
    {
        $$ = $1;
    }
;

Factor: T_LPAREN Expression T_RPAREN
    {
        $$ = $2; /* Pass the expression node up */
    }
    | T_MINUS Factor %prec UMINUS
    {
        $$ = makeNode("UMINUS", $2, NULL, NULL);
    }
    | T_ID
    {
        $$ = makeLeaf_s("ID", $1);
    }
    | T_INT_LITERAL
    {
        $$ = makeLeaf_i("INT_LIT", $1);
    }
    | T_FLOAT_LITERAL
    {
        $$ = makeLeaf_f("FLOAT_LIT", $1);
    }
    | T_REACTION_LITERAL
    {
        $$ = makeLeaf_s("REACTION_LIT", $1);
    }
    | FunctionCall
    {
        $$ = $1;
    }
;

/* Function Call: check_balance(expr) [cite: 512, 555] */
FunctionCall: T_CHECK_BALANCE T_LPAREN Expression T_RPAREN
    {
        $$ = makeNode("CALL_check_balance", $3, NULL, NULL);
    }
;

%%
/* --- C Code Section (Epilogue) --- */

/*
 * Main function: Entry point
 */
int main(int argc, char **argv) {
    /* Open the input file if provided, otherwise read from stdin */
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) {
            perror(argv[1]);
            return 1;
        }
        yyin = fp;
    }

    printf("--- Starting Sci-PL Parse ---\n");
    if (yyparse() == 0) {
        printf("--- Parse Successful ---\n\n");
        printf("--- Abstract Syntax Tree (AST) ---\n");
        printTree(astRoot, 0);
    } else {
        printf("--- Parse Failed ---\n");
    }
    
    return 0;
}

/*
 * Error reporting function
 */
void yyerror(const char *s) {
    fprintf(stderr, "PARSE ERROR: %s at line %d\n", s, yylineno);
}


/* --- AST Helper Function Definitions --- */

/* Generic node constructor */
Node* makeNode(char *type, Node *left, Node *right, Node *mid) {
    Node *n = (Node*) malloc(sizeof(Node));
    if (!n) {
        yyerror("out of memory");
        exit(1);
    }
    n->nodeType = strdup(type);
    n->sValue = NULL;
    n->iValue = 0;
    n->fValue = 0.0;
    n->left = left;
    n->mid = mid;
    n->right = right;
    return n;
}

/* String leaf node constructor */
Node* makeLeaf_s(char *type, char *sval) {
    Node *n = makeNode(type, NULL, NULL, NULL);
    n->sValue = sval; /* Note: sval was strdup'd in lexer */
    return n;
}

/* Int leaf node constructor */
Node* makeLeaf_i(char *type, int ival) {
    Node *n = makeNode(type, NULL, NULL, NULL);
    n->iValue = ival;
    return n;
}

/* Float leaf node constructor */
Node* makeLeaf_f(char *type, double fval) {
    Node *n = makeNode(type, NULL, NULL, NULL);
    n->fValue = fval;
    return n;
}

/* Simple recursive function to print the AST */
void printTree(Node *node, int indent) {
    if (!node) return;

    for (int i = 0; i < indent; i++) printf("  ");
    
    printf("%s", node->nodeType);
    if (node->sValue) printf(" (%s)", node->sValue);
    if (node->nodeType == "INT_LIT") printf(" (%d)", node->iValue);
    if (node->nodeType == "FLOAT_LIT") printf(" (%f)", node->fValue);
    printf("\n");

    printTree(node->left, indent + 1);
    printTree(node->mid, indent + 1);
    printTree(node->right, indent + 1);
}