#include <bits/stdc++.h>
using namespace std;
int N; int M;
vector<vector<int>> v;
int visited[1003][1003][2];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        vector<int> v1;
        for (int j=0; j<M; j++) {
            char x; cin >> x;
            v1.push_back(x-'0');
        }
        v.push_back(v1);
    }

    queue<vector<int>> q;
    // x, y, haveChance, count
    q.push({0,0,1,1});
    visited[0][0][1] = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur[0] == N-1 && cur[1] == M-1) {
            break;
        }

        for (int i=0; i<4; i++) {
            int nxtX = cur[0] + dx[i];
            int nxtY = cur[1] + dy[i];

            if (nxtX>=N || nxtX<0 || nxtY>=M || nxtY<0) {
                continue;
            }

            if (visited[nxtX][nxtY][cur[2]]) {
                continue;
            }

            if (v[nxtX][nxtY] == 0) {
                q.push({nxtX, nxtY, cur[2], cur[3]+1});
                visited[nxtX][nxtY][cur[2]] = cur[3]+1;
                // cout << nxtX << nxtY << visited[nxtX][nxtY] << "\n";
            } else {
                if (cur[2] == false) {
                    continue;
                } else {
                    q.push({nxtX, nxtY, 0, cur[3]+1});
                    visited[nxtX][nxtY][cur[2]] = cur[3]+1;
                    // cout << nxtX << nxtY << visited[nxtX][nxtY] << "\n";
                }
            }

        }
    }

    if (visited[N-1][M-1][0] || visited[N-1][M-1][1]) {
        cout << max(visited[N-1][M-1][0], visited[N-1][M-1][1]);
    } else {
        cout << -1;
    }
}