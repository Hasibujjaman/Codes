#include<stdio.h>
int main(){
    int i,j;
    printf("\n\n\n");
    for(i=7;i>=1;i--){
        for(j=i;j>=1;j--) printf("C");
        printf("\n");
    }
    for(i=2;i<=7;i++){
        for(j=i;j>=1;j--) printf("C");
        printf("\n");
    }
    printf("\n\n\n");
    return 0;
}