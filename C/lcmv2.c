#include<stdio.h>
int main(){
    int a,b,max;
    scanf("%d %d",&a,&b);
    max = a>b ? a:b;
    for(;;max++){
        if(max%a==0&&max%b==0)
            break;
    }
    printf("%d\n",max);
    return 0;

}