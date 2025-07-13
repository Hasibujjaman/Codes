//DS Assignment Q2
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
struct Node
{
    Node *LNode;
    int data = 0;
    Node *RNode;
};

Node *LL[50];
Node *h, *p;

int main()
{
    ifstream file;
    int LNode[50];
    int data[50];
    int RNode[50];
    file.open("array.txt");
    int i = 1, n;
    while (file >> LNode[i])
    {
        file >> data[i];
        file >> RNode[i];
        i++;
    }
    n = i - 1;
    for (i = 1; i <= n; i++)
        LL[i] = new Node();

    LL[0] = 0;
    h = LL[1];
    for (i = 1; i <= n; i++)
    {
        LL[i]->data = data[i];
        LL[i]->LNode = LL[LNode[i]];
        LL[i]->RNode = LL[RNode[i]];
    }

    int sum = 0;
    for (i = 1; i <= n; i++)
    {
        if (LL[i]->LNode == NULL && LL[i]->RNode == NULL)
        {
            sum += LL[i]->data;
        }
    }
    cout << endl
         << "The Tree is" << endl;
    for (i = 1; i <= n; i++)
    {
        cout << (LL[i]->LNode == NULL ? 0 : LL[i]->LNode->data) << "<-" << LL[i]->data << "->" << (LL[i]->RNode == NULL ? 0 : LL[i]->RNode->data) << endl;
    }
    cout << "\n\nLeaf Node sum is : " << sum << endl;
}