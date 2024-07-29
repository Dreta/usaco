// USACO 2018 January Contest, Bronze
// Problem 3. Out of Place

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    vector<int> sorted(heights);
    sort(sorted.begin(), sorted.end());
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (heights[i] != sorted[i]) {
            result++;
        }
    }
    cout << result - 1 << endl;
}
