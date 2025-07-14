//CSE 2203 Assignment
//2003001
#include <iostream>
#include <vector>
#include <fstream>
#include<cmath>
using namespace std;
void writePredictionDataToFile(const vector<int>&, const vector<double>&, const string&);

//This function generates forward difference table. This function is needed for using Newton's Forward Interpolation.
void differenceTable(vector<vector<double>>& table, vector <int>& x,  vector<double>& y) {
    int n = y.size();

    // Initialize the table with y values
    table.assign(n, vector<double>(n, 0));
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
    // cout << "Difference Table:\n\n";
    // int i = 0;
    // for ( auto& row : table) {
    //     cout<<x[i++]<<"\t";
    //     for (double value : row) {
    //         cout << value << "\t";
    //     }
    //     cout << "\n";
    // }
}

//Utility function which retruns the factorial of a given input value . Needed in Newton's Forward Interpolation.
int factorial(int n) 
{ 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 
//Utility function which calculated the p or u terms of Newton's Forward Interpolation Formula.
double pTerm(float p, int m){
    int temp = p;
    for(int i = 1; i < m; i++){
        p = p * (temp - i);
    }
    return p/factorial(m);
}

double newtonForwardInterpolation( vector<vector<double>>& table,  vector<int>& x,  vector<double>& y, int t) {
    double targetYear;
    if(t > 0){
        targetYear = t;
    }
    else{
        cout<<"Enter the target year: ";
        cin>>targetYear;
    }
    differenceTable(table, x , y);
    int n = x.size(); // this is n+1 points 
    double p = (targetYear - x[0]) / (x[1]-x[0]);
    double result = table[0][0]; //y0
    double coeff = 1; // for the first term
    //calutaion of terms from second onwards
    for (int i = 1; i < n; ++i) {
        coeff = pTerm(p,i); // 
        result += coeff * table[0][i];
    }
    if(t < 0)
        cout<<"In year "<<targetYear<<" , the popolation will be : "<<result<<endl<<endl;

    return result;
}


//this function returns the functional value of the function that is used in Newton-Raphson method to find its root
double f(double x, double *coeff, int n){
    double result = 0;
    for(int i = 0; i <= n; i++){
        int power = n - i;
        result += coeff[i]*pow(x,power);
    }
    return result;
}
//this fuction rerurns the value of the derivative which is needed in Newton-Raphson method
double Df(double x, double *coeff, int n){
    double result = 0;
    for(int i = 0; i <= n; i++){
        int power = n - i;
        result += coeff[i]*power*pow(x,power-1);
    }
    return result;
}

void Newton_Raphson(){
    //population(t) = 2.08817t - 4050 , this is the assumed mathematical model for the given data . This equation is obtained by applying curve fitting on the population data
    //we have to find the root of the equation, Population(t) - Target_Population = 0
    double Target_Population;
    cout<<"Enter target population(in millions): ";
    cin>>Target_Population;
    int n = 1;
    double coeff[] = {2.08817, -4050 - Target_Population};
    double tolError,x0;
    x0 = 1970; // initial guess
    tolError = 0.01; //tolarable eroor
    double x = x0; //xn
    int i = 0;

    while(1){
        i++;
        double yn = f(x,coeff,n); //f(Xi-1)
        double Dyn = Df(x,coeff,n); // f'(Xi-1)
        double Xi = x - yn/Dyn;
        //cout<<i<<"\tf(X"<<i-1<<") = "<<yn<<"\tf'(X"<<i-1<<") = "<<Dyn<<"\tX"<<i<<" = "<<Xi<<"\tE"<<i<<" = "<<abs(Xi-x)<<endl;
        if(abs(Xi - x) < tolError) {
            cout<<"\nThe year in which the population reaches the target population =  "<<Target_Population<<" is: "<<ceil(Xi)<<endl<<endl;
            break;
        }
        x = Xi;
    }
}


//After plotting the original data (population data of Bangladesh) it was clear that population value was increasing linearly.
//Therefore, fitting a straight line to this data is the best option available.
double LinearCurveFitting( vector<int>& x,  vector<double>& y, int t) {
     vector<vector<double>> table;
    int n = y.size();
    double sumX = 0, sumY = 0, sumX2 = 0, sumXY = 0;
    // Initialize the table with x values and y values
    table.assign(n, vector<double>(n, 0));
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
    double m = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double Xavg = sumX / n;
    double Yavg = sumY / n;
    double c = Yavg - m*Xavg;
    
    if(t < 0){
        cout<<"The fitted curve is:"<<endl;
        if(c > 0)
            cout<<"\nPopulation(t) = "<<m<<"t + "<<c<<endl;
        else
            cout<<"\nPopulation(t) = "<<m<<"t "<<c<<endl<<endl<<endl;
    }

    
    // //show table
    // cout << "\n\nTable:\n\nXi-->Yi--->Xi^2--->XiYi\n\n";
    // int i = 0;
    // for ( auto& row : table) {
    //     for (double value : row) {
    //         cout << value << "--->";
    //     }
    //     cout << "\n";
    // }
    // cout<<"\n\n";


    //Here i have generated data points accroding to the fitted curve(i.e, straight line) and stored them in the file named "population_prediciton_CF.txt" so that i can plot the points and visualize the fitted curve
    vector<int> x_values; 
    vector<double> y_values_Newton, y_values_CurveFit;
    for(int i = 1970; i <= 2030; i++){
        double resultCurveFit = m*i + c;

        x_values.push_back(i);
        y_values_CurveFit.push_back(resultCurveFit);
    }
    writePredictionDataToFile(x_values, y_values_CurveFit, "population_prediciton_CF");

    cout<<"Please check the file named 'CurveFitting_Visualization.png' to visualize the original data points along with the fitted curve"<<endl<<endl;


    return (m*t + c);
}

void writePredictionDataToFile(const vector<int>& years, const vector<double>& populations, const string& filePath) {
    ofstream outputFile(filePath);

    for (int i = 0; i < years.size(); ++i) {
        outputFile << years[i] << " " << populations[i] << endl;
    }

    outputFile.close();
}

//this fuction predicts/extrapolates population in two different ways :
// (i).using Newton's Interpolation and (ii). using Curve Fitting technique and
// compare the results obtained 
void predictAndCompare(vector<vector<double>>& table,  vector<int>& x,  vector<double>& y){
    vector<int> x_values; 
    vector<double> y_values_Newton, y_values_CurveFit;
    for(int i = 2021; i <= 2030; i++){
        double resultNewton = newtonForwardInterpolation(table,x,y,i);
        double resultCurveFit = LinearCurveFitting(x,y,i);

        x_values.push_back(i);
        y_values_Newton.push_back(resultNewton);
        y_values_CurveFit.push_back(resultCurveFit);

        cout<<"\n\n ####### Year "<<i<<" Prediction ########\n"<<endl;
        cout<<"Newton's Interpolation: "<<resultNewton<<endl;
        cout<<"Curve Fitting: "<<resultCurveFit<<endl<<endl;
    }
    cout<<"\nFrom the results it is clear Curve Fitting produces better results in predicting population"<<endl<<endl;
    writePredictionDataToFile(x_values, y_values_Newton, "population_prediction_Newton");
    writePredictionDataToFile(x_values, y_values_CurveFit, "population_prediciton_CF");
    
}


void readPopulationData(const string& filename, vector<int> &year, vector<double> &population) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    while (!inputFile.eof()) {
        int x; double y;
        inputFile >> x >> y;
        if (inputFile.fail()) {
            break; // Exit the loop if there's an issue reading data
        }
        year.push_back(x);
        population.push_back(y);
    }
    inputFile.close();
}


int main() {
    vector<int> x;
    vector<double> y;
    readPopulationData("population_data.txt", x, y);

    vector<vector<double>> differenceTable;
    int choice;
    while(1){
        cout<<"########### MENU ###########"<<endl;
        cout<<"\nEnter your choice: "<<endl;
        cout<<"(1).[part 1]: Predict population using Interpolation \n(2).[part 2]: Find the year to reach a target population\n(3).[part 3]: Fit a curve to the population data \n(4).[part 4]: Predict the population for the next 10 years using different methods and compare the results \n(5).Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            newtonForwardInterpolation(differenceTable,x,y,-1);
            break;
        case 2:
            Newton_Raphson();
            break;
        case 3:
            LinearCurveFitting(x,y,-1);
            break;
        case 4:
            predictAndCompare(differenceTable,x,y);
            break;
        case 5:
            return 0;
        default:
            cout<<"Wrong input"<<endl;
            break;
        }
    }
    return 0;
}
