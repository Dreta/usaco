// USACO 2024 January Contest, Bronze
// Problem 3. Balancing Bacteria

// Initial Solution: Θ(N^2) for subtasks 1 through 10

#include <iostream>
#include <vector>
#define long long long
using namespace std;

int main() {
    // It can be shown that the minimum amount of moves needed can be accomplished by the following:
    // Let i be 0.
    // If the current element at i is 0, skip it.
    // If the current element is positive, perform N decrease operations of power N - i.
    // If the current element is negative, perform N increase operations of power N - i.
    // After this operation, element i will be 0. Continue for each element.

    long N;
    cin >> N;
    vector<long> a(N);
    for (long i = 0; i < N; i++) {
        cin >> a[i];
    }

    long result = 0;
    long contribution = 0;
    long ops = 0;
    for (long i = 0; i < N; i++) {
        contribution += ops;
        a[i] += contribution;

        long thisChange = -a[i];
        result += abs(thisChange);
        ops += thisChange;
        contribution += thisChange;
    }
    cout << result << endl;
}
