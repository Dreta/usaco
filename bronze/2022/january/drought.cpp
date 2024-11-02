// USACO 2022 January Contest, Bronze
// Problem 3. Drought

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll solve(ll N, vector<ll> h) {
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        if (h[i + 1] > h[i]) {
            if (i + 2 > N) {
                return -1;
            }
            ll steps = h[i + 1] - h[i];
            h[i + 1] -= steps;
            h[i + 2] -= steps;
            if (h[i + 1] < 0 || h[i + 2] < 0) {
                return -1;
            }
            ans += steps * 2;
        } else if (h[i + 1] < h[i]) {
            if (i % 2 == 1) {
                return -1;
            }
            ans += (h[i] - h[i + 1]) * i;
        }
    }
    return ans;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll N;
        cin >> N;
        vector<ll> h(N + 1);
        for (ll i = 1; i <= N; i++) {
            cin >> h[i];
        }
        cout << solve(N, h) << endl;
    }
}
