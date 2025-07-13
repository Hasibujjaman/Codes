#include<stdio.h>
double pi = 3.14; //global
void func1(){
    pi=3.1416; // here pi is undeclared in func1 so it'll deal with global pi
    return; // optional for void type
}
int main(){
    printf("%lf\n",pi);
    func1();
    printf("%lf\n",pi);
    return 0;
}