// USACO 2016 January Contest, Bronze
// Problem 1. Promotion Counting

#include <iostream>
using namespace std;

int main() {
    int parChange[4];
    for (int i = 0; i < 4; i++) {
        int a, b;
        cin >> a >> b;
        parChange[i] = b - a;
    }

    int result[3] = {0};
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            result[j] += parChange[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << result[i] << endl;
    }
}
