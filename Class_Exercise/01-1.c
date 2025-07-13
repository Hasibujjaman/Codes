#include<stdio.h>
int main(){
    double C,F;
    printf("Celsius = ");
    scanf("%lf",&C);
    F = 9*C/5+32;
    printf("Fahrenheit = %.2lf\n",F);
    return 0;
}