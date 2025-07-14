//Topic 2 v)
#include<iostream>
using namespace std;

//Base class
class A{
    private:
        int x;
    protected:
        int y;
    public:
        int z;
        void Set(){
            x = 1;
            y = 2;
            z = 3;
        }
};
//Derived class
class B: virtual public A{};

//Derived class
class C: virtual public A{};

//Hybrid derived class
class D: public B, public C{
    public:
        void Get(){
        //cout<<"x = "<<x<<endl;
        cout<<"y = "<<y<<endl;
        cout<<"z = "<<z<<endl;
        }
};

int main(){
    D d;
    d.Get();

    return 0;
}

