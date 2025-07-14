#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter cardinality of set A: ";
    cin>>a;
    char setA[a];
    cout<<"Enter element(s) of set A: "<<endl;
    for(int i = 0; i < a; i++){
        char x;
        cin>>x;
        setA[i] = x;
    }
    cout<<"Enter cardinality of set B: ";
    cin>>b;
    char setB[b];
    cout<<"Enter element(s) of set B: "<<endl;
    for(int i = 0; i < b; i++){
        char x;
        cin>>x;
        setB[i] = x;
    }
    cout<<"A x B = { ";
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            cout<<"("<<setA[i]<<","<<setB[j]<<"), ";
        }
    }
    cout<<" }"<<endl;

}