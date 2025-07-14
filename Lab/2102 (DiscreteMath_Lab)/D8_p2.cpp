//Combination in lexicographic order
#include<iostream>
using namespace std;

int search(int *arr, int size, int target){
    int index = -1;
    for(int i = 0; i < size; i++){
        if(arr[i] == target)
            index = i;
    }
    return index;
}


int main(){
    int sizeOfS;
    cout<<"Enter the number of elements of set S : ";
    cin>>sizeOfS;
    cout<<"Enter the elements of set S in ascending order: "<<endl;
    int S[sizeOfS];
    for(int i = 0; i < sizeOfS; i++) cin>>S[i];
    cout<<"Enter a number with digits from set S : ";
    string number;
    cin>>number;
    int sizeOfArr = number.size();
    int arr[sizeOfArr];
    for(int i = 0; i < sizeOfArr; i++) arr[i] = number[i] - '0';

    int i = sizeOfArr - 1;
    int j = sizeOfS - 1;
    while(arr[i] == S[j]){
        i--;
        j--;
    }

    int l = search(S, sizeOfS, arr[i]);
    if(l == -1){
        cout<<"Invalid S. Digit not found in S"<<endl;
        return 0;
    }
    cout<<"l = "<<l<<endl;
    l++;
    for(int k = i; k < sizeOfArr; k++){
        arr[k] = S[l];
        j++;
        l++;
    }
    for(int i = 0; i < sizeOfArr; i++) cout<<arr[i];
    cout<<endl;
    


}