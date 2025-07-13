#include <ctime>
#include <fstream>
#include<iostream>
using namespace std;
int bruteSteps,recursiveSteps;


void BruteMinMax(int *arr, int n, int *max, int *min){
    bruteSteps = 0;
    *max = *min = arr[0];
    for(int i = 1; i < n; i++){
        //bruteSteps++; for comparison in for loop
        if(arr[i] > *max){
            bruteSteps++;
            *max = arr[i];
        }
        else if(arr[i] < *min){
            bruteSteps += 2;
            *min = arr[i];
            continue;
        }
        else
            bruteSteps += 2;
    }

}

void RecursiveMinMax(int *arr, int i, int j, int *max, int *min){
    int max1, min1, max2, min2;
    if(i == j){
        //recursiveSteps++;  commented because, for n = 1, T(n) = 0 . i.e, we not counting the comparisons in the if else conditional statements
        *max = *min = arr[i];
    }
    else if(i == j-1){
        //recursiveSteps += 2;
        if(arr[i] < arr[j]){
                *max = arr[j];
                *min = arr[i];
        }
        else {
            *max = arr[i];
            *min = arr[j];
        }
        recursiveSteps++;    //for n = 2, T(n) = 1;
    }
    else{
        int mid = (i + j) / 2;
        max1 = min1 = arr[i];
        max2 = min2 = arr[mid+1];
        RecursiveMinMax(arr, i, mid, &max1, &min1);
        RecursiveMinMax(arr, mid+1, j, &max2, &min2);
        //cout<<"***max 1 = "<<max1<<" min 1 = "<<min1<<" max 2 = "<<max2<<" min 2 = "<<min2<<endl;
        if(max1 < max2)
            *max = max2;
        else 
            *max = max1;
        if(min1 > min2)
            *min = min2;
        else
            *min = min1;
        //recursiveSteps += 4;
        recursiveSteps += 2; // for , n > 2 , T(n) = 2T(n/2) +  2;
    }
    //cout<<"i = "<<i<<" j = "<<j<<" min = "<<*min<<" max = "<<*max<<endl;
    
        

}

void Merge(int *arr, int l, int m, int h){
    int temp[h-l+1];
    int k = 0;
    int i = l,j = m+1;
    while(i <= m && j <= h){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        temp[k++] = arr[j++];
    }
    for(int p = i; p <= m; p++)
        temp[k++] = arr[p];
    for(int q = j; q <=h; q++)
        temp[k++] = arr[q];
    
    //replace arr with temp
    int r = 0;
    k--;
    while(k != 0){
        arr[r] = temp[r];
        r++;
        k--;
    }

}
void Merge_Sort(int *arr, int l, int h){
    if(l < h){
        int m = (l + h) / 2;

        Merge_Sort(arr, l, m);
        Merge_Sort(arr, m+1, h);

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

    //cout << "Pivot: " << pivot << " pivot index after partitioning: " << k << endl;
    // for (int i = low; i <= high; i++)
    //     cout << arr[i] << " ";
    // cout << endl<< endl;
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

void fileGeneration(char fileName[], int n){
    ofstream wfile;
    wfile.open(fileName);
    for(int i = 0; i < n; i++){
        wfile <<rand() % 30000<<endl;
    }
    wfile.close();

}
void getDataFromFile(char fileName[], int *arr, int n){
    ifstream ifile;
    ifile.open(fileName);
    for(int i = 0; i < n; i++){
        ifile >> arr[i];
    }
    ifile.close();

}




int main(){

    clock_t start,end;
    char fileName[] = "input.txt";
    int n;
    //fileGeneration(fileName, 1000000); // if the input file is already generated, you can comment it out
    cout<<"Enter no of data: ";
    cin>>n;
    int arr[n],arrQuick[n],arrMerge[n];
    getDataFromFile(fileName, arr, n);
    getDataFromFile(fileName, arrQuick, n);
    getDataFromFile(fileName, arrMerge, n);
    int bMin, bMax, rMin, rMax;

    start = clock();
    BruteMinMax(arr, n, &bMax, &bMin);
    end = clock();
    float time = (float)(end - start)/CLOCKS_PER_SEC*1000;
    cout<<"BruteMinMax\t"<<"Max = "<<bMax<<"\tMin = "<<bMin<<"\tsteps = "<<bruteSteps<<"\ttime = "<<time<<" ms"<<endl;

    start = clock();
    RecursiveMinMax(arr,0,n-1,&rMax,&rMin);
    end = clock();
    time = (float)(end - start)/CLOCKS_PER_SEC*1000;
    cout<<"RecursiveMinMax\t"<<"Max = "<<rMax<<"\tMin = "<<rMin<<"\tsteps = "<<recursiveSteps<<"\ttime = "<<time<<" ms"<<endl;

    start = clock();
    Quick_Sort(arrQuick,0,n-1);
    end = clock();
    time = (float)(end - start)/CLOCKS_PER_SEC*1000;
    cout<<"Quick sort\t"<<"time = "<<time<<" ms"<<endl;

    start = clock();
    Merge_Sort(arrMerge,0,n-1);
    end = clock();
    time = (float)(end - start)/CLOCKS_PER_SEC*1000;
    cout<<"Merge sort\t"<<"time = "<<time<<" ms"<<endl;


}