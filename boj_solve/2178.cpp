#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
// int maze[100][100];
string maze[100]; //공백이 없을 경우 String 처리하기
int vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N; int M; cin >> N >> M;
    for (int i=0; i<N; i++){
        cin >> maze[i];
        fill(begin(vis[i]), begin(vis[i]) + M, -1);
        // int vis[100][100] = {-1};로 할경우
    }

    queue<pair<int, int> > Q;
    Q.push({0,0});
    vis[0][0] = 0;

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int i=0; i<4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx >=N || ny >= M || nx < 0 || ny < 0) continue;
            if (vis[nx][ny] != -1 || maze[nx][ny] == '0') continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << vis[N-1][M-1] + 1;
}