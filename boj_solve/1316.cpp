#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    int ans = 0;
    while (T--) {
        bool charCnt[26] = {0};
        string s; cin >> s;
        char beforeChar = 'A';
        bool isAnswer = true;
        for (auto x : s) {
            if (charCnt[x-'a'] == 0) {
                charCnt[x-'a'] = true;
                beforeChar = x;
            } else {
                if (beforeChar != x) {
                    isAnswer = false;
                    break;
                }
            }
        }

        if (isAnswer) {
            ans++;
        }
    }
    cout << ans;
}