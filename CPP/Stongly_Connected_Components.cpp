//works on directed graphs only
#include <iostream>
#include <vector>

using namespace std;
int t;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int> > adjOut;  // Adjacency list of neighbors of each vertices in graph G
    vector<vector<int> > adjIn;  // Adjacency list of neighbors of each vertices in graph G(transpose)
    //vector<int> f;
    vector<int> map; //maps finishing time of each vertex to its corresponding vertex in G

    Graph(int V) : V(V), adjOut(V), adjIn(V), map(V){}

    void addEdge(int u, int v) {
        adjOut[u].push_back(v);
        adjIn[v].push_back(u);
    }
    

    void DFS_Visit(int vertex, vector<bool>& visited, bool isTranspose) {
        visited[vertex] = true;
        cout << vertex << " ";
        if(!isTranspose){
            for (const int& neighbor : adjOut[vertex]) {
                if (!visited[neighbor]) {
                    //visited[neighbor] = true;
                    DFS_Visit(neighbor, visited, isTranspose);
                }
            }
            map[t] = vertex;
            t++;
        }
        else{
            for (const int& neighbor : adjIn[vertex]) {
                if (!visited[neighbor]) {
                    //visited[neighbor] = true;
                    DFS_Visit(neighbor, visited, isTranspose);
                }
            }
        }
        //++t;
        //map[t] = vertex;
    }

    void DFS() {
        vector<bool> visited(V, false);
        //cout << "\nDepth-First Traversal (starting from vertex " <<0<< ") : "<<endl<<endl;
        //DFS_Visit(startVertex, visited, );
        for (int i = V-1; i >= 0; i--) {
            if (!visited[i]) {
                cout << "\n\nDepth-First Traversal (starting from vertex " <<i<< ") on G : "<<endl<<endl;
                DFS_Visit(i, visited, false);
            }
        }
        cout<<endl<<endl<<"--------------------\t----------------------\t----------------";
        visited.clear();
        visited.insert(visited.begin(),V,false);
        vector<bool> vis(V,false);
        for (int i = V-1; i >= 0; i--) {
            if (!visited[map[i]]) {
                cout << "\n\nDepth-First Traversal (starting from vertex " <<i<< ") on G(transpose) : "<<endl<<endl;
                DFS_Visit(map[i], visited, true);
            }
        }
        
    }

};

int main() {
    // Create a graph (page: 577) 
    Graph g(8);

    g.addEdge(0, 1);

    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 5);

    g.addEdge(2, 3);
    g.addEdge(2, 6);

    g.addEdge(3, 2);
    g.addEdge(3, 7);

    g.addEdge(4, 0);
    g.addEdge(4, 5);

    g.addEdge(5, 6);

    g.addEdge(6, 5);
    g.addEdge(6, 7);

    g.addEdge(7, 7);

    g.DFS(); 
    cout<<endl<<endl;


    return 0;
}
