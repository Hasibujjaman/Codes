#include<stdio.h>
int main(){
    int y,z;
    int x = (y=3,y+1);
    printf("x=%d\ny=%d\n",x,y);
    z=(x-=3,y=2,x+y);
    printf("x=%d\ny=%d\nz=%d\n",x,y,z);
    return 0;
}