#include<stdio.h>
int main(){
    int total_mark[41]={83,86,97,89,82,85,81,84,74,73,83,86,97,89,82,85,81,
    84,74,73,83,92,82,74,93,92,74,65,99,82,71,82,83,81,63,84,73,93,83,82};    
    int i,j,count;
    for(i=0;i<40;i++){
        for(j=0;j<40;j++){
            if(total_mark[i]==total_mark[j]) count++;
        }
        printf("Marks= %d\tNumber= %d\n",total_mark[i],count);
        count=0;
    }
    return 0;
}