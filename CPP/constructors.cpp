#include<iostream>
using namespace std;

class Class{
    private:
        int a;
        int b;
    public:
        //default constructor
        Class(){
            cout<<"Default constructor initialized"<<endl;
            a = 0;
            b = 0;
        }
        //parameterized constructor
        Class(int x, int y){
            cout<<"Parameterized constructor initialized"<<endl;
            a=x;
            b=y;
        }
        //copy constructor
        Class(const Class &p){
            cout<<"Copy constructor initialized"<<endl;
            this->a = p.a;
            b = p.b;
        }
        
        void Get(){
            cout<<"a = "<<a<<" b = "<<b<<endl;
        }

        ~Class(); // destructor prototype

};
//destructor definition
Class:: ~Class(){
    cout<<"Destructor initiated"<<endl;
}

Class o7; // global object

int main(){
    Class o1; //default constructor will initiate
    o1.Get();

    Class o2(2,3); //parameterized constructor will initiate
    o2.Get();

    Class o3(o1); //copy construtor will initiate
    o3.Get();

    Class o4; //default constructor will initiate
    o4.Get();
    o4 = o1; //copy constructor will not initialize as it is already initialized by default constructor
    o4.Get();
    
    Class o5 = o2; // copy constructor will initialize
    o5.Get();

    Class *pto6 = new Class(); // creates a pointer(of type Class) to a new object of type Class in heap which is initialized by default constructor
    pto6->Get();

    return 0;
}