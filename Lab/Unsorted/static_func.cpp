#include<iostream>
using namespace std;

class Static{
    int x;
    static int y;

    public:
        Static(){
            x = 1   ;
            y++;
        }
        Static (int a){
            x = a;
            y++;
        }
        static int GetY(){
            // x++; non static members not allowed
            return y;
        }
        void Get(){
            cout<<x<<" ";
            cout<<y<<endl; // static members are allowed in non-static function
        }
        int GetX(){
            return x;
        }

};
int Static :: y = 0;


int main(){
    Static o1;
    o1.Get();
    Static o2(2);
    cout<<o2.GetX()<<" ";
    cout<<Static::GetY()<<endl; // as static members are shared between all the objects it can be written like this


}