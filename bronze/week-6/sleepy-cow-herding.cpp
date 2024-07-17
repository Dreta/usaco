// USACO 2019 February Contest, Bronze
// Problem 1. Sleepy Cow Herding

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int cows[3];
    for (int i = 0; i < 3; i++) {
        cin >> cows[i];
    }

    sort(cows, cows + 3);
    int biggerDiff = max(cows[1] - cows[0], cows[2] - cows[1]) - 1;
    int smallerDiff = min(cows[1] - cows[0], cows[2] - cows[1]) - 1;

    if (biggerDiff == 0 && smallerDiff == 0) {
        cout << 0 << endl;
        cout << 0 << endl;
        return 0;
    }
    
    if (smallerDiff == 1) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }

    cout << biggerDiff << endl;
}
