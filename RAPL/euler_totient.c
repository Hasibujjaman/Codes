#include<stdio.h>
#define ll long long
int main(){
    ll n;
    scanf("%lld",&n);
    ll phi=n;
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            phi-=phi/i;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1) phi-=phi/n;
    printf("%lld\n",phi);
    return 0;
}