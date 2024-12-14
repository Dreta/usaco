#include <iostream>
#include <set>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    set<int> x;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        x.insert(r);
    }

    cout << x.size() << endl;
}
