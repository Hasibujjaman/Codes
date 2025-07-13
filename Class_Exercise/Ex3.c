#include<stdio.h>
int main(){
    int arr[5]={1,2,5,4,2};
    int i,temp=arr[0];
    for(i=0;i<5;i++){
        if(arr[i]>temp) temp=arr[i];
    }
    printf("The largest number in the array is: %d\n",temp);
    return 0;
}