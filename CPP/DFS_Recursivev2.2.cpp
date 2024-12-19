//works on directed graphs only
//determines edges' types
#include <iostream>
#include <vector>
using namespace std;

int t;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int> > adj;  // Adjacency list
    vector<int> d,f;
    vector<int> parent;
    vector<char> color;

    Graph(int V) : V(V), adj(V), d(V,-1), f(V,-1), parent(V,-1), color(V, 'w'){}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    

    void DFS_Visit(int vertex, vector<char>& color) {
        d[vertex] = ++t;
        color[vertex] = 'g';
        //cout << vertex << " ";

        for (const int& neighbor : adj[vertex]) {
            if (color[neighbor] == 'w') {
                parent[neighbor] = vertex;
                cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Tree edge"<<endl;
                DFS_Visit(neighbor, color);
            }
            else if(color[neighbor] == 'g'){
                cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Back edge"<<endl;
            }
            else if(d[neighbor] > d[vertex]){
                cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Forward edge"<<endl;
            }
            else{
                cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Cross edge"<<endl;
            }
        }
        f[vertex] = ++t;
        color[vertex] = 'b';

    }

    void DFS(int startVertex) {
        
        //vector<bool> visited(V, false);
        cout << "\nDepth-First Traversal (starting from vertex " <<0<< ") : "<<endl<<endl;
        DFS_Visit(startVertex, color);
        for (int i = 0; i < V; i++) {
            if (color[i] == 'w') {
                cout << "\n\nDepth-First Traversal (starting from vertex " <<i<< ") : "<<endl<<endl;
                DFS_Visit(i, color);
            }
        }
    }
};

int main() {
    // Create a graph (page: 568 ,fig.20.5.(c)) 
    Graph g(8);  // s=0,t=1,.....,y=6,z=7
    g.addEdge(0, 7);
    g.addEdge(0, 4);

    g.addEdge(1, 3);
    g.addEdge(1, 2);

    g.addEdge(2, 3);

    g.addEdge(3, 0);
    g.addEdge(3, 4);

    g.addEdge(4, 5);

    g.addEdge(5, 7);

    g.addEdge(6, 5);

    g.addEdge(7, 6);
    g.addEdge(7, 4);
    //g.addEdge(7, 5);

    g.DFS(0); //using s = 0 as sources
    cout<<endl<<endl;


    return 0;
}
