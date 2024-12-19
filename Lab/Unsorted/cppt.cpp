#include <iostream>
using namespace std;

class MyArray
{
public:
    int arr[1000];
    int size;
    void Create(){
        cout<<"Enter array size: "<<endl;
        cin>>size;
        cout<<"Enter array data:"<<endl;
        for(int i=0; i<size; i++) cin>>arr[i];
    }


    void Display()
    {
        cout << "The array is:";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " " << endl;
        }
    }

    void Binary_Search()
    {
        int x;
        cout<<"Enter the target:"<<endl;
        cin>>x;
        int li = 0;
        int hi = size;
        while (li <= hi)
        {
            int mi = (li + hi) / 2;
            if (arr[mi] == x)
            {
                cout<<"Target found at index: "<<mi<<endl;
                return;
            }
            else if (arr[mi] < x)
            {
                li = mi + 1;
            }
            else if (arr[mi] > x)
            {
                hi = mi - 1;
            }
        }
        cout<<"Not found"<<endl;
        return;
    }

    void Linear_Search()
    {
        int x;
        cout<<"Enter the target: "<<endl;
        cin>>x;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == x)
            {
                cout<<"Found at index: "<<i<<endl;
                return;
            }
        }
        cout<<"Not found"<<endl;
        return;
    };
};

int main()
{
    int option;
    MyArray obj;
    do
    {
        cout << "***** Menu *****\n"<< endl;
        cout << "1. Create" << endl;
        cout << "2. Linear search" << endl;
        cout << "3. Binary search" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter you option:" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            obj.Create();
            break;
        case 2:
            obj.Linear_Search();
            break;
        case 3:
            obj.Binary_Search();
            break;
        case 4:
            obj.Display();
            break;
        default:
            if(option<1&&option>5)cout << "Wrong input" << endl;
        }
    }while (option != 5);
    

    return 0;
}