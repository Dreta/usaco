// USACO 2022 January Contest, Bronze
// Problem 1. Herdle

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    vector<string> correct(3);
    map<char, int> correctMap;
    vector<string> guess(3);

    for (int i = 0; i < 3; i++) {
        cin >> correct[i];
        for (char c : correct[i]) {
            correctMap[c]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        cin >> guess[i];
    }

    int green = 0;
    int yellow = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (guess[i][j] == correct[i][j]) {
                green++;
                correctMap[guess[i][j]]--;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (guess[i][j] != correct[i][j] && correctMap[guess[i][j]] > 0) {
                yellow++;
                correctMap[guess[i][j]]--;
            }
        }
    }
    cout << green << endl << yellow << endl;
}
