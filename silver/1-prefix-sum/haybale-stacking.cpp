// USACO 2012 January Contest, Bronze
// Problem 2. Haybale Stacking

// IMPRESSION: Adding within a range can be converted into a prefix sum problem by adding the value
// at the start of the range and subtracting the value at the end of the range. This is because the
// value at the start of the range is added to all values in the range, and the value at the end of
// the range is subtracted from all values after the range. This is a common technique used in prefix
// sum problems.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> values(N + 1, 0);
    values[0] = 0;
    while (K--) {
        int a, b;
        cin >> a >> b;
        values[a]++;
        values[b + 1]--;
    }
    vector<int> prefixSums(N + 1);
    prefixSums[0] = values[0];
    for (int i = 1; i <= N; i++) {
        prefixSums[i] = prefixSums[i - 1] + values[i];
    }
    sort(prefixSums.begin(), prefixSums.end());
    cout << prefixSums[(N + 1) / 2] << endl;
}
