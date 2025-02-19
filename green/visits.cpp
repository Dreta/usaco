// USACO 2022 US Open Contest, Silver
// Problem 1. Visits

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

long long N;
vector<long long> reward;
vector<long long> results;

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
};

int main() {
    cin >> N;
    DirectedGraph graph(N + 1);

    reward.resize(N + 1);

    for (long long i = 1; i <= N; i++) {
        long long t, r;
        cin >> t >> r;
        graph.addEdge(i, t);
        reward[i] = r;
    }

}
