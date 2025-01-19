// USACO 2024 January Contest, Silver
// Problem 3. Cowlendar

#include <cmath>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<long long> divisors(long long n) {
    vector<long long> div;
    n = abs(n);
    for (long long i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n / i) {
                div.push_back(n / i);
            }
        }
    }
    
    return div;
}

int main() {
    long long N;
    cin >> N;
    set<long long> a;
    for (long long i = 0; i < N; i++) {
        long long value;
        cin >> value;
        a.insert(value);
    }

    long long maxResult = *a.begin() / 4;
    if (a.size() <= 3) {
        long long result = 0;
        for (long long i = 1; i <= maxResult; i++) {
            result += i;
        }
        cout << result << endl;
        return 0;
    }

    vector<long long> v;
    for (auto it = a.begin(); it != a.end() && v.size() < 4; it++) {
        v.push_back(*it);
    }
    vector<long long> diffs = {v[1] - v[0], v[2] - v[0], v[3] - v[0], v[2] - v[1], v[3] - v[1], v[3] - v[2]};
    set<long long> possibilities;
    for (long long diff : diffs) {
        for (long long f : divisors(diff)) {
            if (f <= maxResult) {
                possibilities.insert(f);
            }
        }
    }

    long long result = 0;
    for (long long r : possibilities) {
        set<long long> modValues;
        bool passed = true;
        for (long long j : a) {
            modValues.insert(j % r);
            if (modValues.size() > 3) {
                passed = false;
                break;
            }
        }
        if (passed) {
            result += r;
        }
    }
    cout << result << endl;
}
