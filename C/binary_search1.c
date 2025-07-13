#include<stdio.h>
int main(){
    int arr[]={1,2,3,4,7,51,78,96,99,100};
    int num;
    scanf("%d",&num);
   int li=0,hi=9;
    int mi;
    while(li<=hi){
        mi=(li+hi)/2;
        if(num==arr[mi]) break;
        if(num>arr[mi]){
            li=mi+1;
        }
        else
        hi=mi-1;
    }
    if(li>hi) printf("%d is not in the array\n",num);
    else printf("%d is the %d th element of the array",num,mi+1);
    return 0;
}