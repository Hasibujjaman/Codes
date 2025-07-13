#include<stdio.h>
int arr[10][10];
void pnamata(){
    int i,j;
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            printf("%d x %d = %d\n",i,j,arr[i-1][j-1]);
        }
        printf("\n");
    }
    return;
}
int main(){
    int i,j;
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            arr[i-1][j-1]=i*j;
        }
    }
    pnamata();
    return 0;
}