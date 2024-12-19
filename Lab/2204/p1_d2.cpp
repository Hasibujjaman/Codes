//root finding methods: Iteration Method, Newton-Raphson Method
#include<iostream>
#include<cmath>
using namespace std;
int nBisection,nFalsePosition,nIteration,nNewton_Raphson;
double X[1000];


double f(double x, int *coeff, int n){
    double result = 0;
    for(int i = 0; i <= n; i++){
        int power = n - i;
        result += coeff[i]*pow(x,power);
    }
    return result;
}
double Df(double x, int *coeff, int n){
    double result = 0;
    for(int i = 0; i <= n; i++){
        int power = n - i;
        result += coeff[i]*power*pow(x,power-1);
    }
    return result;
}
void Bisecton_FalsePosiotion(int *coeff, int n,int c){
    double a,b,tolError;
    cout<<"Enter the interval for searching the root: ";
    cin>>a>>b;
    cout<<"Enter tolerable error: ";
    cin>>tolError;
    double fA = f(a,coeff,n);
    double fB = f(b,coeff,n);
    double check = fA*fB;
    if(check > 0) cout<<"No root exists in this interval"<<endl;
    else if (check == 0){
        if(fA == 0) cout<<"The root is "<<a<<endl;
        else cout<<"The root is "<<b<<endl;
        return;
    }
    else {
        int nIteration = 0;

        while(1){
            nIteration++;
            double Xn;
            fA = f(a,coeff,n);
            fB = f(b,coeff,n);

            if(c == 1) Xn = (a + b)/2;
            else {
                //double N = a*fB - b*fA;
               // double D = fB - fA;
                Xn = (a*fB - b*fA)/(fB - fA);
                //cout<<"\nN = "<<N<<"\tD = "<<D<<"\tXn = "<<Xn<<endl;
            }

            double fXn = f(Xn,coeff,n);
            X[nIteration] = Xn;

            cout<<"n = "<<nIteration<<"\ta = "<<a<<"\tb = "<<b<<"\tXn = "<<Xn<<"\tf(Xn) = "<<fXn
                <<"\tf(a) = "<<fA<<"\tf(b) = "<<fB<<endl;

            if(fXn*fA < 0){
                b = Xn;
            }
            else if(fXn*fA > 0){
                a = Xn;
            }
            else{
                cout<<"The root is "<<Xn<<endl;
                return;
            }

            if(nIteration > 1){
                double A = X[nIteration], B = X[nIteration-1];
                double tempEroor = A - B;
                cout<<"Xn = "<<A<<"\tXn-1 = "<<B<<"\tEn-1 = "<<tempEroor<<endl;
                if(abs(tempEroor) <= tolError){
                    cout<<"\nThe aproximate root is: "<<Xn<<endl;
                    if(c == 1) nBisection = nIteration;
                    else nFalsePosition = nIteration;
                    return;
                }
            }

        }
    }
}
void Iteration(){
    //f(x) = x^3 - 2x - 5 = 0
    double tolError,x0;
    cout<<"Enter the the initial approximation of the root: ";
    cin>>x0;
    cout<<"Enter tolerable error: ";
    cin>>tolError;
    int i = 1;
    double x = sqrt(2 + 5/x0); // x1 
    cout<<"\nn\t Xn\t En-1"<<endl<<endl;
    cout<<i<<"\t"<<x<<endl;

    while(1){
        i++;
        double phi_xi = sqrt(2 + 5/x); //xi+1
        double error = abs(phi_xi - x);
        cout<<i<<"\t"<<phi_xi<<"\t"<<error<<endl;
        x = phi_xi; // xi+1
        if(error < tolError){
            cout<<"\nThe root is : "<<phi_xi<<endl;
            nIteration = i;
            break;
        }
    }
}
void Newton_Raphson(int *coeff, int n){
    double tolError,x0;
    cout<<"Enter the the initial approximation of the root: ";
    cin>>x0;
    cout<<"Enter tolerable error: ";
    cin>>tolError;
    double x = x0; //xn
    int i = 0;
    //cout<<"\ni\tf(Xi-1)\t\tf'(Xi-1)\t\tXi\t\tEi"<<endl;
    while(1){
        i++;
        double yn = f(x,coeff,n); //f(Xi-1)
        double Dyn = Df(x,coeff,n); // f'(Xi-1)
        double Xi = x - yn/Dyn;
        cout<<i<<"\tf(X"<<i-1<<") = "<<yn<<"\tf'(X"<<i-1<<") = "<<Dyn<<"\tX"<<i<<" = "<<Xi<<"\tE"<<i<<" = "<<abs(Xi-x)<<endl;
        if(abs(Xi - x) < tolError) {
            cout<<"\nThe root is : "<<Xi<<endl<<endl;
            nNewton_Raphson = i;
            break;
        }
        x = Xi;
    }
}

void CompareMethod(){
    cout<<"Number of iteration for Bisection method: "<<nBisection<<endl;
    cout<<"Number of iteration for False position method: "<<nFalsePosition<<endl;
    cout<<"Number of iteration for Iteration method: "<<nIteration<<endl;
    cout<<"Number of iteration for Newton-Raphson method: "<<nNewton_Raphson<<endl;

}

int main(){
    int highestPower;
    cout<<"Enter degree: ";
    cin>>highestPower;
    int coeff[highestPower+1];
    for(int i = 0; i <= highestPower; i++){
        cout<<"Enter co-efficient of x^"<<highestPower-i<<": ";
        cin>>coeff[i];
    }
    while(1){
        int choice;
        cout<<"\n************\nChoose a method: "<<endl<<endl;
        cout<<"1. Bisection Method"<<endl;
        cout<<"2. False Positon Method"<<endl;
        cout<<"3. Iteration Method"<<endl;
        cout<<"4. Newton-Raphson Method"<<endl;
        cout<<"5.Comparision"<<endl;
        cout<<"6.Exit"<<endl;
    
        cin>>choice;

        switch (choice) {
            case 1:
                Bisecton_FalsePosiotion(coeff, highestPower,1);
                break;
            case 2:
                Bisecton_FalsePosiotion(coeff, highestPower,2);
                break;
            case 3:
                Iteration();
                break;
            case 4:
                Newton_Raphson(coeff,highestPower);
                break;
            case 5:
                CompareMethod();
                break;
            case 6:
                return 0;
            default:
                cout<<"Wrong input. Try again"<<endl;
        }
    }


}