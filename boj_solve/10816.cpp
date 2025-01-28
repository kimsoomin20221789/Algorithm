#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<int, int> m;
    int N; cin >> N;

    for (int i=0; i<N; i++) {
        int x; cin >> x;
        m[x]++;
    }

    int M; cin >> M;
    for (int i=0; i<M; i++) {
        int x; cin >> x;
        cout << m[x] << " ";
    }
}