#include <bits/stdc++.h>
using namespace std;
char arr[503][503];
int N; int H; int D;
int ans = 987654321;
bool noAns = true;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[503][503] = {false};

void backTrack(int x, int y, int cnt, int u, int h) {
    if (visited[x][y]) return; 
    if (u == 0 && h == 0) {
        return;
    }
    
    visited[x][y] = true;
    int nu=u;
    int nh=h;
    if (arr[x][y] == 'E') {
        noAns = false;
        ans = min(cnt, ans);
        return;
    }

    if (arr[x][y] == 'U') {
        nu = D;
    }

    if (arr[x][y] == '.') {
        if (u != 0) {
            nu = u-1;
        } else {
            nh = h -1;
        }
    }

    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
            continue;
        } else {
            backTrack(nx, ny, cnt+1, nu, nh);
            
        }
    }
    visited[x][y] = false; 
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> H >> D;
    pair<int, int> st;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            char k;
            cin >> k;
            if (k == 'S') {
                st.first = i;
                st.second = j;
            }
            arr[i][j] = k;
        }
    }

    backTrack(st.first, st.second, 0, 0, H);

    if (noAns) {
        cout << -1;
    } else {
        cout << ans;
    }
}