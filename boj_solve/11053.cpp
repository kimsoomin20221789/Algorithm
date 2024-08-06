#include <bits/stdc++.h>
using namespace std;
int main() {
    int D[1001];
    int val[1001];

    int n; cin >> n;

    for (int i=0; i<n; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++) {
        D[i] = 1;
    }

    D[0] = 1;

    for (int i=1; i<n; i++) {
        for (int j=i-1; j>= 0; j--){
            if (val[i] > val[j]) {
                if (D[i] < D[j] +1) {
                   D[i] = D[j]+1;
                }
            }
        }
    }

    cout << *max_element(D, D+n);
}