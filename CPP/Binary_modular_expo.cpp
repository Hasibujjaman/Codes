#include <iostream>
using namespace std;
 
int power(int x, int y, int p)
{
 
    // Initialize answer
    int res = 1;
 
    // Check till the number becomes zero
    while (y > 0) {
 
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x);
 
        // y = y/2
        y = y >> 1;
 
        // Change x to x^2
        x = (x * x);
    }
    return res % p;
}
 
int main()
{
    int x = 5;
    int y = 1;
    int p = 3;
    cout << "Power is " << power(x, y, p) <<endl;
    return 0;
}