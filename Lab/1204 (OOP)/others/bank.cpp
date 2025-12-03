//Banking automation program
#include <iostream>
using namespace std;
#define admin_pass 123
#define max_ac 1000

int N;


class Account
{
private:
    int acn;
    char name[50];
    int age;
    float balance;

public:
    int GetACN(){
        return acn;
    }
    void GetData(){
        cout<<"\nAccont No. : "<<acn<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
    
    void OpenAC()
    {
        N++;
        cout << "Enter A/C number: ";
        cin >> acn;
        cout << "Enter A/C holder's name: ";
        cin >> name;
        cout << "Enter A/C holder's age: ";
        cin >> age;
        balance = 0;
        cout << "AC created sucessfully" << endl;
    }
    void CloseAC(Account DB[], int index)
    {
        if(!DB[index].balance){
            for(int i = index; i < N-1 ; i++) DB[i] = DB[i+1];
            N--;
            cout<<"AC successfully closed"<<endl;
        }
        else cout<<"AC can not be close . It has money in it."<<endl;
    }
    void Deposit(){
        int amount;
        cout<<"Enter deposit amount: ";
        cin>>amount;
        balance += amount;
        cout<<"Deposit successfull"<<endl;

    }
    void Withdraw(){
        int amount;
        cout<<"Enter withdrawl amount: ";
        cin>>amount;
        if(balance-amount>=0){
            balance -= amount;
            cout<<"Withdrawn successfully"<<endl;
        }
        else cout<<"Insufficient balance"<<endl;
    }
    void CheckBal(){
        cout<<"Balance is: "<<balance<<endl;
    }


};

int Search_AC(Account DB[])
    {
        int x;
        cout << "\nEnter AC number: ";
        cin >> x;
        for (int i = 0; i < N; i++)
        {
            if (DB[i].GetACN() == x)
                return i;
        }
        return -1;
    }

int main()
{
    int c, admin,index;
    Account AC[max_ac];
    do
    {
        cout << "\n***** Main Menu *****\n"<< endl;
        cout << "1. Open New Account" << endl;
        cout << "2. Close Old Account" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Check Balance" << endl;
        cout << "6. Show database" << endl;
        cout << "7. Exit\n"<< endl;
        cin >> c;

        switch (c)
        {
        case 1:
            if(N<=max_ac){
                cout << "\nEnter admin password: ";
                cin >> admin;
                if (admin == admin_pass) 
                    AC[N].OpenAC();
                else
                    cout << "Wrong password" << endl;
                break;
            }
            else cout<<"Acount limit exceeded"<<endl;

        case 2:
            cout << "\nEnter admin password: ";
            cin >> admin;
            if (admin == admin_pass)
            {
                index = Search_AC(AC);
                if(index != -1) AC[index].CloseAC(AC,index);
                else cout<<"AC not found"<<endl;
            }
            else
                cout << "Wrong password" << endl;
            break;
        case 3:
            index = Search_AC(AC);
            if(index != -1) AC[index].Deposit();
            else cout<<"AC not found"<<endl;
            break;
        case 4:
            index = Search_AC(AC);
            if(index != -1) AC[index].Withdraw();
            else cout<<"AC not found"<<endl;
            break;
        case 5:
            index = Search_AC(AC);
            if(index != -1) AC[index].CheckBal();
            else cout<<"AC not found"<<endl;
            break;
        case 6:
            cout << "\nEnter admin password: ";
            cin >> admin;
            if (admin == admin_pass)
            {
                for(int i = 0; i < N; i++){
                    AC[i].GetData();
                }
            }
            else
                cout << "Wrong password" << endl;
            break;
        case 7:
            cout << "Exited successfully" << endl;
            return 0;
        default:
            cout << "Wrong input\n";
        }
    } while (1);

    return 0;
}
