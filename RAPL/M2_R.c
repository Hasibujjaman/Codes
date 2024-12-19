#include<stdio.h>
#include<string.h>
int main(){
    char size[1000000];
    scanf("%s",size);
    int l=strlen(size);
    int i;
    for(i=0;i<l;i++){
        printf("%c",size[i]);
    }
    for(i=l-1;i>=0;i--){
        printf("%c",size[i]);
    }
    printf("\n");
    
    
    return 0;

}