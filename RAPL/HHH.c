#include<stdio.h>
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int sum=a+b+c+d;
    if(sum%2==0){
        if(a==b+c+d) printf("Yes\n");
        else if(b==a+c+d) printf("Yes\n");
        else if(c==a+b+d) printf("Yes\n");
        else if(d==a+b+c) printf("Yes\n");
        else if(a+b==c+d) printf("Yes\n");
        else if(a+c==b+d) printf("Yes\n");
        else if(a+d==b+c) printf("Yes\n");
        else printf("No\n");
    }
    else printf("No\n");
    return 0;
}