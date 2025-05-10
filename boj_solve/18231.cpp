#include <bits/stdc++.h>
using namespace std;

bool fired[2003];

bool isNotBomb[2003];

vector<int> v[2003];
int N; int M; int K;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i=0; i<M; i++) {
        int a; int b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cin >> K;

    for (int i=0; i<K; i++) {
        int x; cin >> x;
        fired[x] = true;
    }

    for (int i=1; i<=N; i++) {
        if (!fired[i]) {
            isNotBomb[i] = 1;
            for (auto j : v[i]) {
                isNotBomb[j] = true;
            }
        }
    }
    
    vector<int> v1;
    for (int i=1; i<=N; i++) {
        if (!isNotBomb[i]) {
            v1.push_back(i);
        }
    }
    set<int> s;
    for (auto i : v1) {
        s.insert(i);
        for (auto j : v[i]) {
            s.insert(j);
        }
    }

    if (s.size() != K) {
        cout << -1;
        return 0;
    }
    if (v1.size()==0) {
        cout << -1;
    } else {
        cout << v1.size() << "\n";
        for (auto i : v1) {
            cout << i << " ";
        }
    }
}