#include<stdio.h>
int main(){
    int i,j,n=7;
    for(i=1;i<=7;i+=2){
        for(j=1;j<=15;j++){
            if(j<=(7-i)/2||) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}