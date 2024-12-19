#include<stdio.h>
int main(){
    int a,b,gcd,lcm;
    scanf("%d %d",&a,&b);
    int i;
    if(a>b){
        for(i=b;i>=1;i--){
            if(a%i==0&&b%i==0){
                gcd=i;
                break;
            }
        }
    }
    else{
        for(i=a;i>=1;i--){
            if(a%i==0&&b%i==0){
                gcd=i;
                break;
            }
        }
    }
    lcm=(a*b)/gcd;
    printf("GCD: %d\tLCM: %d\n",gcd,lcm);
    return 0;
}