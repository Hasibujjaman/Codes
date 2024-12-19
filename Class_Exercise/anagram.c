#include<stdio.h>
int anagram(char s1[],char s2[]){
    char f1[26]={0},f2[26]={0};
    int i=0;
    while(s1[i]!='\0'){
        f1[s1[i]-'a']++;
        i++;
    }
    i=0;
    while(s2[i]!='\0'){
        f2[s2[i]-'a']++;
        i++;
    }
    for(i=0;i<26;i++){
        if(f1[i]!=f2[i])
            return 0;
    }
    return 1;
}
int main(){
    char s1[100],s2[100];
    printf("Enter 1st sting(only lower case):\n");
    scanf(" %[^\n]/s",s1);
    printf("Enter 2st sting(only lower case):\n");
    scanf(" %[^\n]/s",s2);
    if(anagram(s1,s2)) printf("Anagram\n");
    else printf("Not anagram\n");
    return 0;
}