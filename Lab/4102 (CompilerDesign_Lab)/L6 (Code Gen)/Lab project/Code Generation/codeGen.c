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


#include <stdio.h>
#include "codeGen.h"

void print_assembly();

void gen_code(enum code_ops op, int arg)
{
    code[code_offset].op = op;
    code[code_offset].arg = arg;

    code_offset++;
}

void print_code()
{
    int i = 0;
    for(i=0; i<code_offset; i++)
    {
        printf("%3d: %-15s  %4d\n", i, op_name[code[i].op], code[i].arg);
    }
}

void print_assembly()
{
    int i = 0;
    int j = 0;
    int stack_variable_counter = 0;

    for(i=0; i<code_offset; i++)
    {
        printf("\n;%s %d\n", op_name[code[i].op], code[i].arg);

        if(code[i].op == LD_INT || code[i].op == LD_VAR)
            stack_variable_counter++;
        if(code[i].op == ADD || code[i].op == SUB)
            stack_variable_counter--;

        switch(code[i].op)
        {
            case START:
                            printf(".686\n");
                            printf(".model flat, c\n");
                            printf("include C:\\masm32\\include\\msvcrt.inc\n");
                            printf("includelib C:\\masm32\\lib\\msvcrt.lib\n");
                            printf("\n.stack 100h\n");
                            printf("printf PROTO arg1:Ptr Byte, printlist:VARARG\n");
                            printf("\n.data\n");
                            printf("output_integer_msg_format byte \"%%d\", 0Ah, 0\n");
                            printf("number sdword ?\n\n");
                            printf(".code\n\n");
                            printf("main proc\n");
                            printf("\tpush ebp\n");
                            printf("\tmov ebp, esp\n");
                            printf("\tsub ebp, 100\n");
                            printf("\tmov ebx, ebp\n");
                            printf("\tadd ebx, 4\n");
                            break;

            case HALT:
                            printf("\tadd ebp, 100\n");
                            printf("\tmov esp, ebp\n");
                            printf("\tpop ebp\n");
                            printf("\tret\n");
                            printf("main endp\n");
                            printf("end\n");
                            break;

            case STORE:
                            printf("\tmov dword ptr [ebp-%d], eax\n", 4*code[i].arg);
                            break;

            case PRINT_OP:
                            printf("\tpush eax\n");
                            printf("\tpush ebx\n");
                            printf("\tpush ecx\n");
                            printf("\tpush edx\n");
                            printf("\tpush ebp\n");

                            printf("\tmov eax, [ebp-%d]\n", 4*code[i].arg);
                            printf("\tINVOKE printf, ADDR output_integer_msg_format, eax\n");

                            printf("\tpop ebp\n");
                            printf("\tpop edx\n");
                            printf("\tpop ecx\n");
                            printf("\tpop ebx\n");
                            printf("\tpop eax\n");
                            break;

            case LD_VAR:
                            printf("\tmov eax, [ebp-%d]\n", 4*code[i].arg);
                            printf("\tmov dword ptr [ebx], eax\n");
                            printf("\tadd ebx, 4\n\n");
                            break;

            case LD_INT:
                            printf("\tmov eax, %d\n", code[i].arg);
                            printf("\tmov dword ptr [ebx], eax\n");
                            printf("\tadd ebx, 4\n\n");
                            break;

            case ADD:
                            printf("\tsub ebx, 4\n");
                            printf("\tmov eax, [ebx]\n");
                            printf("\tsub ebx, 4\n");
                            printf("\tmov edx, [ebx]\n");
                            printf("\tadd eax, edx\n");
                            printf("\tmov dword ptr [ebx], eax\n");
                            printf("\tadd ebx, 4\n\n");
                            break;

            case SUB:
                            printf("\tsub ebx, 4\n");
                            printf("\tmov eax, [ebx]\n");
                            printf("\tsub ebx, 4\n");
                            printf("\tmov edx, [ebx]\n");
                            printf("\tsub edx, eax\n");        // edx = left - right
                            printf("\tmov eax, edx\n");         // result in eax (consistent with ADD)
                            printf("\tmov dword ptr [ebx], eax\n");
                            printf("\tadd ebx, 4\n\n");
                            break;

            default:
                            break;
        }
    }
}