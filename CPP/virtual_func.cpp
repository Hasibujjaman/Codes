#include <iostream>
using namespace std;

class A
{
public:
    virtual void Print() { cout << "Inside A" << endl; }
    void P(){ cout<<"INSIDE A"<<endl; }
};
class B : public A
{
public:
    void Print() { cout << "Inside B" << endl; }
    void P(){ cout<<"INSIDE B"<<endl; }
};
int main(void)
{
    A *pa;
    B *pb;
    A a;
    B b;

    pa = &a;
    pa->Print();

    pa = &b;
    pa->Print();
    pa->P(); // if function is not virtual then pointer's type will determine which class function to be executed


    a.Print();
    b.Print(); //derived class is invoked and base class ignored
    a.P();
    b.P(); //derived class is invoked and base class ignored
}