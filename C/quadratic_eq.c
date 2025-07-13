#include<stdio.h>
int main()
{
    int a,b,c;
    float x1,x2,d;
    printf("Enter the coeffitient of x^2\n");
    scanf("%d",&a);
    printf("Enter the coeffitient of x\n");
    scanf("%d",&b);
    printf("Enter the constant number\n");
    scanf("%d",&c);
    d = sqrt(b*b-4*a*c); // sqrt returns double type value
    x1 = (-b+d)/2*a;
    x2 = (-b-d)/2*a;
    if(d>=0)    {
        printf("d = %f\n", d);
        printf("x1 = %.2f\nx2 = %.2f\n",x1,x2);
    }
    else printf("There is no real solution");      
}