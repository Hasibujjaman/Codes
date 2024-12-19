//true DFS (same output as the resurvise one)
//prints the edge types
#include <iostream>
#include <vector>
#include <stack>

int t;

using namespace std;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int> > adj; // Adjacency list
    vector<int> d,f; // d for discovery time , f for finishing time for each vertices
    vector<int> parent; // parents for each vertices in the depth first forest 

    Graph(int V) : V(V), adj(V), d(V,-1), f(V,-1), parent(V,-1){}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS_Visit(int startVertex, vector<bool>& visited) {
        cout << "\nDepth-First Traversal (starting from vertex " <<startVertex<< ") : "<<endl<<endl;


        //create a stack for DFS_Visit
        stack< pair<int,int> > stack;

        // Mark the current node as visited and put it in the stack
        visited[startVertex] = true; 
        t++;
        d[startVertex] = t;
        
        pair<int, int> p = {startVertex, 0};
        stack.push(p);
        //cout<<startVertex<<" ";
        while (1) {
            pair<int,int> pop = stack.top();
            stack.pop();
            int u = pop.first, elementIndex = pop.second;
            //(3) for backtracking to the previous node when there is no white(unvisited) neighbors left to visit
            while(adj[u].empty() || elementIndex >= adj[u].size()){
                visited[u] = true; // making u black
                t++;
                f[u] = t;
                if(stack.empty())
                    return;
                else{
                    pop = stack.top();
                    u = pop.first;
                    elementIndex = pop.second;
                    stack.pop();
                }
            }
            //(2) putting the next neighbor of u in the stack before (1) putting the white(not visited) neighbor of v(neighbor of u) so that the white neighbor of v can be processed next (if there is any)
            pair<int,int> push = {u, ++elementIndex};
            stack.push(push);
            //examining edge (u,v) and if v is white (not visited) 
            int v = adj[u].at(--elementIndex);
            if(!visited[v]){
                parent[v] = u;
                d[v] = ++t;
                visited[v] = true; // making v gray
                //(1)
                push.first = v;
                push.second = 0;
                stack.push(push);
                cout<<"("<<u<<", "<<v<<")"<<" --> Tree edge"<<endl;
            }
            //here, v is gray
            else if(f[v]==-1){
                cout<<"("<<u<<", "<<v<<")"<<" --> Back edge"<<endl;
            }
            //v is black
            else{
                if(d[u] < d[v])
                    cout<<"("<<u<<", "<<v<<")"<<" --> Forward edge"<<endl;
                else
                    cout<<"("<<u<<", "<<v<<")"<<" --> Cross edge"<<endl;
            }
            
        }
        cout<<endl<<endl;
    }

    void DFS(int startVertex){
        vector<bool> visited(V, false); //mark all vertices as not discovered ,i.e, white
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

    vector<int> a = {1,23,3};
}
