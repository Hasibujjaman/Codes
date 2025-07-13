#include <stdio.h>
int f1(int n) {
printf("%d ", n);
return 0; 
}
int f2(void) {
printf("entered ");
return 0; 
}

int main(void) {
int t;
printf("Enter a number: "); 
scanf("%d", &t);
int x = t ? f1(t) + f2() : printf("zero entered."); // When the function's name is encountered, the function is executed so that its return value can be determined.
printf("\n%d\n",x);
return 0; 
}