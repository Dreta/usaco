// USACO 2021 December Contest, Silver
// Problem 3. Convoluted intervals

#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> intervals(N);
    for (auto &i : intervals) {
        cin >> i.first >> i.second;
    }

    vector<long long> winStart(2 * M + 1);
    vector<long long> winEnd(2 * M + 1);

    vector<long long> aFreq(M + 1);
    vector<long long> bFreq(M + 1);
    for (long long i = 0; i < N; i++) {
        aFreq[intervals[i].first]++;
        bFreq[intervals[i].second]++;
    }

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            winStart[i + j] += aFreq[i] * aFreq[j];
            winEnd[i + j] += bFreq[i] * bFreq[j];
        }
    }

    long long total = 0;
    for (long long i = 0; i <= 2 * M; i++) {
        total += winStart[i];
        cout << total << endl;
        total -= winEnd[i];
    }
}
