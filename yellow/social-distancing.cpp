// USACO 2020 US Open Contest, Silver
// Problem 1. Social Distancing

#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> intervals;

bool isInInterval(long long coord) {
    auto it = intervals.upper_bound(coord);
    if (it == intervals.begin()) return false; 
    it--;
    return coord <= it->second;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    long long N, M;
    cin >> N >> M;

    long long minVal = 1e18;
    long long maxVal = 0;
    for (long long i = 0; i < M; i++) {
        long long a, b;
        cin >> a >> b;
        intervals[a] = b;
        minVal = min(minVal, a);
        maxVal = max(maxVal, b);
    }
    long long range = maxVal - minVal;

    long long hi = range, lo = 0;
    while (hi > lo) {
        long long mid = (hi + lo + 1) / 2;
        bool canAchieve = true;

        // Test 1: At least N cows can be placed at this interval
        long long left = minVal, right = maxVal;
        long long remaining = N - 2;
        while (remaining > 0) {
            left += mid;

            remaining--;
            if (remaining > 0) {
                right -= mid;
                remaining--;
            }

            bool a = isInInterval(left);
            bool b = isInInterval(right);
            if (!a || !b) {
                while (!a || !b) {
                    if (!a) {
                        // Jump left: find the next interval that starts at or after left.
                        auto it = intervals.lower_bound(left);
                        if (it == intervals.end()) {  // No interval exists after left.
                            canAchieve = false;
                            goto end;
                        }
                        left = it->first; // Jump directly to the start of this interval.
                    }
                    if (!b) {
                        // Jump right: find the interval that might contain right.
                        auto it = intervals.upper_bound(right);
                        if (it == intervals.begin()) {  // No interval exists before right.
                            canAchieve = false;
                            goto end;
                        }
                        it--;
                        right = it->second; // Jump directly to the end of this interval.
                    }
                    // Check if we still have room.
                    if (right - left < mid) {
                        canAchieve = false;
                        goto end;
                    }
                    a = isInInterval(left);
                    b = isInInterval(right);
                }
            }
            
            if (right - left < mid) {
                canAchieve = false;
                break;
            }
        }
        end:;

        if (canAchieve) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << hi << endl;
}
