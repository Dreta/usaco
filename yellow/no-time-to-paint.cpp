// USACO 2021 January Contest, Silver
// Problem 2. No Time to Paint

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<int> colors;
vector<int> prefixSolutions;
vector<int> suffixSolutions;

void solveForPrefix(vector<int> &target) {
    stack<int> s;
    target[0] = 0;
    for (int i = 1; i <= N; i++) {
        int color = colors[i];
        target[i] = target[i - 1];
        while (!s.empty() && s.top() > color) {
            s.pop();
        }
        if (s.empty() || s.top() < color) {
            s.push(color);
            target[i]++;
        }
    }
}

int getChar(char c) {
    return c - 'A' + 1;
}

int main() {
    int Q;
    cin >> N >> Q;

    colors.resize(N + 1);
    prefixSolutions.resize(N + 1);
    suffixSolutions.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        char c;
        cin >> c;
        colors[i] = getChar(c);
    }

    solveForPrefix(prefixSolutions);
    reverse(colors.begin() + 1, colors.end());
    solveForPrefix(suffixSolutions);

    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << prefixSolutions[a - 1] + suffixSolutions[N - b] << endl;
    }
}
