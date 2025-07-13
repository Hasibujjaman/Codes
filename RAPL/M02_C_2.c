#include<stdio.h>
int main()
{
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

            }
            printf("\n");
            j=1;
            i++;
            
        }
        printf("\n");
        i=1;

    }
    return 0;
}