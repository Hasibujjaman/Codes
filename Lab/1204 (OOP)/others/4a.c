#include<stdio.h>
int main(){
    int n=5;
    int ara[n];
    int highest=-100000,lowest=100000;
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&ara[i]);
    }
    for(i=0;i<n;i++){
        if(ara[i]>highest) highest=ara[i];
        if(ara[i]<lowest) lowest=ara[i];
    }
    printf("%d %d\n",highest,lowest);
    return 0;
}