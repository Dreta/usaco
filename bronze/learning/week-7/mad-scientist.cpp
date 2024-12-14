// USACO 2020 February Contest, Bronze
// Problem 2. Mad Scientist

#include <iostream>
using namespace std;

string substringFlip(string s, int start, int length) {
    string substr = s.substr(start, length);
    for (int i = 0; i < length; i++) {
        if (substr[i] == 'H') {
            substr[i] = 'G';
        } else {
            substr[i] = 'H';
        }
    }
    return substr;
}

int main() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    // The idea: Start from the beginning and count the maximum length of the substring
    // that can be flipped to make B equal to A. Continue.
    int i = 0;
    int length = 1;
    int result = 0;
    while (i < n) {
        if (b[i] == a[i]) {
            i++;
            length = 1;
            continue;
        }

        if (substringFlip(b, i, length) == a.substr(i, length)) {
            length++;
            if (i + length >= n) {
                result++; // Reached end of string
                break;
            }
        } else {
            result++;
            i += length - 1;
            length = 1;
        }
    }
    cout << result << endl;
}
