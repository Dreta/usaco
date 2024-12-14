// USACO 2020 January Contest, Bronze
// Problem 3. Race

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int total, amountLimits;
    cin >> total >> amountLimits;

    for (int i = 0; i < amountLimits; i++) {
        int limit;
        cin >> limit;

        int distanceA = 0;
        int distanceB = 0;
        int time = 0;

        for (int speed = 1;; speed++) {
            distanceA += speed;
            time++;

            if (distanceA + distanceB >= total) {
                cout << time << endl;
                break;
            }

            if (speed >= limit) {
                distanceB += speed;
                time++;
                if (distanceA + distanceB >= total) {
                    cout << time << endl;
                    break;
                }
            }
        }
    }
}
