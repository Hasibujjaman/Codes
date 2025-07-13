#include<stdio.h>
int main(){
    double USD,BDT,rate;
    printf("Enter USD amount = ");
    scanf("%lf",&USD);
    printf("Enter exchange rate = ");
    scanf("%lf",&rate);
    BDT = rate*USD;
    printf("BDT = %.2lf\n",BDT);
    return 0;
}