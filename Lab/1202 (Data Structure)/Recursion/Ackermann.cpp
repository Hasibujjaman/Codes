//Module 6 Topic 3
#include<iostream>
using namespace std;

int Ackermann(int m, int n){
    if(m<0 || n<0) return -1;
    if(!m) return n+1;
    if(m>0 && !n) return Ackermann(m-1,1);
        return Ackermann(m-1,Ackermann(m,n-1));
}

int main(){
    cout<<Ackermann(0,2)<<endl;
    cout<<Ackermann(1,0)<<endl;
    cout<<Ackermann(1,1)<<endl;
    return 0;
}