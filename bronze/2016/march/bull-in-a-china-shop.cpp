// USACO 2016 US Open Contest, Bronze
// Problem 2. Bull in a China Shop

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;

// Horizontal: Positive for right, negative for left
// Vertical: Positive for down, negative for up
vector<pair<int, int>> shift(vector<pair<int, int>> original, int horizontal, int vertical) {
    vector<pair<int, int>> coords;
    for (pair<int, int> coord : original) {
        coords.push_back({coord.first + vertical, coord.second + horizontal});
    }

    return coords;
}

bool combineAndCompare(vector<pair<int, int>> a, vector<pair<int, int>> b, vector<pair<int, int>> compareWith) {
    vector<pair<int, int>> combined;
    for (pair<int, int> coords : a) {
        combined.push_back(coords);
    }
    for (pair<int, int> coords : b) {
        combined.push_back(coords);
    }

    sort(combined.begin(), combined.end());
    sort(compareWith.begin(), compareWith.end());

    for (int i = 0; i < combined.size(); i++) {
        if (combined[i] != compareWith[i]) {
            return false;
        }
    }

    return true;
}

pair<int, int> horizontalShiftRange(vector<pair<int, int>> original) {
    int leftMostHash = 10;
    int rightMostHash = -1;

    for (pair<int, int> coords : original) {
        leftMostHash = min(leftMostHash, coords.second);
        rightMostHash = max(rightMostHash, coords.second);
    }

    return {-leftMostHash, n - 1 - rightMostHash};
}

pair<int, int> verticalShiftRange(vector<pair<int, int>> original) {
    int topMostHash = 10;
    int bottomMostHash = -1;

    for (pair<int, int> coords : original) {
        topMostHash = min(topMostHash, coords.first);
        bottomMostHash = max(bottomMostHash, coords.first);
    }

    return {-topMostHash, n - 1 - bottomMostHash};
}

int main() {
    int k;
    cin >> n >> k;

    vector<pair<int, int>> original;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '#') {
                original.push_back({i, j});
            }
        }
    }

    vector<vector<pair<int, int>>> pieces(k);
    vector<pair<int, int>> horizontalShifts(k);
    vector<pair<int, int>> verticalShifts(k);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            for (int l = 0; l < n; l++) {
                if (s[l] == '#') {
                    pieces[i].push_back({j, l});
                }
            }
        }
        horizontalShifts[i] = horizontalShiftRange(pieces[i]);
        verticalShifts[i] = verticalShiftRange(pieces[i]);
    }

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            vector<pair<int, int>> pieceA = pieces[i];
            vector<pair<int, int>> pieceB = pieces[j];

            // Shift pieceA and pieceB in all possible ways.
            for (int horizontalShiftA = horizontalShifts[i].first; horizontalShiftA <= horizontalShifts[i].second; horizontalShiftA++) {
                for (int verticalShiftA = verticalShifts[i].first; verticalShiftA <= verticalShifts[i].second; verticalShiftA++) {
                    for (int horizontalShiftB = horizontalShifts[j].first; horizontalShiftB <= horizontalShifts[j].second; horizontalShiftB++) {
                        for (int verticalShiftB = verticalShifts[j].first; verticalShiftB <= verticalShifts[j].second; verticalShiftB++) {
                            vector<pair<int, int>> shiftedA = shift(pieceA, horizontalShiftA, verticalShiftA);
                            vector<pair<int, int>> shiftedB = shift(pieceB, horizontalShiftB, verticalShiftB);

                            if (combineAndCompare(shiftedA, shiftedB, original)) {
                                cout << i + 1 << " " << j + 1 << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}
