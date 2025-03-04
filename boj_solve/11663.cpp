#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int M; cin >> M;

    vector<int> v;
    while (N--) {
        int a; cin >> a; v.push_back(a);
    }

    sort(v.begin(), v.end());

    while (M--) {
        int x; int y; cin >> x >> y;

        int cnt = upper_bound(v.begin(), v.end(), y) - 
                    lower_bound(v.begin(), v.end(), x);
        cout << cnt << "\n";
    }
}