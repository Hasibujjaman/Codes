#include<stdio.h>
int main(){
    int arr[5]={10,20,20,40,50};
    int ti[5];
    int target;
    printf("Enter the target element: ");
    scanf("%d",&target);
    int i,j;
    for(i=0,j=0;i<5;i++){
        if(target==arr[i]){
            ti[j]=i;
            j++;
        }
    }
    if(j==0) printf("Target not found\n");
    else {
        printf("Target found %d times\tIndex: ",j);
      for(i=0;i<j;i++){
          printf("%d ",ti[i]+1);
      }
      printf("\n");  
    }
    return 0;
}