#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int v,e,st;

vector<pair<int, int>> adj[20005]; // 비용, 간선번호
const int INF = 987654321;
int d[20005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e >> st;
    fill(d, d+v+1, INF);

    for (int i=0; i<e; i++) {
        int a; int b; int c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
    greater<pair<int, int>>> pq;

    d[st] = 0;

    pq.push({d[st], st});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        // 이미 최소값이라고 지정된 곳 (이미 fix 된 곳)
        if (d[cur.Y] != cur.X) continue;

        // fix 되지 않았을 때 -> 업데이트 시킴
        for (auto nxt : adj[cur.Y]) {
            // 새롭게 업데이트 시킨 값이 더 클 때 -> 기존 값 그대로!
            if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            // 새롭게 업데이트 시킨 값이 더 작을 때 => 업데이트!
            d[nxt.Y] = d[cur.Y] + nxt.X;
            // 우선순위큐에도 새로운 값들 넣어주기
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    for (int i=1; i<=v; i++) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
}



// ============시간초과 나는 기본 다익스트라 풀이법 ==============

// vector<pair<int, int>> adj[30005]; // 비용, 간선번호
// #define X first
// #define Y second
// const int INF = 0x3f3f3f3f;
// bool fix[30005];
// int d[30005];
// int V; int E;

// void dijkstra_naive(int st) {
//     fill(d, d+V+1, INF);
//     d[st] = 0;

//     while (true) {
//         int idx = -1;
//         // 최소 값 찾기.
//         for (int i=1; i<=V; i++) {
//             if(fix[i]) continue;
//             if (idx == -1) idx = i;
//             else if (d[i] < d[idx]) idx = i;
//         }

//         // 다 방문했으면
//         if (idx == -1 || d[idx] == INF)
//             break;
        
//         // 방문 체크
//         fix[idx] = 1;

//         // 방문한 노드 기준 거리 업데이트
//         for (auto nxt : adj[idx]) {
//             d[nxt.Y] = min(d[nxt.Y], d[idx] + nxt.X);
//         }

//     }
// }

// int main() {
//     cin.tie(0);
//     ios::sync_with_stdio(0);

//     cin >> V >> E;

//     int st; cin >> st;

//     for (int i=0; i<E; i++) {
//         int a; int b; int c; cin >> a >> b >> c;
//         adj[a].push_back({c, b});
//     }

//     dijkstra_naive(st);

//     for (int i=1; i<=V; i++) {
//         if (d[i] == INF) {
//             cout << "INF" << "\n";    
//         } else {
//             cout << d[i] << "\n";
//         }
//     }
// }