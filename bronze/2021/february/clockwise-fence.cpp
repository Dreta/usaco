// USACO 2021 February Contest, Bronze
// Problem 3. Clockwise Fence

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<char, char> clockwiseNextAction;
    clockwiseNextAction['N'] = 'E';
    clockwiseNextAction['E'] = 'S';
    clockwiseNextAction['S'] = 'W';
    clockwiseNextAction['W'] = 'N';
    map<char, char> ccwNextAction;
    ccwNextAction['N'] = 'W';
    ccwNextAction['W'] = 'S';
    ccwNextAction['S'] = 'E';
    ccwNextAction['E'] = 'N';

    while (N--) {
        string path;
        cin >> path;

        // We observe that:
        // * Each "turn" can either be clockwise or counterclockwise.
        // * If there are more clockwise turns than counterwise turns, the entire path would be clockwise.
        // * Vice versa.

        char currentDirection = path[0];
        int clockwiseActions = 0;
        int ccwActions = 0;
        for (char dir : path) {
            if (dir == currentDirection) {
                continue;
            }
            if (clockwiseNextAction[currentDirection] == dir) {
                clockwiseActions++;
            } else if (ccwNextAction[currentDirection] == dir) {
                ccwActions++;
            }
            currentDirection = dir;
        }
        cout << (clockwiseActions > ccwActions ? "CW" : "CCW") << endl;
    }
}
