// Topic 3 i)
#include<iostream>
using namespace std;

//Base class
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
        int Getax(){  // for class B to be able to access class A's private data ax
            return ax; 
        }
};

//Single inheritance
class B: public A{
    private:
    public:
        int bx;
        B(){
            bx = 2;
            cout<<"Constructor of B executed"<<endl;
        }
        ~B(){
            cout<<"Destructor of B executed"<<endl;
        }
        void Show_Sum(){
            int sum = Getax() + bx; // can't access ax directly as private members aren't inherited
            cout<<"Sum of ax + bx is: "<<sum<<endl;
        }

        
};

int main(){
    B b;
    b.Show_Sum();
    return 0;
}