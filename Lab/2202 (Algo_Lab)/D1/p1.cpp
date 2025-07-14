// complexity analysis of Bubble sort, Selection sort, Insertion sort
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    vector<int> nValues = {5000, 10000, 15000, 20000};
    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    for (int n : nValues)
    {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            inputFile >> arr[i];
        }

        // Bubble Sort
        auto start = high_resolution_clock::now();
        bubbleSort(arr);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cout << "Bubble Sort (n = " << n << "): " << duration.count() << " miliseconds" << endl;

        // Selection Sort
        start = high_resolution_clock::now();
        selectionSort(arr);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        cout << "Selection Sort (n = " << n << "): " << duration.count() << " microseconds" << endl;

        // Insertion Sort
        start = high_resolution_clock::now();
        insertionSort(arr);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        cout << "Insertion Sort (n = " << n << "): " << duration.count() << " microseconds" << endl;

        cout << endl; // Separate results for different n values
    }

    inputFile.close();
    return 0;
}