//Module 8 Topic 1
#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node *ll;
    Node *rr;
};

int main()
{
    int LL[50], DATA[50], RL[50];
    Node *ax[50];
    ax[0] = 0;
    ifstream file;
    file.open("Tree.txt");
    int i = 1;
    while (file >> LL[i])
    {
        char c;
        file >> c;
        DATA[i] = int(c);
        file >> RL[i];
        cout << LL[i] << " " << char(DATA[i]) << " " << RL[i] << endl;
        ax[i] = new Node();
        i++;
    }
    for (int j = 1; j <= i - 1; j++)
    {
        cout << "Node: " << j << " " << char(DATA[j]) << " " << ax[j] << " " << endl;
        ax[j]->data = DATA[j];
        ax[j]->ll = ax[LL[j]];
        ax[j]->rr = ax[RL[j]];
    }
    for (int j = 1; j < i; j++)
    {
        cout << ax[j]->ll << " " << LL[j] << "      " << char(ax[j]->data) << "     " << RL[j] << " " << ax[j]->rr << endl;
    }
}