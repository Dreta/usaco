// USACO 2017 January Contest, Silver
// Problem 2. Hoof, Paper, Scissors

#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int N;
    cin >> N;
    // H, P, S
    vector<char> values(N + 1);
    vector<vector<int>> prefixSums(500, vector<int>(N + 1));
    prefixSums['H'][0] = 0;
    prefixSums['P'][0] = 0;
    prefixSums['S'][0] = 0;

    for (int i = 1; i <= N; i++) {
        char c;
        cin >> c;
        prefixSums['H'][i] = prefixSums['H'][i - 1];
        prefixSums['P'][i] = prefixSums['P'][i - 1];
        prefixSums['S'][i] = prefixSums['S'][i - 1];
        if (c == 'H') {
            values[i] = 'P';
            prefixSums['P'][i]++;
        } else if (c == 'P') {
            values[i] = 'S';
            prefixSums['S'][i]++;
        } else {
            values[i] = 'H';
            prefixSums['H'][i]++;
        }
    }

    int maxWins = 0;
    for (int switchAt = 1; switchAt <= N; switchAt++) {
        int a = prefixSums['H'][N] - prefixSums['H'][switchAt - 1];
        int b = prefixSums['P'][N] - prefixSums['P'][switchAt - 1];
        int c = prefixSums['S'][N] - prefixSums['S'][switchAt - 1];

        int d = prefixSums['H'][switchAt - 1];
        int e = prefixSums['P'][switchAt - 1];
        int f = prefixSums['S'][switchAt - 1];
        int thisWins = max(d, max(e, f)) + max(a, max(b, c));
        maxWins = max(maxWins, thisWins);
    }
    cout << maxWins << endl;
}
