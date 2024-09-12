// USACO 2021 US Open, Bronze
// Problem 2. Acowdemia II

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> k >> n;

    vector<vector<char>> result(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                result[i][j] = 'B';
            } else {
                result[i][j] = '?';
            }
        }
    }

    map<string, int> cowToIndex;
    vector<string> indexToCow(n);
    for (int i = 0; i < n; i++) {
        string cow;
        cin >> cow;
        cowToIndex[cow] = i;
        indexToCow[i] = cow;
    }

    vector<vector<int>> pubs(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            string cow;
            cin >> cow;
            pubs[i][j] = cowToIndex[cow];
        }
    }

    // Observations:
    // * We observe that for two neighboring cows, if they are not in alphabetical order, the second cow must be more senior.
    // * If they are in alphabetical order, we are unsure.
    // * Seniority is transitive.

    for (vector<int> pub : pubs) {
        for (int i = 0; i < n - 1; i++) {
            if (indexToCow[pub[i]] > indexToCow[pub[i + 1]]) {
                // Every cow before (incl.) pub[i] is more junior than every cow after (incl.) pub[i + 1].
                for (int j = 0; j <= i; j++) {
                    for (int k = i + 1; k < n; k++) {
                        result[pub[k]][pub[j]] = '1';
                        result[pub[j]][pub[k]] = '0';
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
}
