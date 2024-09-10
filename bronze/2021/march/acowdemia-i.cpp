// USACO 2021 US Open Contest, Bronze
// Problem 1. Acowdemia I

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int currentPapers, maximumCitations;
    cin >> currentPapers >> maximumCitations;

    vector<int> citations(currentPapers);
    for (int i = 0; i < currentPapers; i++) {
        cin >> citations[i];
    }

    sort(citations.begin(), citations.end(), greater<int>());
    int h;
    int k = 0;

    for (int i = 0; i < currentPapers; i++) {
        if (i + 1 >= citations[i]) {
            h = citations[i];
            break;
        }
    }

    for (int i = 0; i < h; i++) {
        if (citations[i] == h) {
            k++;
        }
    }

    if (citations[h] == h && maximumCitations >= k + 1) {
        cout << h + 1 << endl;
    } else {
        cout << h << endl;
    }
}
