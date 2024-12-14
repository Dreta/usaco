// Codeforces: 102951 B
// Studying Algorithms

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int i = 0;
    int result = 0;
    while (X > 0 && i < N) {
        if (X >= a[i]) {
            X -= a[i];
            result++;
        }
        i++;
    }

    cout << result << endl;
}
