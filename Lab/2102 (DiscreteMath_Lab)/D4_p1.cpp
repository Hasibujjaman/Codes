#include<iostream>
using namespace std;

int main(){
    int sum = 0;
    for(int j = 1; j <= 3; j++){
        for(int i = 0; i <= 8; i++){
            sum+= (3*i + 4*j);
        }
    }
    cout<<"Sum = "<<sum<<endl;
}