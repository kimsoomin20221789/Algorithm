#include <bits/stdc++.h>
#define INF 987654321
#define X first
#define Y second
using namespace std;
int N; int M; int X;
vector<pair<int, int> > timeVal[10005];
int ans[10005];
int ans1[10005];
priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int, int>> > pq;

void goToHome(int st) {
    ans[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (ans[cur.Y] != cur.X) continue;

        for (auto nxt : timeVal[cur.Y]) {
            if (ans[nxt.X] > ans[cur.Y]+nxt.Y) {
                pq.push({ans[cur.Y]+nxt.Y, nxt.X});
                ans[nxt.X] = ans[cur.Y] + nxt.Y;
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;
    fill(ans, ans+N+1, INF);

    for (int i=0; i<M; i++) {
        int a; int b; int c;
        cin >> a >> b >> c;
        timeVal[a].push_back({b, c});
    }

    // 집갈때 시간
    goToHome(X);

    // 올때 
    for (int i=1; i<=N; i++) {
        fill(ans1, ans1+N+1, INF);
        ans1[i] = 0;
        pq.push({0, i});

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            // if (cur.Y == X) {
            //     ans[cur.Y] += cur.X; 
            //     pq = priority_queue<pair<int, int>, vector<pair<int,int>>,greater<pair<int, int>> >(); 
            //     break;
            // }
            if (!ans1[cur.Y] == cur.X) continue;

            for (auto nxt : timeVal[cur.Y]) {
                if (ans1[nxt.X] > ans1[cur.Y]+nxt.Y) {
                    pq.push({ans[cur.Y]+nxt.Y, nxt.X});
                    ans1[nxt.X] = ans1[cur.Y] + nxt.Y;
                }
            }
        }
        ans[i] += ans1[X];
    }

    int max_value = ans[1];
    for (int i = 2; i <= N; i++) {
        max_value = max(max_value, ans[i]);
    }
    cout << max_value;
}