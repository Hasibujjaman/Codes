enum code_ops 
{
    START,
    HALT,
    LD_INT,
    LD_VAR,
    STORE,
    PRINT_OP,
    ADD,
    SUB
};

char *op_name[] = {"start", "halt", "ld_int", "ld_var", "store", "print", "add", "sub"};

struct instruction
{
    enum code_ops op;
    int arg;
};

struct instruction code[999];
int code_offset = 0;
extern int address;