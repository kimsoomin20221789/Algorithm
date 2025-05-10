#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;

    while (T--) {
        int N; int M; cin >> N >> M;

        int totalVal[N][2];

        for (int i=0; i<N; i++) {
            totalVal[i][0] = 0;
            totalVal[i][1] = 0;
        }
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                int x; cin >> x;
                totalVal[i][0] += x;
                totalVal[j][1] += x;
            }
        }

        while (M--) {
            int r1; int c1; int r2; int c2; int v;
            cin >> r1 >> c1 >> r2 >> c2 >> v;
            for (int a = r1; a <= r2; a++) {
                totalVal[a-1][0] += v*(c2-c1+1);
            }

            for (int a = c1; a <= c2; a++) {
                totalVal[a-1][1] += v*(r2-r1+1);
            }
        }

        for (int i=0; i<N; i++) {
            cout << totalVal[i][0] << " ";
        }
        cout << "\n";

        for (int i=0; i<N; i++) {
            cout << totalVal[i][1] << " ";
        }
    }
}