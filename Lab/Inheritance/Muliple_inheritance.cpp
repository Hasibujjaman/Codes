//Topic 2 iii)
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
//Base class
class B{
    public:
        int p;
    protected:
        int q;
    public:
        int r;
        void Set(){
            p = 10;
            q = 20;
            r = 30;
        }
};

//Multiple inheritance
class C: public A, public B{
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
        /*
        int GetP(){
            return p;
        }
        */
        int GetQ(){
            return q;
        }
        int GetR(){
            return r;
        }
};

int main(){
    C c;
   // c.Set(); Set() is ambigues
    c.A::Set();
    c.B::Set();
    //cout<<"x = "<<b.GetX()<<endl;
    cout<<"y = "<<c.GetY()<<endl;
    cout<<"z = "<<c.GetZ()<<endl;
    //cout<<"p = "<<c.GetP()<<endl;
    cout<<"q = "<<c.GetQ()<<endl;
    cout<<"r = "<<c.GetR()<<endl;
    return 0;
}

