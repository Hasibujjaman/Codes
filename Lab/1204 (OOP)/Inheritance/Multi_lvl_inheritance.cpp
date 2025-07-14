//Topic 2 ii)
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
};

class B: public A{};

//Muli-level inheritance
class C: public B{
    public:
       /* 
       int GetX(){
            return x; // private members are not inherited
        } 
        */
        int GetY(){
            return y;
        }
        int GetZ(){
            return z;
        }
        void Set(){
        //    x = 1; inaccessable 
            y = 2;
            z = 3;
        }
};

int main(){
    C c;
    c.Set();
    //cout<<"x = "<<b.GetX()<<endl;
    cout<<"y = "<<c.GetY()<<endl;
    cout<<"z = "<<c.GetZ()<<endl;
}

