//constructor,copy constructor, static, const
#include<iostream>
using namespace std;

class Test{
    private:
        int x;
        int y;
        static int z;
        static int d;
    public:
        
        Test()
        {
            x = 0;
            y = 0;
            z++;
        }
        
        Test(int a, int b)
        {
            x = a;
            y = b;
            z++;
        }

        Test(Test &o1) // copy constructor method
        {
            x = o1.x;
            y = o1.y;
            z++;
        }

        void Display()const{
            d++;
            cout<<"Object No. "<<d<<endl;
            cout<<"x = "<<x<<endl;
            cout<<"y = "<<y<<endl;
            cout<<"z = "<<z<<endl;
        }
        static int getz(){
            return z;
        }
        int getx(){
            return x;
        }
        int gety(){
            return y;
        }

};
int Test::z; // will get initialized to zero automatically
int Test::d=0;

int main(){
    Test o1(1,2),o2(o1),o3(11,22),o4,o5(1,3);
    o4 = o3;  
    o1.Display();
    o2.Display();
    o3.Display();
    o4.Display();
    o5.Display();
    int sum = o1.getx()+o2.getx()+o3.getx()+o4.getx()+o5.getx();
    cout<<"Sum of x = "<<sum<<endl;
    int index = 1;
    int max = o1.gety();
    if(o2.gety()>max){
        max = o2.gety();
        index = 2;
    }
    if(o3.gety()>max){
        max = o3.gety();
        index = 3;
    }
    if(o4.gety()>max){
        max = o4.gety();
        index = 4;
    }
    if(o5.gety()>max){
        max = o5.gety();
        index = 5;
    }
    cout<<"Max = "<<max<<" Object No. "<<index<<endl;
    return 0;
}