// USACO 2022 January Contest, Bronze
// Problem 2. Non-Transitive Dice

#include <iostream>
#include <vector>
using namespace std;

// 1 if a beats b, 0 if a and b are equal, -1 if b beats a
int aBeatsB(vector<int> a, vector<int> b) {
    int aWins = 0;
    int tie = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            aWins += a[i] > b[j];
            tie += a[i] == b[j];
        }
    }
    int bWins = 16 - aWins - tie;
    if (aWins > bWins) {
        return 1;
    } else if (aWins == bWins) {
        return 0;
    } else {
        return -1;
    }
}

bool solve(vector<int> a, vector<int> b) {
    int ab = aBeatsB(a, b);
    if (ab == 0) {
        return false;
    }

    if (ab == 1) {
        for (int w = 1; w <= 10; w++) {
            for (int x = 1; x <= 10; x++) {
                for (int y = 1; y <= 10; y++) {
                    for (int z = 1; z <= 10; z++) {
                        if (aBeatsB(b, {w, x, y, z}) == 1 && aBeatsB({w, x, y, z}, a) == 1) {
                            return true;
                        }
                    }
                }
            }
        }
    } else {
        for (int w = 1; w <= 10; w++) {
            for (int x = 1; x <= 10; x++) {
                for (int y = 1; y <= 10; y++) {
                    for (int z = 1; z <= 10; z++) {
                        if (aBeatsB(a, {w, x, y, z}) == 1 && aBeatsB({w, x, y, z}, b) == 1) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        vector<int> a(4);
        vector<int> b(4);
        for (int i = 0; i < 4; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < 4; i++) {
            cin >> b[i];
        }
        cout << (solve(a, b) ? "yes" : "no") << endl;
    }
}
