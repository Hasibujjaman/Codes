#include<stdio.h>
int main(){
    int n;
    printf("Input the size of array: ");
    scanf("%d",&n);
    int array[n];
    printf("Input %d elements in ascending order:\n",n);
    int i;
    for(i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&array[i]);
    }
    int sorted[n-1];
    int k,j;
    printf("Input rhe position where to delete: ");
    scanf("%d",&k);
    k--;
    for(i=0,j=0;i<n-1;i++,j++){
        if(j==k){
            j++;
            sorted[i]=array[j];
        }
        else{
            sorted[i]=array[j];
        }
    }
    printf("The new list is : ");
    for(i=0;i<n-1;i++){
        printf("%d ",sorted[i]);
    }
    printf("\n");
    return 0;

}