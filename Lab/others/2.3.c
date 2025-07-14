#include<stdio.h>
int main(){
    int row;
    scanf("%d",&row) ;
    int i,j;
    for(i=1;i<=row;i++){
        for(j=1;j<=4*row-1;j++){
            if(((j>=row-i+1)&&(j<=row+i-1))||((j>=2*row+i)&&(j<=4*row-i))) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}