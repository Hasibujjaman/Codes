#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Input the size of array : ");
    scanf("%d",&n);
    printf("Input %d elements in the array :\n",n);
    int i;
    int ara[n];
    for(i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&ara[i]);
    }
    
    int j,temp,i1,i2;
    int sum=ara[0]+ara[1];
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            temp=ara[i]+ara[j];
            if(abs(temp)<=abs(sum)){
                sum=temp;
                i1=i;
                i2=j;
            }
        }
    }
    
    printf("The given array is : ");
    for(i=0;i<n;i++) printf("%d ",ara[i]);
    printf("\nThe Pair of elements whose sum is minimum are:\n[%d, %d]\n",ara[i1],ara[i2]);
    
    return 0;

}