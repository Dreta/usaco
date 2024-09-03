// USACO 2020 December Contest, Bronze
// Problem 1. Do You Know Your ABCs?

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers(7);
    for (int i = 0; i < 7; i++) {
        cin >> numbers[i];
    }
    
    sort(numbers.begin(), numbers.end());
    // Observations:
    // 1. The sum of the numbers is the largest number.
    // 2. The second largest number must be B + C.

    int abc = numbers[6];
    int bc = numbers[5];
    int a = abc - bc;

    int ac = numbers[4];
    int c = ac - a;
    int b = bc - c;

    cout << a << " " << b << " " << c << endl;
}
