#include<stdio.h>
void f1(int ara[],int x){
    ara[0]=0;
    x=0;

}
int main(){
    int arr[]={1,2,3,4,5};
    int x=1;
    f1(arr,x);
    printf("%d %d\n",arr[0],x);
    return 0;
}