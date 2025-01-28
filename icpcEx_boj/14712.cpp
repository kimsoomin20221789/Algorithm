#include <bits/stdc++.h>
using namespace std;

int arr[25][25];
int N; int M; 
int total;
int answer = 0;
void checking() {
    for (int i=0; i<N-1; i++) {
        for (int j=0; j<M-1; j++) {
            if (arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1]){
                return;
            }
        }
    }
    answer++;
}
void backTrack(int cnt) {
    if (cnt == total) {
        checking();
        return;
    }

    int x = cnt / M;
    int y = cnt % M;
    arr[x][y] = 1;
    backTrack(cnt+1);
    arr[x][y] = 0;
    backTrack(cnt+1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    total = N*M;
    backTrack(0);
    cout << answer;
    
}