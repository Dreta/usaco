#include <vector>
using namespace std;

const int MAX_N = 1000;

vector<vector<int>> grid(MAX_N, vector<int>(MAX_N));
int rows;
int cols;
vector<vector<bool>> visited(MAX_N, vector<bool>(MAX_N));
int currSize = 0;

void floodfill(int r, int c, int color) {
	if ((r < 0 || r >= rows || c < 0 || c >= cols) || grid[r][c] != color || visited[r][c])
		return;

	visited[r][c] = true;
	currSize++;

	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}

int main() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (!visited[i][j]) {
				currSize = 0;
				/*
				 * start a flood fill if the square hasn't already been visited,
				 * and then store or otherwise use the component size
				 * for whatever it's needed for
				 */
				floodfill(i, j, grid[i][j]);
			}
		}
	}
}