#include<stdio.h>
int main(){
    int num1,num2,temp,gcd,lcm,multi;
    scanf("%d %d",&num1,&num2);
    multi=num1*num2;
    while(num1!=0){
        temp=num1;
        num1=num2%num1;
        num2=temp;
    }
    gcd = num2;
    lcm=multi/gcd;
    printf("%d %d\n",gcd,lcm);
    return 0;
}