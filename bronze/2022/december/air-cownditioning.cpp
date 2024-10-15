// USACO 2021 December Contest, Bronze
// Problem 2. Air Cownditioning

#include <iostream>
#include <vector>
using namespace std;

int sgn(int x) {
    if (x > 0) {
        return 1;
    }
    if (x < 0) {
        return -1;
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    vector<int> target(N);
    for (int i = 0; i < N; i++) {
        cin >> target[i];
    }
    vector<int> current(N);
    for (int i = 0; i < N; i++) {
        cin >> current[i];
    }
    vector<int> diff(N);
    for (int i = 0; i < N; i++) {
        diff[i] = target[i] - current[i];
    }
    int result = 0;
    int first = 0;
    while (true) {
        while (first < N && diff[first] == 0) {
            first++;
        }
        if (first == N) {
            break;
        }
        int last = first;
        while (last + 1 < N && sgn(diff[last + 1]) == sgn(diff[first])) {
            last++;
        }
        for (int i = first; i <= last; i++) {
            if (diff[i] < 0) {
                diff[i]++;
            } else {
                diff[i]--;
            }
        }
        result++;
    }
    cout << result << endl;
}
