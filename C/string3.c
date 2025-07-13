#include<stdio.h>
int main(){
    char str[100],strc[100],strs[100];
    scanf("%[^\n]s",str);
    int i;
    for(i=0;i<99;i++){
        if(str[i]>='A'&&str[i]<='Z'){          //or, if(str[i]>=65&&str[i]<=97)
            strc[i]=str[i];
            strs[i]='a'+(str[i]-'A');
        }         //or, strs[i]= 97+(str[i]-65);='z'-('Z'-str[i]);
        else if(str[i]>='a'&&str[i]<='z'){    //or, if(str[i]>=97&&str[i]<=122)
            strs[i]=str[i];
            strc[i]= 'A'+(str[i]-'a');         //or, strs[i]= 65+(str[i]-97);='Z'-('z'-str[i]);
        }
        else {
            strc[i]=str[i];
            strs[i]=str[i];
        }
        if (str[i]=='\0'){  //or, str[i]==0
           // strc[i]=str[i];
          //  strs[i]=str[i];
            break;
        }

    }
    printf("In Capital latter: %s\n",strc);
    printf("In Small latter: %s\n",strs);

    return 0;
}
