// USACO 2019 January Contest, Silver
// Problem 1. Grass Planting

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
        return adj[u];
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
    int vertices;
    cin >> vertices;

    UndirectedGraph graph(vertices);
    for (int i = 0; i < vertices - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }
    
    int result = 0;
    for (int i = 0; i < vertices; i++) {
        result = max(result, (int) graph.adjacent(i).size());
    }
    cout << result + 1 << endl;
}
