#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    int i,j;
    for(i=1;i<=t;i++){
        char str[101];
        scanf("%s",str);
        if(strlen(str)>10){
            printf("%c%ld%c\n",str[0],strlen(str)-2,str[strlen(str)-1]);
        }
        else 
            printf("%s\n",str);
    }
    return 0;
}