//Chinese remainder theorem
#include<iostream>
using namespace std;

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

int main(){
    int a1,a2,a3,m1,m2,m3;
    cin>>a1>>a2>>a3;
    cin>>m1>>m2>>m3;

    int M = m1*m2*m3;
    int M1 = m2*m3;
    int M2 = m1*m3;
    int M3 = m1*m2;

    int s,t;

    gcd(M1,m1,&s,&t);
    int y1 = s;

    gcd(M2,m2,&s,&t);
    int y2 = s;

    gcd(M3,m3,&s,&t);
    int y3 = s;

    int x = a1*M1*y1 + a2*M2*y2 + a3*M3*y3;

    cout<<"x = "<<x<<endl;

    

}