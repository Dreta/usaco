// USACO 2024 February Contest, Silver
// Problem 3. Moorbles

#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<vector<int>> habit; // 0 - Even, 1 - Odd
vector<int> possibilities; // 0 - Even Only, 1 - Odd Only, 2 - Both
vector<int> largestOdd;
vector<int> largestEven;
vector<int> smallestOdd;
vector<int> smallestEven;
bool foundResult = false;

void permute(int length, vector<int>& current, int index) {
    if (index == length) {
        // Processing permutation
        int remaining = N;
        for (int i = 0; i < M; i++) {
            if (current[i] == 0) {
                if (possibilities[i] == 1 || possibilities[i] == 2) {
                    remaining -= largestOdd[i];
                } else {
                    remaining += smallestEven[i];
                }
            } else if (current[i] == 1) {
                if (possibilities[i] == 0 || possibilities[i] == 2) {
                    remaining -= largestEven[i];
                } else {
                    remaining += smallestOdd[i];
                }
            }
            if (remaining <= 0) {
                return;
            }
        }
        foundResult = true;
        throw true; // Leave the call stack immediately
    }
    current[index] = 0;
    permute(length, current, index + 1);
    current[index] = 1;
    permute(length, current, index + 1);
}

void task() {
    cin >> N >> M >> K;
    habit = vector<vector<int>>(M, vector<int>(K));
    possibilities = vector<int>(M, -1);
    largestOdd = vector<int>(M, 0);
    largestEven = vector<int>(M, 0);
    smallestOdd = vector<int>(M, 1000000000);
    smallestEven = vector<int>(M, 1000000000);
    foundResult = false;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> habit[i][j];
            if (habit[i][j] % 2 == 0) {
                largestEven[i] = max(largestEven[i], habit[i][j]);
                smallestEven[i] = min(smallestEven[i], habit[i][j]);
            } else {
                largestOdd[i] = max(largestOdd[i], habit[i][j]);
                smallestOdd[i] = min(smallestOdd[i], habit[i][j]);
            }
            if (habit[i][j] % 2 == 0) {
                if (possibilities[i] == -1) {
                    possibilities[i] = 0;
                } else if (possibilities[i] == 1) {
                    possibilities[i] = 2;
                }
            } else {
                if (possibilities[i] == -1) {
                    possibilities[i] = 1;
                } else if (possibilities[i] == 0) {
                    possibilities[i] = 2;
                }
            }
        }
    }


    vector<int> current(M, 0);
    try {
        permute(M, current, 0);
    } catch (bool _) { }
        
    if (foundResult) {
        for (int i = 0; i < M; i++) {
            cout << ((current[i] == 0) ? "Even" : "Odd");
            if (i != M - 1) {
                cout << " ";
            }
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        task();
    }
}
