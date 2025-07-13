// works only on DAGs
// Theta(V+E)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stack>
using namespace std;
bool isDAG = true;
const int INF = numeric_limits<int>::max();

int t; // for calculating finishing time of all vertices

class Graph
{
public:
    int V;                         // Number of vertices
    vector<vector<int>> adj;       // Adjacency list
    vector<vector<int>> adjWeight; // Adjacenct list for weights of edges
    vector<int> map;               // maps finishing time of each vertex to its corresponding vertex in G
    vector<int> parent;
    vector<int> distance;
    vector<char> color;

    Graph(int V) : V(V), adj(V), adjWeight(V), map(V), parent(V, -1), distance(V, INF), color(V, 'w') {}

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(v);
        adjWeight[u].push_back(w);
    }

    void DFS_Visit(int vertex, vector<char> &color)
    {
        // d[vertex] = ++t;
        color[vertex] = 'g';
        cout << vertex << " ";
        for (const int &neighbor : adj[vertex])
        {
            if (color[neighbor] == 'w')
            {
                // parent[neighbor] = vertex;
                // cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Tree edge"<<endl;
                DFS_Visit(neighbor, color);
            }
            else if (color[neighbor] == 'g')
            {
                // cout<<"("<<vertex<<", "<<neighbor<<")"<<" --> Back edge"<<endl;
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
        map[t++] = vertex;
    }

    void DFS(int startVertex)
    {
        cout << "\nDepth-First Traversal (starting from vertex " << startVertex << ") : " << endl
             << endl;
        DFS_Visit(startVertex, color);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == 'w')
            {
                cout << "\n\nDepth-First Traversal (starting from vertex " << i << ") : " << endl
                     << endl;
                DFS_Visit(i, color);
            }
        }
    }
    bool TopologicalSort(int startVertex)
    {
        DFS(startVertex);
        if (isDAG)
        {
            // cout << "\n\nTopological sorted DAG:" << endl
            //      << endl;
            // for (int i = V - 1; i >= 0; i--)
            // {
            //     cout << map[i] << " ";
            // }
            // cout << endl<< endl;
            return true;
        }
        // cout << "Not a DAG" << endl;
        return false;
    }
    bool Relax(int u, int v, int w)
    { // edge (u,v) with weight w
        if (distance[u] + w < distance[v] && distance[u] != INF)
        {
            distance[v] = distance[u] + w;
            parent[v] = u;
            return true;
        }
        return false;
    }
    void ShortestPath(int source, int destination)
    {
        if (TopologicalSort(source))
        {
            distance[source] = 0;
            for (int i = V - 1; i >= 0; i--)
            {
                int u = map[i];
                vector<int>::iterator itr = adjWeight[u].begin();
                for (const int &v : adj[u])
                {
                    int w = *itr;
                    Relax(u, v, w);
                    itr++;
                }
            }
            cout << endl
                 << endl;

            // print shortest path
            for (int i = 0; i < V; i++)
            {
                cout << "Vertex = " << i << " | Parent = " << parent[i] << " | Distance from source vertex " << source << " = " << distance[i] << endl;
            }
            if (parent[destination] == -1)
            {
                cout << "Vertex " << destination << " is disconnected and there is no path to is the destination" << endl;
                cout << "Distance = Infinity" << endl;
            }
            else
            {
                stack<int> predStack;
                int v = destination;
                while (parent[v] != -1)
                {
                    predStack.push(v);
                    v = parent[v];
                }
                predStack.push(v);
                cout << "\nShortest path form vertex " << source << " to vertex " << destination << " :" << endl;
                while (!predStack.empty())
                {
                    cout << predStack.top() << " --> ";
                    predStack.pop();
                }
                cout << "Distance of this path = " << distance[destination] << endl
                     << endl;
            }
        }
        else
            cout << "Not a DAG" << endl;
    }
};

int main()
{
    // Create a graph (page: 618 ,fig.22.5)
    Graph g(6); // m=0,n=1,.....,y=12,z=13
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);

    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);

    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);

    g.addEdge(3, 4, -1);
    g.addEdge(3, 5, 1);

    g.addEdge(4, 5, -2);

    g.ShortestPath(1, 5); 
    cout<< endl;

    return 0;
}