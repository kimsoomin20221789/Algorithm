#include <bits/stdc++.h>
using namespace std;
int arr[110];
bool visited[110];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; int m; cin >> n >> m;

    for (int i=0; i<n+m; i++) {
        int a; int b; cin >> a >> b;
        arr[a] = b;
    }

    queue<pair<int, int> > q;
    q.push({1, 0});
    visited[1]= 1;
    int currentBoard; 
    int currentTotal;

    while (!q.empty()) {
        currentBoard = q.front().first;
        currentTotal = q.front().second;
        if (currentBoard == 100) {
            break;
        }
        q.pop();
        // 
        for (int i=1; i<=6; i++) {
            int newBoard = currentBoard+i;
            if (visited[newBoard] || newBoard > 100) {continue;}
            //

            if (arr[newBoard] == 0) {
                q.push({newBoard, currentTotal+1});
            } else {
                // int beforeBoard = newBoard;
                newBoard = arr[newBoard];
                // if (beforeBoard < newBoard) {
                    q.push({newBoard, currentTotal+1});
                // }
            }
            visited[newBoard] = true;
        }
    }
    cout << currentTotal;
}