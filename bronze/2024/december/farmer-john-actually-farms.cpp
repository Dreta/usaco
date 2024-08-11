// USACO 2023 December Contest, Bronze
// Problem 3. Farmer John Actually Farms

#include <algorithm>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void answer() {
    long long n;
    cin >> n;
    vector<long long> heights(n);
    vector<long long> grow(n);
    vector<long long> target(n);
    for (long long i = 0; i < n; i++) {
        cin >> heights[i];
    }
    for (long long i = 0; i < n; i++) {
        cin >> grow[i];
    }
    for (long long i = 0; i < n; i++) {
        cin >> target[i];
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    // Observation: The minimum days to reach the target number of other plants that are taller than this plant
    // is determined by the difference of the growth rate.

    // Calculate the difference of the growth rate first
    vector<vector<pair<long long, long long>>> growthRateDiff(n);
    for (int i = 0; i < n; i++) {
        growthRateDiff[i].resize(n);
        for (int j = 0; j < n; j++) {
            growthRateDiff[i][j] = {j, grow[j] - grow[i]};
        }
    }

    // Attempt to answer.
    long long result = -1;
    for (long long i = 0; i < n; i++) {
        if (target[i] == 0) {
            continue;
        }

        vector<pair<long long, long long>> thisWithOthers = growthRateDiff[i];
        // Determine how many days it would take.
        long long maxDays = -1;
        for (long long j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }
            pair<long long, long long> thisDiff = thisWithOthers[j];
            if (thisDiff.second <= 0) {
                continue;
            }
            maxDays = max(maxDays, (heights[i] - heights[thisDiff.first]) / thisDiff.second + 1);
        }
        result = max(result, maxDays);
    }
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        answer();
    }
}
