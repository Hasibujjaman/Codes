#include<stdio.h>
int main(){
    int arr[2][3];
    int row,col;

    printf("\n");
    
    for(row=0;row<2;row++){
        for(col=0;col<3;col++){
            scanf("%d",&arr[row][col]);
        }
    }

printf("\n\n");

    for(row=0;row<2;row++){
        for(col=0;col<3;col++){
            printf("%d\t",arr[row][col]);
        }
        printf("\n");
    }

    printf("\n\n");

    for(col=0;col<3;col++){
        for(row=0;row<2;row++){
            printf("%d\t",arr[row][col]);
        }
        printf("\n");
    }
    
    printf("\n");
    return 0;
}