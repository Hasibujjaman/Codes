#include<stdio.h>
int main(){
    int a=0,b=1,n=6;
    int sum=0;
    char fib[n];
    int i,j;
    fib[0]=1;
    for(i=1;i<n;i++){
        sum=a+b;
        fib[i]=sum;
        a=b;
        b=sum;
    }
    printf("\n");
    for(i=0;i<6;i++){
        for(j=1;j<=fib[i];j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}