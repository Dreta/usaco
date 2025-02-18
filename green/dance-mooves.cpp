// USACO 2021 January Contest, Silver
// Problem 1. Dance Moves

#include <iostream>
#include <vector>
#include <set>
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
};

vector<int> visited;
vector<int> positionsToCows;
vector<int> cowsToPositions;
vector<vector<int>> prevPositions;

int main() {
    int N, K;
    cin >> N >> K;

    visited.resize(N + 1, false);
    positionsToCows.resize(N + 1);
    cowsToPositions.resize(N + 1);
    prevPositions.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        positionsToCows[i] = i;
        cowsToPositions[i] = i;
        prevPositions[i].push_back(i);
    }

    vector<pair<int, int>> swaps(K);
    for (pair<int, int> &sw : swaps) {
        cin >> sw.first >> sw.second;
        
        int cowA = positionsToCows[sw.first];
        int cowB = positionsToCows[sw.second];
        swap(positionsToCows[sw.first], positionsToCows[sw.second]);
        swap(cowsToPositions[cowA], cowsToPositions[cowB]);

        prevPositions[cowA].push_back(sw.second);
        prevPositions[cowB].push_back(sw.first);
    }

    DirectedGraph graph(N + 1);
    for (int i = 1; i <= N; i++) {
        graph.addEdge(i, cowsToPositions[i]);
    }

    vector<bool> cycleVisited(N + 1, false);
    vector<int> cycleNodes;

    vector<int> result(N + 1);
    for (int i = 1; i <= N; i++) {
        if (!cycleVisited[i]) {
            cycleNodes.clear();
            int cur = i;
            while (!cycleVisited[cur]) {
                cycleVisited[cur] = true;
                cycleNodes.push_back(cur);
                cur = cowsToPositions[cur];
            }
            
            set<int> unionSet;
            for (int cow : cycleNodes) {
                unionSet.insert(prevPositions[cow].begin(), prevPositions[cow].end());
            }
            
            for (int cow : cycleNodes) {
                result[cow] = unionSet.size();
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << endl;
    }
}
