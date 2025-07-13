#include<stdio.h>
int main(){
    int n;
    printf("Input the size of the array: ");
    scanf("%d",&n);
    printf("Input %d elements in the array in ascending order:\n",n);
    int array[n];
    int i;
    for(i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&array[i]);
    }
    int sorted[n+1],insert;
    printf("Input the value to be inserted : ");
    scanf("%d",&insert);


    int j,count=0;
    for(i=0,j=0;i<n;i++,j++){
        if(insert<array[i]&&count==0){
            sorted[j]=insert;
            j++;
            sorted[j]=array[i];
            count++;
        }
        else{
            sorted[j]=array[i];
            if(count==0) sorted[n] = insert;
        }
    }

    
    printf("The exist array list is:\n");
    for(i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\nAfter Insert the list is :\n");
    for(j=0;j<n+1;j++){
        printf("%d ",sorted[j]);
    }
    printf("\n");
    

    return 0;

}