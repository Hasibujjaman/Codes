#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int sum = 0;
    for(int i = 1; i <= 3; i++){
        for(int j = 0; j <= 4; j++){
            sum += (pow(2,i) + pow(3,j));
        }
    }
    cout<<"Sum = "<<sum<<endl;
}