// Prime Factorization
#include <iostream>
#include <math.h>
using namespace std;

void primeFactorization(int *primeF, int n)
{
    while (n % 2 == 0)
    {
        primeF[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            primeF[i]++;
            n = n / i;
        }
    }
    if (n > 2){
        primeF[n]++;
    }
}
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    int maxPrime = n/2; // less than n/2
    int primeF[maxPrime+1];

    for(int i = 0; i <= maxPrime; i++) 
        primeF[i] = 0;

    primeFactorization(primeF,n);
    cout << "Prime factors of " << n << " are : ";
    for(int i = 2; i <= maxPrime; i++){
        if(primeF[i])
            cout<<i<<"^"<<primeF[i]<<" . ";
    }
    cout<<endl;

    return 0;
}