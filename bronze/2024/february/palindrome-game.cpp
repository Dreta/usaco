// USACO 2024 February Contest, Bronze
// Problem 1. Palindrome Game

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s[s.length() - 1] == '0') {
            cout << "E" << endl;
        } else {
            cout << "B" << endl;
        }
    }
}
