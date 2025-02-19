#include <vector>
#include <queue>
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

void treeTraversal(const DirectedGraph &graph, long long u) {
    // Processing visited node
    for (auto neighbor : graph.adj[u]) {
        treeTraversal(graph, neighbor);
    }
}

void bfs(const UndirectedGraph &graph, long long u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // Processing visited node
        for (auto neighbor : graph.adj[u]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}


// FUNCTIONAL GRAPHS ONLY
struct CycleInfo {
    int cycleStart;
    int cycleLength;
};

// If no cycle, cycleStart is -1.
CycleInfo floyd(const DirectedGraph &graph, int start) {
    if (graph.adjacent(start).empty()) {
        return {-1, 0};
    }

    int tortoise = graph.adjacent(start)[0];
    int hare;
    if (graph.adjacent(tortoise).empty()) {
        return {-1, 0};
    } else {
        hare = graph.adjacent(tortoise)[0];
    }

    // Phase 1: Finding a meeting point.
    while (tortoise != hare) {
        if (graph.adjacent(tortoise).empty() || graph.adjacent(hare).empty()) {
            return {-1, 0};
        }
        tortoise = graph.adjacent(tortoise)[0];
        
        // Advance hare two steps.
        int nextHare = graph.adjacent(hare)[0];
        if (graph.adjacent(nextHare).empty()) {
            return {-1, 0};
        }
        hare = graph.adjacent(nextHare)[0];
    }

    // Phase 2: Find the start of the cycle (mu).
    int mu = 0;
    tortoise = start;
    while (tortoise != hare) {
        tortoise = graph.adjacent(tortoise)[0];
        hare = graph.adjacent(hare)[0];
        mu++;
    }
    int cycleStart = tortoise;

    // Phase 3: Determine the cycle length (lambda).
    int lambda = 1;
    hare = graph.adjacent(tortoise)[0];
    while (hare != tortoise) {
        hare = graph.adjacent(hare)[0];
        lambda++;
    }

    return {cycleStart, lambda};
}
