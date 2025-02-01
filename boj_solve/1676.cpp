#include <bits/stdc++.h>
using namespace std;
int twoCnt;
int fiveCnt;

void cnt(int x) {
    while (true) {
        if (x % 2 == 0) {
            x /= 2;
            twoCnt++;
        } else {
            break;
        }
    }

    while (true) {
        if (x % 5 == 0) {
            x /= 5;
            fiveCnt++;
        } else {
            break;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;

    // 25 , 125, 

    for (int i=1; i<=N; i++) {
        cnt(i);
    }

    cout << min(twoCnt, fiveCnt);
}