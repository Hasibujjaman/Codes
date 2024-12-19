#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++){
        char word[101];
        scanf("%s",word);
        if(strlen(word)>10){
            printf("%c%lu%c\n",word[0],strlen(word)-2,word[strlen(word)-1]);
        }
        else printf("%s\n",word);
    }  
    return 0; 
}