#include <iostream>
using namespace std;

class A
{
    int a;

    public:
    A()
    {
        cout << "default A\n";
    }
    A(int a)
    {
        this->a = a;
        cout << "non-default A = ";
        cout<<a<<endl;
    }
    ~A()
    {
        cout << "destructor A\n";
    }
};
class B : public A
{
    int b;

    public:
        B()
        {
            cout << "default B\n";
        }
        B(int a, int b):A(a)
        {
                this->b = b;
                cout << "non-default B = "; 
                cout<<b<<endl;
        } 
        ~B()
        {
            cout << "destructor B\n";
        }
};

int main()
{
    A aa;
    A aa1(5);
    B bb;
    B bb1(10, 20);
    return 0;
}