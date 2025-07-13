#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter %d elements:\n",n);
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Element going to be searched = ");
    scanf("%d",&target);
    for(i=0,j=0;i<n;i++){
        if(arr[i]==target) {
            printf("### %d is found at position: %d\n",target,i+1); 
            j++;
            break; 
        }
    }
    if(j==0) printf("### %d is not found\n",target);
    return 0;
}