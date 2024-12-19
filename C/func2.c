#include<stdio.h>
double add(double x,double y); //prototype declaration // also can be written as double add(x,y);
//double add(); //old style func. prototype declaration . Not compatible with c++

int main()
{
    double a,b,c;
    scanf("%lf %lf",&a,&b);
    c=add(a,b);
    printf("a: %lf + b: %lf = %lf\n",a,b,c);
    return 0;
}
double add(double num1,double num2)
{
    double sum = (double)num1 + num2;
    printf("num1: %lf + num2: %lf = %lf\n",num1,num2,sum);
    return sum;
}
