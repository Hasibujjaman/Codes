#include<stdio.h>
int st[100005]; //globaly decraled array are automatically initialized with 0s
void sieve(){
    int i,j;
    st[1]=1;
    //for(i=4;i<=100000;i+=2) st[i]=1;
    for(i=2;i*i<=100000;i++){
        if(st[i]==0){
            for(j=2*i;j<=100000;j+=i) st[j]=1;
        }
    }
}

int main(){
    sieve();
    int n,i,j;
    scanf("%d",&n);
    for(i=2;i*i<=n;i++){
        if(st[i]==0){
            if(n%i==0){
                int count=0;
                while(n%i==0){
                    n/=i;
                    count++;
                }
            }
        }
    }
    if(n>1) printf()
}