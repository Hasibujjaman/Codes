// Extended Euclid's GCD
#include <stdio.h>
#include<math.h>
int x,y;
int d = 1;
 
// Recursive function to return gcd of a and b
int gcd(int a, int b, int* x, int* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - y1 * (a / b);
    return d;
}
 
int main()
{
    int a = 240, b = 46;
    int x,y;
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b, &x, &y));
    printf("%d = (%d) * (%d) + (%d) * (%d)\n",gcd(a,b,&x,&y),a,x,b,y);
    return 0;
}