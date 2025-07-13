//true DFS (same output as the resurvise one)
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int> > adj; // Adjacency list

    //constructor
    Graph(int V) : V(V), adj(V){}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS_Visit(int startVertex, vector<bool>& visited) {
        cout << "\nDepth-First Traversal (starting from vertex " <<startVertex<< ") : "<<endl<<endl;


        //create a stack for DFS_Visit
        stack< pair<int,int> > stack;

        // Mark the current node as visited and put it in the stack
        visited[startVertex] = true; 
        
        pair<int, int> p = {startVertex, 0};
        stack.push(p);
        cout<<startVertex<<" ";
        while (1) {
            pair<int,int> pop = stack.top();
            stack.pop();
            int u = pop.first, elementIndex = pop.second;
            //(3) for backtracking to the previous node when there is no white(unvisited) neighbors left to visit
            while(adj[u].empty() || elementIndex >= adj[u].size()){
                visited[u] = true;
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
                visited[v] = true;
                //(1)
                push.first = v;
                push.second = 0;
                stack.push(push);

                cout<<v<<" ";
            }
            
        }
        cout<<endl<<endl;
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
