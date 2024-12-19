#include <stdio.h>
int main(){
    int arr[]={1,2,3};
    char str[]="AB";
    char str1[3]="CD";
    char str2[]={'E','F','\0'};
    for(int i=0;i<3;i++){
    printf("%d %c %c %c\n",arr[i],str[i],str1[i],str2[i]);
    }
    printf("%c\n",str1[2]);
    return 0; 
}