// USACO 2024 US Open Contest, Silver
// Problem 1. Bessie's Interview

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<int> timeRequired;
vector<int> startTime;
vector<int> interviewers;
int currentTime = 0;

struct CompareTime {
    bool operator()(int a, int b) const {
        return startTime[a] + timeRequired[a] > startTime[b] + timeRequired[b];
    }
};

queue<int> remainingCows;
queue<int> remainingInterviewers;
priority_queue<int, vector<int>, CompareTime> pq;
vector<bool> result;

int finalTime = -1;

void fillQueue() {
    if (!pq.empty()) {
        // Advance the current time
        currentTime = startTime[pq.top()] + timeRequired[pq.top()];
    }

    if (currentTime == 0) {
        // Initially, farmer i (1...K) interviews cow i
        for (int i = 1; i <= K; i++) {
            int cow = remainingCows.front();
            remainingCows.pop();
            startTime[cow] = currentTime;
            interviewers[cow] = remainingInterviewers.front();
            remainingInterviewers.pop();
            pq.push(cow);
        }
        return;
    }

    // End interviews for cows that are done
    while (!pq.empty() && startTime[pq.top()] + timeRequired[pq.top()] == currentTime) {
        int cow = pq.top();
        pq.pop();
        remainingInterviewers.push(interviewers[cow]);
        interviewers[cow] = -1;
    }
    
    if (remainingCows.empty()) {
        // We are done
        finalTime = currentTime;

        // Assign all remaining interviewers as possible for Bessie
        while (!remainingInterviewers.empty()) {
            result[remainingInterviewers.front()] = true;
            remainingInterviewers.pop();
        }
        return;
    }

    while (!remainingCows.empty() && !remainingInterviewers.empty()) {
        int cow = remainingCows.front();
        remainingCows.pop();
        
        startTime[cow] = currentTime;
        interviewers[cow] = remainingInterviewers.front();
        remainingInterviewers.pop();

        pq.push(cow);
    }
}

int main() {
    cin >> N >> K;

    startTime.resize(N + 1, -1e9);
    timeRequired.resize(N + 1);
    interviewers.resize(N + 1, -1);
    result.resize(K + 1, false);
    for (int i = 1; i <= N; i++) {
        cin >> timeRequired[i];
    }

    for (int i = 1; i <= K; i++) {
        remainingInterviewers.push(i);
    }
    for (int i = 1; i <= N; i++) {
        remainingCows.push(i);
    }

    while (finalTime == -1) {
        fillQueue();
    }
    cout << finalTime << endl;

    for (int i = 1; i <= K; i++) {
        cout << (result[i] ? "1" : "0");
    }
    cout << endl;
}
