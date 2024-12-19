#include<stdio.h>
int main(){
    char str2[100];
    printf("Enter a sentence:\n");
    fgets(str2,100,stdin);
    printf("%s\n",str2);

    char str1[100];
    printf("Enter a sentence:\n");
    scanf("%[^\n]s",str1);
    printf("%s\n",str1);

    char str0[100];
    printf("Enter a sentence:\n");
    scanf("%s",str0);   //reads a string till whitespace character
    printf("%s\n",str0);
    
    char str3[100];
    gets(str3);
    printf("%s\n",str3); 
    
    return 0;
}