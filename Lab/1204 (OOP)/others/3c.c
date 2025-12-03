#include<stdio.h>
int main(){
    int r1,c1,r2,c2;
    printf("Enter matrix A(r1xc1):\nr1=\nc1=\n");
    scanf("%d %d",&r1,&c1);
    r2=c1;
    int A[r1][c1];
    int i,j,k;
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            printf("(%d,%d) element = ",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter matrix B(r2xc2):\nc2=\n");
    scanf("%d",&c2);
    int B[r2][c2];
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            printf("(%d,%d) element = ",i+1,j+1);
            scanf("%d",&B[i][j]);
        }
    }


    int C[r1][c2];
    printf("A x B = \n");
    int sum=0;
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            for(k=0;k<r2;k++){
                sum+=A[i][k]*B[k][j];
            }
            printf("(%d,%d) = %d ",i+1,j+1,sum);
            sum=0;
        }
        printf("\n");
    }



    return 0;
}