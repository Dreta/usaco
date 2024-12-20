// Codeforces 1137D: Cooperative Game

#include <iostream>
#include <vector>
using namespace std;

vector<int> interact(const vector<int> &toMove) {
    cout << "next ";
    for (int i = 0; i < toMove.size() - 1; i++) {
        cout << toMove[i] << " ";
    }
    cout << toMove[toMove.size() - 1] << endl;

    int groups;
    cin >> groups;
    vector<int> result(10);
    for (int g = 0; g < groups; g++) {
        string group;
        cin >> group;
        for (char i : group) {
            result[i - '0'] = g;
        }
    }
    return result;
}

int main() {
    interact({0, 1});
    vector<int> groups = interact({1});
    while (groups[0] != groups[1]) {
        interact({0, 1});
        groups = interact({1});
    }

    // We have found the cycle.
    while (groups[2] != groups[1]) {
        groups = interact({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    }
    cout << "done" << endl;
}
