#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int i,input,count;
    for(i=1,count=0;i<=n;i++){
        scanf("%d",&input);
        if(input==1){
            count++;
            break;
        }
    }
    if(count==0) printf("Easy\n");
    else printf("Hard\n");
    return 0;
}