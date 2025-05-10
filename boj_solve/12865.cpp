/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12865                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: lucy1382 <boj.kr/u/lucy1382>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12865                          #+#        #+#      #+#    */
/*   Solved: 2025/05/08 16:20:10 by lucy1382      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;
pair<int, int> val[103];

int dp[103][100003];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; int K; cin >> N >> K;

    for (int i=0; i<N; i++) {
        int a; int b; cin >> a >> b;
        val[i] = {a,b};
    }

    for (int i = 0; i < N; i++) {
        for (int j=0; j<=K; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-val[i].first][j] + val[i].second);
        }
    }
    

    cout << dp[N-1][K];
}