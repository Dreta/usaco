// USACO 2023 January Contest, Bronze
// Problem 3. Moo Operations

#include <iostream>
#include <vector>
using namespace std;

void task() {
    string s;
    cin >> s;
    
    int n = s.length();
    if (n < 3) {
        cout << -1 << endl;
        return;
    }

    int ops = 0;
    int bestError = 4;
    int bestIndex = -1;
    for (int i = n - 1; i >= 2; i--) {
        int thisError = 0;
        if (s[i] != 'O') thisError++;
        if (s[i - 1] != 'O') {
            continue; // This error cannot be remedied because it's in the middle.
        }
        if (s[i - 2] != 'M') thisError++;
        if (thisError < bestError) {
            bestError = thisError;
            bestIndex = i;
        }
    }

    if (bestIndex == -1) {
        cout << -1 << endl;
    } else {
        // Amount of deletions required after + amount of deletions required before + amount of errors to correct
        cout << (n - bestIndex - 1) + (bestIndex - 2) + bestError << endl;
    }
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        task();
    }
}
