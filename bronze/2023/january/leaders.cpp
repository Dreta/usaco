// USACO 2023 January Contest, Bronze
// Problem 1. Leaders

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int N;
vector<char> breeds;
vector<bool> containsAll;
vector<int> E;
set<pair<int, int>> leaders;
int firstG = -1;
int firstH = -1;

bool cowContains(int a, int cow) {
    return a >= cow && a <= E[cow];
}

pair<int, int> unique(int a, int b) {
    return a < b ? make_pair(a, b) : make_pair(b, a);
}

int main() {
    cin >> N;
    breeds.resize(N + 1);
    E.resize(N + 1);
    containsAll.resize(N + 1);
    string s;
    cin >> s;

    map<char, pair<int, int>> minMax;
    minMax['G'] = {N + 1, 0};
    minMax['H'] = {N + 1, 0};
    for (int i = 1; i <= N; i++) {
        breeds[i] = s[i - 1];
        if (breeds[i] == 'G' && firstG == -1) {
            firstG = i;
        }
        if (breeds[i] == 'H' && firstH == -1) {
            firstH = i;
        }
        minMax[breeds[i]].first = min(minMax[breeds[i]].first, i);
        minMax[breeds[i]].second = max(minMax[breeds[i]].second, i);
    }
    for (int i = 1; i <= N; i++) {
        cin >> E[i];
        if (minMax[breeds[i]].first >= i && minMax[breeds[i]].second <= E[i]) {
            containsAll[i] = true;
        }
    }

    // There are several cases in which cows A and B can be leaders in a pair:
    // 1. A contains B and B contains A (Impossible)
    // 2. A contains all of its breed and B contains all of its breed
    // 3. A contains all of its breed and B contains A
    
    // Case 2
    if (containsAll[firstG] && containsAll[firstH]) {
        leaders.insert(unique(firstG, firstH));
    }

    // Case 3, where A is a G cow
    if (containsAll[firstG]) {
        for (int i = 1; i <= N; i++) {
            if (breeds[i] == 'H' && cowContains(firstG, i)) {
                leaders.insert(unique(firstG, i));
            }
        }
    }

    // Case 3, where A is an H cow
    if (containsAll[firstH]) {
        for (int i = 1; i <= N; i++) {
            if (breeds[i] == 'G' && cowContains(firstH, i)) {
                leaders.insert(unique(firstH, i));
            }
        }
    }
    
    cout << leaders.size() << endl;
}
