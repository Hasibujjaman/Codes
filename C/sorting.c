#include<stdio.h>
int main(){
    int ara1[]={5,4,2,3,1};
    int ara2[5];
    int i,j,min,min_index;
    for(i=0;i<5;i++){
        min=10000;
        for(j=0;j<5;j++){
            if(ara1[j]<min){
                min=ara1[j];
                min_index=j;
            }
        }
        ara1[min_index]=10000;
        ara2[i]=min;
    }
    for(i=0;i<5;i++) printf("%d\t%d\n",ara1[i],ara2[i]);
    return 0;
}