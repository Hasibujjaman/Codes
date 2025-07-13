#include<stdio.h>
int main(){
    char word[100];
    scanf("%s",word);
    int i,l,c=0;
    for(i=0;word[i]!='\0';i++) {}
    l=i;
    for(i=0;i<l/2&&c==0;i++){
        if(word[i]!=word[l-1-i]) c++;
    }
    if(c==0) printf("%s is a palindrome.\n",word);
    else printf("%s is not a palindrome.\n",word);
    return 0;
}