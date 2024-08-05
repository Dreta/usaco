// USACO 2019 US Open Contest, Bronze
// Problem 3. Cow Evolution

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;
map<string, vector<int>> sets;

bool isInvalid(vector<int> a, vector<int> b) {
    // Check if the two sets are crossing.
    int equal = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) equal++;
        }
    }
    if (equal == 0) return false;
    if (equal == a.size() || equal == b.size()) return false;
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            string s;
            cin >> s;
            sets[s].push_back(i);
        }
    }

    for (auto i = sets.begin(); i != sets.end(); i++) {
        for (auto j = sets.begin(); j != sets.end(); j++) {
            if (i == j) continue;
            if (isInvalid(i->second, j->second)) {
                cout << "no" << endl;
                return 0;
            }
        }
    }
    cout << "yes" << endl;
}
