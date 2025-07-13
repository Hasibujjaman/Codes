#include<stdio.h>
#include<string.h>
int main(){
    char num[100];
    scanf("%s",num);
    int i,l,d=0;
    l=strlen(num);
    for(i=0;i<l/2;i++){
        if(num[i]!=num[l-1-i]) {d++;break;}
    }
    if(d==0) printf("Yes. %c&%c\n",num[0],num[l-1]);
    else printf("No. %c&%c\n",num[0],num[l-1]);
    return 0;
}