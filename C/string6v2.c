#include<stdio.h>
int main(){
    char str0[]="Bangladesh ",str1[]="BD",str2[13];
    int l0=11,l1=2;
    int i;
    for(i=0;i<l0;i++){
        str2[i]=str0[i];
    }
    for(;i<l1+l0;i++){
        str2[i]=str1[i-l0];
    }
    str2[i]='\0';
    printf("%s\n",str2);
    return 0;
}