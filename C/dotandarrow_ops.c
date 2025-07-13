#include<stdio.h>
struct emon{
    float wage;
    int age;
};
int main(){
    struct emon s1,*p;
    p=&s1;
    s1.wage=120.60;
    p->age=21;
    printf("%f %d\n",s1.wage,s1.age);
    return 0;



}