#include<stdio.h>
static int num; // known only to the file that contains it
int series(void){
    num+=1;
    return num;
}
int main(){
    int i=10;
    num=0;
    while(i--){
        printf("%d\n",series());
    }
    return 0;
}