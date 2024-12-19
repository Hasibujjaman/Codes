// Topic 3
#include<iostream>
#include<array>
using namespace std;

int main(){
    array <int,6> ax={10,60,30,70,20};
    cout<<ax.at(2)<<endl;
    cout<<ax.front()<<endl;
    cout<<ax.back()<<endl;
    //ax.fill(1);
    cout<<ax.front()<<endl;
    cout<<ax.back()<<endl;
    if(ax.empty()){
        cout<<"Array is empty"<<endl;
    }
    else cout<<"Array is not empty"<<endl;
    cout<<ax.size()<<endl;
    cout<<ax.max_size()<<endl;
    cout<<ax.begin()<<endl;
    cout<<ax.end()-1<<endl;
    swap((ax.front()),(ax.back()));
    cout<<ax.at(0)<<endl;
    array <int,6> bx = {};
    swap(ax,bx);
    cout<<bx.back()<<endl;

    array <int,3> cx;
    cx.at(0) = 1;
    cx[1] = 2;
    cx.at(2) = 3;
    cout<<cx.back()<<endl;
    
}