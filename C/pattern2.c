#include<stdio.h>
int main(){
    int i,j;
    printf("\n\n\n");
    for(i=11;i>=1;i-=2){
        for(j=1;j<=11;j++){
            if(j>(11-i)/2&&j<=11-(11-i)/2) printf("C");
            else printf(" ");
        }
        printf("\n");
    }
    for(i=3;i<=11;i+=2){
        for(j=1;j<=11;j++){
            if(j>(11-i)/2&&j<=11-(11-i)/2) printf("C");
            else printf(" ");
        }
        printf("\n");
    }
    printf("\n\n\n");
    return 0;
}