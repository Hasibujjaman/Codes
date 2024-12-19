#include<stdio.h>
int main(){
    long long n,k;
    scanf("%lld %lld",&n,&k);
    int check=n/k;
    if(check%2==0) printf("NO\n");
    else printf("YES\n");
    return 0;
}