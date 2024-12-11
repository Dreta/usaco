// Codeforces: 1826D
// Running Miles

#include <iostream>
#include <vector>
using namespace std;

void task() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<int> prefMax(n);
    vector<int> sufMax(n);
    for (int i = 0; i < n; i++) {
        prefMax[i] = b[i] + i;
        sufMax[i] = b[i] - i;
    }
    for (int i = 1; i < n; i++) {
        prefMax[i] = max(prefMax[i - 1], prefMax[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        sufMax[i] = max(sufMax[i], sufMax[i + 1]);
    }
    int result = 0;
    for (int i = 1; i < n - 1; i++) {
        result = max(result, b[i] + prefMax[i - 1] + sufMax[i + 1]);
    }
    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        task();
    }
}
