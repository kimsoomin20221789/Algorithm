#include <iostream>
#define X first
#define Y second
using namespace std;
using ll = long long;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[100][100];

int main() {
    int N; int K; cin >> N >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            board[i][j] = 0;
        }
    }
    for (int i=0; i<K; i++) {
        int x; int y; cin >> x >> y;
        board[x-1][y-1] = 2;
    }

    pair<int, int> cur = {0,0};
    board[cur.X][cur.Y] = 1;
    int k; cin >> k;
    char C;
    int curDirection = 1;
    int answer = 0;
    for (int i=0; i<k; i++) {
        int X; cin >> X;
        for (int j=0; j<X; j++) {
            answer++;
            cur = {cur.X + dx[curDirection], cur.Y + dy[curDirection]};
            // if (cur.X < 0 || cur.X >= N; cur.Y < 0 || cur.Y >= N || board[cur.X][cur.Y] == 1) break;

        }
    }
}