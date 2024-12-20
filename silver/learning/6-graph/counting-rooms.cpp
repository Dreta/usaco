// CSES Problem Set
// Counting Rooms

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int currSize;
int result = 0;

void floodfill(int r, int c, int color) {
	if ((r < 0 || r >= n || c < 0 || c >= m) || grid[r][c] != color || visited[r][c])
		return;

	visited[r][c] = true;
	currSize++;

	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				currSize = 0;
                if (grid[i][j] == 0) {
                    result++;
                }
				floodfill(i, j, grid[i][j]);
			}
		}
	}
    cout << result << endl;
}
