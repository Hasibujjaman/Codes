#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int array[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int temp;
    for(i=0;i<n/2;i++){
        temp=array[i];
        array[i]=array[n-1-i];
        array[n-1-i]=temp;
    }
    for(i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}