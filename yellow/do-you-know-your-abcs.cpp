// USACO 2021 US Open, Silver
// Problem 2. Do You Know Your ABCs?

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void task() {
    int N;
    cin >> N;
    vector<int> nums;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    set<int> differences;
    for (int x : nums) {
        differences.insert(x);
        for (int y : nums) {
            if (y > x) {
                differences.insert(y - x);
            }
        }
    }

    int result = 0;
    for (int a : differences) {
        for (int b : differences) {
            for (int c : differences) {
                if (a <= b && b <= c) {
                    vector<int> numbers = {a, b, c, a + b, a + c, b + c, a + b + c};
                    bool works = true;
                    for (int num : nums) {
                        if (find(numbers.begin(), numbers.end(), num) == numbers.end()) {
                            works = false;
                            break;
                        }
                    }

                    if (works) {
                        result++;
                    }
                }
            }
        }
    }
    cout << result << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        task();
    }
}
