#include<stdio.h>
int main()
{
    int num1,num2;
    float avg;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    avg = (num1 + num2) / 2;
    printf("The average of the numbers without type casting is = %.2f\n", avg);
    printf("The average of the numbers with type casting is = %.2f\n", (float)(num1 + num2)/2); //type casting
    getch();
}
