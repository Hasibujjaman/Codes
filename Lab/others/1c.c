#include<stdio.h>
int main(){
    int row,col;
    printf("Enter row and column:\n");
    scanf("%d %d",&row,&col);
    int A[row][col],B[row][col],C[row][col];
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d %d",&A[i][j],&B[i][j]);
        }
    }
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
     for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;

}