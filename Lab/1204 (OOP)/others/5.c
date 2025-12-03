#include <stdio.h>
int main() {
  char ch;
  printf("Enter a Capital later: ");
  scanf("%c", &ch);
  switch (ch) {
      
  case 'F':
    printf("First division\n");
    break;

  case 'S':
    printf("Second division\n");
    break;

  case 'T':
    printf("Third division\n");
    break;

  case 'X':
    printf("Fail\n");
    break;

  default:
    printf("Wrong input\n");  

  }

  return 0;

}