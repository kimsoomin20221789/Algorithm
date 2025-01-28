#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll arr[1025][1025];

ll answer(int x1, int y1, int x2, int y2) {
    return arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N; 
    int M; cin >> M;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int x;
            cin >> x;
            arr[i][j] = arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1] + x;
        }
    }

    for (int i=0; i<M; i++) {
        int x1; int y1; int x2; int y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << answer(x1, y1, x2, y2) << "\n";
    }
}