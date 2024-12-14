// USACO 2021 January Contest, Bronze
// Problem 2. Even More Odd Photos

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int even = 0;
    int odd = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    while (odd > even) {
        odd -= 2;
        even++; // Combine two odd numbers for an even number
    }
    if (odd == even) {
        cout << odd * 2 << endl;
    } else if (odd < even) {
        cout << odd * 2 + 1 << endl;
    }
}
