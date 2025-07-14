//Module 6 Topic 1
//Queue using array
#include<iostream>
using namespace std;
#define size 10

class Queue{
    private:
        int arr[size];
        int f = 0;
        int r = 0;
    public:
        void Enqueue(){
            if((r+1)%size == f) cout<<"Queue is full"<<endl;
            else {
                r = (r+1)%size;
                cout<<"Enter data: ";
                cin>>arr[r];
                cout<<"Data enqueued successfully"<<endl;
            }
        }
        void Dequeue(){
            if(f==r) cout<<"Queue is empty"<<endl;
            else {
                f = (f+1) % size;
                cout<<arr[f]<<" dequeued"<<endl;
            }
        }
        void Display(){
            if(f==r) cout<<"Queue is empty"<<endl;
            else{
                int i = (f+1)%size;
                while(1){
                    if(i == (r+1)%size) break;
                    else{
                        cout<<" "<<arr[i];
                        i = (i+1)%size;
                    }

                }
                cout<<endl;
            }

        }
};
void Menu(){
    cout<<"***** Menue *****"<<endl;
    cout<<"1. Enqueue"<<endl;
    cout<<"2. Dequeue"<<endl;
    cout<<"3. Display"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<" Enter your option[1-4]: ";
}

int main(){
    Queue q1;
    while(1){
        Menu();
        int c;
        cin>>c;
        switch(c){
            case 1:
                q1.Enqueue();
                break;
            case 2: 
                q1.Dequeue();
                break;
            case 3:
                q1.Display();
                break;
            case 4:
                return 0;
            default:
                cout<<"Wrong input"<<endl;
        }
    }
    return 0;
}