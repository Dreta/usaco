// USACO 2022 US Open Contest, Bronze
// Problem 1. Photoshoot

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    string _;
    cin >> _;
    for (int i = 0; i < n; i++) {
        if (_[i] == 'G') {
            b[i] = 1;
        } else {
            b[i] = 0;
        }
    }
}
