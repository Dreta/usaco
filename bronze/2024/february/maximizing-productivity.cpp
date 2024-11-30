// USACO 2024 February Contest, Bronze
// Problem 3. Maximizing Productivity

#include <iostream>
#include <vector>
using namespace std;

int MAX_T = 1000001;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> c(N);
    vector<int> r(MAX_T, 0);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    int impossible = 0;
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
        if (c[i] - t[i] >= 0) {
            r[c[i] - t[i]]++;
        } else {
            impossible++;
        }
    }

    vector<int> prefixSums(MAX_T, 0);
    prefixSums[0] = r[0];
    for (int i = 1; i < MAX_T; i++) {
        prefixSums[i] = prefixSums[i - 1] + r[i];
    }
    // To visit a farm, there must be S < c_i - t_i
    // prefixSum[i] means that there are prefixSum[i] farms with i >= c_i - t_i
    while (Q--) {
        int V, S;
        cin >> V >> S;
        if ((N - prefixSums[S] - impossible) >= V) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
