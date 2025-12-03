#include<stdio.h>
int main(){
   int a=2,b=3;
   printf("%d %d\n",a,b);
   a=b,b=a;
   printf("%d %d\n",a,b);
   return 0;
}