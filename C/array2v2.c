#include<stdio.h>
int main(){
    int total_mark[41]={83,86,97,89,82,85,81,84,74,73,83,86,97,89,82,85,81,
    84,74,73,83,92,82,74,93,92,74,65,99,82,71,82,83,81,63,84,73,93,83,82}; 
    int count[101];   
    int i,j;
    for(i=0;i<101;i++){
        count[i]=0;
    }
    for(i=0;i<40;i++){
        count[total_mark[i]]++;
    }
        for(j=0;j<=100;j++){
            printf("Marks: %d\tCounter:%d\n",j,count[j]);
        }
    return 0;
}