#include<stdio.h>
int main()
{
    int num1;
    float num2;
    double num3;
    char i;
    printf("Enter 3 numbers and the intial of your name ");
    scanf("%d %f %lf %c", &num1, &num2, &num3, &i);
    printf("You have entered %d %f %lf %c \n", num1, num2, num3, i);
    return 0; 
}