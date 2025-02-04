// USACO 2024 December Contest, Silver
// Problem 2. Deforestation

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#define ll long long
using namespace std;

class FenwickTree {
private:
    vector<ll> tree;
    ll n;

public:
    FenwickTree(ll size) : n(size) {
        tree.assign(n + 1, 0);
    }
    
    void update(ll index, ll delta) {
        index++;
        while (index <= n) {
            tree[index] += delta;
            index += index & (-index);
        }
    }
    
    ll prefixSum(ll index) {
        ll result = 0;
        index++;
        while (index > 0) {
            result += tree[index];
            index -= index & (-index);
        }
        return result;
    }
    
    ll rangeSum(ll left, ll right) {
        return prefixSum(right) - (left > 0 ? prefixSum(left - 1) : 0);
    }
};

void task() {
    ll N, K;
    cin >> N >> K;
    vector<ll> x(N);
    vector<vector<ll>> r(K, vector<ll>(3));
    set<ll> coords;
    for (ll &xi : x) {
        cin >> xi;
        coords.insert(xi);
    }
    for (ll i = 0; i < K; i++) {
        cin >> r[i][0] >> r[i][1] >> r[i][2];
        coords.insert(r[i][0]);
        coords.insert(r[i][1]);
    }

    // Coordinate compression
    FenwickTree trees(coords.size());
    map<ll, ll> compressed;
    ll idx = 0;
    for (ll coord : coords) {
        compressed[coord] = idx++;
    }
    for (ll &xi : x) {
        xi = compressed[xi];
        trees.update(xi, 1);
    }

    // Begin solution
    sort(x.begin(), x.end());
    sort(r.begin(), r.end(), [](const vector<ll> &a, const vector<ll> &b) {
        return a[0] < b[0];
    });

    for (ll i = 0; i < K; i++) {
        r[i][0] = compressed[r[i][0]];
        r[i][1] = compressed[r[i][1]];
    }

    map<ll, vector<ll>> restrictions;
    for (ll i = 0; i < K; i++) {
        restrictions[r[i][0]].push_back(i);
    }

    auto cmp = [](const vector<ll>& a, const vector<ll>& b) {
        return a[2] < b[2]; // max r[i][2] at top
    };
    priority_queue<vector<ll>, vector<vector<ll>>, decltype(cmp)> pq(cmp);

    ll result = 0;
    for (ll i = 0; i < coords.size(); i++) {
        for (ll j : restrictions[i]) {
            pq.push(r[j]);
        }
        while (!pq.empty() && i > pq.top()[1]) {
            pq.pop();
        }
        if (trees.rangeSum(i, i) == 0) {
            continue;
        }
        if (pq.empty() || trees.rangeSum(pq.top()[0], pq.top()[1]) > pq.top()[2]) {
            result++;
            trees.update(i, -1);
        }
    }
    cout << result << endl;
}

int main() {
    ll T;
    cin >> T;
    while (T--) {
        task();
    }
}
