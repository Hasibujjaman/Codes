#include<stdio.h>
int main(){
   // int num[]; length must be given
   // int num[3]; redeclaration not allowed
  // num[3]={0,1,2}; data type missing
  int num[3]={0,1,2};
  // int num[]={0,1,2}; allowed
  num[0]=1;
  num[2]=1;
  num[3]=2; //past array bound
  num[4]=3;
  printf("%d %d %d %d %d\n",num[0],num[1],num[2],num[3],num[4]);
  return 0;
}