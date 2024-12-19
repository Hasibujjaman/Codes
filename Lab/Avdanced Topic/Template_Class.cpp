// Topic 2
#include<iostream>
using namespace std;

template <typename T1, typename T2>
class A{
    private:
        T1 x;
        T2 y;
    public:
        void setData(T1 x, T2 y){
            this->x = x;
            this->y = y;
        }
        double Sum(){
            double s;
            s = x + y;
            return  s;
        }

};

int main(){
    A <int,int> a;
    A <int , double> b;
    A <double,int> c;
    A <double,double> d;
    a.setData(1,2);
    b.setData(1,1.1);
    c.setData(1.2,1);
    d.setData(1.1,1.2);
    cout<<a.Sum()<<endl;
    cout<<b.Sum()<<endl;
    cout<<c.Sum()<<endl;
    cout<<d.Sum()<<endl;
    return 0;
}