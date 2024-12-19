#include<stdio.h>

void pscore(int * score,int n){
    int i;
    for(i=0;i<n;i++){
       // printf("Player: %d\tPoints: %d\n",i+1,score[i]);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int x = 3;
        int GF[x][n];
        int i,j;
        for(i=0;i<n;i++){
            scanf("%d",&GF[0][i]);
        }
        for(i=0;i<n;i++){
            scanf("%d",&GF[1][i]);
        }
        int tscore,max=0;
        for(i=0;i<n;i++){
            tscore=0;
            tscore=GF[0][i]*20-GF[1][i]*10;

            if(tscore>0) GF[2][i]=tscore;
            else GF[2][i]=0;

            if(tscore>max) max=tscore;

        }
        pscore(GF[2],n);
        printf("%d\n",max);

    }
}