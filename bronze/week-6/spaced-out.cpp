// USACO 2021 January Contest, Silver
// Problem 3. Spaced Out

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    // Observation: Possible arrangements of cows have either:
    // * All rows are alternating between cows and no cows
    // * All columns are alternating between cows and no cows

    // Rows case
    int rowsResult = 0;
    for (int i = 0; i < N; i++) {
        // Two cases: Cows on odd columns or on even columns. Pick the best.
        int odd = 0;
        int even = 0;
        for (int j = 0; j < N; j++) {
            if (j % 2 == 0) {
                odd += a[i][j];
            } else {
                even += a[i][j];
            }
        }
        rowsResult += max(odd, even);
    }

    // Columns case
    int colsResult = 0;
    for (int j = 0; j < N; j++) {
        // Two cases: Cows on odd rows or on even rows. Pick the best.
        int odd = 0;
        int even = 0;
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                odd += a[i][j];
            } else {
                even += a[i][j];
            }
        }
        colsResult += max(odd, even);
    }

    cout << max(rowsResult, colsResult) << endl;
}
