// USACO 2024 December Contest, Bronze
// Problem 2. Farmer John's Cheese Block
// Live

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int> > xLines(N, vector<int>(N, N));
    vector<vector<int> > yLines(N, vector<int>(N, N));
    vector<vector<int> > zLines(N, vector<int>(N, N));

    int emptyLines = 0;

    for (int i = 0; i < Q; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (xLines[y][z] != -1) {
            xLines[y][z] = max(xLines[y][z] - 1, 0);
        }
        if (yLines[x][z] != -1) {
            yLines[x][z] = max(yLines[x][z] - 1, 0);
        }
        if (zLines[x][y] != -1) {
            zLines[x][y] = max(zLines[x][y] - 1, 0);
        }
        if (xLines[y][z] == 0) {
            emptyLines++;
            xLines[y][z] = -1;
        }
        if (yLines[x][z] == 0) {
            emptyLines++;
            yLines[x][z] = -1;
        }
        if (zLines[x][y] == 0) {
            emptyLines++;
            zLines[x][y] = -1;
        }
        cout << emptyLines << endl;
    }

    return 0;
}
