// Codeforces 102951B
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
    int result = 0;
    int current = 0;
    while (result < N && current + a[result] <= X) {
        current += a[result];
        result++;
    }
    cout << result << endl;
}
