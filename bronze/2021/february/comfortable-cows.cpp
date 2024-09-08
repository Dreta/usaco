// USACO 2021 February Contest, Bronze
// Problem 2. Comfortable Cows

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long>> cows(100001);
vector<long long> adjacencies(100001, 0);
vector<vector<long long>> grid(1001, vector<long long>(1001, -1));

long long current = 0;

void processAgain(long long x, long long y) {
    adjacencies[grid[y][x]]++;
    if (adjacencies[grid[y][x]] == 3) {
        current++;
    }
    if (adjacencies[grid[y][x]] == 4) {
        current--;
    }
}

int main() {
    long long n;
    cin >> n;

    for (long long i = 0; i < n; i++) {
        long long x;
        long long y;
        cin >> x >> y;
        cows[i] = {x, y};
        grid[y][x] = i;

        if (y > 0 && grid[y - 1][x] != -1) {
            adjacencies[i]++;
            processAgain(x, y - 1);
        }
        if (y < 1000 && grid[y + 1][x] != -1) {
            adjacencies[i]++;
            processAgain(x, y + 1);
        }
        if (x > 0 && grid[y][x - 1] != -1) {
            adjacencies[i]++;
            processAgain(x - 1, y);
        }
        if (x < 1000 && grid[y][x + 1] != -1) {
            adjacencies[i]++;
            processAgain(x + 1, y);
        }

        if (adjacencies[i] == 3) {
            current++;
        }
        cout << current << endl;
    }
}
