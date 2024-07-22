// USACO 2017 US Open Contest, Bronze
// Problem 3. Modern Art

#include <iostream>
#include <set>
using namespace std;

int N;
int canvas[11][11];
pair<pair<int, int>, pair<int, int>> regions[10]; // the top left and bottom right of the regions of each color
set<int> colors;

bool aCoversB(int a, int b) {
    for (int i = regions[b].first.first; i <= regions[b].second.first; i++) {
        for (int j = regions[b].first.second; j <= regions[b].second.second; j++) {
            if (canvas[i][j] == a) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 10; i++) {
        regions[i].first.first = 11;
        regions[i].first.second = 11;
        regions[i].second.first = -1;
        regions[i].second.second = -1;
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            canvas[i][j] = s[j] - '0';

            if (canvas[i][j] == 0) {
                continue;
            }
            colors.insert(canvas[i][j]);

            int thisColor = canvas[i][j];
            regions[thisColor].first.first = min(regions[thisColor].first.first, i);
            regions[thisColor].first.second = min(regions[thisColor].first.second, j);
            regions[thisColor].second.first = max(regions[thisColor].second.first, i);
            regions[thisColor].second.second = max(regions[thisColor].second.second, j);
        }
    }

    int result = 0;
    for (int color = 1; color < 10; color++) {
        if (colors.find(color) == colors.end()) {
            continue;
        }
        bool thisColorBad = false;
        for (int j = 1; j < 10; j++) {
            if (aCoversB(color, j) && color != j) {
                thisColorBad = true;
                break;
            }
        }
        if (!thisColorBad) {
            result++;
        }
    }
    cout << result << endl;
}
