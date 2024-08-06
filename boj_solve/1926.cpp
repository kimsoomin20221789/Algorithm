#include <queue>
#include <iostream>
using namespace std;
#define X first
#define Y second
int paper[500][500];
int vis[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    int n; int m; cin >> n >> m;
    queue<pair<int, int> > Q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> paper[i][j];
        }
    }
    int mx = 0;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (paper[i][j] == 1 && vis[i][j] == 0) {
                cnt++;
                int width = 1;
                Q.push({i, j});
                vis[i][j] = 1;
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); 
                    Q.pop();
                    for (int k=0; k<4; k++) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] == 1 || paper[nx][ny] == 0) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                        width++;
                    }
                }
                mx = max(mx, width);
            }
        }
    }
    cout << cnt << "\n" << mx;
}