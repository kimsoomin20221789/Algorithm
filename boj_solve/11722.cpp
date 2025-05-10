#include <bits/stdc++.h>
using namespace std;

vector<int> dp[1003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    
    for (int i=0; i<N; i++) {
        int x; cin >> x;
        dp[i].push_back(x);
        bool isUpdated = false;
        int maxVal = -1;
        for (int j=i-1; j>=0; j--) {
            if (dp[j][0] > x) {
                maxVal = max(maxVal, dp[j][1]);
                isUpdated = true;
            }
        }

        if (!isUpdated) {
            dp[i].push_back(1);
        } else {
            dp[i].push_back(maxVal + 1);
        }
    }

    int answer = dp[0][1];
    for (int i=1; i<=N-1; i++) {
        answer = max(dp[i][1], answer);
    }
    cout << answer;
}