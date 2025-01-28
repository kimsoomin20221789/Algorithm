#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[203][203];
int cnt[203][203][53];
vector<pair<pair<int, int>, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h; int w; int n;
    cin >> h >> w;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a; int b; int c;
        cin >> a >> b >> c;
        v.push_back({{a,b}, c});
    }

    for (int a = 1; a <= h; a++) {
        for (int b = 1; b <= w; b++) {

            if (dp[a-1][b] < dp[a][b-1]) {
                dp[a][b] = dp[a][b-1];
                for (int i=0; i<n; i++) {
                    cnt[a][b][i] = cnt[a][b-1][i];
                }
            } else {
                dp[a][b] = dp[a-1][b];
                for (int i=0; i<n; i++) {
                    cnt[a][b][i] = cnt[a-1][b][i];
                }
            }
            
            int k=0;
            for (auto i : v) {
                int x = i.first.first;
                int y = i.first.second;
                int val = i.second;
                if (x <= a && y <= b) {
                    if (dp[a][b] < val+dp[x][b-y]+dp[a-x][b]) {
                        dp[a][b] = val+dp[x][b-y]+dp[a-x][b];
                        for (int p = 0; p < n; p++) {
                            if (p == k) {
                                cnt[a][b][k] = 1+cnt[x][b-y][k]+cnt[a-x][b][k];
                            } else {
                                cnt[a][b][p] = cnt[x][b-y][p]+cnt[a-x][b][p];
                            }
                        }

                    } else if (dp[a][b] < val+dp[a-x][y]+dp[a][b-y]) {
                        dp[a][b] = val+dp[a-x][y]+dp[a][b-y];
                        for (int p = 0; p < n; p++) {
                            if (p == k) {
                                cnt[a][b][k] = 1+cnt[a-x][y][k]+cnt[a][b-y][k];
                            } else {
                                cnt[a][b][p] = cnt[a-x][y][p]+cnt[a][b-y][p];
                            }
                        }
                    } else if (dp[a][b] == val+dp[x][b-y]+dp[a-x][b]) {
                        int ex1 = 0;
                        int ex2 = 0;
                        for (int p = 0; p < n; p++) {
                            ex1 += cnt[a][b][p];
                            ex2 += cnt[x][b-y][p]+cnt[a-x][b][p];
                        }
                        if (ex1 < ex2+1) {
                            for (int p = 0; p < n; p++) {
                                if (p == k) {
                                    cnt[a][b][k] = 1+cnt[a-x][y][k]+cnt[a][b-y][k];
                                } else {
                                    cnt[a][b][p] = cnt[a-x][y][p]+cnt[a][b-y][p];
                                }
                            }
                        }
                    } else if (dp[a][b] == val+dp[a][b-y]+dp[a-x][y]) {
                        int ex1 = 0;
                        int ex2 = 0;
                        for (int p = 0; p < n; p++) {
                            ex1 += cnt[a][b][p];
                            ex2 += cnt[a][b-y][p]+cnt[a-x][y][p];
                        }
                        if (ex1 < ex2+1) {
                            for (int p = 0; p < n; p++) {
                                if (p == k) {
                                    cnt[a][b][k] = 1+cnt[a-x][b][k]+cnt[x][b-y][k];
                                } else {
                                    cnt[a][b][p] = cnt[a-x][b][p]+cnt[x][b-y][p];
                                }
                            }
                        }
                    }
                }
                k++;
            }
        }
    }

    // for (int i=1; i<=h; i++) {
    //     for (int j=1; j<=w; j++) {
    //         cout << dp[i][j];
    //     }
    //     cout << "\n";
    // }

    // for (int i=1; i<=h; i++) {
    //     for (int j=1; j<=w; j++) {
    //         cout << cnt[i][j][0];
    //         cout << cnt[i][j][1];
    //         cout << cnt[i][j][2];
    //     }
    //     cout << "\n";
    // }
    
    cout << dp[h][w] << "\n";
    for (int i=0; i<n; i++) {
        cout << cnt[h][w][i] << " ";
    }

}