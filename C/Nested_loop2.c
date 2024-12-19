#include<stdio.h>
int main(){
    int n,i,j,k,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++){ 
        for(j=1;j<=n;j++){
            if(j!=i){
                for(k=1;k<=n;k++){
                    if(k!=i&&k!=j){
                        for(l=1;l<=n;l++){
                            if(l!=i&&l!=j&&l!=k){
                                printf("%d, %d, %d, %d\n", i,j,k,l);
                            }
                        }
                    }   
                }   
            }             
        }   
    }
    return 0;
}