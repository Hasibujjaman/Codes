//Topic 6
#include<iostream>
#include<utility>
#include<stack>
using namespace std;

int main(){
     stack <int> s;
     if(s.empty()) cout<<"Stack empty"<<endl;
     s.push(10);
     s.push(20);
     s.push(30);
     s.push(100);
     cout<<"Top 1 = "<<s.top()<<endl;
     s.pop();
     cout<<"Top 1 = "<<s.top()<<endl;
     if(s.empty()) cout<<"Stack empty"<<endl;
     cout<<"Stack size: "<<s.size()<<endl;
     stack <int> ss;
     ss.push(200);
     s.swap(ss);
     cout<<"Top 1 = "<<s.top()<<endl;
     cout<<"Top 2 = "<<ss.top()<<endl;


}