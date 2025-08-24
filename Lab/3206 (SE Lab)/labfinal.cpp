#include<iostream>
using namespace std;

class Operation{
    public:
        virtual float execute(float x, float y) = 0;
};

class Add: public Operation{
    public:
        float execute(float x, float y){
            return x+y;
        }
};

class Subtract: public Operation{
    public:
        float execute(float x, float y){
            return x-y;
        }
};

class Multiply: public Operation{
    public:
        float execute(float x, float y){
            return x*y;
        }
};

class Calculator{
    private:
        Operation* operation; 
    
    public:
        Calculator() : operation(nullptr) {}
        
        void setOperation(Operation* op) {
            operation = op;
        }
        
        float calculate(float x, float y) {
            if (operation == nullptr) {
                cout<<"No operation set!"<<endl;
                return 0; // Return a default value when no operation is set
            }
            return operation->execute(x, y);
        }
    };

int main() {
    Add add;
    Subtract subtract;
    Multiply multiply;
    
    Calculator calc;
    
    calc.setOperation(&add);
    cout << "10 + 5 = " << calc.calculate(10, 5) << endl;