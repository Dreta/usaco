// USACO 2024 February Contest, Bronze
// Problem 2. Milk Exchange

// Subtasks 1 - 8

#include <iostream>
#include <vector>
#include <numeric>
using ll = long long;
using namespace std;

ll N, M;
string ops;
vector<ll> capacity;
vector<ll> current;

ll left(ll i) {
    return (i - 1 + N) % N;
}

ll right(ll i) {
    return (i + 1) % N;
}

void minute() {
    for (ll i = 0; i < N; i++) {
        if (current[i] >= 1) {
            current[i]--;
            if (ops[i] == 'L') {
                current[left(i)]++;
            } else if (ops[i] == 'R') {
                current[right(i)]++;
            }
        }
    }
    for (ll i = 0; i < N; i++) {
        current[i] = min(current[i], capacity[i]);
    }
}

int main() {
    cin >> N >> M;
    cin >> ops;
    capacity.resize(N);
    current.resize(N);
    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        current[i] = a;
        capacity[i] = a;
    }

    for (ll i = 0; i < M; i++) {
        minute();
    }
    ll result = 0;
    for (ll i = 0; i < N; i++) {
        result += current[i];
    }
    cout << result << endl;
}
