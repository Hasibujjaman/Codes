#include<stdio.h>
int main(){
    unsigned long x,balance;
    int r=1;
    balance=100;
    int y;
    scanf("%lu",&x);
    for(y=0;balance<x;y++){
        balance+=(balance*r)/100;
    }
    printf("%d\n",y);
    return 0;
}