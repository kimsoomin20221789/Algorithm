#include <bits/stdc++.h>
using namespace std;
vector<int> vp[100005];
vector<pair<int, int> > ans;
int prevX = 0;
bool comp(int a, int b) {
    return abs(prevX-a) < abs(prevX-b);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        for (int i=0; i<100005; i++) {
            vp[i].clear();
        }
        ans.clear();
        int n; cin >> n; // n : 카페 수
        int maxX = 0;
        while (n--) {
            int x; int y;
            cin >> x >> y;
            if (maxX < x) {
                maxX = x;
            }
            vp[x].push_back(y);
        }

        for (int i=0; i<=maxX; i++) {
            int cnt = vp[i].size();
            switch(cnt) {
                case 0:
                    break;
                case 1:
                    ans.push_back({i, vp[i][0]});
                    prevX = vp[i][0];
                    break;
                default: // 여러개있을때
                    sort(vp[i].begin(), vp[i].end(), comp);
                    for (int j=0; j<vp[i].size(); j++) {
                        ans.push_back({i, vp[i][j]});
                    }
                    prevX = vp[i][vp[i].size()-1];
                    break;
            }
            prevX = 0;
        }

        int m; cin >> m;
        while (m--) {
            int a; cin >> a;
            cout << ans[a-1].first << " " << ans[a-1].second << "\n";
        }
    }
}