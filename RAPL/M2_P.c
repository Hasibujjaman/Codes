#include<stdio.h>
int main(){
    int r,l;
    scanf("%d",&r);
    int i,j;
    int check;
    for(i=1;i<=r;i++){
        check=0;
        scanf("%d",&l);
        char snake[l+1];
        scanf("%s",snake);
        snake[l]='\0';
            for(j=0;j<l;j++){
                if(snake[j]=='H') check++;
                else if(snake[j]=='T') check--;
                if(check==2||check==-1){
                    printf("Invalid\n");
                    break;
                }
            }
            if(check==0) printf("Valid\n");
            else if(check==1) printf("Invalid\n");
    }
    return 0;
}