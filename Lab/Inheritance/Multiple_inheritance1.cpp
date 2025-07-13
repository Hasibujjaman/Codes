//Topic 3 iii)
#include<iostream>
using namespace std;

class A{
    private:
        int ax;
    public:
        A(){
            ax = 1;
            cout<<"Constructor of A executed"<<endl;
        }
        ~A(){
            cout<<"Destructor of A executed"<<endl;
        }
        int Getax(){
            return ax;
        }
};

class B{
    private:
        int bx;
    public:
        B(){
            bx = 2;
            cout<<"Constructor of B executed"<<endl;
        }
        ~B(){
            cout<<"Destructor of B executed"<<endl;
        }
        int Getbx(){
            return bx;
        }
};

class C: public A, public B{
        private:
            int cx;
        public:
            C(){
                cx = 3;
                cout<<"Constructor of C executed"<<endl;
            }
            ~C(){
                cout<<"Destructor of C executed"<<endl;
            }
            void Sum(){
                int sum = Getax() + Getbx() + cx;
                cout<<"Sum of ax + bx + cx = "<<sum<<endl;
            }


};


int main(){
    C c;
    c.Sum();
}