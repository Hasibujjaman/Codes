//Topic 2 iv)
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
class B: public A{

    public:
        void Get(){
        //cout<<"x = "<<x<<endl;
        cout<<"y = "<<y<<endl;
        cout<<"z = "<<z<<endl;
        }
};

//Derived class
class C: public A{
    public:
       void Get(){
        //cout<<"x = "<<x<<endl;
        cout<<"y = "<<y<<endl;
        cout<<"z = "<<z<<endl;
        }
};

int main(){
    B b;
    C c;
    b.Set();
    c.Set();
    b.Get();
    c.Get();

    return 0;
}

