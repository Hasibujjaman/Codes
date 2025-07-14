//Module 4 Topic 3
// Circular linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Circular_LL
{
private:
    Node *h;
    Node *t;
    int nodes; // needed if you want to delete node based on node number

public:
    Circular_LL()
    {
        h = NULL;
        t = NULL;
        nodes = 0;
    }
    void CreateN()
    {
        Node *temp = new Node();

        int x;
        cout << "Enter node data: ";
        cin >> x;

        temp->data = x;
        temp->next = NULL;

        if (h == NULL)
        {
            h = temp;
            t = temp;
        }
        else
        {
            t->next = temp;
            t = t->next; // or, t = temp;
        }
        t->next = h; // statement for circular structure

        nodes++;
        cout << "\nNode has been successfully added to the list\n"<< endl;
    }
    void Display()
    {
        Node *i = h;
        if (h == NULL) // or, nodes == 0
            cout << "\nList empty\n" << endl;
        else
        {
            while (1)
            {
                cout << "\n" << i->data << endl<<endl;
                if (i->next == h)
                    break;
                i = i->next;
            }
        }
    }
    void Insert()
    {
        if (!nodes)
            cout << "\nList is empty. Create a node first\n" << endl;
        else
        {
            int n;
            cout << "Enter the node no.[1 - " << nodes << "] to insert : ";
            cin >> n;
            if (n > nodes || n < 1)
                cout << "\nWrong input\n" << endl;
            else
            {
                Node *temp = new Node;
                int x;
                cout << "\nEnter new node data: ";
                cin >> x;
                temp->data = x;
                if (n == 1)
                {
                    temp->next = h;
                    h = temp;
                    t->next = h; // updating tail.next as head node has been changed
                }
                else
                {
                    Node *j = h;
                    for (int i = 1; i < n - 1; i++) 
                        j = j->next;
                    temp->next = j->next;
                    j->next = temp; //
                }
                nodes++;
                cout << "\nNode inserted successfully\n" << endl;
            }
        }
    }
    void Delete()
    {
        if (h == NULL)
            cout << "\nNo nodes to delete\n" << endl;
        else
        {
            int n;
            cout << "\nEnter the node no. you want to delete [1 - " << nodes << "]: ";
            cin >> n;
            if (n > nodes || n < 1)
                cout << "\nWrong node no.\n" << endl;
            else
            {
                if(n == 1) {
                    h = h->next;
                    t->next = h; // as head has been changed
                    nodes--;
                    cout << "\nNode deleted successfully\n" << endl;
                if (!nodes)
                {
                    h = NULL; // all nodes deleted hece head must be null
                    cout << "List emptied\n" << endl;
                }
                }
                
                else
                {
                    Node *i = h;
                    for (int j = 1; j < n - 1; j++)
                        i = i->next;
                    i->next = (i->next)->next;
                    nodes--;
                    cout << "\nNode deleted successfully\n" << endl;
                }
            }
        }
    }
    void Update()
    {
        if(!nodes) cout<<endl<<"List is empty"<<endl<<endl;
        else{
            int n;
            cout << "\nEnter node no. that you want to update[1 - " << nodes << "]: ";
            cin >> n;
            if (n > nodes || n < 1)
                cout << "\nWrond input\n" << endl;
            else
            {
                Node *j = h;
                for (int i = 1; i < n; i++)
                    j = j->next;
                int x;
                cout << "Enter data: ";
                cin >> x;
                j->data = x;
                cout << "Node data updated successfully\n" << endl;
            }
        }
    }
};

int main()
{
    Circular_LL o;

    while (1)
    {
        int x;
        cout << "****** Menu *******" << endl;
        cout << "1. Create" << endl;
        cout << "2. Insert" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Update" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "  Enter your option[1-6]: ";
        cin >> x;

        switch (x)
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
            return 0;
        default:
            cout << "Wrong input" << endl;
        }
    }

    return 0;
}