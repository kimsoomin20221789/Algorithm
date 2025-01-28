#include <bits/stdc++.h>
using namespace std;
bool isErased[1000003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M; int N; cin >> M >> N;
    isErased[1] = true;

    for (int i=2; i*i <= N; i++) {
        if (!isErased[i]) {
            for (int j=i; i*j<=N; j++) {
                isErased[i*j] = true;
            }
        }
    }

    for (int i=M; i<=N; i++) {
        if (!isErased[i]) {
            cout << i << "\n";
        }
    }
}