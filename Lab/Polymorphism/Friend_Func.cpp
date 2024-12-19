// Topic 5
#include <iostream>
using namespace std;

class A
{
private:
    int x;

public:
    A()
    {
        x = 0;
    }
    friend void Add(A &p);
    friend void IncX(A &p);
    friend void DecX(A &p);
    void Show()
    {
        cout << "x = " << x << endl;
    }
};

void Add(A &p)
{
    int x;
    cout << "Enter x = ";
    cin >> x;
    p.x = x;
}
void IncX(A &p)
{
    int m;
    cout << "Enter m = ";
    cin >> m;
    p.x += m;
}
void DecX(A &p)
{
    int n;
    cout << "Enter n = ";
    cin >> n;
    p.x -= n;
}

int main()
{
    A a;
    a.Show();
    Add(a);
    IncX(a);
    DecX(a);
    a.Show();
}