// USACO 2024 December Contest, Bronze
// Problem 1. Roundabout Rounding
// Live

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

long long findDigits(long long x) {
    long long p = 0;
    while (x > 0) {
        x /= 10;
        p++;
    }
    return p;
}

void task() {
    long long n;
    cin >> n;
    long long digits = findDigits(n);
    if (digits == 1) {
        cout << 0 << endl;
        return;
    }
    long long result = 0;
    for (long long i = 1; i < digits; i++) {
        long long number = 0;
        for (long long j = 0; j < i; j++) {
            number = number * 10 + 5;
        }

        if (i == digits - 1) {
            long long number2 = 5;
            for (long long j = 1; j < digits; j++) {
                number2 += 4 * pow(10, j);
            }

            if (n < number2) {
                continue;
            }
            long long number3 = 4 * pow(10, digits - 1);
            for (long long j = digits - 2; j >= 0; j--) {
                number3 += 9 * pow(10, j);
            }
            result += (min(n, number3) - number2 + 1);
        } else {
            result += number;
        }
    }
    cout << result << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        task();
    }
}
