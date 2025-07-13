#include<stdio.h>
#include<string.h>
const char* pangrams(char str[]){
    int i,j,check;
    char *s1="pangram";
    int l=strlen(str);
    for(i=0;i<26;i++){
        for(j=0,check=0;j<l;j++){
            if('A'+i==str[j]||'a'+i==str[j]) check++;
        }
        if(check==0) return "not pangram";
    }
    return s1;

}
int main(){
    char str[1001];
    scanf("%[^\n]s",str);
    printf("%s\n",pangrams(str));
    return 0;
}
