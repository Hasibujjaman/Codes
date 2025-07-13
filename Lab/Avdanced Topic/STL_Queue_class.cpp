//Topic 7
#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue <int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    cout<<"Front: "<<qu.front()<<" Back: "<<qu.back()<<endl;
    qu.pop();
    cout<<"Front: "<<qu.front()<<" Back: "<<qu.back()<<endl;
    if(!qu.empty()) cout<<"Queue not empty"<<endl;
    
}