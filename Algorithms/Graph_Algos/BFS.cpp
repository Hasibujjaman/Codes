//BFS + Shortest path(unweighted graphs)
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {


public:
    int V;  // Number of vertices
    vector<vector<int> > adj;  // Adjacency list
    vector<int> dist; // Distances of each vertices from a particular vertex
    vector<int> parent; // Parents of each vertices in the BFS tree

    Graph(int V) : V(V), adj(V), dist(V,INF), parent(V,-1){}

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // Breadth-First Search
    void BFS(int startVertex) {
        cout << "Breadth-First Traversal (starting from vertex " <<startVertex<< ") : "<<endl<<endl;
        vector<bool> visited(V, false);  // Mark all vertices as not visited

        // Create a queue for BFS
        queue<int> queue;

        // Mark the current node as visited and enqueue it
        visited[startVertex] = true;
        dist[startVertex] = 0;
        queue.push(startVertex);

        while (!queue.empty()) {
            // Dequeue a vertex from the queue and print it
            int vertex = queue.front();
            cout <<"Vertex: "<< vertex << "\tDistance: "<<dist[vertex]<<"\tParent: "<<parent[vertex]<<endl;
            queue.pop();

            // Get all adjacent vertices of the dequeued vertex
            for (const int& neighbor : adj[vertex]) {
                if (!visited[neighbor]) {
                    // Mark the adjacent vertex as visited and enqueue it
                    visited[neighbor] = true;
                    dist[neighbor] = dist[vertex] + 1;
                    parent[neighbor] = vertex;
                    queue.push(neighbor);
                }
            }
        }
    }

    void printPath(int s, int v){
        if(v==s){
            cout<<s<<" --> ";
            return;
        }
        else if(parent[v] == -1){
            cout<<"No path exists from vertex "<<s<<" to vertex "<<v<<endl;
            return;
        }
        else
            printPath(s, parent[v]);

        cout<<v<<" --> ";
    }
    
    void shortestPath(int s, int v){
        BFS(s);
        cout<<"\nShortest path from vertex "<<s<<" to vertex "<<v<<" :"<<endl;
        printPath(s, v);

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


    g.BFS(3); //using u = 3 as sources
    cout<<endl<<endl;

    g.shortestPath(1,8);


    return 0;
}
