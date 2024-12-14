// USACO 2016 January Contest, Silver
// Problem 2. Subsequences Summing to Sevens

#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        a[i] = 0;
        if (i > 0) {
            a[i] = a[i - 1];
        }
        int j;
        cin >> j;
        a[i] += j;
    }
    // We start from the longest subsequences, and check if the sum of the subsequence is divisible by 7.
    for (int size = N; size >= 1; size--) {
        for (int start = 0; start <= N - size; start++) {
            long long sum = a[start + size - 1];
            if (start > 0) {
                sum -= a[start - 1];
            }
            if (sum % 7 == 0) {
                cout << size << endl;
                return 0;
            }
        }
    }
}
