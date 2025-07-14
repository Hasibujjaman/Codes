//Topic 5
#include<iostream>
#include<string>
#include<tuple>
using namespace std;

int main(){
    tuple <int,string,float> tx;
    tx = make_tuple(100,"Kamal",3.5);
    cout<<get<0>(tx)<<endl;
    cout<<get<1>(tx)<<endl; //  cout<<get<string>(tx)<<endl; also works
    cout<<get<2>(tx)<<endl;
    get<2>(tx) = 3.7;
    cout<<get<2>(tx)<<endl;
    tuple <int,string,float> bx{200,"Emon",4.0};
    swap(tx,bx); // or, tx.swap(bx); 
    cout<<get<int>(tx)<<" "<<get<string>(tx)<<" "<<get<float>(tx)<<endl;
}