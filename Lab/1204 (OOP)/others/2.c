#include<stdio.h>
int main(){
    double x,y;
    printf("\nEnter two numbers\n");
    scanf("%lf %lf", &x,&y);
    if(x>y)
    printf("x is larger\n");
    else if(x<y)
    printf("y is larger\n");
    else
    printf("Equal\n");
    return 0;
}
