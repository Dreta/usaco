// USACO 2023 February Contest, Silver
// Problem 1. Bakery

#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

void task() {
    long long N, tc, tm;
    cin >> N >> tc >> tm;
    vector<long long> a(N), b(N), c(N);
    for (long long i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // 0 <= m <= tc - 1
    // 0 <= n <= tm - 1
    // For each i = 1...N
    // a[i] * m + b[i] * n >= a_i * t_c + b_i * t_m - c_i

    long long hi = tc + tm - 2, lo = 0;
    long long answer = -1;
    while (hi > lo) {
        long long mid = lo + (hi - lo) / 2;

        bool canAchieve = true;
        long long mMinBound = max(0LL, mid - tm + 1);
        long long mMaxBound = min(tc - 1, mid);
        for (long long i = 0; i < N; i++) {
            if (a[i] == b[i]) {
                if (!(a[i] * mid >= a[i] * tc + b[i] * tm - c[i])) {
                    canAchieve = false;
                    break;
                }
            }
            long long thisMMinBound = numeric_limits<long long>::min();
            long long thisMMaxBound = numeric_limits<long long>::max();
            if (a[i] > b[i]) {
                thisMMinBound = ceil((double) (a[i] * tc + b[i] * tm - c[i] - b[i] * mid) / (double) (a[i] - b[i]));
            }
            if (a[i] < b[i]) {
                thisMMaxBound = floor((double) (a[i] * tc + b[i] * tm - c[i] - b[i] * mid) / (double) (a[i] - b[i]));
            }
            mMinBound = max(mMinBound, thisMMinBound);
            mMaxBound = min(mMaxBound, thisMMaxBound);
        }

        if (mMinBound > mMaxBound) {
            canAchieve = false;
        }

        if (canAchieve) {
            hi = mid;
            answer = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << answer << endl;
}

int main() {
    long long T;
    cin >> T;
    while (T--) {
        task();
    }
}
