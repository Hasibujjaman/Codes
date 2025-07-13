#include<stdio.h>
#include<string.h>
int main(){
    char a[1000], b[100];
    gets(a);
    int length=strlen(a);
    printf("String length (gets): %d\n",length);
    int i,j,start=0;
    for(i=0,j=0;i<=length;i++){  
        if(a[i]>='A'&&a[i]<='Z'){
            if(start==0){
                start=1;
            }
            b[j]=a[i];
            j++;
        }
        else if(a[i]>='a'&&a[i]<='z'){
            if(start==0){
                start=1;
                b[j]='A'+(a[i]-'a');
                j++;
            }
            else{
                b[j]=a[i];
                j++;
            }
        }
        else if(a[i]>='0'&&a[i]<='9'){
            if(start==0){
                start=1;
            }
            b[j]=a[i];
            j++;
        }
        else {
            if(start==1){
                start=0;
                b[j]='\0';
                printf("%s\n",b);
                j=0;
            }
        }
    }
    return 0;
}