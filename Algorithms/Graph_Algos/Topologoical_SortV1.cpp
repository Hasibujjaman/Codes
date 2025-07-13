//works on directed acyclic graph (DAG)
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
bool isDAG = true;

int t;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int> > adj;  // Adjacency list
    //vector<int> d; //discovery time
    vector<pair<int,int>> f; // finish examining time
    //vector<int> parent;
    vector<char> color;

    Graph(int V) : V(V), adj(V), f(V), color(V, 'w'){}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    

    void DFS_Visit(int vertex, vector<char>& color) {
        //d[vertex] = ++t;
        color[vertex] = 'g';
        cout<<vertex<<" ";

        for (const int& neighbor : adj[vertex]) {
            if (color[neighbor] == 'w') {
                //parent[neighbor] = vertex;
                //cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Tree edge"<<endl;
                DFS_Visit(neighbor, color);
            }
            else if(color[neighbor] == 'g'){
                //cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Back edge"<<endl;
                isDAG = false;
            }
            // else if(d[neighbor] > d[vertex]){
            //     //cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Forward edge"<<endl;
            // }
            // else{
            //     //cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Cross edge"<<endl;
            // }
        }
        color[vertex] = 'b';
        ++t;
        f[vertex] = make_pair(t,vertex);
    }

    void DFS(int startVertex) {
        cout << "\nDepth-First Traversal (starting from vertex " <<0<< ") : "<<endl<<endl;
        DFS_Visit(startVertex, color);
        for (int i = 0; i < V; i++) {
            if (color[i] == 'w') {
                cout << "\n\nDepth-First Traversal (starting from vertex " <<i<< ") : "<<endl<<endl;
                DFS_Visit(i, color);
            }
        }
    }
    void TopologicalSort(int startVertex){
        DFS(startVertex);
        if(isDAG){
            sort(f.begin(),f.end()); // this should be avoided . otherwise the time complexity won't be linear anymore
            cout<<"\n\nTopological sorted DAG:"<<endl<<endl;
            for(int i = f.size()-1; i >= 0; i--){
                cout<<f[i].second<<" ";
            }
            cout<<endl<<endl;
            return;
        }
        cout<<"Not a DAG"<<endl;


    }
};

int main() {
    // Create a graph (page: 575 ,fig.20.8) 
    Graph g(14);  // m=0,n=1,.....,y=12,z=13
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(0, 11);

    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 8);

    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(2, 9);

    g.addEdge(3, 2);
    g.addEdge(3, 6);
    g.addEdge(3, 13);

    g.addEdge(4, 7);

    g.addEdge(5, 8);
    g.addEdge(5, 12);

    g.addEdge(6, 5);

    g.addEdge(8, 7);

    g.addEdge(9, 10);
    g.addEdge(9, 11);

    g.addEdge(10, 13);

    g.addEdge(12, 9);


    g.TopologicalSort(0); //using m = 0 as sources
    cout<<endl<<endl;


    return 0;
}
