#include<stdio.h>
struct student{
    int roll;
    char name[50];
    double height;
};
int main(){
    struct student s1,s2[2];
    scanf("%d %d %d",&s1.roll,&s2[0].roll,&s2[1].roll);
    scanf(" %[^/n]s",s1.name);
    scanf("%lf",&s1.height);
    printf("%d\n%d\n",s1.roll,s2[0].roll);
    return 0;

}