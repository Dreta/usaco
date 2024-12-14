// Codeforces: 102951D
// Static Range Queries

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<long long> indices;
struct Op {
    long long left;
    long long right;
    long long value;
};

long long comp(long long x) {
    return lower_bound(indices.begin(), indices.end(), x) - indices.begin();
}

int main() {
    long long n, q;
    cin >> n >> q;
    vector<Op> ops(n);
    vector<pair<long long, long long>> queries(q);

    for (long long i = 0; i < n; i++) {
        cin >> ops[i].left >> ops[i].right >> ops[i].value;
        indices.push_back(ops[i].left);
        indices.push_back(ops[i].right);
    }
    for (long long i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
        indices.push_back(queries[i].first);
        indices.push_back(queries[i].second);
    }

    // Coordinate compression
    sort(indices.begin(), indices.end());
    // Remove duplicates
    indices.erase(unique(indices.begin(), indices.end()), indices.end());

    vector<long long> differences(1000000, 0);
    for (long long i = 0; i < n; i++) {
        differences[comp(ops[i].left) + 1] += ops[i].value;
        differences[comp(ops[i].right) + 1] -= ops[i].value;
    }

    vector<long long> recovered(indices.size() + 1, 0);
    for (long long i = 1; i < indices.size(); i++) {
        recovered[i] = recovered[i - 1] + differences[i];
    }

    vector<long long> widths(indices.size(), 0);
    for (long long i = 0; i < indices.size() - 1; i++) {
        widths[i + 1] = indices[i + 1] - indices[i];
    }
    
    vector<long long> prefixSums(indices.size(), 0);
    for (long long i = 1; i < indices.size(); i++) {
        prefixSums[i] = prefixSums[i - 1] + widths[i] * recovered[i];
    }

    for (pair<long long, long long> query : queries) {
        cout << prefixSums[comp(query.second)] - prefixSums[comp(query.first)] << endl;
    }
}
