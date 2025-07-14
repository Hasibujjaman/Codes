// Topic 4
#include <iostream>
using namespace std;

class A
{
public:
    virtual void Print() = 0;
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
    // A a;   object of abstract class is not allowed
    // a.Print();

    B b;
    b.Print();

    A *p;
    // p = &a;
    // p->Print();

    p = &b;
    p->Print();
}