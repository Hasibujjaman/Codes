#include<stdio.h>
int main(){
    int N,i,sum;
    scanf("%d",&N);
    i=1,sum=0;
    while(i<=N){
        sum=sum+i;
        i++;   
    }
    printf("%d\n",sum);
    return 0;
}