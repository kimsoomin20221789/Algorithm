#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
int R; int C;

string board[1000]; //장소
int p_dist[1000][1000];  // 사람 거리 배열
int f_dist[1000][1000]; //불 거리 배열
// pair<int, int> j_st;
// pair<int, int> f_st;
queue<pair<int, int> > Q_p;
queue<pair<int, int> > Q_f;
void input(){
    cin >> R >> C;
    for (int i=0; i<R; i++){
        cin >> board[i];
        for (int j=0; j<C; j++){
            if (board[i][j] == 'F'){
                Q_f.push(make_pair(i, j));
                f_dist[i][j] = 1;
            } else if (board[i][j] == 'J'){
                Q_p.push(make_pair(i, j));
                p_dist[i][j] = 1;
            }
        }
    }
}

void bfs_fire(){
    //q를 넣고 빼고를 빌때까지
    //조건 1. 범위 넘어가면 안됨
    //조건 2. 주변이 벽이거나 거리가 0이 아니면 안됨.

    while (!Q_f.empty()){
        pair<int, int> cur = Q_f.front();
        Q_f.pop();
        for (int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx<0 || nx>=R || ny<0 || ny>=C) continue;
            if (board[nx][ny] == '#' || f_dist[nx][ny] != 0) continue;
            f_dist[nx][ny] = f_dist[cur.first][cur.second] + 1;
            Q_f.push(make_pair(nx, ny));
        }
    }


}

void bfs_person(){
    //q를 넣고 빼고를 빌때까지->impossible 
    //조건1. 불이 이미 왔던 거리,
    while (!Q_p.empty()){ 
        pair<int, int> cur = Q_p.front();
        Q_p.pop();
        for (int i=0; i<4; i++){
            if (cur.first == 0 || cur.first==R-1 || cur.second == 0 || cur.second == C-1){
                cout << p_dist[cur.first][cur.second];
                return;
            }
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (board[nx][ny] == 'F' || p_dist[nx][ny] != 0 || board[nx][ny] == '#' || (f_dist[nx][ny]!=0 && f_dist[nx][ny]<=p_dist[cur.first][cur.second]+1)) continue;
            if (nx==0 || nx==R-1 || ny==0 || ny==C-1){
                cout << p_dist[cur.first][cur.second]+1;
                return;
            }
            p_dist[nx][ny] = p_dist[cur.first][cur.second] + 1;
            Q_p.push(make_pair(nx, ny));
        }
    }
    
    cout << "IMPOSSIBLE";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    bfs_fire();
    bfs_person();
}