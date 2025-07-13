//Topic 3 v)
#include<iostream>
using namespace std;

class A{
    
    private:
        int ax;

    public:
        A(){
            ax = 1;
            cout<<"Constructor A executed"<<endl;
        }
        ~A(){
            cout<<"Destructor A executed"<<endl;
        }
        int Getax(){
            return ax;
        }
};

class B: virtual public A {
    private:
        int bx;
    public:
        B(){
            bx = 2;
            cout<<"Constructor B executed"<<endl;
        }
        ~B(){
            cout<<"Destructor B executed"<<endl;
        }
        int Getbx(){
            return bx;
        }
};

class C: virtual public A {
    private:
        int cx;
    public:
        C(){
            cx = 3;
            cout<<"Constructor C executed"<<endl;
        }
        ~C(){
            cout<<"Destructor C executed"<<endl;
        }
        int Getcx(){
            return cx;
        }

};

class D: public B, public C {
    private:
        int dx;
    public:
        D(){
            dx = 4;
            cout<<"Constructor D executed"<<endl;
        }
        ~D(){
            cout<<"Destructor D executed"<<endl;
        }
        void Sum(){
            int sum = Getax() + Getbx() + Getcx() + dx;
            cout<<"ax + bx + cx + dx = "<<sum<<endl;
        }
};

int main(){

D d;
d.Sum();

return 0;
}