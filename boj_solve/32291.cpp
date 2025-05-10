#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long x; cin >> x;

    for (long long i=1; i<=x; i++) {
        if ((x+1) % i == 0) {
            cout << i << " ";
        }
    }
}