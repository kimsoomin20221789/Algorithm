#include <bits/stdc++.h>
using namespace std;
long long dp[10003];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; int k;
    cin >> n >> k;

    vector<int> v;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    fill(dp, dp+k+1, INT_MAX);
    dp[0] = 0;
    for (int i=1; i<=k; i++) {  
        for (auto x : v) {
            if (i<x) {continue;}
            dp[i] = min(dp[i], dp[i-x] + 1);
        }
    }

    if (dp[k] == INT_MAX) {
        cout << -1;
    } else {
        cout << dp[k];
    }
}