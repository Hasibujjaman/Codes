#include<stdio.h>
int main(){
    int row;
    scanf("%d",&row);
    int i,j,k;
    for(i=1,k=0;i<=row;i++){
        if(i%2==0) {
            for(j=1;j<=row+1;j++){
                if(j==1||j==row+1) printf("*");
                else printf(" ");
            }
        }
        else {
            for(j=1;j<=row+1;j++){
                if((j<=i-k)||(j>=row+1-k)) printf("*");
                else printf(" ");
            }
            k++;
        }
        printf("\n");
    }
    return 0;
}