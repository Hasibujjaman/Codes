#include <iostream>
using namespace std;

class A
{
public:
    virtual void Print()
    {
        cout << "Inside Print() of class A" << endl;
    }
};

class B : public A
{
public:
    void Print()
    {
        cout << "Inside Print() of class B" << endl;
    }
};

int main()
{
    A a;
    a.Print();
    B b;
    b.Print();
    A *p;
    p = &a;
    p->Print();
    p = &b;
    p->Print();
}