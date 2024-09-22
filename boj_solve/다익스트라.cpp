#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ads[20005]; // 비용, 간선번호
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
bool fix[20005];
int d[20005];
int V = 10;

void dijkstra_naive(int st) {
    fill(d, d+V+1, INF);
    d[st] = 0;

    while (true) {
        int idx = -1;
        // 최소 값 찾기.
        for (int i=1; i<=V; i++) {
            if(fix[i]) continue;
            if (idx == -1) idx = i;
            else if (d[i] < d[idx]) idx = i;
        }

        // 다 방문했으면
        if (idx == -1 || d[idx] == INF)
            break;
        
        // 방문 체크
        fix[idx] = 1;

        // 방문한 노드 기준 거리 업데이트
        for (auto nxt : ads[idx]) {
            d[nxt.Y] = min(d[nxt.Y], d[idx] + nxt.X);
        }

    }
}