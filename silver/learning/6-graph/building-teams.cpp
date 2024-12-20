// CSES Problem Set
// Building Teams

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

vector<bool> visited;
vector<int> color;
bool success = true;

void dfs(const UndirectedGraph &graph, long long u, bool previousColor) {
    visited[u] = true;
    color[u] = !previousColor;
    for (auto neighbor : graph.adj[u]) {
        if (color[neighbor] == color[u]) {
            success = false;
            return;
        }
        if (!visited[neighbor]) {
            dfs(graph, neighbor, color[u]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    visited.resize(n);
    color.resize(n, -1);
    UndirectedGraph graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, i, 0);
        }
    }
    if (success) {
        for (int i = 0; i < n; i++) {
            cout << color[i] + 1 << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
