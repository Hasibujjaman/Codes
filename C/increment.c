#include<stdio.h>
int main()
{   
    int x = 10;
    int y = ++x; // pre increment
    printf("x = %d\n", x); 
    printf("y = %d\n", y);
    x = 10;
    y = x++; //post increment
    printf("x = %d\n", x); 
    printf("y = %d\n", y); 
    x = 10;
    printf("x = %d\n", x++); 
    printf("x = %d\n", x); 
    printf("x = %d\n", ++x); 
    printf("x = %d\n", x); 
    printf("x = %d\n", x--); 
    printf("x = %d\n", --x); 

}