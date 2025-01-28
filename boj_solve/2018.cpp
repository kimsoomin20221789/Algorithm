#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;

    int pointer1 = 0;
    int pointer2 = 1;

    long long total = 1;
    int cnt = 0;
    while (!(pointer1 == N && pointer2 == N+1)) {
        if (total < N) {
            pointer2++;
            total += pointer2;
        } else if (total == N) {
            // cout << pointer1 << pointer2;
            cnt++; 
            pointer2++;
            total += pointer2;
        } else { // total > N
            total -= pointer1;
            pointer1++;
        }
    }

    cout << cnt;
}