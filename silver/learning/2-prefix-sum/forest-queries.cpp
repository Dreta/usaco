#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_SIDE = 1000;
vector<vector<int>> forest(MAX_SIDE + 1, vector<int>(MAX_SIDE + 1));
vector<vector<int>> prefix(MAX_SIDE + 1, vector<int>(MAX_SIDE + 1));

int main() {
	int N;
	int Q;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char a;
			cin >> a;
			forest[i + 1][j + 1] += a == '*';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			prefix[i][j] = forest[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
		}
	}

	for (int q = 0; q < Q; q++) {
		int from_row, to_row, from_col, to_col;
		cin >> from_row >> from_col >> to_row >> to_col;
		cout << prefix[to_row][to_col] - prefix[from_row - 1][to_col] - prefix[to_row][from_col - 1] + prefix[from_row - 1][from_col - 1] << endl;
	}
}