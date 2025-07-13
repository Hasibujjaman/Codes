//Moudle 9 Topic 1
#include<iostream>
#include<stack>
using namespace std;

class Node
{
public:
    Node *LL;
    int data;
    Node *RL;
};

class BST
{
public:
    Node *h = NULL;

public:
    void Create1(int x)
    {
        Node *temp = new Node;
        Node *i;
        temp->data = x;
        temp->LL = NULL;
        temp->RL = NULL;
        if (h == NULL)
        {
            h = temp;
        }
        else
        {
            i = h;
            while (1)
            {
                if (i->data >= x)
                {
                    if (i->LL == NULL)
                    {
                        i->LL = temp;
                        break;
                    }
                    else
                    {
                        i = i->LL;
                    }
                }
                else
                {
                    if (i->RL == NULL)
                    {
                        i->RL = temp;
                        break;
                    }
                    else
                    {
                        i = i->RL;
                    }
                }
            }
        }
    }
    void Create2(int n)
    {
        cout << "Enter the nodes : ";
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            Create1(x);
        }
    }
    void Search(int x)
    {
        Node *i = h;
        int choice = 0;
        bool nf = true;
        if (i != NULL)
        {
            while (i != NULL)
            {
                if (i->data == x)
                {
                    cout << x << " Data is found and depth is " << choice - 1 << endl;
                    nf = false;
                    break;
                }
                else if (i->data > x)
                {
                    i = i->LL;
                    choice++;
                }
                else if (i->data < x)
                {
                    i = i->RL;
                    choice++;
                }
            }
        }
        else if (i == NULL)
            cout << "List is Empty" << endl;
        if (nf == true)
            cout << "Data not found" << endl;
    }
    void Delete(int x)
    {
        Node *i = h;
        Node *temp = NULL;
        if (i != NULL)
        {
            while (i != NULL && i->data != x)
            {
                temp = i;
                if (i->data > x)
                    i = i->LL;
                else if (i->data < x)
                    i = i->RL;
            }
            if (i != NULL)
            {
                if (i->LL == NULL || i->RL == NULL)
                {
                    Node *U;
                    if (i->LL == NULL)
                        U = i->RL;
                    else
                        U = i->LL;
                    if (i == temp->LL)
                        temp->LL = U;
                    else
                        temp->RL = U;
                    if (U == NULL)
                        cout << "A leaf Node " << i->data << " is deleted" << endl;
                    else
                        cout << "A Node with one child " << i->data << " is deleted" << endl;
                    free(i);
                }
                else
                {
                    cout << "a Node " << i->data << " two childs is deleted" << endl;
                    Node *a = NULL;
                    Node *b;
                    b = i->RL;
                    while (b->LL != NULL)
                    {
                        a = b;
                        b = b->LL;
                    }
                    if (a != NULL)
                        a->LL = b->RL;
                    else
                        i->RL = b->RL;
                    i->data = b->data;
                    free(i);
                }
            }
            else if (i == NULL)
            {
                cout << "Data not Found" << endl;
            }
        }
        else if (i == NULL)
        {
            cout << "List is Empty tooo" << endl;
        }
    }
    void Display()
    {
        stack<Node *> st;
        Node *i = h;
        cout << "Node value "<< "Node address "<< "L child address "<< "Right child address " << endl;
        if (i == NULL)
            cout << "Tree is Empty" << endl;
        while (i != NULL || st.empty() != true)
        {
            if (i != NULL)
            {
                st.push(i);
                i = i->LL;
            }
            else
            {
                i = st.top();

                cout << i->data << " " << i << " " << i->LL << " " << i->RL << endl;
                st.pop();
                i = i->RL;
            }
        }
        cout << endl;
    }
};

int main()
{
    BST t;
    int choice;
    while (choice != 5)
    {
        cout<<"\n**** Menu ****"<<endl<<endl;
        cout<<" 1. Insert"<<endl;
        cout<<" 2. Search"<<endl;
        cout<<" 3. Delete"<<endl;
        cout<<" 4. Display"<<endl;
        cout<<" 5. Exit"<<endl;
        cout<<"   Enter your option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int c, n;
            cout << "Choose inserting method from the following:\n1.Lopping method\n2.Recursive method"<<endl;
            cin >> c;
            if (c == 1)
            {
                int x;
                cout << "Enter node data : ";
                cin >> x;
                t.Create1(x);
                break;
            }
            else if (c == 2)
            {
                cout << "Enter how many nodes : ";
                cin >> n;
                t.Create2(n);
                break;
            }
        case 2:
            cout << "Enter node data You want to Search : ";
            int x2;
            cin >> x2;
            t.Search(x2);
            break;
        case 3:
            cout << "Enter node data You want to Delete : ";
            int x3;
            cin >> x3;
            t.Delete(x3);
            break;
        case 4:
            t.Display();
            break;
        case 5:
            cout<<"Program terminated"<<endl;
            return 0;
        }
    }
}