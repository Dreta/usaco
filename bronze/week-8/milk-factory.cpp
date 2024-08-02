// USACO 2019 US Open Contest, Bronze
// Problem 2. Milk Factory

#include <iostream>
#include <vector>
using namespace std;

class DirectedGraph {
public:
    int vertices;
    vector<vector<int>> adj;
    vector<vector<int>> adjInv; // inverted adj, for quick query purposes

    DirectedGraph(int vertices) {
        this->vertices = vertices;
        this->adj = vector<vector<int>>(vertices);
        this->adjInv = vector<vector<int>>(vertices);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adjInv[v].push_back(u);
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
        return edges;
    }
};

class DepthFirstTraversal {
    private:
    vector<bool> marked;
    vector<int> edgeTo;

    void dfs(DirectedGraph graph, int vertex) {
        marked[vertex] = true;
        for (int neighbor : graph.adjacent(vertex)) {
            if (!marked[neighbor]) {
                edgeTo[neighbor] = vertex;
                dfs(graph, neighbor);
            }
        }
    }

    public:
    DepthFirstTraversal(DirectedGraph graph, int start) {
        this->marked = vector<bool>(graph.vertices, false);
        this->edgeTo = vector<int>(graph.vertices, -1);
        dfs(graph, start);
    }

    bool hasPathTo(int vertex) {
        return marked[vertex];
    }
};

int main() {
    int N;
    cin >> N;

    DirectedGraph graph(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a - 1, b - 1);
    }

    for (int vertex = 0; vertex < N; vertex++) {
        if (graph.adjInv[vertex].size() == 0) { // If there are no incoming edges, this is not the answer.
            continue;
        }
        bool flag = true;
        for (int v = 0; v < N; v++) {
            if (v == vertex) {
                continue;
            }
            DepthFirstTraversal dfs(graph, v);
            if (!dfs.hasPathTo(vertex)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << vertex + 1 << endl;
            return 0;
        }
    }


    cout << -1 << endl;
}
