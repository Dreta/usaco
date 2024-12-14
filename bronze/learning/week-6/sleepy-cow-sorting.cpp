// USACO 2019 January Contest, Bronze
// Problem 2. Sleepy Cow Sorting

#include <iostream>
using namespace std;

int main() {
    int N;

    cin >> N;
    int p[N];
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    int y = 1;
    for (int i = N - 1; i >= 1; i--) {
        if (p[i - 1] < p[i]) {
            y++;
        } else {
            break;
        }
    }
    cout << N - y << endl;
}
