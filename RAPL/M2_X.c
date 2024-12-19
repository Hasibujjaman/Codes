#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int k = 1; k <= t; k++){
        long long n,q;
        scanf("%lld %lld",&n,&q);
        long long arr[n], colarr[n+1];
        colarr[0] = 0;
        for(int i = 0; i < n; i++) {
            scanf("%lld",&arr[i]);
            colarr[i+1] = colarr[i] + arr[i];
        }
        for(int i = 1; i <= q; i++){
            long long t1,t2;
            scanf("%lld %lld",&t1,&t2);
            long long sum = colarr[t2] - colarr[t1-1];
            if(i==1) printf("Case %d:\n",k);
            printf("%lld\n",sum); 
        }


    }
    return 0;
}