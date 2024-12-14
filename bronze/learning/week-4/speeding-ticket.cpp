#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> limits;
    vector<int> speeds;

    for (int i = 0; i < N; i++) {
        int length, limit;
        cin >> length >> limit;
        for (int i = 0; i < length; i++) {
            limits.push_back(limit);
        }
    }

    for (int i = 0; i < M; i++) {
        int length, speed;
        cin >> length >> speed;
        for (int i = 0; i < length; i++) {
            speeds.push_back(speed);
        }
    }

    int result = 0;
    for (int i = 0; i < 100; i++) {
        result = max(result, speeds[i] - limits[i]);
    }
    cout << result << endl;
}
