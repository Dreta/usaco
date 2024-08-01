// USACO 2019 February Contest, Bronze
// Problem 2. The Great Revegetation

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class UndirectedGraph {
public:
    int vertices;
    vector<vector<int>> adj;

    UndirectedGraph(int vertices) {
        this->vertices = vertices;
        this->adj = vector<vector<int>>(vertices);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> adjacent(int u) {
        return vector<int>(adj[u]);
    }

    int edges() {
        int edges = 0;
        for (int i = 0; i < vertices; i++)
        {
            edges += adj[i].size();
        }
        return edges / 2;
    }
};

int main() {
    int edges;
    int vertices;
    cin >> edges >> vertices;

    UndirectedGraph graph(edges);
    for (int i = 0; i < vertices; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    vector<int> colors(edges, 0);
    for (int i = 0; i < edges; i++) {
        vector<int> adj = graph.adjacent(i);
        if (colors[i] == 0) {
            // Color this vertex with 1
            colors[i] = 1;
            // Color all adjacent vertices
            for (int j : adj) {
                if (colors[j] == 0) {
                    colors[j] = 2;
                }
            }
        } else {
            sort(adj.begin(), adj.end());
            // Resolve conflicts
            for (int j : adj) {
                if (colors[j] == colors[i]) {
                    if (j < i) { // Prefer incrementing the color of the vertex with the bigger index (to get the smallest result)
                        colors[i]++;
                    } else {
                        colors[j] = colors[i] + 1;
                    }
                }
            }
        }
    }

    for (int color : colors) {
        cout << color;
    }
    cout << endl;
}
