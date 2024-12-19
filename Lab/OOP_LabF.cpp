#include <iostream>
using namespace std;

class Department
{

public:
    string dept;
    int students;
    int teachers;

    virtual double equipment_Index() = 0;
    Department(){
        dept = "";
        students = 0;
        teachers = 0;
    }
    Department(string str, int x, int y)
    {
        dept = str;
        teachers = x;
        students = y;
    }
    void Display()
    {
        cout << "Name: " << dept << endl;
        cout << "Total Teachers = " << teachers << endl;
        cout << "Total Students = " << students << endl;
    }
};
class EEE : public Department
{
    private:
        int machines;

public:
    EEE(){
        machines = 0;
    }
    EEE(string str, int t = 0, int stu = 0, int m = 0):Department(str,t,stu)
    {
        machines = m;
    }
    double equipment_Index()
    {
        try
        {
            if (students == 0)
            {
                throw "Divide by zero error";
            }
        }
        catch (char const *str)
        {
            cout << str << endl;
        }
        return (double)machines / students;
    }
    void Display()
    {
        Department::Display();
        cout << "Total Machines = " << machines << endl;
        cout << "Machine index = " << (double)machines / students << endl;
    }
    int total()
    {
        return machines;
    }
};
class CSE : public Department
{
    private:
        int computers;

public:
    CSE(){
        computers = 0;
    }
    CSE(string str, int t, int stu, int c):Department(str,t,stu)
    {
        computers = c;
    }
    double equipment_Index()
    {
        try
        {
            if (students == 0)
            {
                throw "Divide by zero error";
            }
        }
        catch (char const *str)
        {
            cout << str << endl;
        }
        return (double)computers / students;
    }
    void Display()
    {
        Department::Display();
        cout << "Total computers = " << computers << endl;
        cout << "Computer index = " << equipment_Index() << endl;
    }
    int total()
    {
        return computers;
    }
};
class ECE : public Department
{
    private:
        int machines;
        int computers;

public:
    ECE(){
        machines = 0;
        computers = 0;
    }
    ECE(string str, int t, int stu, int m, int c):Department(str,t,stu)
    {
        machines = m;
        computers = c;
    }
    double equipment_Index()
    {
        try
        {
            if (students == 0)
            {
                throw "Divide by zero error";
            }
        }
        catch (char const *str)
        {
            cout << str << endl;
        }
        return (double)(machines + computers) / students;
    }
    void Display()
    {
        Department::Display();
        cout << "Total Machines = " << machines << endl;
        cout << "Total computers = " << computers << endl;
        cout << "Computer + Machine index = " << equipment_Index() << endl;
    }
    int total()
    {
        return (machines + computers);
    }
};
int main()
{
    EEE eee("EEE", 50, 1000, 50);
    CSE cse("CSE", 30, 1200, 200);
    ECE ece("ECE", 30, 1200, 25, 100);
    eee.Display();
    cse.Display();
    ece.Display();
    cout << "Total equipments = " << eee.total() + cse.total() + ece.total() << endl;
    cout << "End of program" << endl;
}