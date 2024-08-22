// USACO 2020 US Open Contest, Bronze
// Problem 2. Social Distancing II

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Cow {
    int position;
    bool infected;
};

int main() {
    int N;
    cin >> N;
    vector<Cow> cows(N);
    bool hasInfected = false;
    bool hasUninfected = false;
    for (int i = 0; i < N; i++) {
        cin >> cows[i].position;
        cin >> cows[i].infected;
        if (cows[i].infected) {
            hasInfected = true;
        } else {
            hasUninfected = true;
        }
    }

    if (!hasInfected) {
        cout << 0 << endl;
        return 0;
    }
    if (!hasUninfected) {
        cout << 1 << endl; // If no cows are uninfected, we can say that a single cow infected everyone, because it's impossible to determine the radius upper bound.
        return 0;
    }
    sort(cows.begin(), cows.end(), [](const Cow &a, const Cow &b) {
        return a.position < b.position;
    });

    // Observations:
    // 1. We must determine the upper bound of the radius.
    // 2. The key is in the "groups" of cows, in which the distance between the cows in a group is less than or equal to the radius.
    // 3. Each group needs one initial infected cow to infect all the cows in that group.

    int radiusUpperBound = 10001; // not inclusive
    for (int i = 0; i < N; i++) {
        if (!cows[i].infected) {
            for (int j = i - 1; j >= 0; j--) {
                if (cows[j].infected) {
                    radiusUpperBound = min(radiusUpperBound, cows[i].position - cows[j].position);
                    break;
                }
            }
            for (int j = i + 1; j < N; j++) {
                if (cows[j].infected) {
                    radiusUpperBound = min(radiusUpperBound, cows[j].position - cows[i].position);
                    break;
                }
            }
        }
    }

    int groupLastMember = 0;
    int groups = 1;
    for (int i = 0; i < N; i++) {
        if (!cows[i].infected) {
            continue;
        }
        if (cows[i].position - cows[groupLastMember].position >= radiusUpperBound) {
            groups++;
        }
        groupLastMember = i;
    }
    cout << groups << endl;
}
