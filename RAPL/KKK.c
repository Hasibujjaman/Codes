#include<stdio.h>
int main(){
    int m,f;
    scanf("%d %d",&f,&m);
    if((m-2*f)>=f) printf("0\n");
    else printf("%d\n",3*f-m);
    return 0;
}