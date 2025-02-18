#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent; // parent[i] points to the parent of i
    vector<int> size;   // size[i] stores the size of the tree rooted at i

public:
    // Constructor: initializes N elements with each element in its own set.
    DisjointSet(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find the root of element p.
    int find(int p) {
        while (p != parent[p]) {
            p = parent[p];  // Move p up the tree.
        }
        return p;
    }

    // Check if elements p and q are in the same set.
    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    // Union the sets containing p and q.
    void connect(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);

        // If they are already in the same set, no need to union.
        if (rootP == rootQ)
            return;

        // Weighted union: attach the smaller tree to the larger tree.
        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        } else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
    }
};
