#include<stdio.h>
int main(){
    int n;
    printf("Input the number of elements to be stored in the array :");
    scanf("%d",&n);
    int array[n];
    printf("Input %d elements in the array: \n",n);
    int i;
    for(i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&array[i]);
    }
    int j;
    int count=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(array[i]==array[j]) count++;
        }
    }
    printf("The total number of duplicate elements found in the array is : %d\n",count);
    return 0;
}