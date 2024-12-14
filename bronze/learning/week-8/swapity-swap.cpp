// USACO 2020 February Contest, Bronze
// Problem 3. Swapity Swap

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> swap(vector<int> &cows, int a1, int a2, int b1, int b2) {
    while (a1 < a2) {
        int temp = cows[a1];
        cows[a1] = cows[a2];
        cows[a2] = temp;
        a1++;
        a2--;
    }

    while (b1 < b2) {
        int temp = cows[b1];
        cows[b1] = cows[b2];
        cows[b2] = temp;
        b1++;
        b2--;
    }
    return cows;
}

int main() {
    int n, k, a1, a2, b1, b2;
    cin >> n >> k >> a1 >> a2 >> b1 >> b2;

    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cows[i] = i + 1;
    }

    set<vector<int>> visited;
    visited.insert(cows);
    while (true) { 
        swap(cows, a1 - 1, a2 - 1, b1 - 1, b2 - 1);
        if (visited.count(cows)) {
            break;
        }
        visited.insert(cows);
    }

    int remaining = k % visited.size();
    for (int i = 0; i < remaining; i++) {
        swap(cows, a1 - 1, a2 - 1, b1 - 1, b2 - 1);
    }

    for (int i = 0; i < n; i++) {
        cout << cows[i] << endl;
    }
}
