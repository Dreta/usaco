// USACO 2022 December Contest, Silver
// Problem 3. Range Reconstruction

#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> current;
vector<vector<int>> constraints;

int main() {
    cin >> n;
    current.resize(n);
    current[n - 1] = 0;
    constraints.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> constraints[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        current[i] = current[i + 1] + constraints[i][i + 1];

        int mx = INT_MIN;
        int mn = INT_MAX;
        bool ok = true;
        for (int j = i; j < n; j++) {
            mx = max(mx, current[j]);
            mn = min(mn, current[j]);
            if (mx - mn != constraints[i][j]) {
                ok = false;
                break;
            }
        }
        
        if (!ok) {
            current[i] = current[i + 1] - constraints[i][i + 1];
        }
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << current[i];
            continue;
        }
        cout << " " << current[i];
    }
    cout << endl;
}
