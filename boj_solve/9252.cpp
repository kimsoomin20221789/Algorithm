#include <bits/stdc++.h>
using namespace std;

string s1;
string s2;
int dp[1001][1001];

string answer = "";


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1;
    cin >> s2;

    int s1Length = s1.length();
    int s2Length = s2.length();
    // DP 배열 채우기
    for (int i = 1; i <= s1Length; i++) {
        for (int j = 1; j <= s2Length; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[s1Length][s2Length];
    int startX = s1Length;
    int startY = s2Length;

    while (!(startX == 0 || startY == 0)) {
        if (s1[startX-1] == s2[startY-1]) {
            answer += s1[startX-1];
            startX--;
            startY--;
        } else if (dp[startX-1][startY] > dp[startX][startY-1]) {
            startX--;
        } else {
            startY--;
        }
    }
    reverse(answer.begin(), answer.end());
    cout << answer;

}