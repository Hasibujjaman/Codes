#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform bucket sort
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    
    // Create an array of empty buckets
    vector < vector<float> > buckets(n);
    
    // Place elements in the appropriate buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index].push_back(arr[i]);
    }

    // Sort each bucket using a sorting algorithm (e.g., insertion sort)
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all the buckets to get the sorted array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    vector<float> arr = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bucketSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
