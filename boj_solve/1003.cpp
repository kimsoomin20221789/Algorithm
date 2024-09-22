#include <bits/stdc++.h>
using namespace std;
int x[43];
int y[43];

int main() {
    x[0] = 1; y[0] = 0;
    x[1] = 0; y[1] = 1;

    for (int i=2; i<=40; i++) {
        x[i] = x[i-1] + x[i-2];
        y[i] = y[i-1] + y[i-2];
    }

    int T; cin >> T;

    for (int i=0; i<T; i++) {
        int k; cin >> k;
        cout << x[k] << " " << y[k] << "\n";
    }
}