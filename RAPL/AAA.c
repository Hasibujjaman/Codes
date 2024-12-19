#include<stdio.h>
int main(){
    int D;
    scanf("%d",&D);
    if(D==25)
        printf("Christmas\n");
    else if(D==24)
        printf("Christmas Eve\n");
    else if(D==23)
        printf("Christmas Eve Eve\n");
    else if(D==22)
        printf("Christmas Eve Eve Eve\n");
    return 0;
}