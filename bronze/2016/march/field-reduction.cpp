// USACO 2016 US Open Contest, Bronze
// Problem 3. Field Reduction

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double distance(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);

    int N;
    cin >> N;

    vector<pair<int, int>> cows(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    int minX = 40001, maxX = 0, minY = 40001, maxY = 0;
    for (pair<int, int> cow : cows) {
        minX = min(minX, cow.first);
        maxX = max(maxX, cow.first);
        minY = min(minY, cow.second);
        maxY = max(maxY, cow.second);
    }

    // Observation: Only removing a cow on the perimeter of the fence will reduce the area.
    int minArea = 40000 * 40000;
    for (pair<int, int> cow : cows) {
        if (cow.first == minX || cow.first == maxX || cow.second == minY || cow.second == maxY) {
            // Try calculate the resulting area
            int minX2 = 40001, maxX2 = 0, minY2 = 40001, maxY2 = 0;
            for (pair<int, int> cow2 : cows) {
                if (cow2 == cow) {
                    continue;
                }
                minX2 = min(minX2, cow2.first);
                maxX2 = max(maxX2, cow2.first);
                minY2 = min(minY2, cow2.second);
                maxY2 = max(maxY2, cow2.second);
            }
            minArea = min(minArea, (maxX2 - minX2) * (maxY2 - minY2));
        }
    }
    cout << minArea << endl;
}
