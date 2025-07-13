#include<stdio.h>
int main(){
    int i,j;
    printf("\n\n\n");
    for(i=7;i>=1;i--){
        for(j=1;j<=7;j++){
            if(j>(7-i)) printf("C");
            else printf(" ");
        }
        printf("\n");
    }
    for(i=2;i<=7;i++){
        for(j=1;j<=7;j++){
             
            if(j>(7-i)) printf("C");
            else printf(" ");
        }
        printf("\n");
    }
    printf("\n\n\n");
    return 0;
}