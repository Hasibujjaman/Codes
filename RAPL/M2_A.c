#include<stdio.h>
int main(){
    unsigned long a,b;
    scanf("%lu %lu",&a,&b);
    unsigned long i,sum=0;
    for(i=a;i<=b;i++){
        if(i%2!=0) sum+=i;
    }
    printf("%lu\n",sum);
    return 0;
}