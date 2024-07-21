// USACO 2018 February Contest, Bronze
// Problem 3. Taming the Herd

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> expected(N); // Expected values, assuming that no breakout occurred during unknown dates
    expected[0] = 0; // Certainly a breakout on the first day
    for (int i = N - 1; i >= 1; i--) {
        if (a[i] == -1 && i < N - 1) {
            expected[i] = expected[i + 1] - 1;
        } else {
            expected[i] = a[i];
        }
    }

    // Check for impossibilities, namely,
    //   Time skipped by more than 1 day between 2 items, except for changing to 0
    //   Time remained the same between 2 items, except for two 0s
    for (int i = 0; i < N - 1; i++) {
        if (expected[i + 1] - expected[i] > 1 || (expected[i + 1] == expected[i] && expected[i] != 0)) {
            cout << -1 << endl;
            return 0;
        }
    }

    int min = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (expected[i] == 0) {
            min++;
            max++;
        } else if (expected[i] <= -1) {
            max++;
        }
    }
    cout << min << " " << max << endl;
}
