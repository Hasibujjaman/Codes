#include <iostream>
using namespace std;
int w;

int main() {
  cout << "Enter no of vertex: ";
  int n;
  cin >> n;
  w = n;
  int G[n][n];
  char color[n];
  for (int i = 0; i < n; i++) {
    color[i] = 'W';
    for (int j = 0; j < n; j++) {
      G[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    int a;
    cout << "Enter no of vertexes that are adjecent to vertex " << i + 1
         << " : ";
    cin >> a;
    if (a != 0)
      cout << "Enter those vertexes: ";
    for (int j = 0; j < a; j++) {
      int v;
      cin >> v;
      G[i][v - 1]++;
    }
  }

  int isBipartile = 1;
  color[0] = 'R';
  w--;
  while (w != 0) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (G[i][j] == 0)
          continue;

        if (color[i] == 'R') {
          if (color[j] == 'W') {
            color[j] = 'G';
            w--;
          }
          if (color[j] == 'R') {
            // cout << "i,j = " << i << " ," << j << endl;
            isBipartile = 0;
          }
          color[j] = 'G';
        } 
        else if (color[i] == 'G') {
          if (color[j] == 'W') {
            color[j] = 'R';
            w--;
          }
          if (color[j] == 'G') {
            isBipartile = 0;
            // cout << "i,j = " << i << " ," << j << endl;
          }
          color[j] = 'R';
        }
      }
      cout<<"vertex = "<<i+1<<" , color = "<<color[i]<<endl;
      for (int k = 0; k < n; k++) {
            cout << color[k] <<" ";
        }
        cout<<endl;
    }
  }

  if (isBipartile == 0)
    cout << "Not Bipartile" << endl;
  else
    cout << "Bipartile" << endl;

  for (int i = 0; i < n; i++) {
    cout << color[i] <<" ";
  }
}