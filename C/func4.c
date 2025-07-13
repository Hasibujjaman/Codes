#include<stdio.h>
int find_max(int ara[],int size){
    int max;
    int i;
    max=ara[0];
    for(i=1;i<size;i++){
        if(ara[i]>max){
            max=ara[i];
        }
    }
    return max;
}
int main(){
    int n=11;
    int i;
    int array[]={-100,0,53,22,42,22,53,624,42,42,42};
    printf("%d\n",find_max(array,n));
    return 0;
}