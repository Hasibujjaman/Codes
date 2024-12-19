#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    if(N<42){
        if(N<10){
            printf("AGC00%d\n",N);
        }
        else 
            printf("AGC0%d\n",N);
    }
    else
        printf("AGC0%d\n",N+1);
    return 0;
}