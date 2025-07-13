//isn't a true DFS
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int> > adj; // Adjacency list

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS_Visit(int startVertex, vector<bool>& visited) {
        cout << "\nDepth-First Traversal (starting from vertex " <<startVertex<< ") : "<<endl<<endl;


        //create a stack for DFS_Visit
        stack<int> stack;

        // Mark the current node as visited and put it in the stack
        visited[startVertex] = true;
        stack.push(startVertex);

        while (!stack.empty()) {
            int vertex = stack.top();
            stack.pop();
            cout << vertex << " ";

            for (const int& neighbor : adj[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
    }

    void DFS(int startVertex){
        vector<bool> visited(V, false); //mark all vertices as not discovered
        DFS_Visit(startVertex, visited);

        //for visiting even the disconnected vertices of the graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS_Visit(i, visited);
            }
        }
    }
};

int main() {
    // Create a graph 
    Graph g(9);  // r=0,s=1,t=2,.....,y=7,z=8
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 5);

    g.addEdge(1, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.addEdge(2, 0);
    g.addEdge(2, 3);

    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 7);

    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(4, 7);

    g.addEdge(5, 0);
    g.addEdge(5, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 8);

    g.addEdge(6, 5);
    g.addEdge(6, 7);
    g.addEdge(6, 8);

    g.addEdge(7, 3);
    g.addEdge(7, 4);
    g.addEdge(7, 6);

    g.addEdge(8, 5);
    g.addEdge(8, 6);


    g.DFS(3); //using u = 3 as sources
    cout<<endl<<endl;

    return 0;
}
