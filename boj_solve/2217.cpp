#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    for (int i=0; i<N; i++) {
        long long x; cin >> x;
        pq.push(x);
    }

    long long ans = pq.top()*N;
    pq.pop();

    while (N--) {
        ans = max(pq.top()*N, ans);
        pq.pop();
    }

    cout << ans;
}