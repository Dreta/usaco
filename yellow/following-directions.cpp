// USACO 2023 January Contest, Silver
// Problem 2. Following Directions

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    bool vat;
    bool right;
    int cost;
};

int N;
vector<vector<Point>> grid;
vector<vector<int>> passThroughs;

void output() {
    int result = 0;
    for (int i = 1; i <= N; i++) {
        result += passThroughs[i][N + 1] * grid[i][N + 1].cost;
    }
    for (int i = 1; i <= N; i++) {
        result += passThroughs[N + 1][i] * grid[N + 1][i].cost;
    }
    cout << result << endl;
}

int main() {
    cin >> N;

    grid.resize(N + 2, vector<Point>(N + 2));
    passThroughs.resize(N + 2, vector<int>(N + 2));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char c;
            cin >> c;
            if (c == 'R') {
                grid[i][j].right = true;
            } else if (c == 'D') {
                grid[i][j].right = false;
            }
            passThroughs[i][j] = 1;
        }
        int cost;
        cin >> cost;
        grid[i][N + 1].cost = cost;
        grid[i][N + 1].vat = true;
        passThroughs[i][N + 1] = 0;
    }
    {
        for (int i = 1; i <= N; i++) {
            int cost;
            cin >> cost;
            grid[N + 1][i].cost = cost;
            grid[N + 1][i].vat = true;
            passThroughs[N + 1][i] = 0;
        }
    }

    // MARK: - Solution
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j].right) {
                passThroughs[i][j + 1] += passThroughs[i][j];
            } else {
                passThroughs[i + 1][j] += passThroughs[i][j];
            }
        }
    }

    output();
    
    int Q;
    cin >> Q;
    while (Q--) {
        int y, x;
        cin >> y >> x;
        int delta = passThroughs[y][x];

        int curY = y, curX = x;
        bool oldRight = grid[y][x].right;
        while (!(curY == N + 1 || curX == N + 1)) {
            if (oldRight) {
                curX++; 
            } else {
                curY++; 
            }
            passThroughs[curY][curX] -= delta;
            if (curY == N + 1 || curX == N + 1) break;
            oldRight = grid[curY][curX].right;
        }
        grid[y][x].right = !grid[y][x].right;

        curY = y, curX = x;
        bool newRight = grid[y][x].right;
        while (!(curY == N + 1 || curX == N + 1)) {
            if (newRight) {
                curX++; 
            } else {
                curY++; 
            }
            passThroughs[curY][curX] += delta;
            if (curY == N + 1 || curX == N + 1) break;
            newRight = grid[curY][curX].right;
        }

        output();
    }
}
