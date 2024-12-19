#include<stdio.h>
int main(){
    int x,y,g,f,r;
    scanf("%d %d %d %d %d",&x,&y,&g,&f,&r);
    int c=g*g+f*f-r*r;
    int check=x*x+y*y-2*g*x-2*f*y+c;
    if(check<0) printf("Yes\n");
    else printf("No\n");
    return 0;
}