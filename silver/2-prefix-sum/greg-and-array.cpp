// Codeforces: 295A
// Greg and Array

#include <iostream>
#include <vector>
using namespace std;

struct Op {
    long long l;
    long long r;
    long long d;
};

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> diff(n);
    diff[0] = a[0];
    for (long long i = 1; i < n; i++) {
        diff[i] = a[i] - a[i - 1];
    }

    vector<Op> ops(m);
    for (long long i = 0; i < m; i++) {
        cin >> ops[i].l >> ops[i].r >> ops[i].d;
        ops[i].l--;
        ops[i].r--;
    }

    // Observe that operations can be exchanged
    vector<long long> opsCount(m, 0);
    while (k--) {
        long long x, y;
        cin >> x >> y;
        x--;
        y--;
        opsCount[x]++;
        if (y + 1 < m) {
            opsCount[y + 1]--;
        }
    }

    long long currentOps = opsCount[0];
    for (long long i = 1; i <= m; i++) {
        Op op = ops[i - 1];
        diff[op.l] += currentOps * op.d;
        if (op.r + 1 < n) {
            diff[op.r + 1] -= currentOps * op.d;
        }
        currentOps += opsCount[i];
    }

    long long current = diff[0];
    for (long long i = 1; i <= n; i++) {
        cout << current << " ";
        current += diff[i];
    }
    cout << endl;
}
