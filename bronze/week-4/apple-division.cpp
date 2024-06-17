#include <iostream>
#include <vector>
using namespace std;

int n;
vector<long long> p;

long long solve(long long group1Sum, long long group2Sum, long long index) {
    if (index == n) {
        return abs(group2Sum - group1Sum);
    }
    return min(
        solve(group1Sum + p[index], group2Sum, index + 1),
        solve(group1Sum, group2Sum + p[index], index + 1)
    );
}

int main(void) {
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << solve(0, 0, 0) << endl;
}
