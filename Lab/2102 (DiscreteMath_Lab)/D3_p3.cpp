#include <iostream>
#include <math.h>
using namespace std;

int removeDuplicates(int *arr, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){

            if (arr[j] == arr[i]){
                n--;
                for (int k = i; k < n; k++){
                    arr[k] = arr[k + 1];
                }
                i--;
            }
        }
    }
    return n;
}

void PowerSet(int A[], int sa){
    cout<<"P(A) = { ";
    int powsize = pow(2, sa);
    for(int counter = 0; counter < powsize; counter++){
        cout<<"{ ";
        for(int i = 0; i < sa; i++){
            if(counter & (1 << i))
                cout<<A[i]<<" ";
        }
        cout<<" },";
    }
    cout<<" }"<<endl;
}

int main(){
    int sa;   
    cout<<"Enter no. of elements of set A : ";
    cin>>sa;
    int A[sa];
    cout<<"Enter elments of set A : "<<endl;
    for(int i = 0; i < sa; i++) cin>>A[i];
    int a = removeDuplicates(A,sa);
    cout<<"A = {";
    for(int i = 0; i < a; i++) cout<<" "<<A[i];
    cout<<" }"<<endl;
    PowerSet(A,a);
    return 0;
}
