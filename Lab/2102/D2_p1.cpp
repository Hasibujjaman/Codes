#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int balls = 20;
    int c;
    cout << "Choose player:" << endl
         << "1. Player 1" << endl
         << "2. Player 2" << endl;
    cin >> c;

    int m;
    int flag = 2;
    if (c == 1)
    {

        while (1)
        {
            cout << "Enter P1's move: ";
            cin >> m;
            if (m < 1 || m > 4)
            {
                cout << "Invalid move" << endl;
                continue;
            }
            balls -= m;
            if (balls == 0)
            {
                cout << "\nP1 is the winner\n" << endl;
                break;
            }
            cout << "P2's move: " << 5 - m << endl;
            balls -= (5 - m);
            if (balls == 0)
            {
                cout << "\nP2 is the winner\n" << endl;
                break;
            }
            // cout<<"Remaining balls: "<<balls<<endl;
        }
    }
    else
    {
        while (1)
        {
            if (balls % 5 == 0)
            {
                m = rand() % 4 + 1;
                cout << "P1's move: " << m << endl;
            }
            else
            {
                m = balls % 5;
                cout << "P1's move: " << m << endl;
            }
            balls -= m;
            if (balls == 0)
            {
                cout << "\nP1 is the winner\n" << endl;
                break;
            }
        lebel:
            cout << "Enter P2's move: ";
            cin >> m;
            if (m < 1 || m > 4)
            {
                cout << "Invalid move" << endl;
                goto lebel;
            }
            balls -= m;
            if (balls == 0)
            {
                cout << "\nP2 is the winner\n" << endl;
                break;
            }

            // cout<<"Remaining balls: "<<balls<<endl;
        }
    }
}