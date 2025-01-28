#include <bits/stdc++.h>
using namespace std;
multiset<int> ms;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;

    for (int i=1; i<=T; i++) {
        ms.clear();
        int M; cin >> M;
        cout << (M+1)/2 << "\n";

        int tenCnt = 0;
        for (int j=1; j<=M; j++) {
            int x; cin >> x;
            ms.insert(x);

            if (j%2 == 1) { // 홀수
                tenCnt++;
                auto it = ms.begin();
                advance(it, (j+1)/2 -1);
                cout << *it << " ";
                if (tenCnt == 10) {
                    cout << "\n";
                    tenCnt = 0;
                }
            }
        }

        cout << "\n";
    }
}