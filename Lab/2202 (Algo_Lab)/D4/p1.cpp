#include <ctime>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
int bruteSteps, recursiveSteps;

void Merge(int *arr, int l, int m, int h)
{
    int temp[h - l + 1];
    int k = 0;
    int i = l, j = m + 1;
    while (i <= m && j <= h)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        temp[k++] = arr[j++];
    }
    for (int p = i; p <= m; p++)
        temp[k++] = arr[p];
    for (int q = j; q <= h; q++)
        temp[k++] = arr[q];

    // replace arr with temp
    int r = 0;
    k--;
    while (k != 0)
    {
        arr[r] = temp[r];
        r++;
        k--;
    }
}
void Merge_Sort(int *arr, int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;

        Merge_Sort(arr, l, m);
        Merge_Sort(arr, m + 1, h);

        Merge(arr, l, m, h);
    }
}
int Partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int st = low; // st points to the starting of array
    int end = high; // end points to the ending of the array
    int k = high;
    for (int i = high; i > low; i--) {
        if (arr[i] > pivot)
            swap(arr[i], arr[k--]);
    }
    swap(arr[low], arr[k]);

    cout << "Pivot: " << pivot << " pivot index after partitioning: " << k << endl;
    for (int i = low; i <= high; i++)
        cout << arr[i] << " ";
    cout << endl<< endl;
    // As we got pivot element index is end
    // now pivot element is at its sorted position
    // return pivot element index (end)
    return k;
}

void Quick_Sort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    // cout<<"Low = "<<low<<" High = "<<high<<endl;
    int part = Partition(arr, low, high);
    // cout<<"After pivot"<<endl;
    // Display(arr);
    Quick_Sort(arr, low, part - 1);
    Quick_Sort(arr, part + 1, high);
}

void fileGeneration(char fileName[], int n)
{
    ofstream wfile;
    wfile.open(fileName);
    for (int i = 0; i < n; i++)
    {
        wfile << rand() % 30000 << endl;
    }
    wfile.close();
}
void getDataFromFile(char fileName[], int *arr, int n)
{
    ifstream ifile;
    ifile.open(fileName);
    for (int i = 0; i < n; i++)
    {
        ifile >> arr[i];
    }
    ifile.close();
}

int main()
{

    clock_t start, end;
    char fileName[] = "input.txt";
    int n;
    // fileGeneration(fileName, 1000000); // if the input file is already generated, you can comment it out
    cout << "Enter no of data: ";
    cin >> n;
    int arr[n];
    getDataFromFile(fileName, arr, n);

    cout << "\nUnsorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
    Quick_Sort(arr, 0, n - 1);
    cout << "\n\nSorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}