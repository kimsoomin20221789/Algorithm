#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
vector<pii> busTime[6003];
ll dist[6003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V; int E; cin >> V >> E;

    for (int i=0; i<E; i++) {
        int a; int b; int c; cin >> a >> b >> c;
        busTime[a].push_back({b, c});
    }

    // 벨만포드
    fill(dist, dist + V + 1, LLONG_MAX);
    dist[1] = 0;
    bool negativeCycle = false;

    for (int n=1; n<=V; n++) {
        for (int i=1; i<=V; i++) {
            for (auto x : busTime[i]) {
                int nxtVertex = x.first;
                int nxtEdge = x.second;

                if ((dist[nxtVertex] > nxtEdge + dist[i]) && (dist[i] != LLONG_MAX) ) {
                    dist[nxtVertex] =nxtEdge + dist[i];
                }
            }
        }
    }


    for (int i=1; i<=V; i++) {
        for (auto x : busTime[i]) {
            int nxtVertex = x.first;
            int nxtEdge = x.second;

            if ((dist[nxtVertex] > nxtEdge + dist[i]) && (dist[i] != LLONG_MAX) ) {
                negativeCycle = true;
            }
        }
    }

    if (negativeCycle) {
        cout << -1;
    } else {
        for (int i=2; i<=V; i++) {
            if (dist[i] == LLONG_MAX) {
                cout << -1 << "\n";
            } else {
                cout << dist[i] << "\n";
            }
        }
    }

}