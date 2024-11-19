// USACO 2024 January Contest, Bronze
// Problem 2. Cannonball

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, start;
    cin >> N >> start;

    int direction = 1;
    int power = 1;
    vector<pair<int, int>> locations(N + 1);
    for (int i = 1; i <= N; i++) {
        int q, v;
        cin >> q >> v;
        locations[i] = {q, v};
    }
    vector<bool> broken(N + 1, false);
    int loops = 0;
    while (true) {
        loops++;
        if (loops > 5 * N) {
            break;
        }
        if (locations[start].first == 0) {
            direction = -direction;
            power += locations[start].second;
        } else {
            if (power >= locations[start].second) {
                broken[start] = true;
            }
        }
        start += direction * power;
        if (start > N || start < 1) {
            break;
        }
    }
    int result = 0;
    for (int i = 1; i <= N + 1; i++) {
        result += broken[i];
    }
    cout << result << endl;
}
