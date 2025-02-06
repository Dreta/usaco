#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int queryMax(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return INT_MIN;
        }
        if (left <= start && end <= right) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMax = queryMax(2 * node + 1, start, mid, left, right);
        int rightMax = queryMax(2 * node + 2, mid + 1, end, left, right);
        return max(leftMax, rightMax);
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, INT_MIN);
        build(arr, 0, 0, n - 1);
    }

    int queryMax(int left, int right) { // incl.
        return queryMax(0, 0, n - 1, left, right);
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }
};