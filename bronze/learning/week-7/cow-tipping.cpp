// USACO 2017 January Contest, Bronze
// Problem 3. Cow Tipping

#include <iostream>
using namespace std;

int N;
char grid[10][10]; // row, column

void tip(int row, int column) {
    for (int r = 0; r <= row; r++) {
        for (int c = 0; c <= column; c++) {
            if (grid[r][c] == '1') {
                grid[r][c] = '0';
            } else {
                grid[r][c] = '1';
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            grid[i][j] = s[j];
        }
    }

    int result = 0;
    for (int row = N - 1; row >= 0; row--) {
        for (int column = N - 1; column >= 0; column--) {
            if (grid[row][column] == '1') {
                tip(row, column);
                result++;
            }
        }
    }
    cout << result << endl;
}
