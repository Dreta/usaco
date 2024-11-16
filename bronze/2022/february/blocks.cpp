// USACO 2022 February Contest, Bronze
// Problem 3. Blocks

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<char>> blocks(4, vector<char>(6));
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 6; j++) {
            blocks[i][j] = s[j];
        }
    }

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        if (word.size() == 1) {
            for (vector<char> block : blocks) {
                for (char c : block) {
                    if (c == word[0]) {
                        cout << "YES" << endl;
                        goto end;
                    }
                }
            }
            cout << "NO" << endl;
        } else if (word.size() == 2) {
            for (int a = 0; a < 4; a++) {
                for (int b = 0; b < 4; b++) {
                    if (a == b) {
                        continue;
                    }
                    for (int c = 0; c < 6; c++) {
                        for (int d = 0; d < 6; d++) {
                            if (blocks[a][c] == word[0] && blocks[b][d] == word[1]) {
                                cout << "YES" << endl;
                                goto end;
                            }
                        }
                    }
                }
            }
            cout << "NO" << endl;
        } else if (word.size() == 3) {
            for (int a = 0; a < 4; a++) {
                for (int b = 0; b < 4; b++) {
                    for (int c = 0; c < 4; c++) {
                        if (a == b || b == c || a == c) {
                            continue;
                        }
                        for (int d = 0; d < 6; d++) {
                            for (int e = 0; e < 6; e++) {
                                for (int f = 0; f < 6; f++) {
                                    if (blocks[a][d] == word[0] && blocks[b][e] == word[1] && blocks[c][f] == word[2]) {
                                        cout << "YES" << endl;
                                        goto end;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << "NO" << endl;
        } else if (word.size() == 4) {
            for (int a = 0; a < 4; a++) {
                for (int b = 0; b < 4; b++) {
                    for (int c = 0; c < 4; c++) {
                        for (int d = 0; d < 4; d++) {
                            if (a == b || b == c || c == d || a == c || a == d || b == d) {
                                continue;
                            }
                            for (int e = 0; e < 6; e++) {
                                for (int f = 0; f < 6; f++) {
                                    for (int g = 0; g < 6; g++) {
                                        for (int h = 0; h < 6; h++) {
                                            if (blocks[a][e] == word[0] && blocks[b][f] == word[1] && blocks[c][g] == word[2] && blocks[d][h] == word[3]) {
                                                cout << "YES" << endl;
                                                goto end;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << "NO" << endl;
        } else {
            cout << "NO" << endl;
        }
        end: continue;
    }
}
