/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17258                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: lucy1382 <boj.kr/u/lucy1382>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17258                          #+#        #+#      #+#    */
/*   Solved: 2025/05/10 20:24:00 by lucy1382      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int dp[303][303]; 
// dp[a][b] : a의 구간에서 남은 친구의 수가 b일때 욱제가 있을 수 있는 최대시간
// dp[a][b] = 현재 친구를 투입했을때(뒤에서 그친구를 사용할 수 있음.) vs 현재 친구를 투입 안했을때(뒤에서는 사용할 수 있는 친구도 없음!!)
// dp[a][b] = max(dp[a+1][b-현재 사용한 친구 수], dp[a+1][b] )


vector<pair<int, int> > v; 
// first : 구간의 시간, second : 구간에 들어있는 사람 수

// 욱재가 현재 위치에서 remainFriends만큼 사용할 수 있고 전에서도 있었던 친구가 preFriends만큼 있을때
// 욱재의 최대시간.
int n, m, k, t, a, b, cnt[301];

int wookJaeMaxTime(int hereLocation, int remainFriends, int preFriends) {
    if (hereLocation == v.size()) {
        return 0;
    }
    if(dp[hereLocation][remainFriends]) return dp[hereLocation][remainFriends];

    int needFriends = t - v[hereLocation].second - preFriends;

    if (needFriends <= 0) {
        needFriends = 0;
    }


    // 이게 안되는 이유 = usedFriends가 불가능할 때는 그 구간 자체가 포함되면 안됨.
    // 주석코드는 불가능할때 그 구간을 넣는 경우와 비교해서 안넣는 경우를 비교하기때문에 틀림.
    
    // int usedFriends = needFriends > remainFriends ? 0 : needFriends;
    // return dp[hereLocation][remainFriends] = 
    //     max(wookJaeMaxTime(hereLocation+1, remainFriends-usedFriends, usedFriends) +v[hereLocation].first,
    //         wookJaeMaxTime(hereLocation+1, remainFriends, 0)
    //     );


    int usedFriends = needFriends > remainFriends ? -1 : needFriends;

    if (usedFriends == -1)
    return dp[hereLocation][remainFriends] = wookJaeMaxTime(hereLocation+1, remainFriends, 0);

    return dp[hereLocation][remainFriends] = 
        max(wookJaeMaxTime(hereLocation+1, remainFriends - usedFriends, needFriends) + v[hereLocation].first,
            wookJaeMaxTime(hereLocation+1, remainFriends, 0));

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> t; 
    
    for(int j = 0; j < m; j++){
        cin >> a >> b; 
        for(int i = a; i < b; i++)cnt[i] = min(t, ++cnt[i]);
    }
    int temp = cnt[1]; 
    int _count = 1; 
    for(int i = 2; i <= n; i++){  
        if(temp != cnt[i]){ 
            v.push_back(make_pair(_count, temp));  
            _count = 0; 
            temp = cnt[i];
        }
        _count++;
    }

    v.push_back(make_pair(_count, temp));
    cout << wookJaeMaxTime(0, k, 0) << "\n"; 
    return 0; 
}