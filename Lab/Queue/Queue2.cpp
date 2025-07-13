//Module 6 Topic 2
//Queue using LL
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Queue{
    private:
        Node *h = NULL;
        Node *r = NULL;
    public:
        void Enqueue(){
            Node *temp = new Node;
            cout<<"Enter data:  ";
            cin>>temp->data;
            temp->next = NULL;

            if(h==NULL) {
                h = temp;
                r = temp;
            }
            else{
                r->next = temp;
                r = r->next;
            }
            cout<<temp->data<<" enqueued"<<endl;
        }
        void Dequeue(){
            if(h==NULL) cout<<"Queue is empty"<<endl;
            else{
                cout<<h->data<<" dequeued"<<endl;
                h = h->next;
            }
        }
        void Display(){
            if(h == NULL) cout<<"Queue is empty"<<endl;
            else{
                Node *i = h;
                while(i != NULL){
                    cout<<i->data<<" ";
                    i = i->next;
                }
            }
            cout<<endl;
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