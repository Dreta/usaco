// Codeforces 1556D: Take a Guess

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int interact(string op, int a, int b) {
    cout << op << " " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
}

int sum(int a, int b) {
    a++;
    b++;
    int andRes = interact("and", a, b);
    int orRes = interact("or", a, b);
    int xorRes = ~andRes & orRes;
    return 2 * andRes + xorRes;
}

int main() {
    int n, k;
    cin >> n >> k;

    int ab = sum(0, 1);
    int ac = sum(0, 2);
    int bc = sum(1, 2);
    vector<int> results{(ab + ac - bc) / 2};
    results.push_back(ab - results[0]);
    results.push_back(ac - results[0]);
    for (int i = 3; i < n; i++) {
        results.push_back(sum(i - 1, i) - results.back());
    }
    sort(results.begin(), results.end());
    cout << "finish " << results[k - 1] << endl;
}
