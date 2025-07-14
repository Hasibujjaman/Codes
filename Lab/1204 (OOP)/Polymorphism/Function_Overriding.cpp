// Topic 3
#include <iostream>
using namespace std;

class A
{
public:
    void Print()
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
    p = &b; // though base type pointer can point to derived type object , it can only access the members of derived class that are inherited from base class
    p->Print(); //hence base class member function Print() will be called
}