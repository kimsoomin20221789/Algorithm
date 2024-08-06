#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int w; int h;
int graph[50][50];
bool visited[50][50];
int numberOfLand = 0;

int dw[8] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
int dh[8] = { 0, 1, 0 , -1, -1, 1,-1, 1 };


void dfs(int h, int w){
    visited[h][w] = 1;
    for (int i=0; i<8; i++){
        int nh = h + dh[i];
        int nw = w + dw[i];
        //dfs조건(깊게 들어가는 조건) : 8개의 방향이 간선이라고 생각하고, 
        //그때 간선의 점이 1이고 visited가 아닐때 깊이 들어감!
        if (0 <= nw && 0 <= nh && nw < 50 && nh < 50){
            if (graph[nh][nw] == 1 && !visited[nh][nw]){
                visited[nh][nw] = true;
                dfs(nh, nw);
            }
        }
    }
}

int main(void){
    while (1){
        cin >> w >> h;
        if (!w && !h) break;
        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++){
                cin >> graph[i][j];
            }
        }

        //===============
        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++){
                if (graph[i][j]==1 && !visited[i][j]){
                    numberOfLand++;
                    dfs(i, j); //bfs돌면서 visited바꿔주기 == 방문하기
                }
            }
        }
        cout << numberOfLand << "\n";
 
        /* 그래프 및 방문기록, 섬의 개수 초기화 */
        memset(graph, false, sizeof(graph));
        memset(visited, false, sizeof(visited));
        numberOfLand = 0;

    }


}