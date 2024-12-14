// USACO 2017 February Contest, Silver
// Problem 2. Why Did the Cow Cross the Road II

#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int N, K, B;
    cin >> N >> K >> B;
    
    vector<int> isBroken(N + 1);
    for (int i = 0; i < B; i++) {
        int broken;
        cin >> broken;
        isBroken[broken] = 1;
    }
    vector<int> prefixSums(N + 1);
    prefixSums[0] = 0;
    for (int i = 1; i <= N; i++) {
        prefixSums[i] = prefixSums[i - 1] + isBroken[i];
    }
    int minFixes = N;
    for (int i = 1; i <= N - K + 1; i++) {
        int thisFixes = prefixSums[i + K - 1] - prefixSums[i - 1];
        minFixes = min(minFixes, thisFixes);
    }
    cout << minFixes << endl;
}
