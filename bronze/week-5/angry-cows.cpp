// USACO 2016 January Contest, Bronze
// Problem 2. Angry Cows

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N;
vector<int> cows;

int explode(set<int> thisExplode, int radius, vector<int> cowsRemaining) {
    if (thisExplode.empty() || cowsRemaining.empty()) {
        return 0;
    }

    cowsRemaining.erase(remove_if(cowsRemaining.begin(), cowsRemaining.end(), [&](int cow) {
        return thisExplode.find(cow) != thisExplode.end();
    }), cowsRemaining.end());

    int exploded = thisExplode.size();
    set<int> nextExplode;
    for (int i : thisExplode) {
        for (int cow : cowsRemaining) {
            if (abs(cow - i) <= radius) {
                nextExplode.insert(cow);
            }
        }
    }
    return exploded + explode(nextExplode, radius + 1, cowsRemaining);
}

int main() {
    cin >> N;
    cows.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }

    int result = 0;
    for (int i : cows) {
        result = max(explode({i}, 1, cows), result);
    }
    cout << result << endl;
}
