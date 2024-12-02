// USACO 2023 January Contest, Bronze
// Problem 2. Air Cownditioning II

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Cow {
    int start;
    int end;
    int target;
};

struct AirConditioner {
    int start;
    int end;
    int power;
    int cost;
    bool used = false;
};

vector<Cow> cows;
vector<int> stallsToCows(101, -1);
vector<AirConditioner> acs;
int result = 10001;

void subsets(const std::vector<int>& nums) {
    int n = nums.size();
    int totalSubsets = 1 << n;

    for (int mask = 0; mask < totalSubsets; ++mask) {
        std::vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }

        int cost = 0;
        vector<int> current(101, 0);
        for (int num : subset) {
            AirConditioner ac = acs[num];
            for (int i = ac.start; i <= ac.end; i++) {
                current[i] += ac.power;
            }
            cost += ac.cost;
        }

        bool valid = true;
        for (int i = 1; i <= 100; i++) {
            if (stallsToCows[i] != -1) {
                Cow cow = cows[stallsToCows[i]];
                if (current[i] < cow.target) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            result = min(result, cost);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    cows.resize(N);
    acs.resize(M);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].start >> cows[i].end >> cows[i].target;
        for (int j = cows[i].start; j <= cows[i].end; j++) {
            stallsToCows[j] = i;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> acs[i].start >> acs[i].end >> acs[i].power >> acs[i].cost;
    }

    vector<int> nums(M);
    for (int i = 0; i < M; i++) {
        nums[i] = i;
    }
    subsets(nums);
    cout << result << endl;
}
