// USACO 2021 February Contest, Silver
// Problem 2. Year of the Cow

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <numeric>
#include <set>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> ancestors(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> ancestors[i];
    }

    vector<int> cycles;
    for (int a : ancestors) {
        cycles.push_back(floor((a + 11) / 12));
    }
    sort(cycles.rbegin(), cycles.rend());

    vector<int> gaps;
    for (int i = 1; i <= N; i++) {
        gaps.push_back(cycles[i - 1] - cycles[i]);
    }
    sort(gaps.rbegin(), gaps.rend());
    gaps.resize(K - 1);

    cout << cycles[0] * 12 - (accumulate(gaps.begin(), gaps.end(), 0) - gaps.size()) * 12 << endl;
}
