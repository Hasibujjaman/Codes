#include<iostream>
using namespace std;
int sum;

void Summation(int level, int *LL, int *UL, int*coeff){

if(level == 0){
    return;
}
int temp = 0;
int ll = LL[level-1];
int ul = UL[level-1];
int diff = ul - ll + 1;

for(int i = ll; i <= ul; i++){
    temp += coeff[level-1]*i;

}
//cout<<"Temp = "<<temp<<endl;
sum = sum*diff + temp;
temp = 0;

for(int i = 0; i < level; i++) 
    coeff[i] *= diff;
--level;
//cout<<"*TSum is : "<<sum<<endl;
Summation(level,LL,UL,coeff);

}


int main(){
    int n;
    cout<<"Enter number of summation(s): ";
    cin>>n;

    int LL[n],UL[n];
    for(int i = 0; i < n ; i++){
        cout<<"Enter the lower limit of summation "<<i+1<<" : ";
        cin>>LL[i];
        cout<<"Enter the upper limit of summation "<<i+1<<" : ";
        cin>>UL[i];
    }

    int coeff[n];
    cout<<"Enter coefficient(s) of the expression: "<<endl;
    for(int i = 0; i < n; i++){
        cin>>coeff[i];
    }

    Summation(n,LL,UL,coeff);
    cout<<"Result is : "<<sum<<endl;

}