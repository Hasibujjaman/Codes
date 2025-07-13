#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int array[n];
    printf("\nEnter %d elements:\n",n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    printf("The elements in reverse order:\n");
    for(i=n-1;i>=0;i--){
        printf("Element[%d] = %d\n",i+1,array[i]);
    }
    return 0;
}