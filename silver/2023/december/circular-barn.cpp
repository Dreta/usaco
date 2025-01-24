// USACO 2022 December Contest, Silver
// Problem 2. Circular Barn

#include <iostream>
#include <vector>
using namespace std;

const int maximum = 5000005;
vector<bool> composite(maximum, false);
vector<int> maxMod4 = {2, 1, 2, 3};
vector<int> minTurns(maximum);

void task() {
    int N;
    cin >> N;

    int answer = maximum;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (minTurns[a[i]] / 2 < answer / 2) {
            answer = minTurns[a[i]];
        }
    }
    if (answer % 2 == 1) {
        cout << "Farmer John" << endl;
    } else {
        cout << "Farmer Nhoj" << endl;
    }
}

int main() {
    minTurns[0] = 0;
    minTurns[1] = 1;

    for (int i = 2; i < maximum; i++) {
        if (!composite[i]) {
            for (int j = i; j < maximum; j += i) {
                composite[j] = true;
            }
            maxMod4[i % 4] = i;
        }
        minTurns[i] = (i - maxMod4[i % 4]) / 2 + 1;
    }

    int T;
    cin >> T;
    while (T--) {
        task();
    }
}
