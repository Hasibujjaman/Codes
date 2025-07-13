//newton's forward and newton's backward interpolation formula
#include <iostream>
#include <vector>
using namespace std;
void differenceTable(vector<vector<double>>& table, vector <double>& x,  vector<double>& y);

// Function to generate forward difference table
void differenceTable(vector<vector<double>>& table, vector <double>& x,  vector<double>& y) {
    int n = y.size();

    // Initialize the table with y values
    table.assign(n, vector<double>(n, 0)); //table[][] will not contain x values in it as we don't need it 
    for (int i = 0; i < n; ++i) {
        table[i][0] = y[i];
    }

    // Generate the forward difference table
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            table[i][j] = table[i + 1][j - 1] - table[i][j - 1];
        }
    }
    //show table
    cout << "Difference Table:\n\n";
    int i = 0;
    for ( auto& row : table) {
        cout<<x[i++]<<"\t";
        for (double value : row) {
            cout << value << "\t";
        }
        cout << "\n";
    }



}

int factorial(int n) 
{ 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 

double pTerm(double X, double Xo, double h, int r, char c){
    double p = (X - Xo) / h; // this is value of p here
    double result = p;
    for(int i = 1; i < r; i++){
        p = (X - Xo) / h;
        if(c == 'f'){ // c = 1 for forward
            p = (p - i);
        }
        else if(c == 'b'){ // c== 2 for backward
            p = (p + i);
        }
        else{
            //wrong choice

        }
        result *= p;
    }

    return result/factorial(r);

}


// Function to calculate Newton's Forward Interpolation
void newtonForwardInterpolation( vector<vector<double>>& table,  vector<double>& x,  vector<double>& y) {
    double xValue;
    cout<<"Enter value of x: ";
    cin>>xValue;
    differenceTable(table, x , y);
    int n = x.size(); // this is n+1 points 
    double h = x[1] - x[0];
    double result = table[0][0]; //y0
    double coeff = 1; // for the first term
    //calutaion of terms from second onwards
    for (int j = 1; j < n; ++j) {

        //term *= (xValue - x[j - 1]) / static_cast<double>(j);
        coeff = pTerm(xValue, x[0], h, j, 'f'); // 
        result += coeff * table[0][j];
    }
    
    cout<<"\ny("<<xValue<<") = "<<result<<endl<<endl;
}


void newtonBackwardInterpolation( vector<vector<double>>& table,  vector<double>& x,  vector<double>& y){
    double xValue;
    cout<<"Enter value of x: ";
    cin>>xValue;
    differenceTable(table, x , y);

    int size = x.size(); //size = n + 1
    double result = table[size-1][0]; //yn
    double h = x[1] - x[0];
    double coeff = 1; // for the first term 
    //calutaion of terms from second onwards
    for (int j = 1,i = size-2; j < size; ++j,--i) {

        //term *= (xValue - x[j - 1]) / static_cast<double>(j);
        coeff = pTerm(xValue, x[size-1], h, j, 'b');
        result += coeff * table[i][j];
    }

    cout<<"\ny("<<xValue<<") = "<<result<<endl<<endl;
}


int main() {
    vector<vector<double>> differenceTable;
    int n;
    cout<<"Enter no of points: ";
    cin>>n;
    vector<double> x(n,0);
    vector<double> y(n,0);
    for(int i = 0 ; i < n; i++){
        cout<<"Enter (X"<<i<<",Y"<<i<<"): ";
        cin>>x[i]>>y[i];
    }

    int choice;
    while(1){
        cout<<"########### MENU ###########"<<endl;
        cout<<"\nEnter your choice: "<<endl;
        cout<<"(1). Newton's Forward Interpolation\n(2). Newton's Backward Interpolation\n(3). Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            newtonForwardInterpolation(differenceTable, x, y);
            break;
        case 2:
            newtonBackwardInterpolation(differenceTable, x, y);
            break;
        case 3:
            return 0;
        default:
            cout<<"Wrong input"<<endl;
            break;
        }
    }

    // Display the result
    // cout << "\nNewton's Forward Interpolation at x = " << xValue << " is: " << interpolationResult << "\n";

    return 0;
}
