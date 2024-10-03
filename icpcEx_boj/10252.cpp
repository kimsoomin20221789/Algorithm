#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    
    while (T--) {
        int m; int n; cin >> m >> n;
        cout << "1\n";

        for (int i=0; i<m; i++) {
            cout << "(0," << i << ")\n";
        }

        for (int i=1; i<n; i++) {
            // 홀수일때
            if (i&1) {
                for (int j=(m-1); j>=1; j--) {
                    cout << "(" << i << "," << j << ")\n";
                }
            } else {
                for (int j=1; j<m; j++) {
                    cout << "(" << i << "," << j << ")\n";
                }
            }
        }
        //첫번째 열 출력
        for (int i=(n-1); i>=1; i--) cout << "(" << i << ",0)\n";
    }
}