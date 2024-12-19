#include<iostream>
using namespace std;

int main(){
    int p[] = {0,1};
    int q[] = {0,1};
    int x,y;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(!p[i] && (!p[i]||q[j])) x = 1;
            else x = 0;
            cout<<"p = "<<p[i]<<" q = "<<q[j]<<" p'^(p->q) = "<<x<<endl;
        }
    }
    cout<<endl<<endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(p[i] || (p[i]||q[j])) x = 1;
            else x = 0;
            cout<<"p = "<<p[i]<<" q = "<<q[j]<<" p||(q'->p) = "<<x<<endl;
        }
    }
    
}