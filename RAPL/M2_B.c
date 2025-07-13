#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    int sum=0;
    int i;
    for(i=1;i<=5;i++){
        sum+=num-(num/10)*10;
        num=num/10;
    }
    printf("%d\n",sum);
    return 0;
}