enum code_ops 
{
    START, 
    HALT, 
    LD_INT, 
    LD_VAR, 
    STORE, 
    PRINT_INT_VALUE, 
    ADD,
    SUB
};

static const char *op_name[] = {"start", "halt", "ld_int", "ld_var", "store", "print_int_value", "add", "sub"};

struct instruction
{
    enum code_ops op;
    int arg;
};

extern int address;

void gen_code(enum code_ops op, int arg);
void print_code();
void print_assembly();

// char if_label[]="IF_LABEL";
// char else_label[]="ELSE_LABEL";

// typedef struct if_while
// {
//     int label;
// }if_while;

// if_while *new_if_while()
// {
//     return (if_while*) malloc (sizeof(if_while));
// }