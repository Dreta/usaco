#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class SegmentTree {
private:
    vector<int> treeMax;
    vector<int> treeMin;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            treeMax[node] = arr[start];
            treeMin[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            treeMax[node] = max(treeMax[2 * node + 1], treeMax[2 * node + 2]);
            treeMin[node] = min(treeMin[2 * node + 1], treeMin[2 * node + 2]);
        }
    }

    int queryMax(int node, int start, int end, int left, int right) const {
        if (right < start || left > end) {
            return INT_MIN;
        }
        if (left <= start && end <= right) {
            return treeMax[node];
        }
        int mid = (start + end) / 2;
        int leftMax = queryMax(2 * node + 1, start, mid, left, right);
        int rightMax = queryMax(2 * node + 2, mid + 1, end, left, right);
        return max(leftMax, rightMax);
    }

    int queryMin(int node, int start, int end, int left, int right) const {
        if (right < start || left > end) {
            return INT_MAX;
        }
        if (left <= start && end <= right) {
            return treeMin[node];
        }
        int mid = (start + end) / 2;
        int leftMin = queryMin(2 * node + 1, start, mid, left, right);
        int rightMin = queryMin(2 * node + 2, mid + 1, end, left, right);
        return min(leftMin, rightMin);
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            treeMax[node] = value;
            treeMin[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            treeMax[node] = max(treeMax[2 * node + 1], treeMax[2 * node + 2]);
            treeMin[node] = min(treeMin[2 * node + 1], treeMin[2 * node + 2]);
        }
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        treeMax.resize(4 * n, INT_MIN);
        treeMin.resize(4 * n, INT_MAX);
        build(arr, 0, 0, n - 1);
    }

    int queryMax(int left, int right) const {
        return queryMax(0, 0, n - 1, left, right);
    }

    int queryMin(int left, int right) const {
        return queryMin(0, 0, n - 1, left, right);
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }
};