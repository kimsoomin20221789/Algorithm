#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;

    vector<int> v;
    while (N--) {
        int x; cin >> x;
        v.push_back(x);
    }

    vector<int> v2(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for (int i=0 ; i<v.size(); i++) {
        auto it = lower_bound(v2.begin(), v2.end(), v[i]);
        cout << it - v2.begin() << " ";
    }
}