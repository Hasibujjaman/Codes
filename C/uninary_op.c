#include <stdio.h>
int main() {
  int x = 10;
  printf("unary minus result: %d\n", -x);
  x = -x;
  printf("unary plus result: %d", +x);
}