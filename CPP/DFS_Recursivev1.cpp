#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int> > adj;  // Adjacency list

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    

    void DFS_Visit(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (const int& neighbor : adj[vertex]) {
            if (!visited[neighbor]) {
                //visited[neighbor] = true;
                DFS_Visit(neighbor, visited);
            }
        }

    }

    void DFS(int startVertex) {
        vector<bool> visited(V, false);
        cout << "\nDepth-First Traversal (starting from vertex " <<0<< ") : "<<endl<<endl;
        DFS_Visit(startVertex, visited);
        
        //for visiting even the disconnected vertices of the graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cout << "\n\nDepth-First Traversal (starting from vertex " <<i<< ") : "<<endl<<endl;
                DFS_Visit(i, visited);
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

    g.DFS(0); //using s = 0 as sources
    cout<<endl<<endl;


    return 0;
}
