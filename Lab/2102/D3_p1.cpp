#include <iostream>
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

void Display(int *arr, int s){
    for(int i = 0; i < s; i++) cout<<" "<<arr[i];
}

void Union(int *A, int sa, int *B, int sb){
    int size = sa + sb;
    int U[size];
    int k = 0;
    for (int i = 0; i < sa; i++, k++)
        U[i] = A[i];
    for (int i = 0; i < sb; i++, k++){
        U[k] = B[i];
    }
    int end = removeDuplicates(U, sa + sb);
    cout << "A U B = { ";
    for (int i = 0; i < end; i++)
        cout << U[i] << " ";
    cout << "}" << endl;
}

void Intersection(int *A, int a, int *B, int b){
    cout << "A ^ B = {";
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            if (A[i] == B[j]){
                cout << " " << A[i];
            }
        }
    }
    cout << " }" << endl;
}

void Complement(int *A, int sa, int *B, int sb){
    int size = sa + sb;
    int U[size];
    int k = 0;
    for (int i = 0; i < sa; i++, k++)
        U[i] = A[i];
    for (int i = 0; i < sb; i++, k++){
        U[k] = B[i];
    }
    int end = removeDuplicates(U, sa + sb);
    cout<<"A' = {";
    for(int i = 0,count; i < end; i++){
        count = 0;
        for(int j = 0; j < sa; j++){
            if(U[i]==A[j]) {
                count++;
                break;
            }
        }
        if(!count) cout<<" "<<U[i];
    }
    cout<<" }"<<endl;

}

void Difference(int *A, int a, int *B, int b){
    cout<<"A - B = {";
    for(int i = 0; i < a; i++){
        int count = 0;
        for(int j = 0; j < b; j++){
            if(A[i]==B[j]){
                count++;
                break;
            }
        }
        if(!count) cout<<" "<<A[i];
    }
    cout<<" }"<<endl;

    cout<<"B - A = {";
    for(int i = 0; i < b; i++){
        int count = 0;
        for(int j = 0; j < a; j++){
            if(B[i]==A[j]){
                count++;
                break;
            }
        }
        if(!count) cout<<" "<<B[i];
    }
    cout<<" }"<<endl;
}

void SymmetricDiff(int *A, int sa, int *B, int sb){
    cout<<"A @ B = {";
    for(int i = 0; i < sa; i++){
        int count = 0;
        for(int j = 0; j < sb; j++){
            if(A[i]==B[j]){
                count++;
                break;
            }
        }
        if(!count) cout<<" "<<A[i];
    }
    for(int i = 0; i < sb; i++){
        int count = 0;
        for(int j = 0; j < sa; j++){
            if(B[i]==A[j]){
                count++;
                break;
            }
        }
        if(!count) cout<<" "<<B[i];
    }
    cout<<" }"<<endl;
}

int main()
{
    int sa, sb;
    cout << "Enter no. of elements of set A:" << endl;
    cin >> sa;
    int A[sa];
    cout << "Enter the elements of A:" << endl;
    for (int i = 0; i < sa; i++)
        cin >> A[i];

    cout << "Enter no. of elements of set B:" << endl;
    cin >> sb;
    int B[sb];
    cout << "Enter the elements of B:" << endl;
    for (int i = 0; i < sb; i++)
        cin >> B[i];
    int a = removeDuplicates(A,sa);
    int b = removeDuplicates(B,sb);
    cout<<endl;
    cout<<"A = {";
    Display(A,a);
    cout<<" }"<<endl;
    cout<<"B = {";
    Display(B,b);
    cout<<" }"<<endl;
    Union(A, a, B, b);
    Intersection(A, a, B, b);
    Complement(A,a,B,b);
    Difference(A,a,B,b);
    SymmetricDiff(A,a,B,b);
}