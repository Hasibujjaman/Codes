#include <stdio.h>
int main() {
  int a, b;
  printf("Enter an integer a = ");
  scanf("%d", &a);
  printf("Enter another integer b = ");
  scanf("%d", &b);
  
  printf("a += b : %d\n", a+=b);
  printf("a -= b : %d\n", a-=b);
  printf("a *= b : %d\n", a*=b);
  printf("a /= b : %d\n", a/=b);
  printf("a %= b : %d\n", a%=b);
  return 0;
}