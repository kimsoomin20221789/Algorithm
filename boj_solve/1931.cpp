#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<pair<int, int>> v;

    while (N--) {
        int a; int b; cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(), comp);

    int passVal = -1;
    int ans = 0;

    for (int i=0; i<v.size(); i++) {
        if (v[i].first < passVal) {
            continue;
        }
        ans++;
        passVal = v[i].second;
    }
    
    cout << ans;
}