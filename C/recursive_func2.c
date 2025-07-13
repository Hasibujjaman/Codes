#include<stdio.h>
int fib(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",fib(n-1));
    return 0;
}
/*
0 1 1 2 3 5 8 13
1 2 3 4 5 6 7 8 
*/