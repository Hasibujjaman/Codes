#include<stdio.h>
int main(){
    int n;
    printf("Input the number of elements to store in the array: ");
    scanf("%d",&n);
    printf("Input %d numbers of elements in the array:\n",n);
    int i;
    int array[n];
    for(i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&array[i]);
    }
    printf("The values store into the array are:\n");
    for(i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\nThe values store into the array in reverse are:\n");
    for(i=0;i<n;i++){
        printf("%d ",array[n-1-i]);
    }
    printf("\n");
    return 0;
}