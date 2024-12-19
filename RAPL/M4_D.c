#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char str[51]; 
        scanf("%s",str);
        int alpha[26]={};
        int c1,c2;
        c1=c2=0;
        for(int i = 0; str[i]; i++){
            alpha[str[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(alpha[i]>1) c1++;
            else if(alpha[i]==1) c2++;
        }
        printf("%d\n",c1+c2/2);
    }
    return 0;
}