// CSES Problem Set: Maximum Subarray Sum

#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> prefixSum(n + 1);
    prefixSum[0] = 0;
    for (long long i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        prefixSum[i] = prefixSum[i - 1] + x;
    }
    long long maxSum = prefixSum[1];
    long long minSum = prefixSum[0];
    for (long long i = 1; i <= n; i++) {
        maxSum = max(maxSum, prefixSum[i] - minSum);
        minSum = min(minSum, prefixSum[i]);
    }
    cout << maxSum << endl;
}
