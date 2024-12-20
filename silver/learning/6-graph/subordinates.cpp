// CSES Problem Set
// Subordinates

#include <iostream>
#include <vector>
using namespace std;

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

int dfs(const DirectedGraph &graph, long long u, vector<int> &size) {
    size[u] = 1;
    for (auto neighbor : graph.adj[u]) {
        size[u] += dfs(graph, neighbor, size);
    }
    return size[u];
}

int main() {
    int n;
    cin >> n;
    DirectedGraph graph(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        graph.addEdge(x - 1, i);
    }
    vector<int> size(n);
    dfs(graph, 0, size);

    for (int i = 0; i < n; i++) {
        cout << size[i] - 1 << " ";
    }
    cout << endl;
}
