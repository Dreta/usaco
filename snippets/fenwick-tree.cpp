#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) : n(size) {
        tree.assign(n + 1, 0);
    }
    
    FenwickTree(const vector<int>& arr) {
        n = arr.size();
        tree.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            update(i, arr[i]);
        }
    }
    
    void update(int index, int delta) {
        index++;
        while (index <= n) {
            tree[index] += delta;
            index += index & (-index);
        }
    }
    
    int prefixSum(int index) {
        int result = 0;
        index++;
        while (index > 0) {
            result += tree[index];
            index -= index & (-index);
        }
        return result;
    }
    
    int rangeSum(int left, int right) {
        return prefixSum(right) - (left > 0 ? prefixSum(left - 1) : 0);
    }
};
