#include<stdio.h>
int main(){
    double math,phy,chem,total;
    printf("\nEnter obtained number in Math Physics and Chemistry\n");
    scanf("%lf %lf %lf", &math,&phy,&chem);
    total = math+phy+chem;
    if(math>=65&&phy>=55&&chem>=50&&total>=190)
        printf("Eligible\n");
    else
        printf("Not eligible\n");
    return 0;
}