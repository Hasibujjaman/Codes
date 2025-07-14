#include<iostream>
#include<fstream>
using namespace std;

void Bubble(int *arr, int n)
{
    int a, b;
    int t;
    for (a = 1; a < n; ++a)
        for (b = n - 1; b >= a; --b)
        {
            if (arr[b - 1] > arr[b])
            {
                /* exchange elements */ t = arr[b - 1];
                arr[b - 1] = arr[b];
                arr[b] = t;
            }
        }
}
//1
void linearSearch(int *arr, int n, int target){
    int LSC = 0;
    for(int i = 0; i < n; i++){
        LSC++;
        if(arr[i] == target){
            cout<<"Key: "<<i+1<<"\tValue: "<<target<<"\tTotal steps: "<<LSC<<endl; 
            return;
        } 
    }
    cout<<"Data not found"<<"\tTotal steps: "<<LSC<<endl; 
}
//2
void binarySearch(int *arr, int n, int target)
    {
        int BSC = 0;
        int li = 0;
        int hi = n;
        while (li <= hi)
        {
            BSC++;
            int mi = (li + hi) / 2;
            if (arr[mi] == target)
            {
                cout<<"Key: "<<mi+1<<"\tValue: "<<target<<"\tTotal steps: "<<BSC<<endl; 
                return;
            }
            else if (arr[mi] < target)
            {
                li = mi + 1;
            }
            else if (arr[mi] > target)
            {
                hi = mi - 1;
            }
        }
        cout<<"Data not found"<<"\tTotal steps: "<<BSC<<endl; 
        return;
    }


void dataFileGen(int n, int arr[], char fileName[]){
    // ofstream wfile;
    // wfile.open(fileName);

    // for(int i = 0; i < n; i++){
    //     int random = rand();
    //     wfile<<random<<"\n";
    // }
    // wfile.close();

    //reading file starts from here
    ifstream ifile; 
    ifile.open(fileName);
    int data;
    int i = 0;
    while(ifile >> data){ 
        arr[i++] = data;
    }
    ifile.close();

}
// void wFile(int n, int arr[], char fileName[]){
//     ofstream wfile;
//     wfile.open(fileName);

//     for(int i = 0; i < n; i++){
//         wfile<<arr[i]<<"\n";
//     }
//     wfile.close();

// }


int main(){

    int size1 = 10000, size2 = 20000 , size3 = 30000, size4 = 40000, size5 = 50000;
    int arr1[size1], arr2[size2], arr3[size3], arr4[size4], arr5[size5];
    char fileName1[] = "Search_1.txt", fileName2[] = "Search_2.txt", fileName3[] = "Search_3.txt", fileName4[] = "Search_4.txt", fileName5[] = "Search_5.txt";   

    dataFileGen(size1, arr1, fileName1);
    dataFileGen(size2, arr2, fileName2);
    dataFileGen(size3, arr3, fileName3);
    dataFileGen(size4, arr4, fileName4);
    dataFileGen(size5, arr5, fileName5);


    int target;
    cout<<"Enter target: ";
    cin>>target;

    cout<<"Search 1"<<endl;
    cout<<"Linear Search\t";
    linearSearch(arr1, size1, target);
    cout<<"Binary Search\t";
    Bubble(arr1, size1);
    binarySearch(arr1, size1, target);

    // cout<<"\nSearch 2"<<endl;
    // cout<<"Linear Search\t";
    // linearSearch(arr2, size2, target);
    // cout<<"Binary Search\t";
    // Bubble(arr2, size2);
    // binarySearch(arr2, size2, target);

    // cout<<"\nSearch 3"<<endl;
    // cout<<"Linear Search\t";
    // Bubble(arr3, size3);
    // linearSearch(arr3, size3, target);
    // cout<<"Binary Search\t";
    // binarySearch(arr3, size3, target);
    
    // cout<<"\nSearch 4"<<endl;
    // cout<<"Linear Search\t";
    // linearSearch(arr4, size4, target);
    // cout<<"Binary Search\t";
    // Bubble(arr4, size4);
    // binarySearch(arr4, size4, target);

    // cout<<"\nSearch 5"<<endl;
    // cout<<"Linear Search\t";
    // linearSearch(arr5, size5, target);
    // cout<<"Binary Search\t";
    // Bubble(arr5, size5);
    // binarySearch(arr5, size5, target);

}