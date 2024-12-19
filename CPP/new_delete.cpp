#include<iostream>
using namespace std;

class Rectangle{
    private:
        int width;
        int length;
    public:
        void Set(int w, int l);
        int area();
        void Get(){
            cout<<width<<endl;
            cout<<length<<endl;
        }
};
void Rectangle::Set(int w, int l){
    width = w;
    length = l;
}
int Rectangle::area(){
    return width*length;
}

int main(){
    Rectangle r1;
    r1.Set(5,8);
    Rectangle *p1;
    p1 = &r1;
    r1.Get();
    cout<<r1.area()<<endl;
    p1->Set(8,10);
    r1.Get();
    cout<<r1.area()<<endl;
    cout<<"\n\n";

    Rectangle *p2;
    p2 = new Rectangle(); // new keyword dynamicallly allocates memory in heap
    p2->Set(10,20);
    p2->Get();
    delete p2; // delete keyword destroys/deallocates memory in heap that is allocated via new keyword
   // p2 = NULL;
    p2->Get();



    
}