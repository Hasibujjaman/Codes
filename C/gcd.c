//Noob's GCD
#include<stdio.h>
int main(){
    int a,b,i,gcd;
    scanf("%d %d",&a,&b);
    if(a>b){
        for(i=b;i>=1;i--){
            if(a%i==0&&b%i==0){
                gcd=i;
                break;
            }
        }
    }
    else if(a<b){
        for(i=a;i>=1;i--){
            if(a%i==0&&b%i==0){
                gcd=i;
                break;
            }
        }
    }
    else gcd =a;
    printf("%d\n",gcd);
    return 0;
}