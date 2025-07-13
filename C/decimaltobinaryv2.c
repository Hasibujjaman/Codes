#include<stdio.h>
void dtob(int a);
int main(){
    int dec;
    printf("Enter decimal number: ");
    scanf("%d",&dec);
    dtob(dec);
    return 0;
}
void dtob(int dec){
    int bin[1000];
    int i;
    for(i=0;dec/2!=0;i++){
        if(dec%2==0) bin[i]=0;
        else bin[i]=1;
        dec/=2;
    }
    bin[i]=1;
    printf("i=%d\nIn binary: ",i);
    for(;i>=0;i--){
        printf("%d",bin[i]);
    }
    printf("\n");
    return;
}