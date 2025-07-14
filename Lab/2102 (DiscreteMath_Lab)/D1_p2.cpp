#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int Dx[n];
    int Dy[m];

    cout<<"Enter domain of x:"<<endl;
    for(int i = 0; i < n; i++) cin>>Dx[i];
    cout<<"Enter domain of y:"<<endl;
    for(int i = 0; i < m; i++) cin>>Dy[i];

    bool y;

    for(int i = 0; i < n; i++){
        y = false;
        for(int j = 0; j < m; j++){
            if(Dx[i] + Dy[j] > 0) {
                y = true;
                break;
            }
        }
        if(!y){
            cout<<"False"<<endl;
            return 0;
        } 
    }
    cout<<"True"<<endl;


    return 0;

}