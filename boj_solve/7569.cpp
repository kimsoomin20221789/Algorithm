#include <bits/stdc++.h>
#include <tuple>
#include <cstdio>
using namespace std;

int dz[6] = {1,0,0,-1,0,0};
int dx[6] = {0,1,0,0,-1,0}; 
int dy[6] = {0,0,1,0,0,-1};
int board[100][100][100];
int dist[100][100][100];
int M; int N; int H;
vector<tuple<int, int, int> > start;
void bfs(){
    queue<tuple<int,int,int> > Q;
    for (int i=0; i<start.size(); i++){
        tuple<int, int, int> vt = start.at(i);
        Q.push(vt);
        dist[get<0>(vt)][get<1>(vt)][get<2>(vt)] = 0;
    }
    while (!Q.empty()){
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        for (int dir=0; dir<6; dir++){
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
            if(dist[nz][nx][ny]>=0 || board[nz][nx][ny] != 0) continue; 
            board[nz][nx][ny] = 1;
            dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] +1;
            Q.push(make_tuple(nz, nx, ny));
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> H;
    int cnt = 0;
    for (int h=0; h<H; h++){
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                cin >> board[h][i][j];
                if (board[h][i][j] == 1){
                    start.push_back(make_tuple(h, i, j));
                }
                if (board[h][i][j] == 0){
                    cnt++;
                }
            }
        }
    }

    if (cnt == 0){
        cout << 0;
        return 0;
    }

    for (int h=0; h<H; h++){
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                dist[h][i][j] = -1;
            }
        }
    }

    bfs();

    int ans = 0;

    for (int h=0; h<H; h++){
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                if (board[h][i][j] == 0){
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[h][i][j]);
            }
        }
    }

    cout << ans;

}