#include<vector>
#include <queue>
#include <iostream>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int dist[5][5] = {{0}};
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<pair<int, int> > Q;
    Q.push(make_pair(0,0));
    int nx;
    int ny;
    dist[0][0] = 1;
    while (!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for (int dir=0; dir<4; dir++){
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];
            if (nx == 4 && ny == 4) {
                answer = dist[cur.first][cur.second] + 1;
                return answer;
            } // 이부분을 마지막에 처리하니까 에러가 발생 왜그러는지 이유 찾아보기
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if(dist[nx][ny]>0 || maps.at(nx).at(ny) == 0) continue;
            maps.at(nx).at(ny) = 0;
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            Q.push(make_pair(nx,ny));
        }
    }
 
    answer = -1;
    return answer;
}