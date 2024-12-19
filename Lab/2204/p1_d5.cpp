//Linear curve fitting
#include <iostream>
#include <vector>
using namespace std;

// Function to generate forward difference table
void Table(vector<vector<double>>& table, vector <double>& x,  vector<double>& y) {
    int n = y.size();
    double sumX = 0, sumY = 0, sumX2 = 0, sumXY = 0;
    // Initialize the table with x values and y values
    table.assign(n, vector<double>(4, 0));
    for (int i = 0; i < n; ++i) {
        table[i][0] = x[i];
        table[i][1] = y[i];
        table[i][2] = x[i]*x[i];
        table[i][3] = x[i]*y[i];
        sumX += table[i][0];
        sumY += table[i][1];
        sumX2 += table[i][2];
        sumXY += table[i][3];
    }
    float m = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    float Xavg = sumX / n;
    float Yavg = sumY / n;
    float c = Yavg - m*Xavg;
    
    //show table
    cout << "\n\nTable:\n\nXi---Yi---Xi^2---XiYi\n\n";
    int i = 0;
    for ( auto& row : table) {
        for (double value : row) {
            cout << value << "----";
        }
        cout << "\n";
    }
    cout<<"\n\n";

    cout<<"a0 = "<<c<<"\na1 = "<<m<<endl<<endl;
    cout<<"The fitted curve is: "<<endl;
    if(c > 0)
        cout<<"\ny = "<<m<<"x + "<<c<<endl<<endl;
    else
        cout<<"\ny = "<<m<<"x "<<c<<endl<<endl;

}



// Function to calculate Newton's Forward Interpolation
void LinearCurveFitting( vector<vector<double>>& table,  vector<double>& x,  vector<double>& y) {
    Table(table, x, y);
    

}





int main() {
    vector<vector<double>> Table;
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
        cout<<"(1). Linear curve fitting\n(2). Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            LinearCurveFitting(Table, x, y);
            break;
        break;
        case 2:
            return 0;
        default:
            cout<<"Wrong input"<<endl;
            break;
        }
    }

    return 0;
}
