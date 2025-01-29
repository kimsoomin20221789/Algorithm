#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; int P; cin >> N >> P;

    priority_queue<int> pq[300003];
    long long cnt = 0;
    for (int i=0; i<N; i++) {
        int a; int b; cin >> a >> b;
        int isInLoop = true;
        while (isInLoop) { 
            if (pq[a].empty()) {
                cnt++;
                pq[a].push(b);
                isInLoop = false;
            } else {
                auto x = pq[a].top();
                if (x == b) {
                    isInLoop = false;
                } else if ( x < b) {
                    cnt++;
                    pq[a].push(b);
                    isInLoop = false;
                } else {
                    cnt++;
                    pq[a].pop();
                }
            }
        }
    }
    cout << cnt;
}