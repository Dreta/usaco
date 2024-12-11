// AtCoder Beginner Contest 164
// D: Multiples of 2019

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<long long> prefixSum(s.size() + 1);
    prefixSum[0] = s[0] - '0';
    for (long long i = 1; i < s.size(); i++) {
        prefixSum[i] = prefixSum[i - 1] * 10 + (s[i] - '0');
    }

    long long result = 0;
    for (long long left = 0; left < s.size(); left++) {
        for (long long right = left + 1; right < s.size(); right++) {
            long long num;
            if (left == 0) {
                num = prefixSum[right];
            } else {
                num = prefixSum[right] - (prefixSum[left - 1] * pow(10, right - left + 1));
            }
            if (num % 2019 == 0) {
                result++;
            }
        }
    }
    cout << result << endl;
}
