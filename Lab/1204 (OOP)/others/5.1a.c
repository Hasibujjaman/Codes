#include<stdio.h>
int main(){
    int i,j;
    int ch=65;
    int row;
    scanf("%d",&row);
    for(i=1;i<=row;i++,ch=65){
        for(j=1;j<=row-i;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("%c",ch++);
        }
        ch--;
        for(j=1;j<i;j++){
            printf("%c",--ch);
        }
        printf("\n");
    }

    return 0;
}