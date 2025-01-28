#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x; cin >> x;
    string s;
    while (x != 1) {
        if (x % 2 == 0) {
            s.push_back('0');
        } else {
            s.push_back('1');
        }
        x = x / 2;
    }

    s.push_back('1');
    int ans = 0;

    for (auto i : s) {
        if (i == '1') {
            ans++;
        }
    }
    
    cout << ans;
}