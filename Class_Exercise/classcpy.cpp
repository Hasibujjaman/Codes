#include<iostream>
using namespace std;

class Today{
    private:
        int x;
        int y;
    public:
        void Set(int a, int b){
            x = a;
            y = b;
        }

        void Get(){
            cout<<"y = "<<y<<" x = "<<x<<endl;
        }

        void SetDataCopy(Today &a){
            y = a.y;
            x = a.x;
        }
    
    
};

int main(){
    Today s,t;
    t.Set(10,20);
    s.SetDataCopy(t);
    t.Get();
    cout<<"\n";
    s.Get();

}