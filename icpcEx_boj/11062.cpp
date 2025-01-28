#include<bits/stdc++.h>
using namespace std;

int t,n;
int card[1001];
// dp[i][j][k] = i부터 j까지 k 차례일때, 근우 점수의 최대값
int dp[1001][1001][2]; // 근우는 1, 명우는 0


// 카드가 l부터 r 까지 남아있을때, 근우 or 명우 의 차례가 되었을때 근우가 최대가 되도록 하는 전체값.
int recursive_game(int l, int r, bool turn) {
  if (dp[l][r][turn] != -1) return dp[l][r][turn];
  if(l==r) {
    if(turn) return dp[l][r][1] = card[l]; // 근우 차례라면 근우 점수
    else return dp[l][r][0] = 0; // 명우 차례라면 근우는 점수를 못 받음
  }


  if(turn) // 근우 차례 -> 근우 점수 최댓값
    // l부터 r까지 근우가 먼저 뽑을 차례인데 최대의 값.
    dp[l][r][1] = max(recursive_game(l+1,r,0)+card[l], recursive_game(l,r-1,0)+card[r]); // 각각 왼쪽, 오른쪽 카드 선택 시 결론적으로 근우 점수의 촤대 값 + 방금 뽑은 카드
  else // 명우 차례 -> 근우 점수 최솟값
    dp[l][r][0] = min(recursive_game(l+1,r,1), recursive_game(l,r-1,1)); // 각각 왼쪽, 오른쪽 카드 선택 시 결론적으로 근우 점수의 최솟 값


  return dp[l][r][turn]; // 그때의 근우 점수 반환
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while(t--) {
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<n; i++)
      cin >> card[i];
    cout << recursive_game(0,n-1,1) << '\n';
  }
}
