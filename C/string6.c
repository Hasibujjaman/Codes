#include<stdio.h>
int main(){
    char str0[]="Bangladesh ",str1[]="BD",str2[13];
    int l0=11,l1=2;
    int i,j;
    for(i=0,j=0;i<l0;i++,j++){
        str2[j]=str0[i];
    }
    for(i=0;i<l1;i++,j++){
        str2[j]=str1[i];
    }
    str2[j]='\0';
    printf("%s\n",str2);
    return 0;
}