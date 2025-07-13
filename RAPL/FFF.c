#include<stdio.h>
int main(){
    int X,Y;
    scanf("%d %d",&X,&Y);
    if(Y%X==0)
        printf("0\n");
    else if(Y<X) 
        printf("%d\n",X-Y);
    else if(Y>X)
        printf("%d\n",X-(Y-Y/X*X));
    return 0;
}