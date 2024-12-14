// USACO 2018 January Contest, Silver
// Problem 1. Rest Stops

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int L, N, rf, rb;
    cin >> L >> N >> rf >> rb;

    vector<pair<int, int>> stops(N);
    for (int i = 0; i < N; i++) {
        cin >> stops[i].first >> stops[i].second;
    }
    
    vector<bool> toVisit(N, false);
    long long currentMax = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (stops[i].second > currentMax) {
            currentMax = stops[i].second;
            toVisit[i] = true;
        }
    }

    long long result = 0;
    long long lastStoppedAt = 0;
    for (int i = 0; i < N; i++) {
        if (!toVisit[i]) {
            continue;
        }

        long long distance = stops[i].first - lastStoppedAt;
        result += distance * (rf - rb) * stops[i].second;
        lastStoppedAt = stops[i].first;
    }
    cout << result << endl;
}
