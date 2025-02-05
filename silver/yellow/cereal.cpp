// USACO 2020 US Open Contest, Silver
// Problem 2. Cereal

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> f;
vector<int> s;
map<int, int> current;
vector<int> result;
int prev = 0;

int main() {
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);

    int N, M;
    cin >> N >> M;
    f.resize(N + 1);
    s.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> f[i] >> s[i];
    }

    for (int i = 1; i <= M; i++) {
        current[i] = -1;
    }

    vector<int> results(N + 1);
    int result = 0;
    for (int i = N; i >= 1; i--) {
        int j = i;
        int cereal = f[i];
        while (true) {
            if (current[cereal] == -1) {
                current[cereal] = j;
                result++;
                break;
            } else if (current[cereal] < j) {
                break;
            } else {
                int k = current[cereal];
                current[cereal] = j;
                if (s[k] == cereal) {
                    break;
                }
                j = k;
                cereal = s[k];
            }
        }
        results[i] = result;
    }

    for (int i = 1; i <= N; i++) {
        cout << results[i] << endl;
    }
}
