//Topic 1
#include<iostream>
using namespace std;

class Test{
    public:
        int Sum(int x){
            return x;  
        }
        int Sum(int x, int y){
            int s = x + y;
            return s;
        }
        float Sum(float x, int y){
            
            return x+y;
        }
        float Sum(int x, float y){
            float s = x + y;
            return s;
        }
        double Sum(double x, double y){
            return x + y;
        }
};

int main(){
    Test t;
    cout<<t.Sum(10)<<endl;
    cout<<t.Sum(10,20)<<endl;
    cout<<t.Sum(5.7f,20)<<endl; // a floating point is considered double unless specifically specified
    cout<<t.Sum(10,2.6f)<<endl; 
    cout<<t.Sum(10.5,20.7)<<endl;

}