#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0)


int main() {
    fastio;
    int N; int M; cin >> N >> M;

    vector<int> dist(N+3, 987654321);
    vector<int> v[1003];

    for (int i=0; i<M; i++) {
        int x; int y; cin >> x >> y;
        v[y].push_back(x);
    }
    
    for (int cnt=1; cnt<=N; cnt++) {
        for (int i=1; i<=N; i++) {
            if (dist[i] < cnt) {
                continue;
            }
            bool isCompleted = true;
            for (auto x : v[i]) {
                if (dist[x] >= cnt) {
                    isCompleted = false;
                    break;
                }
            }
            
            if (isCompleted) {
                dist[i] = cnt;
            }
        }
    }

    for (int i=1; i<=N; i++) {
        cout << dist[i] << " ";
    }
}