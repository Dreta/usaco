// USACO 2021 US Open, Silver
// Problem 1. Maze Tac Toe

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<vector<char>> Board;

int hashBoard(const Board& board) {
    int hash = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hash = hash * 3 + (board[i][j] == 'O' ? 1 : (board[i][j] == 'M' ? 2 : 0));
        }
    }
    return hash;
}

bool wins(const Board& board) {
    for (int i = 0; i < 3; i++) {
        string s;
        for (int j = 0; j < 3; j++) {
            s.push_back(board[i][j]);
        }
        if (s == "MOO" || s == "OOM") {
            return true;
        }
    }
    
    for (int j = 0; j < 3; j++) {
        string s;
        for (int i = 0; i < 3; i++) {
            s.push_back(board[i][j]);
        }
        if (s == "MOO" || s == "OOM") {
            return true;
        }
    }
    string diag1;
    for (int i = 0; i < 3; i++) {
        diag1.push_back(board[i][i]);
    }
    if (diag1 == "MOO" || diag1 == "OOM") {
        return true;
    }
    string diag2;
    for (int i = 0; i < 3; i++) {
        diag2.push_back(board[i][2 - i]);
    }
    if (diag2 == "MOO" || diag2 == "OOM") {
        return true;
    }
    
    return false;
}

struct State {
    Board board;
    int row; // 0-indexed
    int col; // 0-indexed
};

struct Block {
    char type; // #, O, M, .
    int row; // 0-indexed
    int col; // 0-indexed
};

vector<vector<Block>> world;
vector<vector<vector<bool>>> visited; // row, col, board hash

set<Board> winningStates;

void search(int row, int col, State state) {
    if (row < 0 || row >= world.size() || col < 0 || col >= world.size() || visited[row][col][hashBoard(state.board)]) {
        return;
    }
    visited[row][col][hashBoard(state.board)] = true;

    if (world[row][col].type == 'O' && state.board[world[row][col].row][world[row][col].col] == '.') {
        state.board[world[row][col].row][world[row][col].col] = 'O';
    } else if (world[row][col].type == 'M' && state.board[world[row][col].row][world[row][col].col] == '.') {
        state.board[world[row][col].row][world[row][col].col] = 'M';
    }

    if (wins(state.board)) {
        winningStates.insert(state.board);
        return; // No need to continue searching.
    }

    if (!visited[row + 1][col][hashBoard(state.board)] && world[row + 1][col].type != '#') {
        search(row + 1, col, state);
    }
    if (!visited[row - 1][col][hashBoard(state.board)] && world[row - 1][col].type != '#') {
        search(row - 1, col, state);
    }
    if (!visited[row][col + 1][hashBoard(state.board)] && world[row][col + 1].type != '#') {
        search(row, col + 1, state);
    }
    if (!visited[row][col - 1][hashBoard(state.board)] && world[row][col - 1].type != '#') {
        search(row, col - 1, state);
    }
}

int main() {
    int N;
    cin >> N;

    world.resize(N, vector<Block>(N));
    visited.resize(N, vector<vector<bool>>(N, vector<bool>(20000, false)));

    State initState;

    initState.board = vector<vector<char>>(3, vector<char>(3, '.'));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char a, b, c;
            cin >> a >> b >> c;
            if (a == 'B') {
                world[i][j] = {'.', -1, -1};
                initState.row = i;
                initState.col = j;
            } else {
                world[i][j] = {a, b - '1', c - '1'};
            }
        }
    }

    search(initState.row, initState.col, initState);
    cout << winningStates.size() << endl;
}
