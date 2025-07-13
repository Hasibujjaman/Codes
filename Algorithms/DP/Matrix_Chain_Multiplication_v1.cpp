//plain recursion, no DP tecniques are used
//T(n) = O(2^n)
#include<iostream>
#include <climits>

using namespace std;
#define INF INT_MAX


int Recursive_Matrix_Chain(int **m, int **s, int *p, int i, int j){

    if(i == j)
        return 0;

    m[i][j]= INF;
    for(int k = i; k <= j-1; k++){
        int q = Recursive_Matrix_Chain(m,s,p,i,k) + Recursive_Matrix_Chain(m,s,p,k+1,j) + p[i-1]*p[k]*p[j];
        if(q < m[i][j]){
            m[i][j]=q;
            s[i][j]=k;
        }
    }
    return m[i][j];
}

void Print_Optimal_Soln(int **s, int i, int j){
    if(i == j)
        cout<<"A"<<i;
    else{
        cout<<"(";
        Print_Optimal_Soln(s,i,s[i][j]);
        Print_Optimal_Soln(s,s[i][j]+1,j);
        cout<<")";
    }
}

int main(){
int n = 6; //no. of matrices
int p[n+1] = {30,35,15,5,10,20,25}; // matrices dimensions, (p0*p1),(p1*p2),....,(p5*p6)

//making an 2d array that can be passed to a function
int rows = n+1, cols = n+1;
    int **m = new int*[rows]; //m[i][j] will hold the value of the solution of the subproblem Ai.Ai+1....Aj-1.Aj
     int **s = new int*[rows]; //s[i][j] will hold the kth index that achieved optimal cost in computing subproblem Ai.Ai+1....Aj-1.Aj
    for (int i = 0; i < rows; ++i) {
        m[i] = new int[cols];
        s[i] = new int[cols];
    }

Recursive_Matrix_Chain(m,s,p,1,n);
cout<<"\nOptimal soln value (minimum number of scalar multiplication): "<<m[1][n]<<endl;
cout<<"Optimal soln: ";
Print_Optimal_Soln(s,1,n);
cout<<endl<<endl;


}