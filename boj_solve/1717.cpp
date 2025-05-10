#include <bits/stdc++.h>
using namespace std;
const int MN = 1000001;
int par[MN];

void init(int n) {
    for (int i=1; i<=n; i++) {
        par[i] = i;
    }
}

// 조상 찾아서 본인의 부모를 최상위 조상으로 바꿈.
// 그리고 최상위 조상 return.
int find(int x) {
    if (x==par[x]) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);

    par[x] = find(y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; int m; cin >> n >> m;

    init(n);

    while (m--) {
        int isOutput; cin >> isOutput;
        int a; int b; cin >> a >> b;

        if (isOutput) {
            if (find(a) == find(b)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        } else {
            unite(a, b);
        }
    }
}