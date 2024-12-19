//Module 7 Topic 4
#include<iostream>
using namespace std;
#define size 7
int a[size] = {10,78,32,90,20,19,25};
int b[size];
void Display(int *a){
    for(int i = 0; i < size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void Merge(int l, int m, int h){
    int i,j,k;
    i = l;
    j = m+1;
    k = l;
    while (i <= m && j <= h)
    {
        if(a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++]; 
    }
    for(int p = i; p <= m; p++){
        b[k++] = a[p];
    }
    for(int p = j; p <= h; p++){
        b[k++] = a[p];
    }

    for(int i=l ;i<=h ;i++)
        a[i]=b[i];

   // Display(b);

}
void M_Sort(int l, int h){
    if(l<h){
        int m = (l+h)/2;
        M_Sort(l,m);
        M_Sort(m+1,h);
        Merge(l,m,h);
    }
}

int main(){
    Display(a);
    M_Sort(0,6);
    Display(a);
    
}

