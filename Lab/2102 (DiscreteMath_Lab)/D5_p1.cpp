//Time complexity 
#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

void Bubble(int *arr, int count)
{
    int a, b;
    int t;
    for (a = 1; a < count; ++a)
        for (b = count - 1; b >= a; --b)
        {
            if (arr[b - 1] > arr[b])
            {
                /* exchange elements */ t = arr[b - 1];
                arr[b - 1] = arr[b];
                arr[b] = t;
            }
        }
}
void linearSearch(int *arr, int size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i] == target) return;
    }
}


void Complexity(int *arr, int count){
    clock_t start,end;
    float time;
    start = clock();

    Bubble(arr,count);

    end = clock();
    cout<<"s: "<<start<<endl<<"e: "<<end<<endl;
    time = (float)(end - start)/CLOCKS_PER_SEC;
    cout<<"time: "<<time<<" s"<<endl;

}

void dataGen(int number, int arr[]){
    ofstream wfile;
    wfile.open("data.txt");

    for(int i = 0; i < number; i++){
        int random = rand();
        wfile<<random<<"\n";
    }
    wfile.close();

    ifstream ifile;
    ifile.open("data.txt");
    int data;
    int i = 0;
    while(ifile >> data){
        arr[i++] = data;
    }
    ifile.close();

}


int main(){

    void (*bubble_ptr) (int* , int) = &Bubble;

    int n;
    cout<<"Enter number of data: ";
    cin>>n;
    int arr[n];
    dataGen(n,arr);

    cout<<"Linear sort"<<endl;
    

    cout<<"Bubble sort"<<endl;
    Complexity(arr,n);

}