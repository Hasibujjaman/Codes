#include<stdio.h>
#include<string.h>
int main(){
    char str[7][100]={"Bangladesh","India","Nepal","Japan","Korea","America","Canada"};
    //char str[][]={"Bhahd","fha"}; not allowed but char str[]="Vaj ajs"; is allowed
    int row;
    for(row=0;row<7;row++){
        printf("%s\n",str[row]);
    }
    printf("\n\n\n");
    int i,j;
    for(i=0;i<7;i++){
        for(j=0;j<strlen(str[i]);j++){
            printf("%c",str[i][j]);
        }
        printf("\n");
    }
    return 0;
}