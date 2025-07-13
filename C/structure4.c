#include <stdio.h>
/* Define a structure type. */
struct struct_type  // should be globally declared for it to be visible to all the function and for the functions to be able to use it
{
    int a, b;
    char ch;
};

void f1(struct struct_type parm); // structure type name must match

int main(void)
{
    struct struct_type arg;
    arg.a = 1000;
    f1(arg);
    printf("%d\n", arg.a);
    return 0;
}
void f1(struct struct_type parm) // structure type name must match
{
    parm.a = 500; // call by value
    printf("%d\n", parm.a);
}