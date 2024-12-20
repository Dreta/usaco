#include <vector>
using namespace std;

const int MAX_N = 1000;

vector<vector<int>> grid(MAX_N, vector<int>(MAX_N));
int rows;
int cols;
vector<vector<bool>> visited(MAX_N, vector<bool>(MAX_N));  // keeps track of which nodes have been visited
int currSize = 0;           // reset to 0 each time we start a new component

void floodfill(int r, int c, int color) {
	if ((r < 0 || r >= rows || c < 0 || c >= cols)  // if out of bounds
	    || grid[r][c] != color                            // wrong color
	    || visited[r][c]                                  // already visited this square
	)
		return;

	visited[r][c] = true;  // mark current square as visited
	currSize++;           // increment the size for each square we visit

	// recursively call flood fill for neighboring squares
	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}

int main() {
	/*
	 * input code and other problem-specific stuff here
	 */
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