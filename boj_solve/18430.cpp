#include <bits/stdc++.h>
using namespace std;
int N; int M;
int arr[5][5];
long long ans = 0;
bool visited[5][5];
int dx[4][2] = {{1,0}, {-1, 0}, {-1,0}, {1,0}};
int dy[4][2] = {{0,-1}, {0, -1}, {0,1}, {0, 1}};

vector<int> big;
vector<int> small;

void check() {
    long long total = 0;
    for (int i = 0; i<big.size(); i++) {
        total += 2*big[i];
    }
    for (int i = 0; i<small.size(); i++) {
        total += small[i];
    }
    ans = max(total, ans);
}


void backTrack(int x, int y) {
    if (x == N || y == M) {
        check();
        return;
    }
    int nx = x, ny = y + 1;
    if (ny == M) {
        nx = x + 1;
        ny = 0;
    }
    for (int k = 0; k<4; k++) {
        int nx1 = x + dx[k][0];
        int nx2 = x + dx[k][1];
        int ny1 = y + dy[k][0];
        int ny2 = y + dy[k][1];

        if (nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= M || nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= M) {continue;}
        if (!visited[x][y] && !visited[nx1][ny1] && !visited[nx2][ny2]) {
            visited[x][y] = 1;
            visited[nx1][ny1] = 1;
            visited[nx2][ny2] = 1;
            big.push_back(arr[x][y]);
            small.push_back(arr[nx1][ny1]);
            small.push_back(arr[nx2][ny2]);

            backTrack(nx, ny);
            
            visited[x][y] = 0;
            visited[nx1][ny1] = 0;
            visited[nx2][ny2] = 0;

            big.pop_back();
            small.pop_back();
            small.pop_back();
        }
    }
    backTrack(nx, ny);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }


    backTrack(0, 0);
    memset(visited, false, sizeof(visited));
    cout << ans;
}