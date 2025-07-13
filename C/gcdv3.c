//Euclid's GCD v1
#include <stdio.h>
// Recursive function to return gcd of a and b
long long gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
 
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
 
int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    printf("GCD of %lld and %lld is %lld\n", a, b, gcd(a, b));
    return 0;
}