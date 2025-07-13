#include <stdio.h>
int main() {
  float num1, num2;
  int op;
  printf("Enter x = ");
  scanf("%f", &num1);
  printf("Enter y = ");
  scanf("%f", &num2);
  printf("Select your preferred operation from these options\n 1.Summation\n "
         "2.Subtraction\n 3.Multiplication\n 4.Division\n");
  scanf("%d", &op);
  switch (op) {
  case 1: {
    printf("x + y = %.2f", num1 + num2);
    break;
  }
  case 2: {
    printf("x - y = %.2f", num1 - num2);
    break;
  }
  case 3: {
    printf("x * y = %.2f", num1 * num2);
    break;
  }
  case 4: {
    printf("x / y = %.2f", num1 / num2);
    break;
  }
  default:
    printf("Not a valid choice");
  }
  return 0;
}