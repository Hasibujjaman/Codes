#include<stdio.h>
int main(){
    int i=1;
    lebel:
    printf("%d\t", i);
    i++;
    if(i<5)
        goto lebel;
}