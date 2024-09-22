#include <bits/stdc++.h>

using namespace std;
int dp[100003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;

    for (int i=1; i<=N; i++) {
        int k; cin >> k;
        if (i==0) {
            dp[i] = k;
        } else {
            dp[i] = max(dp[i-1]+k, k);
        }
    }

    int max_value = dp[1];
    for (int i = 2; i <= N; i++) {
        max_value = max(max_value, dp[i]);
    }

     cout << max_value;
}