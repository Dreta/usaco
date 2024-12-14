// Yosupo: Static Range Sum

#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, Q;
    cin >> N >> Q;
    vector<long long> a(N);
    for (long long i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<long long> prefixSums(N);
    prefixSums[0] = a[0];
    for (long long i = 1; i < N; i++) {
        prefixSums[i] = prefixSums[i - 1] + a[i];
    }

    while (Q--) {
        long long l, r;
        cin >> l >> r;
        if (l == 0) {
            cout << prefixSums[r - 1] << endl;
        } else {
            cout << prefixSums[r - 1] - prefixSums[l - 1] << endl;
        }
    }
}
