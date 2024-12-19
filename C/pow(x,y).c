#include<stdio.h>
#include<math.h>
int main()
{
    int x,y;
    double z;
    printf("Enter base = ");
    scanf("%d",&x);
    printf("Enter power = ");
    scanf("%d",&y);
    z = pow(x,y);
    printf("The result is = %lf",z);
}