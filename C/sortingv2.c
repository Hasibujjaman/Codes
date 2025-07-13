#include<stdio.h>
int main(){
    int ara[]={999,4,2,3,1};
    int i,j,small,si;
    for(i=0;i<5;i++){
        small=1000;
        for(j=i;j<5;j++){
            if(ara[j]<small) {
                small=ara[j];
                si=j;
            }

        }
        ara[si]=ara[i];
        ara[i]=small;    
    }
    for(i=0;i<5;i++) {
        printf("%d ",ara[i]);
    }
    printf("\n");
    return 0;
}