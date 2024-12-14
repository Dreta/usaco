#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> firstSizes;
vector<int> secondSizes;
vector<vector<int>> allCombinations;

void findCombinations(vector<int>& currentCombination, int round) {
    if (round == 4) {
        allCombinations.push_back(currentCombination);
        return;
    }

    if (round == 0 || round == 2) {
        vector<int> valid(firstSizes.begin(), firstSizes.end());
        for (int num : valid) {
            currentCombination.push_back(num);
            firstSizes.erase(find(firstSizes.begin(), firstSizes.end(), num));
            secondSizes.push_back(num);
            findCombinations(currentCombination, round + 1);
            firstSizes.push_back(num);
            secondSizes.erase(find(secondSizes.begin(), secondSizes.end(), num));
            currentCombination.pop_back();
        }
    } else {
        vector<int> valid(secondSizes.begin(), secondSizes.end());
        for (int num : valid) {
            currentCombination.push_back(num);
            secondSizes.erase(find(secondSizes.begin(), secondSizes.end(), num));
            firstSizes.push_back(num);
            findCombinations(currentCombination, round + 1);
            secondSizes.push_back(num);
            firstSizes.erase(find(firstSizes.begin(), firstSizes.end(), num));
            currentCombination.pop_back();
        }
    }
}


int main(void) {
    for (int i = 0; i < 10; i++) {
        int j;
        cin >> j;
        firstSizes.push_back(j);
    }
    for (int i = 0; i < 10; i++) {
        int j;
        cin >> j;
        secondSizes.push_back(j);
    }
    
    set<int> result;

    vector<int> currentCombination;
    findCombinations(currentCombination, 0);

    set<int> results;
    for (vector<int> combination : allCombinations) {
        results.insert(1000 - combination[0] + combination[1] - combination[2] + combination[3]);
    }
    cout << results.size() << endl;
}
