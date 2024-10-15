// USACO 2021 December Contest, Bronze
// Problem 1. Lonely Photo

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    int result = 0;
    for (int start = 0; start < N - 2; start++) {
        int h = 0;
        int g = 0;
        for (int i = start; i < N; i++) {
            if (s[i] == 'G') {
                g++;
            } else {
                h++;
            }

            if (i - start + 1 >= 3 && ((g == 1) || (h == 1))) {
                result++;
            }
        }
    }
    cout << result << endl;
}
