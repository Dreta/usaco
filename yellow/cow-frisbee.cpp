// USACO 2022 January Contest, Silver
// Problem 2. Cow Frisbee

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long N;
long long result = 0;

void solve(const vector<long long> &h) {
    vector<long long> hReverse(N + 1);
    for (long long i = 0; i < N; i++) {
        hReverse[h[i]] = i;
    }
    set<long long> s;
    for (long long i = N; i >= 1; i--) {
        auto it = s.insert(hReverse[i]).first;
        if (next(it) != s.end()) {
            result += *next(it) - *it + 1;
        }
    }
}

int main() {
    cin >> N;
    vector<long long> h(N);
    for (long long i = 0; i < N; i++) {
        cin >> h[i];
    }

    solve(h);
    reverse(h.begin(), h.end());
    solve(h);
    cout << result << endl;
}
