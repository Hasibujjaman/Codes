#include<stdio.h>
int main(){
    int ara1[]={1,2,3,4,5,6,7,8,9,10};
    int ara2[10];
    int i,j;
    for(i=0,j=9;i<10;i++,j--){
        ara2[i] = ara1[j]; //ara2[j]=ara1[i];
    }
    for(i=0;i<10;i++){
        ara1[i]=ara2[i];
    }
    for(i=0;i<10;i++){
        printf("%d ", ara1[i]);
    }
    printf("\n");
    return 0;
}