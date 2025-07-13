#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i;
    printf("I hate ");
    for(i=2;i<=n;i++){
        if(i%2==0) printf("that I love ");
        else printf("that I hate ");
    }
    printf("it\n");
    return 0;
}