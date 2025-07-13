// https://codeforces.com/problemset/problem/231/A
#include<stdio.h>
int main(){
    int t,count,check;
    scanf("%d",&t);
    count = 0;
    while(t){
        check = 0;
        int x;
        scanf("%d",&x);
        if(x) check++;
        scanf("%d",&x);
        if(x) check++;
        scanf("%d",&x);
        if(x) check++;
        if(check>1) count++;
        //printf("Check = %d , Count = %d\n",check,count);
        --t;
    }
    printf("%d\n",count);

    return 0;

}