// Topic 1
#include<iostream>
using namespace std;

int main(){
    int i;
    int ax[5] = {10,20,60,40,30};
    cout<<"enter index: ";
    cin>>i;
    try{
        if(i>4 || i<0) throw "Out of Range Error";
        throw i;
    }
    catch(char const *c){
        cout<<c<<endl;
    }
    catch(int i){
        cout<<i<<endl;
    }
    catch(...){
        cout<<"Other errors"<<endl;
    }
    return 0;
}