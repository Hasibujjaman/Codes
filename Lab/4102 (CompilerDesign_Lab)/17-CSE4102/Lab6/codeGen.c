#include "codeGen.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static struct instruction code[1024];
static int code_offset = 0;

void gen_code(enum code_ops op, int arg)
{
    code[code_offset].op = op;
    code[code_offset].arg = arg;
    code_offset++;
}

void print_code()
{
    for(int i=0; i<code_offset; i++)
    {
        printf("%3d: %-15s  %4d\n", i, op_name[code[i].op], code[i].arg);
    }
}

void print_assembly()
{
    printf("; Pseudo assembly (stack machine)\n");
    for(int i=0; i<code_offset; i++)
    {
        switch(code[i].op)
        {
            case START:
                printf("BEGIN\n");
                break;
            case HALT:
                printf("END\n");
                break;
            case LD_INT:
                printf("PUSH %d\n", code[i].arg);
                break;
            case LD_VAR:
                printf("LOAD v%d\n", code[i].arg);
                break;
            case STORE:
                printf("STORE v%d\n", code[i].arg);
                break;
            case PRINT_INT_VALUE:
                printf("PRINT v%d\n", code[i].arg);
                break;
            case ADD:
                printf("ADD\n");
                break;
            case SUB:
                printf("SUB\n");
                break;
            default:
                break;
        }
    }
}
