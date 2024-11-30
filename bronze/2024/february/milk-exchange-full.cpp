// USACO 2024 February Contest, Bronze
// Problem 2. Milk Exchange

// All Subtasks

#include <iostream>
#include <vector>
#include <numeric>
using ll = long long;
using namespace std;

ll N, M;

ll left(ll i) {
    return (i - 1 + N) % N;
}

ll right(ll i) {
    return (i + 1) % N;
}

int main() {
    cin >> N >> M;
    vector<ll> capacity(N);
    vector<bool> badR(N, false);
    vector<bool> badL(N, false);
    string ops;
    cin >> ops;

    ll total = 0;
    for (ll i = 0; i < N; i++) {
        cin >> capacity[i];
        total += capacity[i];
    }

    for (ll i = 0; i < N; i++) {
        if (ops[i] == 'R' && ops[right(i)] == 'L') {
            badR[i] = true;
            badL[right(i)] = true;
        }
    }

    ll leaks = 0;
    for (ll i = 0; i < N; i++) {
        ll maxPossibleLeaks = 0;
        if (badR[i]) {
            for (ll j = left(i); ops[j] == 'R' && j != i; j = left(j)) {
                maxPossibleLeaks += capacity[j];
            }
        } else if (badL[i]) {
            for (ll j = right(i); ops[j] == 'L' && j != i; j = right(j)) {
                maxPossibleLeaks += capacity[j];
            }
        }
        leaks += min(M, maxPossibleLeaks);
    }

    cout << total - leaks << endl;
}
