#include <iostream> 
using namespace std;
class A
{
    protected:
        int x;

    public:
    A()
    {
        x = 0;
        cout << "Constructor A" << endl;
    }
    void ShowX()
    {
        cout << "x = "<<x<<endl;
    }
};
class B : public virtual A
{
public:
    B()
    {
        x = 1;
        cout << "Constructor B" << endl;
    }
    void ShowX()
    {
        cout << "x = "<<x<<endl;
    }
};
class C : virtual public A
{
public:
    C()
    {
        x = 2;
        cout << "Constructor C" << endl;
    }
    void ShowX()
    {
        cout << "x = "<<x<<endl;;
    }
};
class D : public C, public B
{
public:
    D()
    {
        cout << "Constructor D" << endl;
    }
    void ShowX(){
        cout<<"x = "<<x<<endl;
    }
};
int main()
{
    D d;
    d.ShowX();
    d.B::ShowX();
    d.C::ShowX();
    d.A::ShowX();
}