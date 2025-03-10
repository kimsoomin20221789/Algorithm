#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; int P; cin >> N >> P;

    priority_queue<pii> pq;
    long long cnt = 0;
    for (int i=0; i<N; i++) {
        int a; int b; cin >> a >> b;
        int isInLoop = true;
        int isPop = false;
        while (isInLoop) { 
            if (pq.empty()) {
                cnt++;
                pq.push({a, b});
                isInLoop = false;
            } else {
                auto x = pq.top();
                if (x.first ==  a && x.second == b) {
                    isInLoop = false;
                } else if ((x.first < a) || (x.first == a && x.second <= b)) {
                    cnt++;
                    pq.push({a, b});
                    isInLoop = false;
                } else {
                    if (!isPop) {
                        cnt++;
                        isPop = true;
                    }
                    pq.pop();
                }
            }
        }
    }
    cout << cnt;
}