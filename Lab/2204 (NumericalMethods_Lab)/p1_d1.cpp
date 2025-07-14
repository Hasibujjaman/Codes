//Bisection & False position 
#include<iostream>
#include<cmath>
using namespace std;
int nBisection,nFalsePosition;
double X[1000];



double f(double x, int *coeff, int n){
    double result = 0;
    for(int i = 0; i <= n; i++){
        int power = n - i;
        result += coeff[i]*pow(x,power);
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

void CompareMethod(){
    cout<<"Number of iteration for bisection method: "<<nBisection<<endl;
    cout<<"Number of iteration for false position method: "<<nFalsePosition<<endl;

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
        cout<<"1.Bisection Method"<<endl;
        cout<<"2.False Positon Method"<<endl;
        cout<<"3.Comparision"<<endl;
        cout<<"4.Exit"<<endl;
    
        cin>>choice;

        switch (choice) {
            case 1:
                Bisecton_FalsePosiotion(coeff, highestPower,1);
                break;
            case 2:
                Bisecton_FalsePosiotion(coeff, highestPower,2);
                break;
            case 3:
                CompareMethod();
                break;
            case 4:
                return 0;
            default:
                cout<<"Wrong input. Try again"<<endl;
        }
    }


}