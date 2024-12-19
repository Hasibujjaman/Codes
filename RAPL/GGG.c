#include<stdio.h>
int main(){
    int N,D;
    scanf("%d %d",&N,&D);
    printf("%d %d %d\n", N/D,N-N/D*D,D);
    return 0;
}