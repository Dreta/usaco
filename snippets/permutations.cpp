#include <iostream>
#include <vector>
using namespace std;

vector<int> applyPermutation(const vector<int>& perm, int N) {
    int n = perm.size();
    vector<int> result(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> cycle;
            int x = i;
            while (!visited[x]) {
                visited[x] = true;
                cycle.push_back(x);
                x = perm[x];
            }

            int L = cycle.size();
            int shift = N % L;
            for (int j = 0; j < L; j++) {
                result[cycle[j]] = cycle[(j + shift) % L];
            }
        }
    }

    return result;
}
