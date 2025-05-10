#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x; cin >> x;
    int recharge = 1000-x;
    int arr[6] = {500, 100, 50, 10, 5, 1};
    int ans = 0;

    for (int i=0; i<6; i++) {
        int cnt = recharge / arr[i];
        ans += cnt;
        recharge = recharge % arr[i];
    }

    cout << ans;
}