// Sieve of Eratosthenes

#include <iostream>
#include <cmath>
using namespace std;

void sieve(int *arr, int n)
{
    int m = sqrt(n);
    for (int i = 2; i <= m; i++)
    {

        if (!(i % 2) && i != 2)
            continue;
        for (int j = i; j <= n; j += i)
        {

            if (j == i)
                continue;

            arr[j] = 0;
        }
    }
}

int main()
{
    cout << "Enter value of n : ";
    int n;
    cin >> n;

    int isPrime[n + 1];

    for (int i = 0; i < n + 1; i++)
        isPrime[i] = 1;

    sieve(isPrime, n);

    cout << "Prime number(s) between 1 - " << n << " are :" << endl;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            cout << i<<" ";
    }
    cout<<endl;
}