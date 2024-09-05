#include <bits/stdc++.h>
using namespace std;

int val[503][503];
int dp[503][503];

int main() {
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            cin >> val[i][j];
        }
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + val[i][j];
        }
    }

    cout << *max_element(dp[N], dp[N]+504);
}