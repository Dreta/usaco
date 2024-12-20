// Codeforces 1020B: Badge

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    for (int i = 0; i < n; i++) {
        int a = p[i];
        int b = p[p[i]];
        while (a != b) {
            a = p[a];
            b = p[p[b]];
        }

        a = i;
        while (a != b) {
            a = p[a];
            b = p[b];
        }
        cout << a + 1 << " ";
    }
    cout << endl;
}
