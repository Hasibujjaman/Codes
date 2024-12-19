#include<iostream>
#include<math.h>
using namespace std;
//class definition
class Triangle{
    private:                    //permission lebel
        double a,b,c;                  //member         
    public:                     //permission lebel
        //int A,B,C;                  //member
        Triangle()  // constructor . gets called at the star of the program
        {
            a = 1;
            b = 1;
            c = 1;
        }
        void setter(){
           double A,B,C;
           cout<<"Enter A, B and C :\n";
           cin>>A>>B>>C;
           a = A, b = B; c = C;
        }
        void getter(void){
            cout<<"a = "<<a<<"\nb = "<<b<<"\nc = "<<c<<"\n";
        }
        void area(void){
            double s = (a + b + c)/2;
            double area = sqrt(s*(s-a)*(s-b)*(s-c));
            cout<<"Area = "<<area<<"\n";
            
        }
        void perimeter(void){
            cout<<"Perimeter = "<<(a+b+c)<<"\n";
        }

};

int main() {
    Triangle o;
    o.area();
    o.perimeter();
    o.setter();
    o.getter();
    o.area();
    o.perimeter();
    return 0;
}