#include<iostream>
using namespace std;

class Department{
    public:
        string Dept;
        int Students;
        int Teachers;
        
        Department(){

        }
        Department(string D, int t, int s){
            Dept = D;
            Teachers = t;
            Students = s;
        }
        virtual double equipment_Index() = 0;
        void Display(){
            cout<<"Department : "<<Dept<<endl;
            cout<<"Total Teachers = "<<Teachers<<endl;
            cout<<"Total Students = "<<Students<<endl;
        }
};

class EEE: public Department{
    private:
        int Machines;

    public:
        double equipment_Index(){
            try{
                if(Students == 0){
                    throw "Divide by zero error";
                }
            }
            catch(char const *s){
                cout<<s<<" ";
                return -1;
            }
            return ((double)Machines / Students);
        }
        EEE(){

        }
        EEE(string D, int t, int s, int m):Department(D, t , s){
            this->Dept = D;
            this->Teachers = t;
            this->Students = s;
            this->Machines = m;
        }

        void Display(){
            // cout<<"Department : "<<Dept<<endl;
            // cout<<"Teachers = "<<Teachers<<endl;
            // cout<<"Students = "<<Students<<endl;
            Department::Display();
            cout<<"Machines = "<<Machines<<endl;
            cout<<"Machine index = "<<equipment_Index()<<endl;

        }
        int Total (){
            return (Machines);
        }
};
class CSE: public Department{
    private:
        int Computers;

    public:
        double equipment_Index(){
            try{
                if(Students == 0){
                    throw "Divide by zero error";
                }
            }
            catch(char const *s){
                cout<<s<<" ";
                return -1;
            }
            return ((double)Computers / Students);
        }
        CSE(){

        }
        CSE(string D, int t, int s, int c):Department(D, t , s){
            this->Dept = D;
            this->Teachers = t;
            this->Students = s;
            this->Computers = c;
        }

        void Display(){
            // cout<<"Department : "<<Dept<<endl;
            // cout<<"Teachers = "<<Teachers<<endl;
            // cout<<"Students = "<<Students<<endl;
            Department::Display();
            cout<<"Computers = "<<Computers<<endl;
            cout<<"Computer index = "<<equipment_Index()<<endl;
        }
        int Total (){
            return (Computers);
        }
};
class ECE: public Department{
    private:
        int Machines;
        int Computers;

    public:
        double equipment_Index(){
            try{
                if(Students == 0){
                    throw "Divide by zero error";
                }
            }
            catch(char const *s){
                cout<<s<<" ";
                return -1;
            }
            return ((double)(Machines + Computers)/Students);
        }
        ECE(string D, int t, int s, int m, int c):Department(D, t , s){
            this->Dept = D;
            this->Teachers = t;
            this->Students = s;
            this->Machines = m;
            this->Computers = c;
        }

        void Display(){
            // cout<<"Department : "<<Dept<<endl;
            // cout<<"Teachers = "<<Teachers<<endl;
            // cout<<"Students = "<<Students<<endl;
            // cout<<"Machine = "<<Machines<<endl;
            Department::Display();
            cout<<"Computers = "<<Computers<<endl;
            cout<<"Computer + Mechine index = "<<equipment_Index()<<endl;

        }
        int Total (){
            return (Machines + Computers);
        }
};

int main(){
    EEE eee("EEE", 50 , 1000 , 50);
    CSE cse("CSE", 30, 1200, 200);
    ECE ece("ECE", 30, 1200, 25, 100);
    eee.Display();
    cse.Display();
    ece.Display();
    cout<<"Total equiments = "<<eee.Total()+cse.Total()+ece.Total()<<endl;
    cout<<"End of program"<<endl;
}