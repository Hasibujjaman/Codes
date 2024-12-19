//c1 It contains at least one digit.
//c2  It contains at least one lowercase English character.
//c3 It contains at least one uppercase English character.
//c4 It contains at least one special character. The special characters are: !@#$%^&*()-+
//c5   Its length is at least 6.
#include<stdio.h>

int min_num(char pass[],int n){                            
    int i,num=0;
    int c1=0,c2=0,c3=0,c4=0;
    for(i=0;i<n;i++){
        if(c1==0){
            if(pass[i]>='0'&&pass[i]<='9') c1++;
        }
        if(c2==0){
            if(pass[i]>='a'&&pass[i]<='z') c2++; 
        }
        if(c3==0){
            if(pass[i]>='A'&&pass[i]<='Z') c3++;
        }
        if(c4==0){
            if(pass[i]=='!'||pass[i]=='@'||pass[i]=='#'||pass[i]=='$'||pass[i]=='%'||pass[i]=='^'||pass[i]=='&'||pass[i]=='*'||pass[i]=='('||pass[i]==')'||pass[i]=='-'||pass[i]=='+') c4++;
        }                                   
    }
    int sumc=c1+c2+c3+c4;
    if( n + (4-sumc) >= 6 ){
        return 4-sumc;
    }
    else{
        return 6-n;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    char pass[n+1];
    scanf("%s",pass);
    printf("%d\n",min_num(pass,n));
    return 0;  
}