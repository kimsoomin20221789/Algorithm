#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[1000000];
int pre[1000000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    pre[2] = 1;
    pre[3] = 1;
    vector<int > v;
    v.push_back(N);
    for (int i=4; i<=N; i++) {
        dp[i] = LLONG_MAX;
        if (i%3 == 0) {
            if (dp[i/3] + 1 < dp[i]) {
                dp[i] = dp[i/3] + 1;
                pre[i] = i/3;
                v.push_back(i/3);
            }
        }
        if (i%2 == 0) {
            if (dp[i/2] + 1 < dp[i]) {
                dp[i] = dp[i/2] + 1;
                pre[i] = i/2;
            }
        }
        if (dp[i-1] + 1 < dp[i]) {
            dp[i] = min(dp[i-1] + 1, dp[i]);
            pre[i] = i-1;
        }
    }

    cout << dp[N] << "\n";
    int cur = N;
    while (cur != 1) {
        cout << cur << " ";
        cur = pre[cur];
    }
    cout << cur;
}