#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of vertex: ";
    cin>>n;
    int G[n][n];
    int inward[n];
    int outward[n];
    for(int i = 0; i < n; i++){
        inward[i] = 0;
        outward[i] = 0;
        for(int j = 0; j < n; j++){
            G[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        int m;
        cout<<"Enter no of vertexes that are adjecent to vertex "<<i+1<<" : ";
        cin>>m;
        outward[i] = m;
        if(m!= 0)
            cout<<"Enter those vertexes: ";
        for(int j = 0; j < m; j++){
            int v;
            cin>>v;
            inward[v-1]++;
            G[i][v-1]++; 
        }

    }
    for(int i = 0; i < n; i++){
        cout<<"Vertex "<<i+1<<" : In-degree: "<<inward[i]<<" , Out-degree: "<<outward[i]<<endl;
    }
}