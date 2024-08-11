// USACO 2023 December Contest, Bronze
// Problem 2. Cowntact Tracing 2

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> cows(N);
    string s;
    cin >> s;
    int i = 0;

    vector<int> oneStart;
    vector<int> lengths;
    int startHere = -1;
    for (int i = 0; i < N; i++) {
        cows[i] = s[i] - '0';
        if (cows[i] == 1 && startHere == -1) {
            startHere = i;
            oneStart.push_back(i);
        }
        if ((cows[i] == 0 || i == N - 1) && startHere != -1) {
            lengths.push_back(i - startHere + (i == N - 1 ? 1 : 0));
            startHere = -1;
        }
    }
    if (lengths.empty()) {
        cout << 0 << endl;
    }

    int minimumGroup = 0;
    int minGroupValue = 100000000;
    for (int i = 0; i < lengths.size(); i++) {
        int effectiveLength = lengths[i];
        int thisStart = oneStart[i];
        int thisEnd = thisStart + lengths[i] - 1;
        if ((thisStart == 0 || thisEnd == lengths.size() - 1) && lengths.size() > 1) {
            effectiveLength = lengths[i] * 2 - 1;
        }

        if (effectiveLength < minGroupValue) {
            minimumGroup = i;
            minGroupValue = effectiveLength;
        }
    }

    int maxDays = (lengths[minimumGroup] - 1) / 2 + 1;
    int result = 0;
    for (int i = 0; i < lengths.size(); i++) {
        int effectiveLength = lengths[i];
        int thisStart = oneStart[i];
        int thisEnd = thisStart + lengths[i] - 1;
        if ((thisStart == 0 || thisEnd == lengths.size() - 1) && lengths.size() > 1) {
            effectiveLength = lengths[i] * 2 - 1;
        }
        result += ceil(effectiveLength / maxDays);
    }
    cout << result << endl;

    // Idea:
    // Day 0 110000000110000000100000001
    // Day 1 111000001111000001110000011
    // Day 2 111100011111100011111000111
    //
    // Observe that:
    //  Given that we have D days, each cow infects 2D + 1 cows, including itself.
    //  The maximum number of days correspond to the minimum amount of initial cows.
    //  The maximum number of days is dependent on the SHORTEST chain of 1 cows.
    //    Why? Because the shortest chain of 1 cows will reach the initial cow the quickest, so it's the limiting factor for the days that can pass.
    //    If the group we are testing for is on the edge, the maximum number of days would be LENGTH.
    //    If the group we are testing for is not on the edge and has an odd LENGTH, the maximum number of days would be (LENGTH - 1) / 2.
    //    If the group we are testing for is not on the edge and has an even LENGTH, the maximum number of days would be LENGTH / 2.
}
