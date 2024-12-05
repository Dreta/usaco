// USACO 2022 December Contest, Bronze
// Problem 2. Feeding the Cows

#include <iostream>
#include <vector>
using namespace std;

void task() {
    int N, K;
    cin >> N >> K;
    string breeds;
    cin >> breeds;

    vector<char> result(N, '.');
    int patches = 0;
    int lastG = -K - 1;
    int lastH = -K - 1;
    for (int i = 0; i < N; i++) {
        if (breeds[i] == 'G' && i - lastG <= K) {
            continue;
        }
        if (breeds[i] == 'H' && i - lastH <= K) {
            continue;
        }

        int target = i + K;
        if (i + K > N - 1) {
            target = i;
        }
        patches++;
        if (result[target] == '.') {
            result[target] = breeds[i];
        } else {
            target--;
            result[target] = breeds[i];
        }

        if (breeds[i] == 'G') {
            lastG = target;
        } else {
            lastH = target;
        }
    }
    cout << patches << endl;
    cout << string(result.begin(), result.end()) << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        task();
    }
}
