#include<stdio.h>
int main(){
    char str0[]={'E','M','O','N','\0'};
    char str1[]="EMON";
    str0[2]='\0';
    str1[2]='\0'; //No need . automatically provided by comp.
    printf("%s\n%s\n",str0,str1);
    return 0;
}