// USACO 2022 February Contest, Bronze
// Problem 2. Photoshoot 2

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Observation: A modification where B is pushed left is only required when there exists an A,
    // where A is to the left of B in the original order, but A is to the right of B in the expected order.
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> aInverse(N + 1);
    vector<int> b(N);
    vector<int> bInverse(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        aInverse[a[i]] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        bInverse[b[i]] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        a[i] = bInverse[a[i]];
    }

    int result = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] > max) {
            max = a[i];
        } else {
            result++;
        }
    }
    cout << result << endl;
}
