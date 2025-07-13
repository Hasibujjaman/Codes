#include<stdio.h>
int main(){
    int n,q;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&q);
    while(q--){
        int i,j,k,sum;
        scanf("%d %d",&i,&j);
        sum = 0;
        for(k=i;k<=j;k++){
            sum = sum + arr[k];
        }
        printf("%d\n",sum);
    }
    return 0;
}