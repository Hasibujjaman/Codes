#include<stdio.h>
int main(){
    char input[101];
    scanf("%s",input);
    int i;
    for(i=0;input[i]!='\0';i++){
        if(input[i]!='A'&&input[i]!='a'&&input[i]!='E'&&input[i]!='e'&&input[i]!='O'&&input[i]!='o'&&input[i]!='I'&&input[i]!='i'&&input[i]!='U'&&input[i]!='u'&&input[i]!='Y'&&input[i]!='y'){
            if(input[i]>='a'&&input[i]<='z') printf(".%c",input[i]);
            else if(input[i]>='A'&&input[i]<='Z') printf(".%c",'a'+input[i]-'A');
        }
    }
    printf("\n");
    return 0;
}