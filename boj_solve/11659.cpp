#include <bits/stdc++.h>
using namespace std;
long long arr[100003];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N; int M; cin >> M;

    for (int i=1; i<=N; i++) {
        int a; cin >> a;
        arr[i] = arr[i-1] + a;
    }

    for (int i=0; i<M; i++) {
        int x; int y;
        cin >> x >> y;
        long long ans = arr[y] - arr[x-1];
        cout << ans << "\n";
    }
}