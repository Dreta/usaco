// USACO 2024 January Contest, Silver
// Problem 2. Potion Farming

#include <algorithm>
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

    int degree(int u) {
        return adj[u].size();
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

vector<bool> isLeaf;
vector<int> P;
vector<int> C;
vector<int> potions;

void dfs(const UndirectedGraph &graph, int u, long long parent) {
    if (isLeaf[u]) {
        C[u] = 1;
        P[u] = potions[u] > 0 ? 1 : 0;
        return;
    }
    C[u] = 0;
    int sumChildPotions = 0;
    for (int nxt : graph.adj[u]) {
        if (nxt == parent) {
            continue;
        }
        dfs(graph, nxt, u);
        C[u] += C[nxt];
        sumChildPotions += P[nxt];
    }
    P[u] = min(C[u], sumChildPotions + potions[u]);
}

int main() {
    int N;
    cin >> N;
    UndirectedGraph graph(N + 1);
    isLeaf.resize(N + 1, false);
    P.resize(N + 1);
    C.resize(N + 1);
    potions.resize(N + 1, false);

    vector<int> pots(N);

    for (int i = 0; i < N; i++) {
        cin >> pots[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int leaves = 0;
    for (int i = 1; i <= N; i++) {
        if (i != 1) {
            if (graph.degree(i) == 1) {
                isLeaf[i] = true;
                leaves++;
            }
        } else if (graph.degree(i) == 0) {
            isLeaf[i] = true;
            leaves++;
        }
    }

    for (int i = 0; i < leaves; i++) {
        potions[pots[i]]++;
    }

    dfs(graph, 1, 0);
    cout << P[1] << endl;
}
