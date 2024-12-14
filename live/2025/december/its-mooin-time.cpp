// USACO 2024 December Contest, Bronze
// Problem 3. It's Mooin' Time
// Live

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                          'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                          'u', 'v', 'w', 'x', 'y', 'z'};

set<string> possible;
map<char, map<char, int>> frequencies;

void insertIfCorrect(string s) {
    if (s != "" && s[0] != s[1] && s[1] == s[2]) {
        possible.insert(s);
    }
}

bool isValid(string s) {
    return s[0] != s[1] && s[1] == s[2];
}

void modify(string s, int m) {
    frequencies[s[0]][s[1]] += m;
}

void modifyIfValid(string s, int m) {
    if (isValid(s)) {
        modify(s, m);
    }
}

int main() {
    int N, F;
    cin >> N >> F;
    string s;
    cin >> s;
    for (int i = 0; i < N - 2; i++) {
        modifyIfValid(s.substr(i, 3), 1);
    }

    for (auto a : frequencies) {
        for (auto b : a.second) {
            if (b.second >= F) {
                insertIfCorrect(string(1, a.first) + b.first + b.first);
            }   
        }
    }

    // Try with corruptions
    for (int i = 0; i < N; i++) {
        vector<int> thisModifications;
        if (i >= 2) {
            thisModifications.push_back(i - 2);
        }
        if (i >= 1 && i < N - 1) {
            thisModifications.push_back(i - 1);
        }
        if (i < N - 2) {
            thisModifications.push_back(i);
        }

        for (char c : alphabet) {
            if (c == s[i]) continue;
            vector<string> deleted;
            vector<string> created;

            for (int j : thisModifications) {
                string old = s.substr(j, 3);
                if (isValid(old)) {
                    modify(old, -1);
                    deleted.push_back(old);
                }
            }

            for (int j : thisModifications) {
                string newStr = s.substr(j, 3);
                newStr[i - j] = c;
                if (isValid(newStr)) {
                    modify(newStr, 1);
                    created.push_back(newStr);
                }
            }

            for (string newS : created) {
                if (frequencies[newS[0]][newS[1]] >= F) {
                    insertIfCorrect(newS);
                }
            }

            // Revert
            for (string d : deleted) {
                modify(d, 1);
            }
            for (string c : created) {
                modify(c, -1);
            }
        }
    }

    cout << possible.size() << endl;
    for (string s : possible) {
        cout << s << endl;
    }
}
