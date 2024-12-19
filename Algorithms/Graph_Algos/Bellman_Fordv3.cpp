// shortest distance (in terms of weight)
// negative edges are allowed
// assigns the vertices that have negatives cycles in their paths a distance equal to minus infinity

#include <iostream>
#include <vector>
#include <limits>
#include <stack>
using namespace std;
const int INF = numeric_limits<int>::max();
const int NegINF = numeric_limits<int>::min();

class Graph
{
public:
    int V;
    vector<vector<pair<int, int>>> adj;
    vector<int> parent;
    vector<int> distance;

    Graph(int V) : V(V), adj(V), parent(V, -1), distance(V, INF) {}

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
    }

    bool Relax(int u, int v, int w)
    { // edge (u,v) with weight w
        if (distance[u] + w < distance[v])
        {
            distance[v] = distance[u] + w;
            parent[v] = u;
            return true;
        }
        return false;
    }
    void DFS_Visit(int vertex, vector<bool> &visited)
    {
        visited[vertex] = true;
        distance[vertex] = NegINF;

        for (auto i : adj[vertex])
        {
            int neighbor = i.first;
            if (!visited[neighbor])
            {
                DFS_Visit(neighbor, visited);
            }
        }
    }
    void BellmanFord(int source, int destinaiton)
    {
        distance[source] = 0;
        vector<int> verOnNegCyc; // vertices that are on paths which have negative cycles in them

        for (int i = 0; i < V - 1; i++)
        { // because , shortest paths are simple paths and simple paths in a graph with V vertices have atmost V-1 edges
            // relax each edge
            for (int j = 0; j < V; j++)
            {
                for (auto neighbor : adj[j])
                {
                    int u = j, v = neighbor.first, w = neighbor.second;
                    Relax(u, v, w);
                }
            }
        }
        // negative cycle checking
        for (int j = 0; j < V; j++)
        {
            for (auto neighbor : adj[j])
            {
                int u = j, v = neighbor.first, w = neighbor.second;
                if (Relax(u, v, w))
                {
                    cout << "Negative cycle detected while relaxing edge ( " << u << " , " << v << " )" << endl;
                    verOnNegCyc.push_back(u);
                }
            }
        }
        //assigning the vertices that have negatives cycles in their paths a distance equal to minus infinity
        vector<bool> visited(V, false);
        for (const int &vertex : verOnNegCyc)
        {
            //cout << vertex << endl;
            if(!visited[vertex]){
                DFS_Visit(vertex, visited);
            }
        }
        // print path
        if (parent[destinaiton] == -1)
        {
            cout << "Vertex " << destinaiton << " is disconnected and there is no path to is the destination" << endl;
            cout << "Distance = Infinity" << endl;
        }
        else
        {
            stack<int> predStack;
            int v = destinaiton;
            if (parent[source] == -1)
            {
                while (parent[v] != -1)
                {
                    predStack.push(v);
                    v = parent[v];
                }
                predStack.push(v);

                cout << "\nShortest path form vertex " << source << " to vertex " << destinaiton << " :" << endl;
                while (!predStack.empty())
                {
                    cout << predStack.top() << " --> ";
                    predStack.pop();
                }
                cout << "Distance of this path = " << distance[destinaiton] << endl
                     << endl;
            }
            else
            {
                cout<<"Source is a part of a path with negative cycle"<<endl;
            }
        }
        for(int i = 0; i < V; i++){
            cout<<"Vertex = "<<i<<", Distance from source vertex "<<source<<" = ";
            if(distance[i] == NegINF)
                cout<<"-inf"<<endl;
            else    
                cout<<distance[i]<<endl;
        }
    }
};

int main()
{
    // Create a graph
    Graph g(5); // page 613, fig. 22.4
    g.addEdge(0, 1, 6);
    g.addEdge(0, 2, 7);

    g.addEdge(1, 2, 8);
    g.addEdge(1, 3, -4);
    g.addEdge(1, 4, 5);

    g.addEdge(2, 3, 9);
    g.addEdge(2, 4, -3);

    g.addEdge(3, 0, 2);
    g.addEdge(3, 4, 4);

    g.addEdge(4, 1, -2);

    g.BellmanFord(0, 4);

    return 0;
}