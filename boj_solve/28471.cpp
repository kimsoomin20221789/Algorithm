#include <bits/stdc++.h>
using namespace std;
char arr[2005][2005];
int dx[7] = {-1, -1, 0, 0, 1, -1, 1};
int dy[7] = {-1, 1, -1, 1, -1, 0, 1};
int vis[2005][2005];
int cnt = 0;
int N;


void dfs(int a, int b) {
    if (arr[a][b] == '.') { cnt++; vis[a][b] = 1;}

    for (int i=0; i<7; i++) {
        int nx = a+dx[i];
        int ny = b+dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || vis[nx][ny] || arr[nx][ny] == '#') {continue;}
        dfs(nx, ny);
    }

}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    int a; int b;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            char s;
            cin >> s;
            arr[i][j] = s;
            vis[i][j] = 0;
            if (s == 'F') {
                a = i; b = j;
            }
        }
    }
    dfs(a, b);
    cout << cnt;
}