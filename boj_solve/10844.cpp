// key 포인트
// 1. 모듈러 연산을 미리해서 더하거나 모든값을 더하고 모듈러 연산을 진행하거나 결과는 같다.
// 2. 정수형 오버플로우 계산 잘하기
//    - int = 4B -> 32 bit -> 2^31 -> -> 10^9 + a 까지
//    - long long = 8B -> 64bit -> 2^63 -> 10^18 + a 까지


#include <bits/stdc++.h>
using namespace std;

long long dp[103][10];
const int MOD = 1000000000;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i=1; i<10; i++) {
        dp[1][i] = 1;
    }

    int N; cin >> N;
    // dp[i][j] = i자리의 수에 나오는 j의 번수.
    for (int i=2; i<=N; i++) {
        for (int j=0; j<10; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][1] % MOD;
            } else if (j == 9) {
                dp[i][j] = dp[i-1][8] % MOD;
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] % MOD;
            }
        }
    }

    long long cnt = 0;
    for (int i=0; i<10; i++) {
        cnt = (cnt + dp[N][i]) % MOD;
    }

    cout << cnt % MOD;
}