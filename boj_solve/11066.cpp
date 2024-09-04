#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int dp[503][503];
int sum[503];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int a; cin >> a;
        sum[0] = 0;
        for (int j=1; j<=a; j++) {
            int x;
            cin >> x;
            sum[j] = sum[j-1] + x;
        }

        // dp 수행
        for (int l=1; l<a; l++) {
            for (int k=1; k+l<=a; k++) {
                dp[k][k+l] = INF;

                for (int p=k; p<k+l; p++) {
                    dp[k][k+l] = min(dp[k][k+l], dp[k][p] + dp[p+1][k+l] + (sum[k+l]-sum[k-1]));
                }
            }
        }
        
        cout << dp[1][a] << "\n";
    }
}