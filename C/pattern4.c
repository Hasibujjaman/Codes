#include<stdio.h>
int main(){
    int i,j;
    printf("\n\n\n");
    for(i=1;i<=10;i++){
        for(j=1;j<=20;j++){
            if(j>i&&j<=20-i) printf(" ");
            else printf("C");
        }
        printf("\n");
    }
    printf("\n\n\n");
    return 0;
}