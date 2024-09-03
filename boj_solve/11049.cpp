#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N; 
int dp[503][503];
int row[503];
int col[503];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i=1; i<=N; i++) {
        cin >> row[i];
        cin >> col[i];
    }

    for (int i=1; i<=N-1; i++) {
        for (int j=1; j+i<=N; j++) {
            dp[j][j+i] = INF;
            for (int p=0; p<i; p++) {
                dp[j][j+i] = min(dp[j][j+i], (dp[j][j+p] + dp[j+p+1][j+i] + row[j]*col[j+p]*col[j+i]));
            }
        }
    }

    cout << dp[1][N];
}