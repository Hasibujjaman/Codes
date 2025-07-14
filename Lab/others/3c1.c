#include<stdio.h>
int main(){
    int n;
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d",&n);
    printf("Input %d elements in the array :\n",n);
    int i;
    int array[n];
    for(i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&array[i]);
    }
    int unique,count;
    int j;
    printf("The unique elements found in the array are:\n");
    for(i=0;i<n;i++){
        count=0;
        for(j=0;j<n;j++){
            if(array[i]==array[j]) count++;
        }
        if(count==1) printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}