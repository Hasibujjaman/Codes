#include<stdio.h>
int string_length(char a[]);

int main(){
    char str0[100];
    int length;
    while(1==scanf("%s",str0)){
        length=string_length(str0);
        printf("%d\n",length);
    }
    return 0;
}

int string_length(char str1[]){
    int i,l=0;
    for(i=0;str1[i]!='\0';i++) l++;
    return l;
}

