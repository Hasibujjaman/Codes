#include<stdio.h>
#include<stdlib.h>
int main(){
    float h,m;
    scanf("%f %f",&h,&m);
    float angh=30*h+m/2;
    float angm=6*m;
    float anghm=(((angh-angm) > 0) ? (angh-angm) : (-angh+angm));
    float x=(anghm<180)?anghm:(360-anghm);
    printf("%.4f\n",x);
    return 0;
}