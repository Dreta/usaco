// USACO 2015 December Contest, Silver
// Problem 3. Breed Counting

#include <iostream>
#include <vector>
using namespace std;


int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> prefixes(4, vector<int>(N + 1));
    prefixes[1][0] = 0;
    prefixes[2][0] = 0;
    prefixes[3][0] = 0;
    for (int i = 1; i <= N; i++) {
        int breed;
        cin >> breed;
        for (int j = 1; j <= 3; j++) {
            prefixes[j][i] = prefixes[j][i - 1];
        }
        prefixes[breed][i]++;
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << prefixes[1][r] - prefixes[1][l - 1] << " "
             << prefixes[2][r] - prefixes[2][l - 1] << " "
             << prefixes[3][r] - prefixes[3][l - 1] << endl;
    }
}
