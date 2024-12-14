// USACO 2018 February Contest, Bronze
// Problem 2. Hoofball

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<int> cows; // index to position
vector<int> targets; // index to index

int target(int i) {
    if (i == 0) {
        return 1;
    } else if (i == N - 1) {
        return N - 2;
    } else {
        if (cows[i] - cows[i - 1] <= cows[i + 1] - cows[i]) {
            return i - 1;
        } else {
            return i + 1;
        }
    }
}

int main() {
    cin >> N;
    cows.resize(N);
    targets.resize(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    if (N <= 3) {
        cout << 1 << endl;
        return 0;
    }
    sort(cows.begin(), cows.end());

    // First, we calculate the amount of balls each cow can receive.
    for (int i = 0; i < N; i++) {
        targets[target(i)]++;
    }

    int resultA = 0;
    int resultB = 0;
    for (int i = 0; i < N; i++) {
        if (targets[i] == 0) {
            resultA++;
        }
        if (targets[i] == 1 && targets[target(i)] == 1 && target(target(i)) == i) {
            resultB++; // We are counting twice
        }
    }
    cout << resultA + resultB / 2 << endl;
}
