#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    int N;
    map<string, vector<string>> constraints;
    string cows[] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    cin >> N;
    for (int i = 0; i < N; i++) {
        string a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        constraints[a].push_back(f);
    }
    do {
        bool valid = true;
        for (int i = 0; i < 8; i++) {
            string cow = cows[i];
            if (constraints[cow].size() > 0) {
                for (string other : constraints[cow]) {
                    int b = find(cows, cows + 8, other) - cows;
                    if (abs(i - b) != 1) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) {
                break;
            }
        }
        if (valid) {
            for (int i = 0; i < 8; i++) {
                cout << cows[i] << endl;
            }
            break;
        }
    } while (next_permutation(cows, cows + 8));
}
