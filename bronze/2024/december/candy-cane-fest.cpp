// USACO 2023 December Contest, Bronze
// Problem 1. Candy Cane Fest

#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<long long> cows(N);
    vector<pair<long long, long long>> canes(M);

    for (long long i = 0; i < N; i++) {
        cin >> cows[i];
    }
    for (long long i = 0; i < M; i++) {
        long long end;
        cin >> end;
        canes[i] = {0, end};
    }

    for (long long cane = 0; cane < M; cane++) {
        for (long long cow = 0; cow < N; cow++) {
            if (canes[cane].first < cows[cow]) {
                long long eaten = min(canes[cane].second, cows[cow]) - canes[cane].first;
                cows[cow] += eaten;
                canes[cane].first += eaten;
                if (canes[cane].first >= canes[cane].second) {
                    break;
                }
            }
        }
    }

    for (long long cow : cows) {
        cout << cow << endl;
    }
}
