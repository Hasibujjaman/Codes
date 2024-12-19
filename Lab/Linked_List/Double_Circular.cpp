//Module 4 Topic 4
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

class LL
{
private:
    Node *h;
    Node *t;

public:
    LL()
    {
        h = NULL;
        t = NULL;
    }
    void CreateN()
    {
        Node *temp = new Node;
        temp->prev = NULL;
        temp->next = h;
        cout << "Enter node data: ";
        cin >> temp->data;

        if (h == NULL)
        {
            h = temp;
            t = temp;
            h->prev = h;
            h->next = h;
        }
        else
        {
            t->next = temp;
            temp->prev = t;
            t = t->next; // or, t = temp;
            h->prev = t; // as tail changes head.prev also needs to be updated
        }
        cout<<"Node has been added to the linked list"<<endl;
    }
    void Display()
    {

        Node *i = h;
        if (h == NULL) // or, nodes == 0
            cout << "\nList is empty. Enter nodes first to display\n"<< endl;
        else
        {
            cout<<endl;
            while (1)
            {
                cout <<" "<< i->data;
                if (i->next == h)
                    break;
                i = i->next;
            }
            cout<<endl<<endl;
        }
    }
    void Insert() //Inserts before all copies 
    {
        if (h == NULL)
            cout << "List empty. Create node first" << endl;
        else
        {
            int x, check = 0;
            cout << "Enter target node data: ";
            cin >> x;
            Node *i = h;
            do
            {
                if (i->data == x)
                {
                    Node *temp = new Node;
                    cout << "Enter new node data: ";
                    cin >> temp->data;
                    temp->next = i;
                    temp->prev = i->prev;
                    (i->prev)->next = temp;
                    temp->prev = i->prev;
                    i->prev = temp;
                    if (i == h)
                        h = temp;
                       
                    check++;
                }
                i = i->next;
            } while (i != h);
            if(check == 1) cout<<"Node inserted"<<endl;
            else if(check > 1) cout<<"Nodes inserted"<<endl;
            else cout<<"Node couldn't be found"<<endl;
        }
    }
    void Delete(){    //Doesn't delete copies
        if (h == NULL)
            cout << "List empty. Create node first" << endl;
        else
        {
            int x = 0, check = 0;
            cout << "Enter target node data: ";
            cin >> x;
            Node *i = h;
            do
            {
                if (i->data == x)
                {
                    if(i->next == i)
                        h = NULL;
                    else{
                        i->prev->next = i->next;
                        i->next->prev = i->prev;
                        if(i == h) h = h->next;
                        else if(i == t) t = t->prev;
                    }
                    check++;
                    break;
                }
                i = i->next;
            } while (i != h);
            
            if(check) cout<<"Node deleted"<<endl;
            else cout<<"Node couldn't be found"<<endl;
        }
    }
    void Update(){ //Updates copies also
        int x = 0, check = 0;
        cout<<"Enter node data: ";
        cin>>x;
        Node *i = h;
        do{
            if(i->data == x){
                cout<<"Enter replacement data: ";
                cin>>i->data;
                check++;
            }
            i = i->next;
        }while(i!=h);
        if(check==1) cout<<"Node updated"<<endl;
        else if(check > 1) cout<<"Nodes updated"<<endl;
        else cout<<"Node couldn't be found"<<endl;

    }
};

int main()
{
    LL o;

    while (1)
    {
        int c;
        cout << "****** Menu *******" << endl;
        cout << "1. Create" << endl;
        cout << "2. Insert" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Update" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "  Enter your option[1-6]: ";
        cin >> c;

        switch (c)
        {
        case 1:
            o.CreateN();
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
            cout << "Program terminated" << endl;
            return 0;
        default:
            cout << "Wrong input" << endl;
        }
    }

    return 0;
}