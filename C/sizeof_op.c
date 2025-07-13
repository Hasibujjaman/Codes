#include <stdio.h>
int main()
{
    int l = sizeof(int); //type conversion will occur
    printf("An int takes up %d bytes\n", l);
    printf("A char takes up %lu bytes\n", sizeof(char));
    printf("A long int takes up %lu bytes\n", sizeof(long));
    printf("A float takes up %lu bytes\n", sizeof(float));
    printf("A double takes up %lu bytes\n", sizeof(double));
}