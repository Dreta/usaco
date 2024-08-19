// USACO 2020 US Open Contest, Bronze
// Problem 3. Cowntact Tracing

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Action {
    int time;
    int a;
    int b;
};

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    int N, T;
    cin >> N >> T;

    vector<bool> cowsInfected(N, false);
    string _;
    cin >> _;
    for (int i = 0; i < N; i++) {
        cowsInfected[i] = _[i] == '1';
    }

    vector<Action> actions(T);
    for (int i = 0; i < T; i++) {
        int time, a, b;
        cin >> time >> a >> b;
        actions[i] = {time, a - 1, b - 1}; // 0-indexed
    }

    sort(actions.begin(), actions.end(), [](const Action& a, const Action& b) {
        return a.time < b.time;
    });
    // Let's solve this problem with brute force.
    set<int> patient0s;
    int minK = 251;
    int maxK = 0;
    for (int patient0 = 0; patient0 < N; patient0++) {
        for (int k = 0; k <= 251; k++) {
            // Simulate
            vector<bool> infectedResult(N, false);
            vector<int> infectedRemaining(N, k);
            infectedResult[patient0] = true;
            for (Action action : actions) {
                if (infectedResult[action.a] && infectedRemaining[action.a] > 0) {
                    infectedResult[action.b] = true;
                    infectedRemaining[action.a]--;
                }
                if (infectedResult[action.b] && infectedRemaining[action.b] > 0) {
                    infectedResult[action.a] = true;
                    infectedRemaining[action.b]--;
                }
            }

            // Check if the simulation is valid
            bool valid = true;
            for (int i = 0; i < N; i++) {
                if (cowsInfected[i] != infectedResult[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                patient0s.insert(patient0);
                minK = min(minK, k);
                maxK = max(maxK, k);
            }
        }
    }
    cout << patient0s.size() << " " << minK << " ";
    if (maxK == 251) {
        cout << "Infinity" << endl;
    } else {
        cout << maxK << endl;
    }
}
