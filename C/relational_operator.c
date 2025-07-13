#include<stdio.h>
int main()
{
    float x;
    printf("Enter your mark\n");
    scanf("%f",&x);
    if(x>=80)
    printf("Your grade is A+");
    else if(x>=70)
    printf("Your grade is A");
    else if(x>=60)
    printf("Your grade is A-");
    else if(x>=50)
    printf("Your grade is B");
    else if(x>=40)
    printf("Your grade is C");
    else if(x>=33)
    printf("Your grade is D");
    else
    printf("Your grade is F");
    return 0;

}