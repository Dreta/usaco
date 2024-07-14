#include <iostream>
#include <set>
using namespace std;

int board[3][3];

char individualWins(char a, char b, char c) {
    if (a == b && b == c) {
        return a;
    }
    return ' ';
}

string teamWins(char a, char b, char c) {
    set<char> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    if (s.size() == 2) {
        string result;
        auto it = s.begin();
        result += *it;
        ++it;
        result += *it;
        return result;
    }
    return "";
}


int main(void) {
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 3; j++) {
            board[i][j] = s[j]; // row, column
        }
    }

    // Check valid individual wins first
    set<char> indiv;
    for (int i = 0; i < 3; i++) {
        char winner = individualWins(board[i][0], board[i][1], board[i][2]);
        if (winner != ' ') {
            indiv.insert(winner);
        }
        winner = individualWins(board[0][i], board[1][i], board[2][i]);
        if (winner != ' ') {
            indiv.insert(winner);
        }
    }
    char winner = individualWins(board[0][0], board[1][1], board[2][2]);
    if (winner != ' ') {
        indiv.insert(winner);
    }
    winner = individualWins(board[0][2], board[1][1], board[2][0]);
    if (winner != ' ') {
        indiv.insert(winner);
    }
    cout << indiv.size() << endl;

    // Check valid team wins
    set<string> team;
    for (int i = 0; i < 3; i++) {
        string winner = teamWins(board[i][0], board[i][1], board[i][2]);
        if (winner != "") {
            team.insert(winner);
        }
        winner = teamWins(board[0][i], board[1][i], board[2][i]);
        if (winner != "") {
            team.insert(winner);
        }
    }
    string winner2 = teamWins(board[0][0], board[1][1], board[2][2]);
    if (winner2 != "") {
        team.insert(winner2);
    }
    winner2 = teamWins(board[0][2], board[1][1], board[2][0]);
    if (winner2 != "") {
        team.insert(winner2);
    }
    cout << team.size() << endl;
}
