#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int temp;
    for(i=0;i<n/2;i++){
        temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}