#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int prev[3] = {0, 0, 0};
    int prev2[3] = {0, 0, 0};
    int cur[3];
    int cur2[3];
    for (int i=0; i<n; i++) {
        int a; int b; int c; cin >> a >> b >> c;
        cur[0] = min(prev[0], prev[1]) + a;
        cur2[0] = max(prev2[0], prev2[1]) + a;

        cur[1] = min(prev[0], prev[1]);
        cur[1] = min(cur[1], prev[2]);
        cur[1] = cur[1] + b;

        cur2[1] = max(prev2[0], prev2[1]);
        cur2[1] = max(cur2[1], prev2[2]);
        cur2[1] = cur2[1] + b;

        cur[2] = min(prev[1], prev[2]) + c;
        cur2[2] = max(prev2[1], prev2[2]) + c;

        prev[0] = cur[0];
        prev[1] = cur[1];
        prev[2] = cur[2];

        prev2[0] = cur2[0];
        prev2[1] = cur2[1];
        prev2[2] = cur2[2];
    }

    int  answer = max(cur2[0], cur2[1]);
    cout << max(answer, cur2[2]) << " ";

    answer = min(cur[0], cur[1]);
    cout << min(answer, cur[2]);

    
}