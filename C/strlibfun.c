#include<stdio.h>
#include<string.h>
int main(){
    char str1[]="Hello";
    char str2[]="World";
    char str3[6];
    printf("%lu\n",strlen(str1));
    printf("%d\n%d\n",strcmp(str1,str1),strcmp(str1,str2));
    printf("%s\n%s\n%s\n",strcpy(str1,str2),str1,str2);
    strcpy(str1,"Hello");
    printf("%s\n",str1);


}