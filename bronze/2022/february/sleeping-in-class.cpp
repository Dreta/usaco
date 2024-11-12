// USACO 2022 February Contest, Bronze
// Problem 1. Sleeping in Class

#include <iostream>
#include <vector>
using namespace std;

void task() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int r = n; r >= 1; r--) {
        if (sum % r == 0) {
            int avg = sum / r;
            int current = 0;
            bool works = true;
            for (int i = 0; i < n; i++) {
                current += a[i];
                if (current > avg) {
                    works = false;
                    break;
                } else if (current == avg) {
                    current = 0;
                }
            }
            if (works) {
                cout << n - r << endl;
                return;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        task();
    }
}
