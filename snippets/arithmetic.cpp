// Two numbers x and y have the same remainder mod L if and only if x - y is divisible by L.

#include <cmath>
#include <vector>
using namespace std;

vector<long long> divisors(long long n) {
    vector<long long> div;
    n = abs(n);
    for (long long i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n / i) {
                div.push_back(n / i);
            }
        }
    }
    
    return div;
}

vector<int> primeFactor(int n) {
	vector<int> ret;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret.push_back(i);
			n /= i;
		}
	}
	if (n > 1) { ret.push_back(n); }
	return ret;
}
