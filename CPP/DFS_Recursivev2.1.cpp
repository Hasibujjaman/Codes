//works on undirected graps only
//determines types of edges 
#include <iostream>
#include <utility>
#include <vector>
#include <set>
using namespace std;

int t;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int> > adj;  // Adjacency list
    vector<int> d,f;
    vector<int> parent;
    vector<char> color;
    set< set<int> >  treeEdges, backEdges;

    Graph(int V) : V(V), adj(V), d(V,-1), f(V,-1), parent(V,-1), color(V, 'w'){
        
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    void DFS_Visit(int vertex, vector<char>& color) {
        d[vertex] = ++t;
        color[vertex] = 'g';

        for (const int& neighbor : adj[vertex]) {
            if (color[neighbor] == 'w') {
                parent[neighbor] = vertex;
                //cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Tree edge"<<endl;
                set<int> s = {vertex,neighbor};
                treeEdges.insert(s);
                DFS_Visit(neighbor, color);
            }
            else if(parent[vertex] != neighbor){
                set<int> s = {vertex,neighbor};
                backEdges.insert(s);
                //cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Back edge"<<endl;
            }
            // else if(d[neighbor] > d[vertex]){
            //     cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Forward edge"<<endl;
            // }
            // else{
            //     cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Cross edge"<<endl;
            // }
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
    // Create a graph (page: 557) 
    Graph g(9); 
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 5);

    //g.addEdge(1, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

   // g.addEdge(2, 0);
    g.addEdge(2, 3);

   // g.addEdge(3,1);
    //g.addEdge(3, 2);
    g.addEdge(3, 7);

    //g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(4, 7);

    //g.addEdge(5, 0);
    //g.addEdge(5, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 8);

   // g.addEdge(6, 5);
    g.addEdge(6, 7);
    g.addEdge(6, 8);

    //g.addEdge(7, 3);
    //g.addEdge(7, 4);
    //g.addEdge(7, 6);

    //g.addEdge(8, 5);    
    //g.addEdge(8, 6);    

    g.DFS(3); //using s = 3 as sources
    cout<<endl<<endl;

    cout << "Tree Edges: ";
    for (set<set<int> >::iterator i = g.treeEdges.begin(); i != g.treeEdges.end(); ++i){
        cout<<"{";
        for(std::set<int>:: iterator j = i->begin(); j != i->end(); ++j){
            cout<<" "<<*j<<" ";
        }
        cout<<"} ";
    }
    cout<<endl<<endl;

    cout << "Back Edges: ";
    for (set<set<int> >::iterator i = g.backEdges.begin(); i != g.backEdges.end(); ++i){
        cout<<"{";
        for(std::set<int>:: iterator j = i->begin(); j != i->end(); ++j){
            cout<<" "<<*j<<" ";
        }
        cout<<"} ";
    }
    cout<<endl<<endl;

    return 0;
}
