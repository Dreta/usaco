#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

class SparseTable {
private:
    vector<vector<int>> minTable, maxTable;
    vector<int> logValues;
    int n;

public:
    SparseTable(const vector<int>& arr) {
        n = arr.size();
        int maxLog = log2(n) + 1;
        
        minTable.assign(n, vector<int>(maxLog));
        maxTable.assign(n, vector<int>(maxLog));
        logValues.resize(n + 1);

        // Compute log values
        for (int i = 2; i <= n; i++) {
            logValues[i] = logValues[i / 2] + 1;
        }

        // Initialize base cases
        for (int i = 0; i < n; i++) {
            minTable[i][0] = arr[i];
            maxTable[i][0] = arr[i];
        }

        // Fill the Sparse Tables
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                minTable[i][j] = min(minTable[i][j - 1], minTable[i + (1 << (j - 1))][j - 1]);
                maxTable[i][j] = max(maxTable[i][j - 1], maxTable[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int rangeMinQuery(int L, int R) {
        int j = logValues[R - L + 1];
        return min(minTable[L][j], minTable[R - (1 << j) + 1][j]);
    }

    int rangeMaxQuery(int L, int R) {
        int j = logValues[R - L + 1];
        return max(maxTable[L][j], maxTable[R - (1 << j) + 1][j]);
    }
};
