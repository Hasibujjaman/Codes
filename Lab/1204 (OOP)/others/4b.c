#include<stdio.h>
int main(){
    int arr[5]={1,2,3,4,5};
    int i,odd;
    odd=0;
    for(i=0;i<5;i++){
        if(arr[i]%2!=0) odd++;
    }
    printf("Number of odd elements in the array is: %d\n",odd);
    return 0;
}