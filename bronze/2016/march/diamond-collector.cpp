// USACO 2016 US Open Contest, Bronze
// Problem 1. Diamond Collector

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> sizes(n);
    for (int i = 0; i < n; i++) {
        cin >> sizes[i];
    }

    int result = 0;
    sort(sizes.begin(), sizes.end());
    for (int start = 0; start < n; start++) {
        int end = start;
        while (end < n && sizes[end] - sizes[start] <= k) {
            end++;
        }
        result = max(result, end - start);
    }
    cout << result << endl;
}
