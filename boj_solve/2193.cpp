#include <bits/stdc++.h>
using namespace std;
int N;
long oneDP[93];
long zeroDP[93];

int main() {
    cin >> N;

    for (int i=1; i<=N; i++) {
        if (i == 1) {
            zeroDP[i] = 0;
            oneDP[i] = 1; 
        } else {
            zeroDP[i] = zeroDP[i-1] + oneDP[i-1];
            oneDP[i] = zeroDP[i-1];
        }
    }

    cout << oneDP[N] + zeroDP[N];
}