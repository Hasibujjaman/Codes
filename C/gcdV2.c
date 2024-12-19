#include<stdio.h>
int main(){
    int num1,num2,temp,gcd;
    scanf("%d %d",&num1,&num2);
    while(num1!=0){
        temp=num1;
        num1=num2%num1;
        num2=temp;
    }
    printf("%d\n",num2);
    return 0;
}