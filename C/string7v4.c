#include<stdio.h>
#include<string.h>
int main(){
    char a[1000];
    fgets(a,1000,stdin);
    int length=strlen(a);
    int i,start=0;
    for(i=0;i<length;i++){  //or, a[i]!='\0'
        if((a[i]>='A'&&a[i]<='Z')||(a[i]>='0'&&a[i]<='9')){
            if(start==0){
                start=1;
            }
            printf("%c",a[i]);
        }
        else if(a[i]>='a'&&a[i]<='z'){
            if(start==0){
                start=1;
                printf("%c",'A'+a[i]-'a');
            }
            else{
                printf("%c",a[i]);
            }
        }
        else if(a[i]==' '||a[i]=='\0'||a[i]=='\n'){
            if(start==1){
                start=0;
                printf("\n");
            }
        }
        else{
            if(start==0){
                start=1;
            }
            printf("%c",a[i]);
        }
    }
    return 0;
}
