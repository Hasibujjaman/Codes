#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char str[100];
    scanf("%s",str);
    int decimal=0,i,l=strlen(str),power=l-1;
    
    for(i=0;i<l;i++){
        decimal+=(str[i]-48)*pow(2,--power);
    }
    printf("%d\n",l);
    printf("Binary %s = Decimal %d\n",str,decimal);
    return 0;
}