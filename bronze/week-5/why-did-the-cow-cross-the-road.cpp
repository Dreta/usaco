#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    set<int> timeConsumed;
    vector<pair<int, int>> cows(N);
    for (int i = 0; i < N; i++) {
        int start, consumption;
        cin >> start >> consumption;
        cows[i] = make_pair(start, consumption);
    }

    sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });

    int result = 0;
    for (int i = 0; i < N; i++) {
        result = max(result, cows[i].first) + cows[i].second;
    }

    cout << result << endl;
}
