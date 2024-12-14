#include <iostream>
#include <map>
using namespace std;

int main(void) {
    map<long long, long long> x;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            long long k, v;
            cin >> k >> v;
            x[k] = v;
        } else if (op == 1) {
            long long k;
            cin >> k;
            if (x.count(k) == 0) {
                cout << 0 << endl;
            } else {
                cout << x[k] << endl;
            }
        }
    }
}
