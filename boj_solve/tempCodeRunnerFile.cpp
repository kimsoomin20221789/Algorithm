#include <bits/stdc++.h>
using namespace std;

long long dp[103][10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i=1; i<10; i++) {
        dp[1][i] = 1;
    }

    int N; cin >> N;

    for (int i=2; i<=N; i++) {
        for (int j=0; j<10; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][1];
            } else if (j == 9) {
                dp[i][j] = dp[i-1][8];
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            }
        }
    }

    long long cnt = 0;
    for (int i=0; i<10; i++) {
        cnt += dp[N][i];
    }

    cout << cnt % 1000000000 ;
}