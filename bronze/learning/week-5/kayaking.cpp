#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> w;
int result = 5000;

int main(void) {
    cin >> n;
    w.resize(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> w[i];
    }

    sort(w.begin(), w.end());
    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            vector<int> group;
            for (int p = 0; p < 2 * n; p++) {
                if (p != i && p != j) {
                    group.push_back(w[p]);
                }
            }

            int sum = 0;
            for (int p = 0; p < 2 * n - 2; p += 2) {
                sum += group[p + 1] - group[p];
            }
            result = min(result, sum);
        }
    }
    cout << result << endl;
}
