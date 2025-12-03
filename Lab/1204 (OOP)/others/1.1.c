#include<stdio.h>
int main(){
    int l,h;
    scanf("%d %d",&l,&h);
    int i,j,count;
    for(i=l;i<=h;i++){
        count=0;
        for(j=2;j<=i/2;j++){
            if(i%j==0) count++;
        }
        if(count==0) printf("%d ",i);
    }
    printf("\n");
    return 0;
}