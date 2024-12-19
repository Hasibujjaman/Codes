#include<stdio.h>
int main(){
    char str[16]={'M','y',' ','n','a','m','e',' ','i','s',' ','E','M','@','N','\0'};
    printf("%s\n",str);
    char str0[]={'M','y',' ','n','a','m','e',' ','i','s',' ','E','M','@','N'};
    printf("%s\n",str0);
    char str1[]="My name is EM@N";
    printf("%s\n",str1);
    char *str2="My name is Em@n"; //pointer
    printf("%s\n",str2);
    str[13]='O';
    str0[13]='O';
    str1[13]='O';
   // str2[13]='O'; undefined in C
    printf("%s\n%s\n%s\n%s\n",str,str0,str1,str2);

   
    return 0;
    
}