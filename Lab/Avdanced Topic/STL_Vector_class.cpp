#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector <int> v;
    if(v.empty()) cout<<"Empty"<<endl;
    cout<<v.size()<<endl;
    v = {1,2};
    cout<<v.size()<<endl;
    cout<<v.max_size()<<endl;
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    v[0] = 100;
    cout<<v.front()<<endl;
    for(int n : v)
        cout<<n<<" ";
    cout<<endl;
    v.at(0) = 1;
    for(int n : v)
        cout<<n<<" ";
    cout<<endl;
}