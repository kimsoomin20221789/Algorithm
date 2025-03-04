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

    map<int, int> m;
    int cnt = 1;
    int curVal = 0;
    for (int i=0; i<v2.size(); i++) {
        curVal = v2[i];
        if (m[curVal] == 0) {
            m[curVal] = cnt;
            cnt++;
        }
    }

    for (int i=0; i<v.size(); i++) {
        cout << m[v[i]]-1 << " ";
    }
}