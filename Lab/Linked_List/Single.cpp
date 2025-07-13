//Module 4 Topic 2
//Menu Program
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Linked_List{
    private:
        int n = 0;
        Node *h;

    public:
        void Create(){
        
        h = NULL;
        Node *p = NULL;
        Node *q = NULL;
        cout << "How many node?: ";
        cin >> n;
        cout << endl;
        for (int i = 0; i < n; i++)
        {   int x;
            p = new Node();
            cout << "Enter data: ";
            cin >> x;
            p->data = x;
            if (h == NULL)
                h = p;
                
            else if (q != NULL)
                q->next = p;
            
            q = p;
        }
        q->next = NULL;
        cout<<"List created"<<endl;
    }

    void Display(){
        Node *i = h;
        while(i!=NULL){   //while(i->next!=NULL) not works
            cout<<i->data<<" ";
            i = i->next;
        }
        cout<<endl;
    }

    void Insert(){
        cout<<"Enter node data before which new node will be inserte: ";
        int a;
        cin>>a;
        Node *p = new Node;
        cout<<"Enter new node data: ";
        int b;
        cin>>b;
        p->data = b;
        Node *i = h;
        Node *j = NULL;
        while(i != NULL){
            if(i->data == a){
                p->next = i;
            }
            else{
                j->next = p;
            }
            j = i;
            i = i->next;
        }

    }

    void Delete(){
        int a,check;
        check = 0;
        cout<<"Enter node data that you want to delete: ";
        cin>>a;
        Node *i = h;
        Node *j = NULL;
        while(i != NULL){
            if(i->data == a){
                if(i == h){
                    h = h->next;
                }
                else if(i->next==NULL){
                    j->next = NULL;
                }
                else{
                    j->next = i->next;
                    check++;
                }
            }
                j = i;
                i = i->next;
        }
        if(!check) cout<<"Not found"<<endl;
        cout<<"Node deleted"<<endl;

    }
    
    void Update(){
        int a,b,check;
        check = 0;
        cout<<"Enter node data that you want to Update: ";
        cin>>a;
        cout<<"Enter new data that you want: ";
        cin>>b;
        Node *i = h;
        while(i != NULL){
            if(i->data == a){
                i->data = b;
                check++;
            }
            i = i->next;
        }
        if(!check) cout<<"Not found"<<endl;
        cout<<"Node updated"<<endl;
    }


};

int main()
{
    Linked_List o;

    do{
        int x;
        cout<<"****** Menu *******"<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Insert"<<endl;
        cout<<"3. Delete"<<endl;
        cout<<"4. Update"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"  Enter your option[1-6]: ";
        cin>>x;
        
        switch(x){
            case 1:
                o.Create();
                break;
            case 2:
                o.Insert();
                break;
            case 3:
                o.Delete();
                break;
            case 4:
                o.Update();
                break;
            case 5:
                o.Display();
                break;
            case 6:
                return 0;
            default:
                cout<<"Wrong input"<<endl;

        }

    }while(1);

    return 0;
}