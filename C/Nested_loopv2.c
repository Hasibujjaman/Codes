#include<stdio.h>
int main(){
    int n,i,j,k;
    n=3;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                if(j!=i&&k!=i&&k!=j){
                    printf("%d, %d, %d\n", i,j,k);
                }
            }
        }
    } 
    return 0;
}