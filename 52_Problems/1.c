#include<stdio.h>
int main(){
    int T,n;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&n);
        if(n%2==0)
            printf("Even\n");
        else 
            printf("Odd\n");
    }
    return 0;
}