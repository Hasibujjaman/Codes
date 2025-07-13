//Bottom-up DP
//O(mn)
#include<iostream>
#include<string>
using namespace std;

void Print_LSC(char **b, string X, int i, int j);

void LSC(string X, string Y, int m, int n){
    int rows = m, cols = n;
    int **c = new int*[rows+1]; //c[i][j] will hold the value of the solution of the subproblem c[i,j]
    char **b = new char*[rows+1];  //b[i,j] points to the table entry corresponding to the optimal subproblem solution chosen when computing c[i,j] 
    for(int i = 0; i <= rows; i++){
        c[i] = new int[cols+1];
        b[i] = new char[cols+1];
    }

    for(int i = 0; i <= m; i++)
        c[i][0] = 0;
    for(int j = 1; j <= n; j++)
        c[0][j] = 0;
    
    for(int i = 1; i <=m; i++){
        for(int j = 1; j <= n; j++){
            if(X[i-1] == Y[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'D'; //'D' indicates diagonal arrow
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 'U'; //'U' indicates up arrow
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = 'L'; //'L' indicates left arrow
            }
        }
    }
    cout<<"\n\nLenght of the LSC / Optimal soln value is: "<<c[m][n]<<endl;
    // for(int i = 0; i <= m; i++){
    //     for(int j = 0; j <= n; j++){
    //         cout<<b[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<"A LSC is / Optimal soln is: ";
    Print_LSC(b,X,m,n);
    cout<<endl<<endl;
    
}

void Print_LSC(char **b, string X, int i, int j){
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 'D'){
        Print_LSC(b,X,i-1,j-1);
        cout<<X[i-1];
    }
    else if(b[i][j] == 'U')
        Print_LSC(b,X,i-1,j);
    else 
        Print_LSC(b,X,i,j-1);

}



int main(){
    string X,Y;
    cout<<"Enter string X: ";
    getline(cin,X);
    cout<<"Ente string Y: ";
    getline(cin,Y);
    LSC(X,Y,X.size(),Y.size());

}