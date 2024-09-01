#include <bits/stdc++.h>
using namespace std;
int visited[100][100] = {0,};
int N;
int cnt = 0;

// last : 0 (위), 1 (아래), 2 (우측 상단), 3 (좌측 하단), 4 (좌측 상단), 5 (우측 하단)
int route[6][2] = {{-1, 0}, {1, 0}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
int lasts[6][2] = { {4, 2}, {3, 5}, {0, 5}, {1, 4}, {3, 0}, {2, 1} };

// arrow : 어떤 방향으로 여기에 왔는지.
void dfs(int arrow, int dis, int x, int y) {
    if (visited[x][y] == 1) {
        if (dis == N) {
            cnt++;
        }
        return;
    }

    if (dis > N) {
        return;
    }
    
    visited[x][y] = 1;
    for (int i=0; i<2; i++) {
        int newArrow = lasts[arrow][i];
        int nx =  x + route[newArrow][0];
        int ny = y + route[newArrow][1];
        if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100 ) {continue;}
        dfs(newArrow, dis+1, nx, ny);
    }
    visited[x][y] = 0;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    visited[50][50] = 1;

    dfs(0, 0, 49, 50);
    cout << cnt;
}