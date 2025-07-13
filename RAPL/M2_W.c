#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y,a,b,N,D;
        scanf("%d %d %d %d",&x,&y,&a,&b);
        N = y - x;
        D = a + b;
        if(!(N%D)) printf("%d\n", N/D);
        else printf("-1\n");
    }
}