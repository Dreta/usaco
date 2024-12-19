// CSES Problem Set
// Building Roads

#include <iostream>
#include <vector>
using namespace std;

class UndirectedGraph {
public:
    long long vertices;
    vector<vector<long long>> adj;

    UndirectedGraph(long long vertices) {
        this->vertices = vertices;
        this->adj.resize(vertices);
    }

    void addEdge(long long u, long long v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const vector<long long>& adjacent(long long u) const {
        return adj[u];
    }
};

vector<bool> visited;

void dfs(const UndirectedGraph &graph, long long u, vector<long long> &component) {
    visited[u] = true;
    component.push_back(u);
    for (auto neighbor : graph.adj[u]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, component);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    cin >> n >> m;

    UndirectedGraph graph(n);
    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    visited.assign(n, false);
    vector<vector<long long>> components;
    for (long long i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<long long> component;
            dfs(graph, i, component);
            components.push_back(component);
        }
    }

    cout << (int)components.size() - 1 << "\n";
    for (int i = 0; i < (int)components.size() - 1; i++) {
        cout << components[i][0] + 1 << " " << components[i + 1][0] + 1 << "\n";
    }

    return 0;
}
