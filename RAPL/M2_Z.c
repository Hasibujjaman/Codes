#include<stdio.h>
#include<string.h>
int main(){
    int l1,l2,l3,a1[26]={},a2[26]={};
    char s1[101],s2[101],s3[101];
    scanf("%s %s %s",s1,s2,s3);
    //printf("%s\n%s\n%s\n",s1,s2,s3);
    l1 = strlen(s1), l2 = strlen(s2), l3 = strlen(s3);
    if((l1+l2)<l3) {
        printf("NO\n");
        return 0;
    }
    else{
        for(int i = 0; s3[i]; i++) a2[s3[i]-'A']++;
       // int s = (l1<l2) ? l1 : l2;
        for(int i = 0; i < l1; i++) a1[s1[i]-'A']++;
        for(int i = 0; i < l2; i++) a1[s2[i]-'A']++;
    }
    for(int i=0;i<26;i++){
        if(a1[i]!=a2[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;

}