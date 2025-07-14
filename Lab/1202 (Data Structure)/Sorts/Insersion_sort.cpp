//Module 7 Topic 1
#include<iostream>
using namespace std;
void Insertion(int arr[]){
    int i,j,key;
    for(i = 1; i<7; i++){
        key = arr[i];
        for(j = i-1; j >= 0 && key < arr[j]; j--){
            arr[j+1] = arr[j];
          
        }
        arr[j+1] = key;
    }
}
void Display(int *arr){
    for(int i = 0; i < 7; i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}

int main(){
    int ax[7]={10,78,32,90,20,19,25};
    cout<<"Before sorting"<<endl;
    Display(ax);
    Insertion(ax);
    cout<<"After sorting"<<endl;
    Display(ax);
}
