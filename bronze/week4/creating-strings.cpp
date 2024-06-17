#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    string s;
    cin >> s;

    vector<char> chars(s.begin(), s.end()); 
    sort(chars.begin(), chars.end());
    vector<string> strings;
    do {
        strings.push_back(string(chars.begin(), chars.end()));
    } while (next_permutation(chars.begin(), chars.end()));
    sort(strings.begin(), strings.end());
    cout << strings.size() << endl;
    for (string s : strings) {
        cout << s << endl;
    }
}
