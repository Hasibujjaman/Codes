//Pseudoprime

#include<iostream>
#include<cmath>
using namespace std;

long long primeF[1000];
long long factors[500];
long long np;



void primeFactorization(long long n)
{
    while (n % 2 == 0)
    {
        primeF[2]++;
        np++;
        n = n / 2;
    }
    for (long long i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            primeF[i]++;
            np++;
            n = n / i;
        }
    }
    if (n > 2){
        primeF[n]++;
        np++;
    }
}

long long remainder(long long x, long long y, long long p)
{
 
    // Initialize answer
    long long res = 1;
 
    // Check till the number becomes zero
    while (y > 0) {
 
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x) % p;
 
        // y = y/2
        y = y >> 1;
 
        // Change x to x^2
        x = (x * x) % p;
    }
    return res;
}


 int main(){
    cout<<"Enter b and n respectively: ";
    long long b, n;
    cin>>b>>n;

    
    primeFactorization(n);

    for(long long i = 0, j = 0; i < 1000; i++){
        if(primeF[i] != 0) factors[j++] = i;
    }
    cout<<"Prime factors: ";
    for(long long i = 0; i < np; i++)
        cout<<factors[i]<<" ";
    cout<<endl;
    
    for(long long i = 1, j = 0; i <= np; i++){
        long long p = (n - 1) % (factors[j]-1);
        long long rnd = remainder(b,p,factors[j]);
        if(rnd != 1){
             cout<<"Not pseudoprime"<<endl;
             return 0;
        }
        j++;

    }
    cout<<"Pseudoprime"<<endl;





}