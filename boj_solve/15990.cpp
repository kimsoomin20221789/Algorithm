#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dividingValue = 1000000009;
int num[3] = {1, 2, 3};
ll ans = 0;

void backTrack(int total, int before) {
    for (int i=0; i<3; i++) {
        if (before == num[i]) { continue; }
        total -= num[i];
        if (total == 0) {
            ans++;
            return;
        } else if (total < 0) {
            return;
        } else {
            backTrack(total, num[i]);
        }
        total += num[i];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int x; cin >> x;
        backTrack(x, 0);
        cout << ans % dividingValue << "\n";
        ans = 0;
    }
}