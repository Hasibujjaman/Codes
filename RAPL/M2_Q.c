#include<stdio.h>
int main(){
    char sentence[1200];
    int alpha[26];
    int i,j;

    for(i=0;i<26;i++){
        alpha[i]=0;
    }
//  scanf("%[^EOF]s",sentence); ! stops scanning if encounters 'E'/'O'/'F'/'EOF'
while(scanf("%s",sentence)!=EOF){   //EOF==-1
    for(i=0;sentence[i]!='\0';i++){
        if(sentence[i]>='a'&&sentence[i]<='z'){
            for(j='a';j<='z';j++){
                if(j==sentence[i]){
                    alpha[j-'a']++;
                    break;
                }
            }
        }
        else {
            for(j='A';j<='Z';j++){
                if(j==sentence[i]){
                alpha[j-'A']++;
                break;
                }
            }
        }

    }
}

    for(i=0;i<26;i++){
        printf("%c : %d\n",'a'+i,alpha[i]);
    }

    return 0;
}