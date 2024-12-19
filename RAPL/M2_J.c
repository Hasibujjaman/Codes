#include<stdio.h>
int camelcase(char ss[]);
int main(){
    char s[100001];
    scanf("%s",s);
    printf("%d\n",camelcase(s));
    return 0;
}
int camelcase(char s[]){
    int word=1;
    int i;
    for(i=0;s[i]!='\0';i++){
        if(s[i]>='A'&&s[i]<='Z') word++;
    }
    return word;
}