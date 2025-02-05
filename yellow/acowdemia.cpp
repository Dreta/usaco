// USACO 2021 US Open, Silver
// Problem 3. Acowdemia

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, K, L;
    cin >> N >> K >> L;
    vector<long long> c(N);

    for (long long &x : c) {
        cin >> x;
    }

    sort(c.begin(), c.end(), greater<long long>());

    long long hi = N, lo = 0;
    while (hi > lo) {
        long long mid = (hi + lo + 1) / 2;

        bool canAchieve = true;
        if (c[mid - 1] < mid - K) {
            canAchieve = false;
        }

        long long needed = 0;
        for (long long i = 0; i < mid; i++) {
            if (c[i] < mid) {
                needed += mid - c[i];
            }
        }
        if (needed > K * L) {
            canAchieve = false;
        }

        if (canAchieve) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << hi << endl;
}
