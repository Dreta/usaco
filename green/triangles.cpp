// USACO 2020 February Contest, Silver
// Problem 2. Triangles

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> points(N);

    // SETUP CALCULATIONS
    // point b is as indexed in yValues and xValues
    map<ll, vector<ll>> sumYs; // sumYs[a][b] is the sum of (the distance between point b) and all other points with the same x-value a.
    map<ll, vector<ll>> sumXs; // sumXs[a][b] is the sum of (the distance between point b) and all other points with the same y-value a.

    map<ll, vector<ll>> yValues; // indexed with the same x
    map<ll, map<ll, ll>> yValuesReversed;
    map<ll, vector<ll>> xValues; // indexed with the same y
    map<ll, map<ll, ll>> xValuesReversed;

    for (ll i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
        xValues[points[i].second].push_back(points[i].first);
        yValues[points[i].first].push_back(points[i].second);

        sumYs[points[i].first] = vector<ll>();
        sumXs[points[i].second] = vector<ll>();
    }

    for (auto &x : xValues) {
        sort(x.second.begin(), x.second.end());
        for (ll i = 0; i < x.second.size(); i++) {
            xValuesReversed[x.first][x.second[i]] = i;
        }
    }
    for (auto &y : yValues) {
        sort(y.second.begin(), y.second.end());
        for (ll i = 0; i < y.second.size(); i++) {
            yValuesReversed[y.first][y.second[i]] = i;
        }
    }

    // Calculate the first sumXs and sumYs
    for (auto &sumX : sumXs) {
        ll sum = 0;
        for (ll i = 0; i < xValues[sumX.first].size(); i++) {
            sum += abs(xValues[sumX.first][i] - xValues[sumX.first][0]);
        }
        sumX.second.push_back(sum);
    }

    for (auto &sumY : sumYs) {
        ll sum = 0;
        for (ll i = 0; i < yValues[sumY.first].size(); i++) {
            sum += abs(yValues[sumY.first][i] - yValues[sumY.first][0]);
        }
        sumY.second.push_back(sum);
    }

    // Extend the calculation to all other sumXs and sumYs
    for (auto &sumX : sumXs) {
        ll currentSum = sumX.second[0];
        for (ll i = 1; i < xValues[sumX.first].size(); i++) {
            ll distanceMoved = xValues[sumX.first][i] - xValues[sumX.first][i - 1];
            currentSum += i * distanceMoved;
            currentSum -= (xValues[sumX.first].size() - i) * distanceMoved;
            sumX.second.push_back(currentSum);
        }
    }

    for (auto &sumY : sumYs) {
        ll currentSum = sumY.second[0];
        for (ll i = 1; i < yValues[sumY.first].size(); i++) {
            ll distanceMoved = yValues[sumY.first][i] - yValues[sumY.first][i - 1];
            currentSum += i * distanceMoved;
            currentSum -= (yValues[sumY.first].size() - i) * distanceMoved;
            sumY.second.push_back(currentSum);
        }
    }

    // SOLUTION
    ll ans = 0;
    for (pair<ll, ll> point : points) {
        ll x = point.first;
        ll y = point.second;
        ll sumX = sumXs[y][xValuesReversed[y][x]];
        ll sumY = sumYs[x][yValuesReversed[x][y]];
        ans += sumX * sumY;
    }
    cout << ans % 1000000007 << endl;
}
