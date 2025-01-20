// USACO 2024 February Contest, Silver
// Problem 3. Moorbles

#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<vector<int>> habit; // habit[round][parity] 0 - even, 1 - odd
vector<int> prefix;
bool foundResult = false;

void task() {
    cin >> N >> M >> K;
    habit = vector<vector<int>>(M, vector<int>(2, 1e9));
    prefix = vector<int>(M + 1, 0);
    foundResult = false;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;
            int parity = x % 2;
            habit[i][parity] = min(habit[i][parity], x);
            habit[i][1 - parity] = min(habit[i][1 - parity], -x);
        }
    }

    for (int i = M - 1; i >= 0; i--) {
        prefix[i] = min(0, prefix[i + 1] + max(habit[i][0], habit[i][1]));
    }

    if (N + prefix[0] <= 0) {
        cout << -1 << endl;
        return;
    }
    vector<int> result;
    for (int i = 0; i < M; i++) {
        int current = (N + habit[i][0] + prefix[i + 1] <= 0 ) ? 1 : 0;
        result.push_back(current);
        N += habit[i][current];
    }

    for (int i = 0; i < M; i++) {
        cout << ((result[i] == 1) ? "Odd" : "Even");
        if (i < M - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        task();
    }
}
