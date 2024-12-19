#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform bucket sort for integers
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    
    // Find the minimum and maximum values in the array
    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());
    
    // Determine the range of values
    int range = max_val - min_val + 1;

    // Create an array of empty buckets
    vector<vector<int> > buckets(range);
    
    // Place elements in the appropriate buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] - min_val;
        buckets[index].push_back(arr[i]);
    }

    // Sort each bucket using a sorting algorithm (e.g., insertion sort)
    for (int i = 0; i < range; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all the buckets to get the sorted array
    int index = 0;
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    vector<int> arr = {42, 32, 33, 52, 37, 47, 51};
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
