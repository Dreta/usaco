// USACO 2024 January Contest, Bronze
// Problem 1. Majority Opinion

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    // Special case: n = 1 and n = 2
    if (n == 1) {
        cout << h[0] << endl;
        return;
    }
    if (n == 2) {
        if (h[0] == h[1]) {
            cout << h[0] << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }

    // Special case: all equal
    bool allEqual = true;
    for (int i = 1; i < n; i++) {
        if (h[i] != h[i - 1]) {
            allEqual = false;
            break;
        }
    }
    if (allEqual) {
        cout << h[0] << endl;
        return;
    }

    // General case
    set<int> result;
    for (int i = 0; i < n - 2; i++) {
        if (h[i] == h[i + 1] && h[i + 1] != h[i + 2]) {
            result.insert(h[i]);
        } else if (h[i] != h[i + 1] && h[i + 1] == h[i + 2]) {
            result.insert(h[i + 1]);
        } else if (h[i] == h[i + 2] && h[i] != h[i + 1]) {
            result.insert(h[i]);
        }
    }
    if (result.size() == 0) {
        cout << -1 << endl;
    } else {
        for (auto it = result.begin(); it != result.end(); ++it) {
            if (it != result.begin()) {
                cout << " ";
            }
            cout << *it;
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
