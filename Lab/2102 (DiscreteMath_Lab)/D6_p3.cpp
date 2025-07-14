// Finding Bezout's Coefficients
#include <iostream>
#include<cmath>
using namespace std;

int d = 1;

// Extended Euclid's GCD
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
    int a,b,x,y;
    cout<<"Enter value a and b : ";
    cin>>a>>b;
    printf("GCD of %d and %d is : %d\n", a, b, gcd(a, b, &x, &y));
    cout<<"Bezout's Coefficients are : "<<x<<" "<<y<<endl;
    printf("%d = (%d) * (%d) + (%d) * (%d)\n",gcd(a,b,&x,&y),a,x,b,y);
}