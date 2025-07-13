//Topic 2 i)
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

//Single inheritance
class B: public A{
    public:
       /* 
       int GetX(){
            return x; // private members are not accessable
        } 
        */
        int GetY(){
            return y;
        }
        int GetZ(){
            return z;
        }
        void Set(){
            y = 2;
            z = 3;
        }
};

int main(){
    B b;
    b.Set();
    //cout<<"x = "<<b.GetX()<<endl;
    cout<<"y = "<<b.GetY()<<endl;
    cout<<"z = "<<b.GetZ()<<endl;
}

