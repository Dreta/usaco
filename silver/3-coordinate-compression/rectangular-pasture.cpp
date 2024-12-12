// USACO 2020 December Contest, Silver
// Problem 2. Rectangular Pasture

#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll N;
vector<vector<ll>> prefixSum(2501, vector<ll>(2501));

bool sortByY(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second < b.second;
}

ll rsum(ll x1, ll y1, ll x2, ll y2) {
    return prefixSum[x2 + 1][y2 + 1] - prefixSum[x2 + 1][y1] - prefixSum[x1][y2 + 1] + prefixSum[x1][y1];
}

int main() {
    cin >> N;
    vector<pair<ll, ll>> coords(N);
    for (ll i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        coords[i] = make_pair(x, y);
    }
    // Compress coords
    sort(coords.begin(), coords.end());
    for (ll i = 0; i < N; i++) {
        coords[i].first = i + 1;
    }
    sort(coords.begin(), coords.end(), sortByY);
    for (ll i = 0; i < N; i++) {
        coords[i].second = i + 1;
    }

    prefixSum[0][0] = 0;
    for (ll i = 0; i < N; i++) {
        prefixSum[coords[i].first][coords[i].second] = 1;
    }
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            prefixSum[i][j] += prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    ll answer = 0;
    // Fix point i on the top and point j on the bottom
    for (ll i = 0; i < N; i++) {
        for (ll j = i; j < N; j++) {
            ll x1 = min(coords[i].first, coords[j].first) - 1;
            ll x2 = max(coords[i].first, coords[j].first) - 1;
            answer += rsum(0, i, x1, j) * rsum(x2, i, N - 1, j);
        }
    }
    cout << answer + 1 << endl;
}
