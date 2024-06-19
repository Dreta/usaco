#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;
vector<pair<int, int>> wormholes;
map<int, int> closestRight;
int result = 0;

bool has_cycle(map<int, int>& currentCombination) {
    for (int start = 0; start < N; start++) {
        int pos = start;
        for (int count = 0; count < N; count++) {
            if (closestRight.count(pos) == 0) break;
            pos = currentCombination[closestRight[pos]];
            if (pos == start) return true;
        }
    }
    return false;
}

void generatePairs(map<int, int> currentCombination) {
    int i;
    for (i = 0; i < N; i++) {
        if (currentCombination.count(i) == 0) break;
    }

    if (i == N) {
        if (has_cycle(currentCombination)) {
            result++;
        }
        return;
    }

    for (int j = i + 1; j < N; j++) {
        if (currentCombination.count(j) == 0) {
            currentCombination[i] = j;
            currentCombination[j] = i;
            generatePairs(currentCombination);
            currentCombination.erase(i);
            currentCombination.erase(j);
        }
    }
}

int main(void) {
    cin >> N;
    wormholes.resize(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        wormholes[i] = make_pair(x, y);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pair<int, int> a = wormholes[i];
            pair<int, int> b = wormholes[j];
            if (a.first < b.first && a.second == b.second) {
                if (closestRight.count(i) == 0 || wormholes[closestRight[i]].first > b.first) {
                    closestRight[i] = j;
                }
            }
        }
    }

    map<int, int> initialCombination;
    generatePairs(initialCombination);
    cout << result << endl;
}
