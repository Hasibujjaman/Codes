#include<stdio.h>
int main(){
    int i=1;
    emon:
        printf("%d\t", i);
        i++;
        if(i<5)
            goto emon;
    return 0;
}