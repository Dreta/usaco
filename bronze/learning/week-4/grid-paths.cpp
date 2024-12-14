#include <iostream>
using namespace std;

int actions[48];
bool world[9][9];

// D, U, L, R
int actionsX[4] = {0, 0, -1, 1};
int actionsY[4] = {1, -1, 0, 0};

int possibilities(int cursor, int currX, int currY) {
    // Pruning search tree: if we reach a point where the next move is going to split the
    // grid into two parts that are not connected, skip this case.
    if ((world[currY][currX - 1] && world[currY][currX + 1])
        && (!world[currY - 1][currX] && !world[currY + 1][currX])) return 0;
    if ((!world[currY][currX - 1] && !world[currY][currX + 1])
        && (world[currY - 1][currX] && world[currY + 1][currX])) return 0;

    if (currX == 1 && currY == 7) {
        if (cursor == 48) { // If we reached the end using all of the actions possible
            return 1;
        }
        return 0; // If we reached the end, but some actions haven't been used yet
    }

    if (cursor == 48) { // If we exhausted all of the actions without reaching the end
        return 0;
    }

    int result = 0;
    int thisAction = actions[cursor];
    world[currY][currX] = true;

    if (thisAction < 4) {
        // If this action is already defined, move accordingly
        if (!world[currY + actionsY[thisAction]][currX + actionsX[thisAction]]) {
            result += possibilities(cursor + 1, currX + actionsX[thisAction], currY + actionsY[thisAction]);
        }
    } else {
        // Else, try all possible actions
        for (int i = 0; i < 4; i++) {
            if (!world[currY + actionsY[i]][currX + actionsX[i]]) {
                result += possibilities(cursor + 1, currX + actionsX[i], currY + actionsY[i]);
            }
        }
    }
    world[currY][currX] = false;
    return result;
}

int main(void) {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == 'D') {
            actions[i] = 0;
        } else if (c == 'U') {
            actions[i] = 1;
        } else if (c == 'L') {
            actions[i] = 2;
        } else if (c == 'R') {
            actions[i] = 3;
        } else {
            actions[i] = 4;
        }
    }
    fill(&world[0][0], &world[8][9], false);
    // Create a "boundary" so that the positions are 1-indexed
    // and we don't have to worry about out-of-bounds
    for (int i = 0; i < 9; i++) {
        world[0][i] = true;
        world[8][i] = true;
        world[i][0] = true;
        world[i][8] = true;
    }

    cout << possibilities(0, 1, 1) << endl;
}
