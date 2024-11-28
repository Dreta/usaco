// USACO 2023 February Contest, Bronze
// Problem 3. Watching Mooloo

#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    vector<long long> days(N);
    
    long long moonies = 0;
    for (long long i = 0; i < N; i++) {
        cin >> days[i];
        if (i == 0) {
            moonies += K + 1;
        } else {
            moonies += min(days[i] - days[i - 1], K + 1);
        }
    }
    cout << moonies << endl;
}
