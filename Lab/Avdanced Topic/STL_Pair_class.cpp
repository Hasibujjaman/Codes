// Topic 4
#include<iostream>
#include<utility>
#include<string>
using namespace std;

int main(){
    pair<int,string> px(10, "Rajshahi");
    cout<<px.first<<endl;
    cout<<px.second<<endl;
    get<int>(px) = 20; // get<0>(px) = 20; also works
    pair<int,string> bx(30, "Dhaka");
    px.swap(bx); // swap(px,bx); also works
    cout<<"After swapping:"<<endl<<px.first<<endl<<px.second<<endl;

}
