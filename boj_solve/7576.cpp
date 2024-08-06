#include <bits/stdc++.h>
using namespace std;
#define x first;
#define y second;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
int board[1000][1000];
int dist[1000][1000];
int M; int N;
vector<pair<int, int> > st;
void bfs(){
    queue<pair<int,int> > Q;
    for (int i=0; i<st.size(); i++){
        pair<int, int> vt = st.at(i);
        Q.push(vt);
        dist[vt.first][vt.second] = 0;
    }
    while (!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // 범위 밖일 경우 넘어감
            if(dist[nx][ny]>=0 || board[nx][ny] != 0) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            
            board[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            Q.push(make_pair(nx,ny));
        }
     }
}

int main(){
    int cnt;
    cin >> M >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> board[i][j];
            if (board[i][j] == 1){
                st.push_back(make_pair(i,j));
            }
            if (board[i][j] == 0){
                cnt++;
            }
        }
    }
    if (cnt == 0){
        cout << 0; return 0;
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            dist[i][j] = -1;
        }
    }
    bfs();
    int ans = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (board[i][j] == 0){
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]); //??
        }
    }
    cout << ans;
}
