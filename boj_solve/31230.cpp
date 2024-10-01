#include <bits/stdc++.h>
#define INF 987654321
#define X first
#define Y second
using namespace std;

int N; int M; int A; int B;
vector<pair<int, int> > dist[200005];
pair<long long, vector<int>> minDist[200005];
priority_queue<pair<long long, int> > pq;
set<int> s;

void dfs(int st) {
    if (st == A) {return;}
    for (auto cur : minDist[st].Y) {
        s.insert(cur);
        dfs(cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> A >> B;


    for (int i=0; i<M; i++) {
        int a; int b; int c; cin >> a >> b >> c;
        dist[a].push_back({b,c});
        dist[b].push_back({a,c});
    }

    // fill(minDist, minDist+N+1, INF);
    for (int i=1; i<=N; i++) {
        minDist[i].X = INF;
    }
    
    minDist[A].X = 0;
    minDist[A].Y.push_back(A);
    pq.push({0, A});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.X != minDist[cur.Y].X) continue;
        for (auto nxt : dist[cur.Y]) {
            if (minDist[nxt.X].X > nxt.Y + cur.X) {
                // minDist[nxt.X] = {nxt.Y + cur.X, cur.Y};
                if (minDist[nxt.X].Y.size() != 0) {
                    minDist[nxt.X].Y.pop_back();
                }
                // minDist[nxt.X].Y.pop_back();
                minDist[nxt.X].X = nxt.Y+cur.X;
                minDist[nxt.X].Y.push_back(cur.Y);
                pq.push({minDist[nxt.X].X, nxt.X});
            } else if (minDist[nxt.X].X == nxt.Y + cur.X) {
                minDist[nxt.X].X = nxt.Y+cur.X;
                minDist[nxt.X].Y.push_back(cur.Y);
                pq.push({minDist[nxt.X].X, nxt.X});
            }
        }
    }

    dfs(B);
    s.insert(B);
    set <int>::iterator it;
    cout << s.size() << "\n";
    for (it = s.begin(); it != s.end(); ++it){
        cout << *it << " ";
    }

}