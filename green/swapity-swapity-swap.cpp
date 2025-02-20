// USACO 2020 February Contest, Silver
// Problem 1. Swapity Swapity Swap

#include <iostream>
#include <vector>
using namespace std;

vector<int> applyPermutation(const vector<int>& perm, int N) {
    int n = perm.size();
    vector<int> result(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> cycle;
            int x = i;
            while (!visited[x]) {
                visited[x] = true;
                cycle.push_back(x);
                x = perm[x];
            }

            int L = cycle.size();
            int shift = N % L;
            for (int j = 0; j < L; j++) {
                result[cycle[j]] = cycle[(j + shift) % L];
            }
        }
    }

    return result;
}

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) arr[i] = i;
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        for (int j = 0; j < (r - l + 1) / 2; j++) {
            swap(arr[l + j], arr[r - j]);
        }
    }

    for (int i : applyPermutation(arr, K)) {
        cout << i + 1 << endl;
    }
}
