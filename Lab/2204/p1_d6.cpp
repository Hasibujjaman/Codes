//Numerical Integration
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
double error1, error2, error3;

//user define arbitary function
double func(double x){
    return x*x+1;
}
double trueIntegral(double a , double b){
    double Ib = (b*b*b)/3 + b;
    double Ia = (a*a*a)/3 + a;

    return Ib - Ia;
    
}

void Trapezoidal(){
    double a,b,h;
    cout<<"Enter lower limit: ";
    cin>>a;
    cout<<"Enter upper limit: ";
    cin>>b;
    cout<<"Enter difference between two consecutive x values: ";
    cin>>h;
    int n = ceil((b-a)/h); //n+1 point are needed
    double X[n+1],Y[n+1];
    for(int i = 0; i < n+1; i++){
        X[i] = a + i*h;
        Y[i] = func(X[i]);
        cout<<"x"<<i<<" = "<<X[i]<<"\ty"<<i<<" = "<<Y[i]<<endl;
    }
    
    //calculate the integral
    double s = Y[0] + Y[n];
    for(int i = 1; i < n; i++){
        s += 2*Y[i];
    }
    
    double I = (h/2)*s;

    //error calculation
    double trueI = trueIntegral(a,b);
    error1 = ((trueI - I)/trueI)*100;

    cout<<"\nThe definite integral is : "<<I<<endl;
    cout<<"Percentage error is : "<<error1<<" %"<<endl;

}
void Simpson1by3(){
    double a,b,h;
    cout<<"Enter lower limit: ";
    cin>>a;
    cout<<"Enter upper limit: ";
    cin>>b;
    cout<<"Enter difference between two consecutive x values: ";
    cin>>h;
    int n = ceil((b-a)/h); //n+1 point are needed
    double X[n+1],Y[n+1];
    for(int i = 0; i < n+1; i++){
        X[i] = a + i*h;
        Y[i] = func(X[i]);
        cout<<"x"<<i<<" = "<<X[i]<<"\ty"<<i<<" = "<<Y[i]<<endl<<endl;
    }
    
    //calculate the integral
    double s = Y[0] + Y[n];
    for(int i = 1; i < n; i++){
        if(i%2){ // odd i s , y1,y3,y5,....
        s += 4*Y[i];
        continue;
        }
        s += 2*Y[i];

    }
    
    double I = (h/3)*s;
    //error calculation 
    double trueI = trueIntegral(a,b);
    error2 = ((trueI - I)/trueI)*100;

    cout<<"\nThe definite integral is : "<<I<<endl;
    cout<<"Percentage error is : "<<error2<<" %"<<endl;

}

void Simpson3by8(){
double a,b,h;
    cout<<"Enter lower limit: ";
    cin>>a;
    cout<<"Enter upper limit: ";
    cin>>b;
    cout<<"Enter difference between two consecutive x values: ";
    cin>>h;
    int n = ceil((b-a)/h); //n+1 point are needed
    double X[n+1],Y[n+1];
    for(int i = 0; i < n+1; i++){
        X[i] = a + i*h;
        Y[i] = func(X[i]);
        cout<<"x"<<i<<" = "<<X[i]<<"\ty"<<i<<" = "<<Y[i]<<endl<<endl;
    }
    
    //calculate the integral
    double s = Y[0] + Y[n];
    for(int i = 1; i < n; i++){
        if(i%3 == 0){ // multiples of 3 , y3,y6,y9,....
        s += 2*Y[i];
        continue;
        }
        s += 3*Y[i];

        cout<<"i = "<<i<<" s = "<<s<<endl;
    }
    
    double I = (3*h*s)/8;
    //error calculation 
    double trueI = trueIntegral(a,b);
    error3 = ((trueI - I)/trueI)*100;

    cout<<"\nThe definite integral is : "<<I<<endl;
    cout<<"Percentage error is : "<<error3<<" %"<<endl;



}

void Comparison(){
    cout<<"-----------Percentage Error-----------"<<endl;
    cout<<"Trapezoidal Rule: "<<error1<<endl;
    cout<<"Simpson's 1/3 Rule: "<<error2<<endl;
    cout<<"Simpson's 3/8 Rule: "<<error3<<endl<<endl;
}


int main() {

    int choice;
    while(1){
        cout<<"\n\n########### MENU ###########"<<endl;
        cout<<"\nEnter your choice: "<<endl;
        cout<<"(1).Trapezoidal Rule\n(2).Simpson 1/3 Rule \n(3).Simpson 3/8 Rule \n(4).Comparison \n(5).Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            Trapezoidal();
            break;
        case 2:
            Simpson1by3();
        break;
        case 3:
            Simpson3by8();
        break;
        case 4:
            Comparison();
        case 5:
            return 0;
        default:
            cout<<"Wrong input"<<endl;
            break;
        }
    }

    return 0;
}
