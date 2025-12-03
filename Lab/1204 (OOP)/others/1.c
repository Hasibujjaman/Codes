#include<stdio.h>
int main(){
    double x;
    printf("\nEnter a number\n");
    scanf("%lf",&x);
    if(x>0) 
        printf("Positive\n");
    else if(x<0) 
        printf("Negative\n");
    else
        printf("Equal\n");
    return 0;
}
