#include<stdio.h>
int main(){
    int arr[5][5]={{6,4,7,8,9},{3,7,1,9,9},{8,6,4,2,7},{2,4,2,5,9},{4,1,6,7,3}};
    int i,j,sum=0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            sum+=arr[i][j];
        }
        printf("Sum of row %d: %d\n",i+1,sum);
        sum = 0;
    }
    printf("\n\n");
    sum=0;
    for(j=0;j<5;j++){
        for(i=0;i<5;i++){
            sum+=arr[i][j];
        }
        printf("Sum of collumn %d: %d\n",j+1,sum);
        sum=0;
    }
    return 0;
}