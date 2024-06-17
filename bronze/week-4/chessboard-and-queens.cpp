#include <iostream>
#include <map>
using namespace std;

int rows[8]; // Mark if there are queens on a specific row
int columns[8]; // Mark if there are queens on a specific column
map<int, int> mainDiagonal; // Mark if there are queens on a specific main diagonal, identified by the x-position of its top-left point
map<int, int> crossDiagonal; // Mark if there are queens on a specific cross diagonal, identified by the x-position of its top-right point
int grid[8][8]; // Mark if certain locations are blocked

int validPlacements(int row) {
    int result = 0;
    // if (rows[row] == 1) {
    //     return 0; // There are no possible valid placements on this row, because there is already a queen here.
    // }
    for (int x = 0; x < 8; x++) {
        if (grid[row][x] == 1) {
            continue; // Blocked, continue
        }
        if (columns[x] == 1) {
            continue; // Already a queen on another column on this row
        }
        if (mainDiagonal[x - row] == 1) {
            continue; // Already a queen on the main diagonal
        }
        if (crossDiagonal[x + row] == 1) {
            continue; // Already a queen on this cross diagonal
        }
        columns[x] = 1; // Mark this point as occupied,
        mainDiagonal[x - row] = 1; // so that we can iterate conditions based on this
        crossDiagonal[x + row] = 1;
        if (row == 7) {
            result++;
        } else {
            result += validPlacements(row + 1);
        }
        columns[x] = 0; // Reset this point,
        mainDiagonal[x - row] = 0; // so that we go on to other situations
        crossDiagonal[x + row] = 0;
    }
    return result;
}

int main(void) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            char c;
            cin >> c;
            if (c == '.') {
                grid[y][x] = 0;
            } else if (c == '*') {
                grid[y][x] = 1;
            }
        }
    }

    cout << validPlacements(0) << endl;
}
