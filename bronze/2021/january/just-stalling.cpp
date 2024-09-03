// USACO 2021 January Contest, Bronze
// Problem 3. Just Stalling

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> cows(N);
    vector<long long> heights(N);
    for (long long i = 0; i < N; i++) {
        cin >> cows[i];
    }
    for (long long i = 0; i < N; i++) {
        cin >> heights[i];
    }

    long long result = 1;
    long long minus = 0;
    sort(cows.begin(), cows.end());
    for (long long i = N - 1; i >= 0; i--) {
        long long available = -minus;
        for (long long j = 0; j < N; j++) {
            if (cows[i] <= heights[j]) {
                available++;
            }
        }
        minus++;
        result *= available;
    }
    cout << result << endl;
}
