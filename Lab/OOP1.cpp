//OOP Assignment Q1
#include <iostream>
using namespace std;

class Manager;
class EmpList;
class Emp;

class EmpList
{
public:
    Emp *data;
    EmpList *next;
};

class Emp
{
public:
    int ID;
    string name;
    int salary;
    int age;
    Manager *manager;

    Emp(string name, int ID, int salary, int age)
    {
        this->name = name;
        this->ID = ID;
        this->salary = salary;
        this->age = age;
    }
    void printDelaits()
    {
        cout << "Name of the employee is " << this->name << "\nSalary: " << this->salary << "\nAge: " << this->age << endl;
    }
    void setManager(Manager *manager)
    {
        this->manager = manager;
    }
};

class Manager : public Emp
{
public:
    EmpList *employees;
    EmpList *tmp;
    int employeeCount = 0;
    int maxEmployeeCount = 10;

    Manager(string name, int ID, int salary, int age) : Emp(name, ID, salary, age) {}
    void printDelaits()
    {
        cout << "Name of the employee is " << this->name << "\nSalary: " << this->salary << "\nAge: " << this->age << endl;
        cout << "Employees supervised under " << this->name << endl;
        tmp = this->employees;
        for (int i = 0; i < employeeCount; i++)
        {
            cout << i + 1 << ": " << tmp->data->name << endl;
            tmp = tmp->next;
        }
    }

    void addEmployee(Emp *employee)
    {
        tmp = this->employees;
        for (int i = 0; i < employeeCount; i++)
            tmp = tmp->next;
        EmpList *tmpL = new EmpList();
        tmp->next = tmpL;
        tmp->data = employee;
        employeeCount++;
    }

    void deleteEmployee(Emp *employee)
    {
        tmp = this->employees;
        for (int i = 0; i < employeeCount; i++)
        {
            if (tmp->next->data == employee)
            {
                tmp->next = tmp->next->next;
                employeeCount--;
            }
            tmp = tmp->next;
        }
    }
};

int main()
{
    Manager manager("Person A", 20003001, 11000, 23);

    Emp *emp1 = new Emp("Person B", 2003002, 1200, 23);
    emp1->setManager(&manager);

    Emp *emp2 = new Emp("Person C", 2003003, 1300, 23);
    emp2->setManager(&manager);

    Emp *emp3 = new Emp("Person D", 2003004, 1400, 23);
    emp3->setManager(&manager);

    Emp *emp4 = new Emp("Person E", 2003005, 1500, 23);
    emp4->setManager(&manager);

    

    manager.addEmployee(emp1);
    manager.addEmployee(emp2);
    manager.addEmployee(emp3);
    manager.addEmployee(emp4);
    
    

    manager.printDelaits();
    manager.deleteEmployee(emp4);
    manager.printDelaits();
}