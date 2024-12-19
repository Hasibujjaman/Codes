#include<stdio.h>
int series(void){
    static int num=0; // will initialize once and hold value between func. calls
    num+=1;
    return num;
}
int main(){
    int i=10;
    while(i--){
        printf("%d\n",series());
    }
    return 0;
}