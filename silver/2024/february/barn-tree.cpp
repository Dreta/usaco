// USACO 2022 December Contest, Silver
// Problem 1. Barn Tree

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class UndirectedGraph {
public:
    long long vertices;
    vector<vector<long long>> adj;

    UndirectedGraph(long long vertices) {
        this->vertices = vertices;
        this->adj = vector<vector<long long>>(vertices);
    }

    void addEdge(long long u, long long v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

long long N;
vector<long long> haybales;
vector<tuple<long long, long long, long long>> orders;
vector<long long> subtreeTotal;

void fillSubtreeTotal(const UndirectedGraph &farm, long long x, long long parent) {
    subtreeTotal[x] = haybales[x];

    for (long long y : farm.adj[x]) {
        if (y == parent) continue;
        fillSubtreeTotal(farm, y, x);
        subtreeTotal[x] += subtreeTotal[y];
    }
}

void distribute(const UndirectedGraph &farm, long long x, long long parent) {
    for (long long c : farm.adj[x]) {
        if (c == parent) continue;
        if (subtreeTotal[c] >= 0) {
            distribute(farm, c, x);
            if (subtreeTotal[c] > 0) {
                orders.emplace_back(c, x, subtreeTotal[c]);
            }
        }
    }
    for (long long c : farm.adj[x]) {
        if (c == parent) continue;
        if (subtreeTotal[c] < 0) {
            orders.emplace_back(x, c, -subtreeTotal[c]);
            distribute(farm, c, x);
        }
    }
}

int main() {
    cin >> N;
    UndirectedGraph farm(N);
    haybales.resize(N);
    subtreeTotal.resize(N);

    long long sum = 0;
    for (long long &x : haybales) {
        cin >> x;
        sum += x;
    }
    for (long long &x : haybales) {
        x -= sum / N;
    }

    for (long long i = 0; i < N - 1; i++) {
        long long a, b;
        cin >> a >> b;
        farm.addEdge(a - 1, b - 1);
    }

    // MARK: - Solution
    // GOAL: Make all haybales 0.
    fillSubtreeTotal(farm, 0, -1);
    distribute(farm, 0, -1);

    cout << orders.size() << endl;
    for (auto [a, b, c] : orders) {
        cout << a + 1 << " " << b + 1 << " " << c << endl;
    }
}
