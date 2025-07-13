#include<iostream>
using namespace std;


int main(){
    int n,k;
    cout<<"Enter n , k : ";
    cin>>n>>k;
    int A[n],B[n],C[k+1];
    cout<<"Enter n elements (0 <= element <= k): "<<endl;
    for(int j = 0 ; j < n; j++)
        cin>>A[j];

    for(int i = 0 ; i < k+1; i++)
        C[i] = 0;

    for(int i = 0; i < n; i++)
        C[A[i]]++;
    
    for(int i = 1; i < k+1; i++)
        C[i] = C[i] + C[i-1];
    for(int j = 0; j < k+1; j++)
        cout<<C[j]<<endl;

    for(int i = n-1; i >= 0 ; i--){  // to maintain stable sort we need to traverse from right to left
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;   // to handle duplicate values 
    }

    cout<<"\nSorted array :"<<endl<<endl;
    for(int j = 0; j < n; j++){
        cout<<B[j]<<" ";
    }
    cout<<endl;
}