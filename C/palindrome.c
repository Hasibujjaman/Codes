#include<stdio.h>
#include<string.h>
int main(){
    char word[100],r_word[100];
    scanf("%s",word);
    int i,l;
    l=strlen(word);
    for(i=0;i<l;i++){
        r_word[i]=word[l-1-i];
    }
    r_word[l]='\0';
    if(strcmp(word,r_word)==0) printf("%s is a palindrome.\n",word);
    else printf("%s is not a palindrome.\n",word);
    return 0;
}