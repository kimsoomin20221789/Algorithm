#include <bits/stdc++.h>
using namespace std;

int N; int S;
int val[23];
int ans;

void backTrack(int cnt, int total) {
    // if (total == S) {
    //     ans++;
    //     return;
    // }

    // if (cnt == N) {
    //     return;
    // }
    if (cnt == N) {
		if (total == S) {
			cnt++;
		}
		return;
	}

    // backTrack(cnt+1, total+val[cnt+1]);
    backTrack(cnt+1, total+val[cnt]);
    backTrack(cnt+1, total);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    for (int i=1; i<=N; i++) {
        cin >> val[i];
    }

    backTrack(0, 0);
    if (S == 0) ans--;

    cout << ans;
}