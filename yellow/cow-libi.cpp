// USACO 2023 February Contest, Silver
// Problem 2. Cow-libi

#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Point {
    long long x;
    long long y;
    long long t;

    bool operator<(const Point &other) const {
        return t < other.t;
    }

    bool reachableFrom(const Point &other) const {
        return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) <= (t - other.t) * (t - other.t);
    }
};

int main() {
    long long G, N;
    cin >> G >> N;
    set<Point> gardens;
    for (long long i = 0; i < G; i++) {
        long long x, y, t;
        cin >> x >> y >> t;
        gardens.insert({x, y, t});
    }

    long long result = 0;
    while (N--) {
        long long x, y, t;
        cin >> x >> y >> t;
        
        auto it = gardens.lower_bound({0, 0, t});
        bool innocent = false;
        if (it != gardens.end()) {
            // 'it' is the first garden with time >= t
            if (!it->reachableFrom({x, y, t})) {
                innocent = true;
            }
        }
        if (it != gardens.begin()) {
            auto itBefore = prev(it);
            if (!itBefore->reachableFrom({x, y, t})) {
                innocent = true;
            }
        }

        if (innocent) {
            result++;
        }
    }
    cout << result << endl;
}
