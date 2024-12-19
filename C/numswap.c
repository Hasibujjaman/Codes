#include <stdio.h>
int main() {
  int num1 = 10;
  int num2 = 5;
  int temp;

  temp = num1;
  num1 = num2;
  num2 = temp;
  printf("Number 1 = %d\nNumber 2 = %d", num1, num2);
  getch();
}