#include<iostream>
using namespace std;

class Today{
    private:
        int x;
        static int y;
    public:
        void Set(int a, int b){
            x = a;
            y = b;
        }

        void Get(){
            cout<<"y = "<<y<<endl;
        }
    
    
};

int Today :: y = 1;

int main(){
    Today o,p;
    o.Get();
    p.Get();

}