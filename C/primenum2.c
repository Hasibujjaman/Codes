#include<stdio.h>
int prime(int n){
    int i;
    if(n<2) return 0;
    for(i=2;i<n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int main(){
    int n;
    while(1){
        printf("Enter a number (Enter 0 to exit): ");
        scanf("%d",&n);
        if(n==0) break;
        else if(1==prime(n)) printf("%d is a prime number\n",n);
        else printf("%d is not a prime number\n",n);
    }
    return 0;
}
