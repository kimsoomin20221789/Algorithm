#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dividingValue = 1000000009;
ll dp[100003][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    int i=4;
    for (int i=4;  i<=100000; i++) {
        for (int j=1; j<=3; j++) {
            for (int k=1; k<=3; k++) {
                if (k==j || dp[i-j][k] == 0) {continue;}
                dp[i][j] += dp[i-j][k] % dividingValue;
            }
        }
    }

    for (int i=0; i<N; i++) {
        int x; cin >> x;
        int ans = 0;
        cout << (dp[x][1] + dp[x][2] + dp[x][3])%dividingValue << "\n";
    }
}
