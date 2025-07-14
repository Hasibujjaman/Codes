//Prim's minimum spanning tree 
//works on connected undirected graphs with non-negative edge weights
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int V = 5; // Number of vertices

// Function to find the vertex with the minimum key value
int minKey(const vector<int>& key, const vector<bool>& mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed MST
void printMST(const vector<int>& parent, const vector<vector<int>>& graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i]+1 << " - " << i+1 << "\t" << graph[i][parent[i]] << "\n";
    }
}

// Function to perform Prim's algorithm to construct MST
void PrimMST(const vector<vector<int>>& graph) {
    vector<int> parent(V); // To store the constructed MST
    vector<int> key(V, INT_MAX); // Key values used to pick the minimum weight edge
    vector<bool> mstSet(V, false); // To represent set of vertices included in MST

    // Starting with the first vertex
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    // Example graph represented by an adjacency matrix
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Call Prim's algorithm function
    PrimMST(graph);

    return 0;
}
