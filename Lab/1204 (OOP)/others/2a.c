#include<stdio.h>
int is_prime(int n){
    int i,check=0;
    for(i=2;i<=n/2;i++){
        if(n%i==0) check++;
    }
    if(check==0) return 1;
    else return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    int i,j,a,b;
    for(i=0,j=n;i<=n/2;i++,j--){
            if(is_prime(i)==1&&is_prime(j)==1){
                break;
            }
    }
    printf("%d %d\n",i,j);
    return 0;
}