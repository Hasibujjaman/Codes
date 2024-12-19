#include<iostream>
#include<math.h>
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


int main(){
    int sa, sb;
    cout << "Enter no. of domain elements :" << endl;
    cin >> sa;
    int A[sa];
    cout << "Enter the domain elements :" << endl;
    for (int i = 0; i < sa; i++)
        cin >> A[i];

    cout << "Enter no. of co-domain elements :" << endl;
    cin >> sb;
    int B[sb];
    cout << "Enter the co-domain elements:" << endl;
    for (int i = 0; i < sb; i++)
        cin >> B[i];
    int a = removeDuplicates(A,sa);
    int b = removeDuplicates(B,sb);
    cout<<"Choose function : "<<endl;
    cout<<"1. f(x) = x^2 + 1"<<endl;
    cout<<"2. f(x) = x^3 + x^2 - x -1"<<endl;
    cout<<"3. f(x) = x^5 - x^2 + x"<<endl;
    int c1,c2;
    cin>>c1;
    switch (c1)
    {
    case 1: 
        c2 = 1;
        break;
    case 2:
        c2 = 2;
        break;
    case 3:
        c2 = 3;
        break;
    default:
        cout<<"Invalid input"<<endl;
        return 0;
    }

    int Range[a];
    for(int i = 0; i < a; i++){
        int x = A[i];
        if(c2==1) Range[i] = pow(x,2) + 1;
        else if(c2==2) Range[i] = pow(x, 3) + pow(x, 2) - x - 1;
        else Range[i] = pow(x, 5) - pow(x, 2) + x;
    }

    for(int i = 0; i < a; i++){
        int count = 0;
        for(int j = 0; j < b; j++){
            if(Range[i]==B[j]){
                count++;
                break;
            }
        }
        if(!count) {
            cout<<"Not a function"<<endl;
            return 0;
        }
    }
    for(int i = 0; i < a-1; i++){
        for(int j = i+1; j < a; j++){
            if(Range[i]==Range[j]){
                cout<<"Function is not injective"<<endl;
                return 0;
            }
        }
    }
    cout<<"Function is injective"<<endl;
    
}