#include <bits/stdc++.h>
using namespace std;
long long arr[100003][2];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    for (int i=0; i<N; i++) {
        arr[i][0] = LLONG_MAX;
        arr[i][1] = LLONG_MAX;
    }

    vector<int> crossVec;

    for (int i=0; i<N; i++) {
        int x; cin >> x;
        crossVec.push_back(x);
    }

    vector<int> leftVec;
    long long leftTotal = 0;
    for (int i=0; i<N-1; i++) {
        int x; cin >> x;
        leftVec.push_back(x);
    }

    vector<int> rightVec;
    long long rightTotal = 0;
    for (int i=0; i<N-1; i++) {
        int x; cin >> x;
        rightVec.push_back(x);
        rightTotal+=x;
    }

    long long realAnswer = LLONG_MAX;
    int answerPot = -1;
    for (int i=0; i<N; i++) {
        long long answer = 0;
        answer+=crossVec[i];
        if (!(i-1<0 || i-1>=N)) {
            rightTotal -= rightVec[i-1];
            leftTotal += leftVec[i-1];
        }
        answer = answer + rightTotal + leftTotal;
        if (answer < realAnswer) {
            realAnswer = answer;
            answerPot = i+1;
        }
    }

    cout << answerPot << " "<< realAnswer;
}