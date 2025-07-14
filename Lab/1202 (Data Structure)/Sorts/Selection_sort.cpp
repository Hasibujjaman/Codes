//Module 7 Topic 2
#include <iostream>
using namespace std;
void Display(int *arr);
void Selection(int arr[])
{
    for (int i = 0; i < 7 - 1; i++)
    {
        int temp = arr[i];
        int k = 0;
        int check = 0;
        for (int j = i + 1; j < 7; j++)
        {
            if (arr[j] < temp)
            {
                temp = arr[j];
                k = j;
                check++;
            }
        }
        if (check)
        {
            int t = arr[i];
            arr[i] = temp;
            arr[k] = t;
        }
        //cout << k << endl;
       // Display(arr);
    }
}
void Display(int *arr)
{
    for (int i = 0; i < 7; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}

int main()
{
    int ax[7] = {10,78,32,90,20,19,25};
    cout << "Before sorting" << endl;
    Display(ax);
    Selection(ax);
    cout << "After sorting" << endl;
    Display(ax);
}
