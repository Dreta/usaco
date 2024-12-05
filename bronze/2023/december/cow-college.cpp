// USACO 2022 December Contest, Bronze
// Problem 1. Cow College

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ll N;
    cin >> N;
    vector<ll> cowsAtTuition(1000001, 0);
    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        cowsAtTuition[a]++;
    }
    vector<ll> prefixSum(1000001, 0);
    prefixSum[1000000] = cowsAtTuition[1000000];
    for (ll i = 1000000 - 1; i >= 1; i--) {
        prefixSum[i] = prefixSum[i + 1] + cowsAtTuition[i];
    }
    // prefixSum[i] represents the amount of cows willing to accept this tuition

    ll maxEarning = 0;
    ll tuitionForMaxEarning = 0;
    for (ll tuition = 1; tuition <= 1000000; tuition++) {
        ll earning = tuition * prefixSum[tuition];
        if (earning > maxEarning) {
            maxEarning = earning;
            tuitionForMaxEarning = tuition;
        }
    }
    cout << maxEarning << " " << tuitionForMaxEarning << endl;
}
