#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N; int M; cin >> N >> M;

    vector<bool> v;

    while (N--) {
        bool x; cin >> x;
        v.push_back(x);
    }

    while (M--) {
        int i; int a; int b;
        cin >> i >> a >> b;

        if (i == 1) {
            v[a-1] = b;
        } else if (i == 2) {
            for (int k=a; k<=b; k++) {
                v[k-1] = !v[k-1];
            }
        } else if (i == 3) {
            for (int k=a; k<=b; k++) {
                v[k-1] = false;
            }            
        } else {
            for (int k=a; k<=b; k++) {
                v[k-1] = true;
            } 
        }
    }

    for (auto i : v) {
        if (i) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
}