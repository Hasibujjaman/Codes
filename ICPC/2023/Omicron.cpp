#include<iostream>
using namespace std;

int main(){
    int t, x,y,z,k,a,b,c;
    cin>>t;
    long long i = 0;
    while(t--){
        long long check = 0;
        cin>>x>>y>>z>>k;
        long long sum = x + y + z;
        if(sum%3==0){
            long long ss = sum/3;
            if((ss-x)%k) check++;
            if((ss-y)%k) check++;
            if((ss-y)%k) check++;

            if(!check) cout<<"Case "<<++i<<": Peaceful"<<endl;
            else cout<<"Case "<<++i<<": Fight"<<endl;

        }
        else cout<<"Case "<<++i<<": Fight"<<endl;

    }
}