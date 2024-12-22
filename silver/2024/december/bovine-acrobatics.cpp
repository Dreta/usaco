// USACO 2023 December Contest, Silver
// Problem 1. Bovine Acrobatics

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> pairs(N);
    for (int i = 0; i < N; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    
    sort(pairs.rbegin(), pairs.rend());

    deque<pair<long long, long long>> towers;
    towers.push_back({1e12, M});
    long long answer = 0;

    for (auto &[w, a] : pairs) {
        long long remaining = a;
        while (!towers.empty() && remaining > 0 && w + K <= towers.front().first) {
            if (towers.front().second > remaining) {
                towers.front().second -= remaining;
                remaining = 0;
            } else {
                remaining -= towers.front().second;
                towers.pop_front();
            }
        }

        long long cnt = a - remaining;
        if (cnt > 0) {
            towers.push_back({w, cnt});
            answer += cnt;
        }
    }

    cout << answer << endl;
}