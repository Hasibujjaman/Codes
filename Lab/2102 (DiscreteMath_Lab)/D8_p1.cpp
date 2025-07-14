//Permutaion in lexicographic order
#include<iostream>
#include <string>
#include <type_traits>
using namespace std;


int main(){
    string n;
    cout<<"Enter n : ";
    cin>>n;
    
    int size = n.size();
    int arr[size];
    for(int i = 0 ; i < size; i++) 
        arr[i] = n[i] - '0';
    
    int j = size - 2;
    while(arr[j] > arr[j+1])
        j--;
 

    int k = size - 1;
    while(arr[j] > arr[k])
        k--;

    swap(arr[j],arr[k]);

    int r = size - 1;
    int s = j + 1;
    while(r > s){
        swap(arr[r],arr[s]);
        r--;
        s++;
    }
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";

    cout<<endl;




}