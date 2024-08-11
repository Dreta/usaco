// Codeforces Round 961 (Div. 2)
// B1. Bouquet (Easy Version)

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve(long long n, long long m, vector<long long> a) {
    // Classic two pointers solution.

    long long result = 0;
    long long left = 0;
    long long right = 0;
    long long current = 0;
    while (left < n && right < n) {
        while (right < n) {
            current += a[right];
            m -= a[right];
            if (m < 0 || (right < n && a[right] - a[left] > 1)) {
                current -= a[right];
                m += a[right];
                break;
            }
            right++;
        }

        result = max(result, current);
        current -= a[left]; // Move left our left pointer
        m += a[left];
        left++;
    }
    cout << result << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        solve(n, m, a);
    }
}
