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

class DepthFirstTraversal {
private:
    vector<bool> marked;
    vector<int> edgeTo;
    const DirectedGraph& graph;

    void dfs(int vertex) {
        marked[vertex] = true;
        for (int neighbor : graph.adjacent(vertex)) {
            if (!marked[neighbor]) {
                edgeTo[neighbor] = vertex;
                dfs(neighbor);
            }
        }
    }

public:
    DepthFirstTraversal(const DirectedGraph& graph, int start) 
        : graph(graph) {
        this->marked = vector<bool>(graph.vertices, false);
        this->edgeTo = vector<int>(graph.vertices, -1);
        dfs(start);
    }

    bool hasPathTo(int vertex) {
        return marked[vertex];
    }
};
