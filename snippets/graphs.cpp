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

class DirectedGraph {
public:
    int vertices;
    vector<vector<int>> adj;

    DirectedGraph(int vertices) {
        this->vertices = vertices;
        this->adj = vector<vector<int>>(vertices);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    vector<int> adjacent(int u) const {
        return adj[u];
    }

    int edges() {
        int edges = 0;
        for (int i = 0; i < vertices; i++)
        {
            edges += adj[i].size();
        }
        return edges;
    }
};

vector<bool> visited;

void dfs(const UndirectedGraph &graph, long long u) {
    visited[u] = true;
    // Processing visited node
    for (auto neighbor : graph.adj[u]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor);
        }
    }
}
