#include <stdio.h>
int x = 1; // global variable
int main() {
  int x = 2; // local variable
  printf("Main x = %d\n", x);
  local();
}

void local() {
  int x = 3; // local variable
  printf("Local x = %d\n", x);
}
