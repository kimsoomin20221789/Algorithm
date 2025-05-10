#include <bits/stdc++.h>
using namespace std;

bool visited[1003];
vector<int> v[1003];
int ans;

void dfs(int s) {
    visited[s] = true;
    for (auto i : v[s]) {
        if (visited[i]) {continue;}
        dfs(i);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; int M; cin >> N >> M;


    set<int> s;
    for (int i=0; i<M; i++) {
        int x; int y; cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
        s.insert(x);
        s.insert(y);
    }
    // for (auto i : s) {
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            dfs(i);
            ans++;
        }
    }

    cout << ans;
}