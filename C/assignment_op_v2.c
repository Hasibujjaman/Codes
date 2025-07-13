#include <stdio.h>
int main() {
  int a, b, x, y, z, p, q;
  printf("Enter an integer a = ");
  scanf("%d", &a);
  printf("Enter another integer b = ");
  scanf("%d", &b);
  x = a+=b;
  y = a-=b;
  z = a*=b;
  p = a/=b;
  q = a%b;
  printf("a += b : %d\n", x);
  printf("a -= b : %d\n", y);
  printf("a *= b : %d\n", z);
  printf("a /= b : %d\n", p);
  printf("a %= b : %d\n", q);
  return 0;
}