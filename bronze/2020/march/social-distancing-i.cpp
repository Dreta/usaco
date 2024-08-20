// USACO 2020 US Open Contest, Bronze
// Problem 1. Social Distancing I

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Chunk {
    int start;
    int length;
    bool isLeftEnd;
    bool isRightEnd;
};

vector<Chunk> breakUpResult(Chunk chunk) {
    if (chunk.length == 1) {
        return {};
    }

    // For the cows on ends, put them at the ends.
    if (chunk.isLeftEnd) {
        return {{chunk.start + 1, chunk.length - 1, false, chunk.isRightEnd}};
    }

    if (chunk.isRightEnd) {
        return {{chunk.start, chunk.length - 1, chunk.isLeftEnd, false}};
    }

    int length = chunk.length - 1;
    if (length % 2 == 0) {
        return {{chunk.start, length / 2, chunk.isLeftEnd, false}, {chunk.start + length / 2 + 1, length / 2, false, chunk.isRightEnd}};
    }
    return {{chunk.start, length / 2, chunk.isLeftEnd, false}, {chunk.start + length / 2 + 1, length / 2 + 1, false, chunk.isRightEnd}};
}

vector<Chunk> breakUpForTwoCows(Chunk chunk) {
    if (chunk.isLeftEnd && chunk.isRightEnd) {
        return {{chunk.start + 1, chunk.length - 2, false, false}};
    }
    int ld3 = chunk.length / 3;
    if (chunk.length % 3 != 0) {
        ld3++;
    }
    if (chunk.isLeftEnd) {
        return {{chunk.start + 1, ld3, false, false}, {chunk.start + ld3 + 1 + 1, ld3 + (chunk.length % 3 == 0 ? 1 : 0), false, false}};
    }
    if (chunk.isRightEnd) {
        return {{chunk.start, ld3, false, false}, {chunk.start + ld3 + 1, ld3 + (chunk.length % 3 == 0 ? 1 : 0), false, false}};
    }

    if (chunk.length == 2) {
        return {};
    }
    if (chunk.length == 3) {
        return {{chunk.start, 1, chunk.isLeftEnd, false}};
    }
    if (chunk.length == 4) {
        return {{chunk.start, 1, chunk.isLeftEnd, false}, {chunk.start + 3, 1, false, chunk.isRightEnd}};
    }

    // Given this chunk, separate it into three such that the two cows are placed the furthest away from each other
    return {{chunk.start, chunk.length / 3, chunk.isLeftEnd, false}, {chunk.start + chunk.length / 3 + 1, chunk.length / 3, false, false}, {chunk.start + 2 * (chunk.length / 3) + 2, chunk.length / 3, false, chunk.isRightEnd}};

}

int main() {
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);

    int N;
    cin >> N;

    vector<bool> occupied(N, false);
    string s;
    cin >> s;

    vector<Chunk> emptyChunks;
    bool startNewChunk = true;
    for (int i = 0; i < N; i++) {
        occupied[i] = s[i] == '1';
        if (!occupied[i]) {
            if (startNewChunk) {
                emptyChunks.push_back({i, 1, i == 0, i == N - 1});
                startNewChunk = false;
            } else {
                emptyChunks.rbegin()->length++;
                if (i == N - 1) {
                    emptyChunks.rbegin()->isRightEnd = true;
                }
            }
        } else {
            startNewChunk = true;
        }
    }
    
    // Sort by chunk size (second), descending
    sort(emptyChunks.begin(), emptyChunks.end(), [](const Chunk& a, const Chunk& b) {
        return a.length > b.length;
    });
    vector<Chunk> resultingChunks;
    if (N > 2) {
        for (int i = 2; i < emptyChunks.size(); i++) {
            resultingChunks.push_back(emptyChunks[i]);
        }
    }

    // Two cases
    // If the largest chunk has a size bigger that twice the second largest chunk, place the two cows in the same largest chunk
    // Otherwise, place the two cows in the two largest chunks

    if (emptyChunks.size() == 1) {
        for (Chunk chunk : breakUpForTwoCows(emptyChunks[0])) {
            resultingChunks.push_back(chunk);
        }
    } else if (emptyChunks[0].length > 2 * emptyChunks[1].length) {
        for (Chunk chunk : breakUpForTwoCows(emptyChunks[0])) {
            resultingChunks.push_back(chunk);
        }
    } else {
        for (Chunk chunk : breakUpResult(emptyChunks[0])) {
            resultingChunks.push_back(chunk);
        }
        for (Chunk chunk : breakUpResult(emptyChunks[1])) {
            resultingChunks.push_back(chunk);
        }

    }

    // Reconstruct the result based on the resulting chunks
    vector<bool> result(N, true);
    for (Chunk chunk : resultingChunks) {
        for (int i = chunk.start; i < chunk.start + chunk.length; i++) {
            result[i] = false;
        }
    }

    int lastTrue = -1;
    int finalResult = 0xCAFEABC;
    for (int i = 0; i < N; i++) {
        if (result[i]) {
            if (lastTrue != -1) {
                finalResult = min(finalResult, i - lastTrue);
            }
            lastTrue = i;
        }
    }
    cout << finalResult << endl;
}
