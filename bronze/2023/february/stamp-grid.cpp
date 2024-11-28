// USACO 2023 February Contest, Bronze
// Problem 2. Stamp Grid

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> &stamp) {
    int N = stamp.size();
    vector<vector<int>> rotated(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotated[j][N - i - 1] = stamp[i][j];
        }
    }
    return rotated;
}

void task() {
    int N;
    cin >> N;
    vector<vector<int>> target(N, vector<int>(N));
    set<pair<int, int>> ones;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == '*') {
                target[i][j] = 1;
                ones.insert({i, j});
            } else target[i][j] = 0;
        }
    }
    int K;
    cin >> K;
    vector<vector<int>> stamp(K, vector<int>(K));
    for (int i = 0; i < K; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < K; j++) {
            if (s[j] == '*') stamp[i][j] = 1;
            else stamp[i][j] = 0;
        }
    }

    set<pair<int, int>> successfullyMatched;
    for (int topLeftRow = 0; topLeftRow <= N - K; topLeftRow++) {
        for (int topLeftCol = 0; topLeftCol <= N - K; topLeftCol++) {
            for (int rotations = 0; rotations < 4; rotations++) {
                stamp = rotate(stamp);
                // Check if in the current state, the stamp does not result in any 1s placed on 0-targets
                bool valid = true;
                for (int i = 0; i < K; i++) {
                    for (int j = 0; j < K; j++) {
                        if (stamp[i][j] == 1 && target[topLeftRow + i][topLeftCol + j] == 0) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) break;
                }
                // If valid, stamp.
                if (valid) {
                    for (int i = 0; i < K; i++) {
                        for (int j = 0; j < K; j++) {
                            if (stamp[i][j] == 1) {
                                successfullyMatched.insert({topLeftRow + i, topLeftCol + j});
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (successfullyMatched != ones) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        task();
    }
}
