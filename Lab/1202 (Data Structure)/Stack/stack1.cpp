//Module 5 Topic 1
//Stack using array
#include<iostream>
using namespace std;
#define size 10

class Stack{
    private:
        int arr[size];
        int top = -1;
    public:
        void Push(){
            int p;
            cout<<"Enter data to push: ";
            cin>>p;
            if(top < size-1) {
                top += 1;
                arr[top] = p;
                cout<<p<<" has been pushed"<<endl;
            }
            else cout<<"Stack full"<<endl;

        }
        void Pop(){
            if(top < 0) cout<<"Stack empty"<<endl;
            else {
                cout<<arr[top]<<" has been popped"<<endl;
                top -= 1;
            }
        }
        void Display(){
            if(top == -1) cout<<"Stack empty"<<endl;
            else{
                for(int i = top; i >= 0; i--){
                    cout<<arr[i]<<endl;
                }
            }
        }


};

int main(){
    Stack s;
    int choice;
    do{
        cout<<"***** Menu *****"<<endl;
        cout<<"1. PUSH"<<endl;
        cout<<"2. POP"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"   Enter your option[1-4]: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            s.Push();
            break;
        case 2:
            s.Pop();
            break;
        case 3:
            s.Display();
            break;
        case 4:
            return 0;
        default:
            cout<<"Invalid input"<<endl;
        }
    }while(1);

    return 0;
}