//Dijkstra
// works on weighted directed graph
// no negative edges are allowed
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

#define INF INT_MAX

// Structure to represent a weighted directed graph
struct Edge
{
    int destination;
    int weight;
};

class Graph
{
public:
    int vertices;
    vector<vector<Edge>> adjList;
    vector<int> distance;
    vector<int> parent;

    Graph(int V)
    {
        vertices = V;
        adjList.resize(V);
        distance.resize(V);
        parent.resize(V);
        distance.insert(distance.begin(), distance.size(), INF);
        parent.insert(parent.begin(), parent.size(), -1);
    }
    // Graph(int V): adjList(V), distance(V,INF), parent(V,-1){}

    void addEdge(int source, int destination, int weight)
    {
        Edge edge = {destination, weight};
        adjList[source].push_back(edge);
    }

    void Dijkstra(int source)
    {
        distance[source] = 0;

        // Priority queue to store vertices and their distances
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source}); // pair(key, data) = (v.d, v) , hence pq will  keyed by d values of vertices

        while (!pq.empty())
        {
            int u = pq.top().second; // extract min
            pq.pop();                // popped vertices have their v.d s as shortest distances and they will never be added to pq henceforth
            // S = S U {u}

            for (const Edge &edge : adjList[u])
            {
                int v = edge.destination;
                int weight = edge.weight;

                // Relaxation step
                if (distance[u] != INF && distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v}); // as priority_queue doesn't support decrease key we simply add it to the queque and after consider the copy that has the smallest key for a particular vertex
                                               //  hence , the invarient that Q = V - S (in terms of vertices , not key) doesn't hold in all cases as even after popping a vertex from the queue that vertex can still remain in the queue as it can have multiple copies with different key (v.d) values
                    parent[v] = u;
                }
            }
        }
        // Print the shortest distances from the source
        cout << "Shortest distances from source " << source << ":\n";
        for (int i = 1; i < vertices; ++i)
        {
            // if (distance[i] == INF)
            //     cout << i << ": INF\n";
            // else
            //     cout << i << ": " << distance[i] << "\n";
            printPath(0,i);

        }
    }
    void printPath(int source, int destination)
    {
        // for (int i = 0; i < vertices; i++)
        // {
        //     cout << "Vertex = " << i << " | Parent = " << parent[i] << " | Distance from source vertex " << source << " = " << distance[i] << endl;
        // }
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
            cout<<"\nDistance = "<<distance[destination]<<endl<<endl;
        }
    }
};

    int main()
    {
        // Example usage
        int V = 5; // Number of vertices (page: 609)
        Graph graph(V);

        graph.addEdge(0, 1, 3);
        graph.addEdge(0, 3, 5);

        graph.addEdge(1, 2, 6);
        graph.addEdge(1, 3, 2);

        graph.addEdge(2, 4, 2);

        graph.addEdge(3, 1, 1);
        graph.addEdge(3, 2, 4);
        graph.addEdge(3, 4, 6);

        graph.addEdge(4, 0, 3);
        graph.addEdge(4, 2, 7);

        int source = 0; // Source vertex
        graph.Dijkstra(source);

        return 0;
    }