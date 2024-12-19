#include<stdio.h>
int main(){
    int A,B;
    scanf("%d %d",&A,&B);
    if(A>0){
        if(B>0) printf("Alloy\n");
        else printf("Gold\n");
    }
    else printf("Silver\n");
    return 0;
}