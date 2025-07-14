//Module 6 Topic 4
#include<iostream>
using namespace std;

void TOH(int n, char const *src, char const *aux, char const *dest){
    //cout<<"n = "<<n<<endl<<endl;
    if(n==1) {
        cout<<"Move top disk from "<<src<<" to "<<dest<<endl;
        return;
    }

    TOH(n-1,src,dest,aux);

    cout<<"Move top disk from "<<src<<" to "<<dest<<endl;

    TOH(n-1,aux,src,dest);
}

int main(){
    int n;
    cout<<"Enter no. of disks: ";
    cin>>n;
    TOH(n,"Source","Auxiliary","Destination");
}