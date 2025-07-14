//Module 7 Topic 3
#include<iostream>
using namespace std;
int Partition(int *arr, int l, int h){
    int pivot = arr[h];
    int pvt_index = l-1;
    for(int i = l; i < h; i++){
        if(arr[i]<=pivot){
            int temp = arr[i];
            arr[i] = arr[++pvt_index];
            arr[pvt_index] = temp;
        }
    }
    arr[h] = arr[++pvt_index];
    arr[pvt_index] = pivot;
    //cout<<"Pivot = "<<pivot<<" Index = "<<pvt_index<<endl;
    return pvt_index;
}

void Display(int *arr){
    for(int i = 0; i < 7; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void QuickS(int *arr,int low, int high){
    if(low >=high) return;
    //cout<<"Low = "<<low<<" High = "<<high<<endl;
    int part = Partition(arr,low,high);
    //cout<<"After pivot"<<endl;
    //Display(arr);
    QuickS(arr,low,part-1);
    QuickS(arr,part+1,high);
}

int main(){
    int ax[7] = {10,78,32,90,20,19,25};
    cout<<"Before sorting: "<<endl;
    Display(ax);
    cout<<"After sorting: "<<endl;
    QuickS(ax,0,6);
    Display(ax);
}