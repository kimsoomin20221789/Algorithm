#include <bits/stdc++.h>
using namespace std;
multiset<int> ms;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    for (int i=0; i<N; i++) {
        int x; cin >> x;
        ms.insert(x);
        auto it = ms.begin();
        advance(it, i/2);
        cout << *it << "\n";
    }
}