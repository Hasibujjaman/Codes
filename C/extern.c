#include<stdio.h>
int main(){
    extern int a,b;
    printf("%d %d\n",a,b);
    return 0;
}
int a=1,b=2;
