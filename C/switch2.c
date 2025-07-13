#include <stdio.h>
int main() {
  int digit;
  int x=0;
  printf("Enter a digit: ");
  scanf("%d", &digit);
  switch (digit) {
      
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    printf("Digit is in the range 0-5\n");
    break;

  case 6:
    x = !x;
  case 7:
    if(x) {
        printf("Digit is 6\n");
        break;
    }
  case 8:
  case 9:
    printf("Digit is in the range 7-9\n");
    break;
    
  default:
    printf("Not a valid digit\n");  

  }
}