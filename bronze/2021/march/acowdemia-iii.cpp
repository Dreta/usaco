// USACO 2021 US Open, Bronze
// Problem 3. Acowdemia III

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> points(N + 2, vector<char>(M + 2));

    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            points[i][j] = s[j - 1];
        }
    }

    // Observations:
    // * Let's simply go over each grass block, and find adjacent cows to pair up.

    set<vector<pair<int, int>>> usedPairs;
    int result = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (points[i][j] == 'G') {
                vector<pair<int, int>> available;
                int dx[]{1, 0, -1, 0};
                int dy[]{0, 1, 0, -1};
                for (int d = 0; d < 4; d++) {
                    if (points[i + dx[d]][j + dy[d]] == 'C') {
                        available.push_back({i + dx[d], j + dy[d]});
                    }
                }
                if (available.size() == 2) {
                    sort(available.begin(), available.end());
                    usedPairs.insert(available);
                } else if (available.size() > 2) {
                    result++;
                }
            }
        }
    }
    cout << result + usedPairs.size() << endl;
}
