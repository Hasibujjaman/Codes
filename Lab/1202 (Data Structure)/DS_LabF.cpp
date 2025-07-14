#include<iostream>
#include<stack>
using namespace std;


class Queue{
    private:
        int arr1[101];
        int f1 = 0;
        int r1 = 0;
        int size1 = 0;
    public:
        void Enqueue(int x){
            if((r1+1)%101 == f1) cout<<"Queue is full"<<endl;
            else {
                r1 = (r1+1)%101;
                arr1[r1] = x;
                cout<<"Data enqueued successfully"<<endl;
                size1++;
            }
        }
        int Dequeue(){
            if(f1==r1) cout<<"Queue is empty"<<endl;
            else {
                f1 = (f1+1) % 101;
                return arr1[f1];
            }
        }
        void Display(){
            if(f1==r1) cout<<"Queue is empty"<<endl;
            else{
                int i1 = (f1+1)%101;
                while(1){
                    if(i1 == (r1+1)%101) break;
                    else{
                        cout<<" "<<arr1[i1];
                        i1 = (i1+1)%101;
                    }

                }
                cout<<endl;
            }

        }
        int Qsize(){
            return size1;
        }
};

class Node{
    public:
        int data1;
        Node *next;
};

class Linked_List{
    private:
        int n1;
        Node *h;
        Node *t;

    public:
        Linked_List(){
            h = NULL;
            t = NULL;
            n1 = 0;

        }

        void Create(int x){
        Node *temp = new Node();
        temp->data1 = x;
        temp->next = NULL;


            if (h == NULL){
                h = temp;
                t = h;
            }
                
            else {
                t->next = temp;
                t = t->next;
            }
            cout<<"Node with data1 "<<x<<" added to the list"<<endl;

    }

    void Display(){
        Node *i1 = h;
        while(i1!=NULL){  
            cout<<i1->data1<<" ";
            i1 = i1->next;
        }
        cout<<endl;
    }

    Node* LLH(){
        return h;
    }

};

class BSTNode
{
public:
    BSTNode *LL;
    int data1;
    BSTNode *RL;
};

class BST
{
public:
    BSTNode *h = NULL;

public:
    void Create(int x)
    {
        BSTNode *temp = new BSTNode;
        BSTNode *i1;
        temp->data1 = x;
        temp->LL = NULL;
        temp->RL = NULL;
        if (h == NULL)
        {
            h = temp;
        }
        else
        {
            i1 = h;
            while (1)
            {
                if (i1->data1 >= x)
                {
                    if (i1->LL == NULL)
                    {
                        i1->LL = temp;
                        break;
                    }
                    else
                    {
                        i1 = i1->LL;
                    }
                }
                else
                {
                    if (i1->RL == NULL)
                    {
                        i1->RL = temp;
                        break;
                    }
                    else
                    {
                        i1 = i1->RL;
                    }
                }
            }
        }
    }
    
    
    void Display()
    {
        stack<BSTNode *> st;
        BSTNode *i1 = h;
        cout << "Node value "<< "Node address "<< "L child address "<< "Right child address " << endl;
        if (i1 == NULL)
            cout << "Tree is Empty" << endl;
        while (i1 != NULL || st.empty() != true)
        {
            if (i1 != NULL)
            {
                st.push(i1);
                i1 = i1->LL;
            }
            else
            {
                i1 = st.top();

                cout << i1->data1 << " " << i1 << " " << i1->LL << " " << i1->RL << endl;
                st.pop();
                i1 = i1->RL;
            }
        }
        cout << endl;
    }
};

int main(){
    int ax[100];
    for(int i1 = 0; i1 < 100; i1++){
        ax[i1] = i1+1;
    }

    Queue q;
    for(int i1 = 0; i1 < 100; i1++){
        q.Enqueue(ax[i1]);
    }
    
    Linked_List ll;
    for(int i1 = 1; i1 <= q.Qsize(); i1++){
        int data1 = q.Dequeue();
        if(data1%2==0) ll.Create(data1);
    }

    BST t1;
    Node* i1 = ll.LLH();
    while(i1!=NULL){
        t1.Create(i1->data1);
        i1 = i1->next;
    }
    t1.Display();

}