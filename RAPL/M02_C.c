#include<stdio.h>
int main(){
    int H,W,i=1,j=1;
    while(1)
    {
        scanf("%d %d",&H,&W);
        if(H==0&&W==0) break;
        while(i<=H)
        {
            while(j<=W)
            {
                printf("#");
                j++;
                if(j==W) 
                {
                    printf("\n");
                    i++;
                }
            }
            
        }
        

    }
    return 0;
}