#include<stdio.h>
#include<string.h>
int main(){
    int i,j;
    char A[6][14]={"HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE"};
    for(i=1;i<=2000;i++){
        char temp[15];
        scanf("%s",temp);
        if(strcmp(temp,"#")==0) break;
        else{
            for(j=0;j<6;j++){
                if(strcmp(A[j],temp)==0) break;
            }
            switch(j){
                case 0:
                    printf("Case %d: ENGLISH\n",i);
                    break;
                case 1:
                    printf("Case %d: SPANISH\n",i);
                    break;
                case 2:
                    printf("Case %d: GERMAN\n",i);
                    break;
                case 3:
                    printf("Case %d: FRENCH\n",i);
                    break;
                case 4:
                    printf("Case %d: ITALIAN\n",i);
                    break;
                case 5:
                    printf("Case %d: RUSSIAN\n",i);
                    break;
                case 6:
                    printf("Case %d: UNKNOWN\n",i);
                    break;
            }
        }

    }
    return 0;
}