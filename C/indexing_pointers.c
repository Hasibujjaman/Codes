#include <stdio.h>
int main(){
    int *p,*q;
    int arr[10][9];
    arr[3][0]=111;

    p = (int *) &arr[3][0]; // method 1

    q = arr[0];   // method 2
    q += 3*9;

    printf("%d %d\n",*p,*q);
    return 0; 
}