#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    int i=1;
    while(i<=t){
        int n,count=0;
        scanf("%d",&n);
        int S[n],D[n];
        for(int j=0;j<n;j++){
            scanf("%d",&S[j]);
        } 
        for(int j=0;j<n;j++){
            scanf("%d",&D[j]);
        }
        for(int j=0;j<n;j++){
            if(S[j]==D[j]) count++;
        }
        printf("%d\n",count);
        i++;
    }
    return 0;
}