//Module 5 Topic 2
// Stack using Linked List
#include <iostream>
using namespace std;
#define size 10
int nodes;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};
class Stack
{
private:
    Node *h = NULL;
    Node *t = NULL;

public:
    void Push()
    {
        Node *temp = new Node();
        cout << "Enter data to be pushed: ";
        cin >> temp->data;
        temp->next = NULL;
        temp->prev = NULL;

        if (h == NULL)
        {
            h = temp;
        }

        else
        {
            t->next = temp;
            temp->prev = t;
        }

        t = temp;
        nodes--;

        cout << temp->data << " has been pushed" << endl;
    }
    void Display()
    {
        if (h == NULL)
            cout << "Stack empty" << endl;
        else
        {
            Node *i;
            i = t;
            while (i != NULL)
            {
                // cout<<i<<" "<<i->next<<endl;
                cout << i->data << endl;
                i = i->prev;
            }
        }
    }

    void Pop()
    {
        if (h == NULL)
            cout << "Stack empty" << endl;
        else
        {
            cout << t->data << " has been popped" << endl;
            t = t->prev;
            if (t == NULL)
            {
                h = NULL;
                cout << "Stack emptied" << endl;
            }
        }
    }
};

int main()
{
    Stack s;
    int choice;
    do
    {
        cout << "***** Menu *****" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "   Enter your option[1-4]: ";
        cin >> choice;
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
            cout << "Invalid input" << endl;
        }
    } while (1);

    return 0;
}