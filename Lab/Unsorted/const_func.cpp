#include<iostream>
using namespace std;

class Mutable{
    mutable int x; // makes x modifiable in const functions
    int y;

    public:
        void Set(){
            x = 2;
            y = 0;
        }
        void Get() const;

};
void Mutable::Get() const{
    x--;
    //y = 0; modification is illegal in const function
    cout<<x<<" "<<y<<endl;
}
int main(){
    Mutable o;
    o.Set();
    o.Get();
}