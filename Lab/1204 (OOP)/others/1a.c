#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d",&n);
    int i,power,sum=0;
    for(i=0;pow(2,i)<=n;i++){}
    power=i-1;
    int pv;
    for(i=power;i>=0;i--){
        pv=pow(2,i);
        if(sum+pv<=n){ 
            printf("1");
            sum+=pow(2,i);
        }
        else {
            printf("0");
        }
    }
    printf("\n");
    return 0;
}