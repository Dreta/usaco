// USACO 2020 December Contest, Silver
// Problem 1. Cowntagion

#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited;

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
};

int result = 0;
vector<int> current;

void bfs(const UndirectedGraph &graph, long long u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        int totalNeeded = 0;
        for (int neighbor : graph.adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                if (current[neighbor] == 0) {
                    current[neighbor] = 1;
                    result++;
                    totalNeeded++;
                }
                q.push(neighbor);
            }
        }

        // Duplicate locally to get everything needed
        result += ceil(log2(totalNeeded + 1));
        current[node] = current[node] * pow(2, ceil(log2(totalNeeded + 1)));
        current[node] -= totalNeeded;
    }
}

int main() {
    int N;
    cin >> N;

    if (N == 1) {
        cout << 0 << endl; // Special case
    }

    UndirectedGraph graph(N + 1);
    visited.resize(N + 1, false);
    current.resize(N + 1, 0);
    current[1] = 1;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    bfs(graph, 1);
    cout << result << endl;
}
