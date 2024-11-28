// USACO 2023 February Contest, Bronze
// Problem 1. Hungry Cow

#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, T;
    cin >> N >> T;
    vector<pair<long long, long long>> deliveriesAt(N);
    for (long long i = 0; i < N; i++) {
        long long d, b;
        cin >> d >> b;
        deliveriesAt[i] = {d - 1, b};
    }
    long long available = 0;
    long long consumed = 0;
    for (long long i = 0; i < N; i++) {
        long long thisAt = deliveriesAt[i].first;
        if (i > 0 && available > 0) {
            long long toConsume = min(available, thisAt - deliveriesAt[i - 1].first);
            available -= toConsume;
            consumed += toConsume;
        }
        available += deliveriesAt[i].second;
        if (i == N - 1) {
            consumed += min(available, T - thisAt);
        }
    }
    cout << consumed << endl;
}
