// Codeforces 279D: B
// Books

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    
    int left = 0;
    int right = 0;
    int sum = 0;
    int maxBooks = 0;
    while (right < n) {
        sum += a[right];
        right++;
        while (sum > t) {
            sum -= a[left];
            left++;
        }
        maxBooks = max(maxBooks, right - left);
    }
    cout << maxBooks << endl;
}
