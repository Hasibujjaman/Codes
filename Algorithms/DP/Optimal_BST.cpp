//Bottom-up DP
//O(n^3)
#include<iostream>
#include<climits>
#include<vector>
#include <iomanip> // for std::fixed and std::setprecision
using namespace std;
#define INF INT_MAX


void Construct_Optimal_Subtree(vector<vector<int>> root, int i, int j, int r, string dir){
    if(i>j)
        cout<<"d"<<j<<" is the "<<dir<<" child of "<<"k"<<r<<endl;
    else{
        int t = root[i][j];
        cout<<"k"<<t<<" is the "<<dir<<" child of "<<"k"<<r<<endl;
        Construct_Optimal_Subtree(root,i,t-1,t,"left");
        Construct_Optimal_Subtree(root,t+1,j,t,"right");
    }

}
void Construct_Optimal_BST(vector<vector<int>> root, int n){
    int r = root[1][n];
    cout<<"k"<<r<<" is the root"<<endl;
    Construct_Optimal_Subtree(root,1,r-1,r,"left");
    Construct_Optimal_Subtree(root,r+1,n,r,"right");
}


void Optimal_BST(float *p, float *q, int n){
    vector<vector<float>> e,w; //e[1:n+1,0:n] for calculating optimal value 
    vector<vector<int>> root;
    e.resize(n+2,vector<float>(n+1));
    w.resize(n+2,vector<float>(n+1));
    root.resize(n+1,vector<int>(n+1));
    

    for(int i = 1; i <= n+1; i++){
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    for(int l = 1; l <= n; l++){
        for(int i = 1; i <= n-l+1; i++){
            int j = i + l - 1;
            e[i][j] = INF;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for(int r = i; r <= j; r++){
                float t = e[i][r-1] + e[r+1][j] + w[i][j];
                if(t < e[i][j]){
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
    cout<<"\nDP table: "<<endl;
    cout<<fixed<<setprecision(2);
    for(int i = 1; i <= n+1; i++){
        for(int j = 0; j <= n; j++){
            cout<<e[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nExpected search cost of Optimal BST / Optimal soln value: "<<e[1][n]<<endl<<endl;
    cout<<"\nOptimal BST / Optimal soln:"<<endl;

    Construct_Optimal_BST(root, n);
}





int main(){
    int n = 5; //no. of keys
    float p[n+1] = {NULL,0.15,0.10,0.05,0.10,0.20}; // probabilities corresponding to the n keys(ki): p1,p2,...,pn
    float q[n+1] = {0.05,0.10,0.05,0.05,0.05,0.10}; // probabilities corresponding to the (n+1) dummy keys(di): q0,q1,....,qn

    Optimal_BST(p,q,n);
    cout<<endl;

}