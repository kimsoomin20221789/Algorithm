#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int arr[8][8] = {1};
vector<pair<int, int>> notVisited;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N; int M; 
int maxValue = -1;
int bfs(int arr[8][8]){
    int temp[8][8]; // 배열의 복사본을 만듦.
    memcpy(temp, arr, sizeof(temp));
    int cnt = 0;
    queue<pair<int, int> > Q;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (temp[i][j] == 2) {
                Q.push({i, j});
            } else { continue;}
        }
    }

    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int dir =0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny <0 || ny>=M) { continue;}
            if (temp[nx][ny] != 0 ) {continue;}
            temp[nx][ny] = 2;
            Q.push( {nx, ny} );
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (temp[i][j] == 0) {
                cnt++;
            }
        }
    }

    return cnt;
}

void backTracking(int n, pair<int, int> p, int arr[8][8]) {

    if (n == 4) {
        maxValue = max(maxValue, bfs(arr));
        return;
    }

    for (int i=p.X; i<N; i++) {
        for (int j=(i==p.X?p.Y:0); j<M; j++) { //!!
            if (arr[i][j] == 0 ){
                arr[i][j] = 1;
                backTracking(n+1, {i, j+1}, arr);
                arr[i][j] = 0;
            }
        }
    }
}

int main(){
    cin >> N; cin >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    backTracking(1, {0,0}, arr);
    cout << maxValue;
}