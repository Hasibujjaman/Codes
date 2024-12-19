#include<stdio.h>
int main(){
    unsigned long long int x1,x2,x3,x4,sum;
    scanf("%llu %llu %llu %llu",&x1,&x2,&x3,&x4);
    sum=(x1+x2+x3+x4)/3;
    if(sum==x1)
    printf("%llu %llu %llu\n",x1-x2,x1-x3,x1-x4);
    else if(sum==x2)
    printf("%llu %llu %llu\n",x2-x1,x2-x3,x2-x4);
    else if(sum==x3)
    printf("%llu %llu %llu\n",x3-x1,x3-x2,x3-x4);
    else if(sum==x4)
    printf("%llu %llu %llu\n",x4-x1,x4-x2,x4-x3);
    return 0;
}