#include<stdio.h>
int main(){
    int W,H,x,y,r;
    scanf("%d %d %d %d %d", &W,&H,&x,&y,&r);
    if(r>0&&2*r<=W&&2*r<=H){
        if(x>=r&&x<=W-r&&y>=r&&y<=H-r)
            printf("Yes\n");
    else 
        printf("No\n");
    }
    else 
        printf("No\n");

    return 0;
}