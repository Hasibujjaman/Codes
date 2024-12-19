#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int count = 0;
        char X[11], Y[11];
        scanf("%s %s",X,Y);
        int i;
        int l = strlen(X);
        for(i = 0; i < l; i++){
            if(!(X[i]==Y[i] || X[i]=='?' || Y[i]=='?')) {
                printf("No\n");
                count++;
                break;
                }
        }
        if(!count) printf("Yes\n");
        //printf("%d\n",i);
    }
    return 0;
}